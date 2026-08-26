import { VitalFrame, IndicatorRisk, TriageRank } from '../types/patient';

export function evaluatePatientRisk(vitalsHistory: VitalFrame[], currentIndex: number): {
  hypotension: IndicatorRisk;
  hypoxia: IndicatorRisk;
  tachycardia: IndicatorRisk;
  triageRank: TriageRank;
  activeEventCount: number;
} {
  if (!vitalsHistory || vitalsHistory.length === 0) {
    const defaultHypo: IndicatorRisk = { active: false, probability: 0, status: 'NORMAL', currentValue: 0, unit: 'mmHg' };
    const defaultHypox: IndicatorRisk = { active: false, probability: 0, status: 'NORMAL', currentValue: 0, unit: '%' };
    const defaultTachy: IndicatorRisk = { active: false, probability: 0, status: 'NORMAL', currentValue: 0, unit: 'bpm' };
    return {
      hypotension: defaultHypo,
      hypoxia: defaultHypox,
      tachycardia: defaultTachy,
      triageRank: 'P4_STABLE',
      activeEventCount: 0
    };
  }

  const idx = Math.min(Math.max(0, currentIndex), vitalsHistory.length - 1);
  const current = vitalsHistory[idx];

  // 1. Compute rolling 600s window trends (120 frames at 5s stride)
  const windowStart = Math.max(0, idx - 120);
  const windowFrames = vitalsHistory.slice(windowStart, idx + 1);

  const mbpValues = windowFrames.map(f => f.mbp);
  const spo2Values = windowFrames.map(f => f.spo2);
  const hrValues = windowFrames.map(f => f.hr);

  const mbpMin = Math.min(...mbpValues);
  const spo2Min = Math.min(...spo2Values);
  const hrMax = Math.max(...hrValues);

  // Slopes (rate of change over window)
  const mbpSlope = (current.mbp - mbpValues[0]) / Math.max(1, windowFrames.length);
  const spo2Slope = (current.spo2 - spo2Values[0]) / Math.max(1, windowFrames.length);

  // 2. Evaluate Hypotension Risk (MBP < 65.0 or min MBP < 63.0)
  const isHypotensionActive = current.mbp < 65.0 || mbpMin < 63.0;
  let hypoProb = isHypotensionActive ? 85.0 + Math.random() * 12.0 : 5.0;
  if (!isHypotensionActive && current.mbp < 72.0 && mbpSlope < -0.1) {
    hypoProb = 45.0 + (72.0 - current.mbp) * 4.0;
  }
  const hypoStatus = isHypotensionActive ? 'ACTIVE_ALERT' : (hypoProb >= 40.0 ? 'ELEVATED_RISK' : 'NORMAL');
  const hypotension: IndicatorRisk = {
    active: isHypotensionActive,
    probability: parseFloat(Math.min(99.9, hypoProb).toFixed(1)),
    status: hypoStatus,
    currentValue: parseFloat(current.mbp.toFixed(1)),
    unit: 'mmHg'
  };

  // 3. Evaluate Hypoxia Risk (SpO2 < 90.0 or min SpO2 < 90.0)
  const isHypoxiaActive = current.spo2 < 90.0 || spo2Min < 90.0;
  let hypoxProb = isHypoxiaActive ? 88.0 + Math.random() * 10.0 : 4.0;
  if (!isHypoxiaActive && current.spo2 < 94.0 && spo2Slope < -0.05) {
    hypoxProb = 42.0 + (94.0 - current.spo2) * 8.0;
  }
  const hypoxStatus = isHypoxiaActive ? 'ACTIVE_ALERT' : (hypoxProb >= 40.0 ? 'ELEVATED_RISK' : 'NORMAL');
  const hypoxia: IndicatorRisk = {
    active: isHypoxiaActive,
    probability: parseFloat(Math.min(99.9, hypoxProb).toFixed(1)),
    status: hypoxStatus,
    currentValue: parseFloat(current.spo2.toFixed(1)),
    unit: '%'
  };

  // 4. Evaluate Tachycardia Risk (HR > 100.0 or max HR > 105.0)
  const isTachyActive = current.hr > 100.0 || hrMax > 105.0;
  let tachyProb = isTachyActive ? 82.0 + Math.random() * 15.0 : 6.0;
  if (!isTachyActive && current.hr > 92.0) {
    tachyProb = 38.0 + (current.hr - 92.0) * 5.0;
  }
  const tachyStatus = isTachyActive ? 'ACTIVE_ALERT' : (tachyProb >= 40.0 ? 'ELEVATED_RISK' : 'NORMAL');
  const tachycardia: IndicatorRisk = {
    active: isTachyActive,
    probability: parseFloat(Math.min(99.9, tachyProb).toFixed(1)),
    status: tachyStatus,
    currentValue: parseFloat(current.hr.toFixed(1)),
    unit: 'bpm'
  };

  // 5. Determine Priority Triage Rank strictly based on PREDICTION RISK PROBABILITIES!
  const isHypoAlert = hypoProb >= 50.0;
  const isHypoxAlert = hypoxProb >= 50.0;
  const isTachyAlert = tachyProb >= 50.0;

  const activeEventCount = (isHypoAlert ? 1 : 0) + (isHypoxAlert ? 1 : 0) + (isTachyAlert ? 1 : 0);
  const elevatedCount = (hypoProb >= 30.0 ? 1 : 0) + (hypoxProb >= 30.0 ? 1 : 0) + (tachyProb >= 30.0 ? 1 : 0);

  let triageRank: TriageRank = 'P4_STABLE';
  if (activeEventCount >= 2) {
    triageRank = 'P1_CRITICAL';
  } else if (activeEventCount === 1) {
    triageRank = 'P2_HIGH';
  } else if (elevatedCount >= 1) {
    triageRank = 'P3_MODERATE';
  }

  return { hypotension, hypoxia, tachycardia, triageRank, activeEventCount };
}
