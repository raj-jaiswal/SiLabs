import { NextResponse } from 'next/server';
import fs from 'fs';
import path from 'path';
import { generateDemographics } from '@/utils/demographics';
import { evaluatePatientRisk } from '@/utils/triageEngine';
import { VitalFrame, PatientState } from '@/types/patient';

export async function GET() {
  try {
    const dataDir = '/home/logan78/Desktop/SiLabs/process_labeled_data';
    if (!fs.existsSync(dataDir)) {
      return NextResponse.json({ error: `Directory ${dataDir} not found` }, { status: 404 });
    }

    const files = fs.readdirSync(dataDir)
      .filter(f => f.startsWith('patient_') && f.endsWith('_1hz.csv'))
      .slice(0, 10); // Select 10 offline patients

    const patientStates: PatientState[] = [];

    // 1. Process 10 CSV Simulated Patients
    for (const file of files) {
      const patientId = file.replace('_1hz.csv', '').replace('patient_', 'PATIENT-');
      const filePath = path.join(dataDir, file);
      const csvData = fs.readFileSync(filePath, 'utf-8');
      const lines = csvData.split('\n');

      if (lines.length < 2) continue;

      const headers = lines[0].split(',').map(h => h.trim());
      const hrIdx = headers.indexOf('Solar8000/HR');
      const sbpIdx = headers.indexOf('Solar8000/ART_SBP');
      const dbpIdx = headers.indexOf('Solar8000/ART_DBP');
      const mbpIdx = headers.indexOf('Solar8000/ART_MBP');
      const spo2Idx = headers.indexOf('Solar8000/PLETH_SPO2');
      const etco2Idx = headers.indexOf('Solar8000/ETCO2');
      const fio2Idx = headers.indexOf('Primus/FIO2');
      const tempIdx = headers.indexOf('Solar8000/BT');

      const vitalsHistory: VitalFrame[] = [];
      const stride = 5; // 5-second stride sampling

      for (let i = 1; i < lines.length && vitalsHistory.length < 500; i += stride) {
        const line = lines[i].trim();
        if (!line) continue;
        const row = line.split(',');
        if (row.length < headers.length) continue;

        const hr = parseFloat(row[hrIdx]) || 75.0;
        const sbp = parseFloat(row[sbpIdx]) || 120.0;
        const dbp = parseFloat(row[dbpIdx]) || 80.0;
        const mbp = parseFloat(row[mbpIdx]) || (sbp + 2 * dbp) / 3.0;
        const spo2 = parseFloat(row[spo2Idx]) || 98.0;
        const etco2 = parseFloat(row[etco2Idx]) || 35.0;
        const fio2 = parseFloat(row[fio2Idx]) || 30.0;
        const bodyTemp = parseFloat(row[tempIdx]) || 36.8;

        vitalsHistory.push({
          timestampSec: i,
          hr,
          sbp,
          dbp,
          mbp,
          spo2,
          etco2,
          fio2,
          bodyTemp,
          pulsePressure: sbp - dbp,
          shockIndex: hr / Math.max(1, sbp)
        });
      }

      if (vitalsHistory.length === 0) continue;

      const profile = generateDemographics(patientId);
      const riskEval = evaluatePatientRisk(vitalsHistory, 0);

      patientStates.push({
        profile,
        vitalsHistory,
        currentFrameIndex: 0,
        currentFrame: vitalsHistory[0],
        hypotension: riskEval.hypotension,
        hypoxia: riskEval.hypoxia,
        tachycardia: riskEval.tachycardia,
        triageRank: riskEval.triageRank,
        activeEventCount: riskEval.activeEventCount,
        isEsp32Live: false,
      });
    }

    // 2. Fetch Live ESP32 Telemetry for PATIENT-000 from server.py (port 5000)
    let esp32Scores: number[] = [0.87, 0.95, 0.40]; // Default baseline scores
    let isStale = false;
    let lastUpdateSecAgo = 0;

    try {
      const esp32Res = await fetch('http://localhost:5000/api/devices', { cache: 'no-store', signal: AbortSignal.timeout(1000) });
      if (esp32Res.ok) {
        const devices = await esp32Res.json();
        const deviceList = Object.values(devices) as any[];

        if (deviceList.length > 0) {
          // Sort devices by last_updated_epoch descending to get the MOST RECENT active streaming device!
          deviceList.sort((a, b) => (b.last_updated_epoch || 0) - (a.last_updated_epoch || 0));
          const activeDev = deviceList[0];

          if (activeDev) {
            if (Array.isArray(activeDev.scores) && activeDev.scores.length > 0) {
              esp32Scores = activeDev.scores;
            }
            if (activeDev.last_updated_epoch) {
              const elapsed = Math.max(0, Math.floor((Date.now() / 1000) - activeDev.last_updated_epoch));
              lastUpdateSecAgo = elapsed;
              if (elapsed >= 20) {
                isStale = true;
              }
            } else {
              isStale = true;
            }
          } else {
            isStale = true;
          }
        } else {
          isStale = true;
        }
      } else {
        isStale = true;
      }
    } catch (e) {
      isStale = true;
    }

    // Build PATIENT-000 Vitals History (50 frames matching 10 offline patients)
    const esp32VitalsHistory: VitalFrame[] = [];
    const baseMbP = esp32Scores[0] > 0.5 ? 60.0 : 75.0; // Hypotension correlation
    const baseSpO2 = esp32Scores[1] > 0.5 ? 88.0 : 98.0; // Hypoxia correlation
    const baseHR = esp32Scores[2] > 0.5 ? 110.0 : 72.0;  // Tachycardia correlation

    for (let f = 0; f < 500; f++) {
      esp32VitalsHistory.push({
        timestampSec: f * 5,
        hr: baseHR + (f % 3) * 0.5,
        sbp: baseMbP + 40,
        dbp: baseMbP - 10,
        mbp: baseMbP,
        spo2: baseSpO2,
        etco2: 35.0,
        fio2: 30.0,
        bodyTemp: 36.8,
        pulsePressure: 50.0,
        shockIndex: baseHR / (baseMbP + 40),
      });
    }

    const p000Profile = generateDemographics('PATIENT-000');
    p000Profile.isStale = isStale;
    p000Profile.lastUpdateSecAgo = lastUpdateSecAgo;

    const p000RiskEval = evaluatePatientRisk(esp32VitalsHistory, 0);

    // Override predictions with exact ESP32 model probability scores
    p000RiskEval.hypotension.probability = Math.round(esp32Scores[0] * 100);
    p000RiskEval.hypotension.active = esp32Scores[0] >= 0.5;
    p000RiskEval.hypotension.status = esp32Scores[0] >= 0.5 ? 'ACTIVE_ALERT' : esp32Scores[0] >= 0.3 ? 'ELEVATED_RISK' : 'NORMAL';

    if (esp32Scores.length > 1) {
      p000RiskEval.hypoxia.probability = Math.round(esp32Scores[1] * 100);
      p000RiskEval.hypoxia.active = esp32Scores[1] >= 0.5;
      p000RiskEval.hypoxia.status = esp32Scores[1] >= 0.5 ? 'ACTIVE_ALERT' : esp32Scores[1] >= 0.3 ? 'ELEVATED_RISK' : 'NORMAL';
    }

    if (esp32Scores.length > 2) {
      p000RiskEval.tachycardia.probability = Math.round(esp32Scores[2] * 100);
      p000RiskEval.tachycardia.active = esp32Scores[2] >= 0.5;
      p000RiskEval.tachycardia.status = esp32Scores[2] >= 0.5 ? 'ACTIVE_ALERT' : esp32Scores[2] >= 0.3 ? 'ELEVATED_RISK' : 'NORMAL';
    }

    patientStates.push({
      profile: p000Profile,
      vitalsHistory: esp32VitalsHistory,
      currentFrameIndex: 0,
      currentFrame: esp32VitalsHistory[0],
      hypotension: p000RiskEval.hypotension,
      hypoxia: p000RiskEval.hypoxia,
      tachycardia: p000RiskEval.tachycardia,
      triageRank: p000RiskEval.triageRank,
      activeEventCount: (esp32Scores[0] >= 0.5 ? 1 : 0) + (esp32Scores[1] >= 0.5 ? 1 : 0) + (esp32Scores[2] >= 0.5 ? 1 : 0),
      isEsp32Live: true,
      isStale,
      lastUpdateSecAgo,
    });

    return NextResponse.json({ patients: patientStates });
  } catch (error: any) {
    return NextResponse.json({ error: error.message }, { status: 500 });
  }
}
