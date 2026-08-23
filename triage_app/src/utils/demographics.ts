import { PatientDemographics } from '../types/patient';

const DIAGNOSES = [
  { primary: 'Post-CABG (Coronary Artery Bypass)', comorbidities: ['Hypertension', 'Type 2 Diabetes', 'Hyperlipidemia'] },
  { primary: 'Severe Sepsis (Abdominal Origin)', comorbidities: ['Acute Kidney Injury', 'Hypertension'] },
  { primary: 'COPD Exacerbation & Pneumonia', comorbidities: ['Chronic Bronchitis', 'Pulmonary Hypertension'] },
  { primary: 'Acute Myocardial Infarction', comorbidities: ['Coronary Artery Disease', 'Smoking History'] },
  { primary: 'Polytrauma & Hemorrhagic Shock', comorbidities: ['Traumatic Brain Injury'] },
  { primary: 'Hypertensive Crisis & Aortic Dissection', comorbidities: ['Essential Hypertension', 'Aortic Aneurysm'] },
  { primary: 'Decompensated Heart Failure', comorbidities: ['Atrial Fibrillation', 'CKD Stage 3'] },
  { primary: 'Acute Respiratory Distress Syndrome (ARDS)', comorbidities: ['Asthma', 'Obesity Class II'] },
];

const ALLERGIES_LIST = [
  ['Penicillin', 'Sulfa Drugs'],
  ['Latex'],
  ['Aspirin', 'NSAIDs'],
  ['Morphine'],
  ['None Known'],
  ['Contrast Dye'],
  ['Ciprofloxacin']
];

const PHYSICIANS = [
  'Dr. Sarah Chen, MD (Intensivist)',
  'Dr. Marcus Vance, MD (Cardiothoracic Surgery)',
  'Dr. Elena Rostova, MD (Anesthesiology)',
  'Dr. James Wilson, MD (Trauma Surgery)',
  'Dr. Amara Patel, MD (Pulmonology)',
  'Dr. Robert Sterling, MD (Critical Care)'
];

const BLOOD_TYPES = ['A+', 'O+', 'B+', 'AB+', 'A-', 'O-', 'B-', 'AB-'] as const;

export function generateDemographics(patientId: string): PatientDemographics {
  if (patientId === 'PATIENT-000' || patientId.includes('000')) {
    return {
      id: 'PATIENT-000',
      patientNumber: 'PATIENT-000',
      age: 48,
      sex: 'Male',
      bloodType: 'O+',
      weightKg: 72,
      heightCm: 175,
      bmi: 23.5,
      primaryDiagnosis: 'Real-Time ESP32 AI Model Telemetry Stream',
      comorbidities: ['Live Wi-Fi Telemetry', 'Sub-Second Edge Prediction'],
      allergies: ['None Known'],
      attendingPhysician: 'Dr. ESP32 Wi-Fi Stream',
      isEsp32Live: true,
    };
  }

  // Deterministic seed from patient ID number
  const numStr = patientId.replace(/\D/g, '') || '100';
  const seed = parseInt(numStr, 10);
  
  const age = 35 + (seed % 50);
  const sex = (seed % 2 === 0) ? 'Male' : 'Female';
  const bloodType = BLOOD_TYPES[seed % BLOOD_TYPES.length];
  
  const heightCm = sex === 'Male' ? 170 + (seed % 20) : 155 + (seed % 20);
  const weightKg = 55 + (seed % 45);
  const bmi = parseFloat((weightKg / ((heightCm / 100) ** 2)).toFixed(1));
  
  const diagObj = DIAGNOSES[seed % DIAGNOSES.length];
  const allergies = ALLERGIES_LIST[seed % ALLERGIES_LIST.length];
  const physician = PHYSICIANS[seed % PHYSICIANS.length];

  return {
    id: patientId,
    patientNumber: `PATIENT-${numStr}`,
    age,
    sex,
    bloodType,
    weightKg,
    heightCm,
    bmi,
    primaryDiagnosis: diagObj.primary,
    comorbidities: diagObj.comorbidities,
    allergies,
    attendingPhysician: physician,
  };
}
