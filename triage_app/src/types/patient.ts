export type TriageRank = 'P1_CRITICAL' | 'P2_HIGH' | 'P3_MODERATE' | 'P4_STABLE';

export interface IndicatorRisk {
  active: boolean;       // True if current vital exceeds threshold (e.g. MBP < 65)
  probability: number;   // 0.0 to 100.0% predicted risk
  status: 'ACTIVE_ALERT' | 'ELEVATED_RISK' | 'NORMAL';
  currentValue: number;  // Latest vital value
  unit: string;
}

export interface PatientDemographics {
  id: string;
  patientNumber: string;
  age: number;
  sex: 'Male' | 'Female';
  bloodType: 'A+' | 'O+' | 'B+' | 'AB+' | 'A-' | 'O-' | 'B-' | 'AB-';
  weightKg: number;
  heightCm: number;
  bmi: number;
  primaryDiagnosis: string;
  comorbidities: string[];
  allergies: string[];
  attendingPhysician: string;
}

export interface VitalFrame {
  timestampSec: number;
  hr: number;         // Heart Rate (bpm)
  sbp: number;        // Systolic BP (mmHg)
  dbp: number;        // Diastolic BP (mmHg)
  mbp: number;        // Mean Arterial BP (mmHg)
  spo2: number;       // Oxygen Saturation (%)
  etco2: number;      // End-Tidal CO2 (mmHg)
  fio2: number;       // Inspired O2 (%)
  bodyTemp: number;   // Temperature (°C)
  pulsePressure: number;
  shockIndex: number;
}

export interface PatientState {
  profile: PatientDemographics;
  vitalsHistory: VitalFrame[];
  currentFrameIndex: number;
  currentFrame: VitalFrame;
  hypotension: IndicatorRisk;
  hypoxia: IndicatorRisk;
  tachycardia: IndicatorRisk;
  triageRank: TriageRank;
  activeEventCount: number;
}
