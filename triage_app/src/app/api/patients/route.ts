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
      .slice(0, 10); // Select 10 patients

    const patientStates: PatientState[] = [];

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
        activeEventCount: riskEval.activeEventCount
      });
    }

    return NextResponse.json({ patients: patientStates });
  } catch (error: any) {
    return NextResponse.json({ error: error.message }, { status: 500 });
  }
}
