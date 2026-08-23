# Hospital Triage & Adverse Event Monitoring Dashboard Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use `superpowers:subagent-driven-development` (recommended) or `superpowers:executing-plans` to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a modern, minimalist hospital triage dashboard in Next.js 14 (React, TypeScript, Tailwind CSS) that parses patient 1 Hz telemetry from `/home/logan78/Desktop/SiLabs/process_labeled_data`, streams vitals in 5-second strides, calculates Hypotension, Hypoxia, and Tachycardia risk indicators, and dynamically sorts patients in a Priority Triage Queue.

**Architecture:** A client-server Next.js App Router application where an API route (`/api/patients`) loads a batch of patient CSV files from `/home/logan78/Desktop/SiLabs/process_labeled_data` along with synthetic clinical profiles (demographics, comorbidities, allergies, physician). The client-side dashboard executes an automated 5-second stride loop, computing rolling 600s window features to derive risk scores and dynamically rank patients (P1 Critical ➔ P2 High ➔ P3 Moderate ➔ P4 Stable) with a monochromatic hospital visual aesthetic.

**Tech Stack:** Next.js 14, React 18, TypeScript, Tailwind CSS, Lucide React Icons.

## Global Constraints

- Project Root Directory: `/home/logan78/Desktop/SiLabs/triage_app`
- Data Source Directory: `/home/logan78/Desktop/SiLabs/process_labeled_data`
- Theme: Clinical Monochromatic Slate/Zinc (`slate-950` header, `slate-900` cards, `slate-50` background, high contrast)
- Indicators: Hypotension ($\text{MBP} < 65\text{ mmHg}$), Hypoxia ($\text{SpO}_2 < 90\%$), Tachycardia ($\text{HR} > 100\text{ bpm}$)
- Excluded Fields: No Bed Number, No Ward Unit

---

### Task 1: Initialize Next.js 14 Project & App Scaffolding

**Files:**
- Create: `triage_app/package.json`
- Create: `triage_app/tsconfig.json`
- Create: `triage_app/tailwind.config.js`
- Create: `triage_app/postcss.config.js`
- Create: `triage_app/next.config.js`
- Create: `triage_app/src/app/globals.css`
- Create: `triage_app/src/app/layout.tsx`

**Interfaces:**
- Consumes: Node.js & npm environment
- Produces: Executable Next.js app scaffold with Tailwind CSS

- [ ] **Step 1: Scaffold Next.js application directory and configuration**

Create `triage_app/package.json`:
```json
{
  "name": "hospital-triage-dashboard",
  "version": "1.0.0",
  "private": true,
  "scripts": {
    "dev": "next dev",
    "build": "next build",
    "start": "next start",
    "lint": "next lint"
  },
  "dependencies": {
    "next": "^14.2.5",
    "react": "^18.3.1",
    "react-dom": "^18.3.1",
    "lucide-react": "^0.424.0",
    "clsx": "^2.1.1",
    "tailwind-merge": "^2.4.0"
  },
  "devDependencies": {
    "@types/node": "^20.14.10",
    "@types/react": "^18.3.3",
    "@types/react-dom": "^18.3.0",
    "autoprefixer": "^10.4.19",
    "postcss": "^8.4.39",
    "tailwindcss": "^3.4.6",
    "typescript": "^5.5.3"
  }
}
```

Create `triage_app/tailwind.config.js`:
```js
/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./src/pages/**/*.{js,ts,jsx,tsx,mdx}",
    "./src/components/**/*.{js,ts,jsx,tsx,mdx}",
    "./src/app/**/*.{js,ts,jsx,tsx,mdx}",
  ],
  theme: {
    extend: {
      colors: {
        hospital: {
          dark: '#0f172a',
          card: '#1e293b',
          muted: '#64748b',
          accent: '#0284c7',
          critical: '#ef4444',
          high: '#f59e0b',
          moderate: '#eab308',
          stable: '#10b981'
        }
      }
    },
  },
  plugins: [],
}
```

Create `triage_app/postcss.config.js`:
```js
module.exports = {
  plugins: {
    tailwindcss: {},
    autoprefixer: {},
  },
}
```

Create `triage_app/next.config.js`:
```js
/** @type {import('next').NextConfig} */
const nextConfig = {
  reactStrictMode: true,
}
module.exports = nextConfig
```

Create `triage_app/tsconfig.json`:
```json
{
  "compilerOptions": {
    "target": "es5",
    "lib": ["dom", "dom.iterable", "esnext"],
    "allowJs": true,
    "skipLibCheck": true,
    "strict": true,
    "noEmit": true,
    "esModuleInterop": true,
    "module": "esnext",
    "moduleResolution": "bundler",
    "resolveJsonModule": true,
    "isolatedModules": true,
    "jsx": "preserve",
    "incremental": true,
    "plugins": [{ "name": "next" }],
    "paths": {
      "@/*": ["./src/*"]
    }
  },
  "include": ["next-env.d.ts", "**/*.ts", "**/*.tsx", ".next/types/**/*.ts"],
  "exclude": ["node_modules"]
}
```

Create `triage_app/src/app/globals.css`:
```css
@tailwind base;
@tailwind components;
@tailwind utilities;

body {
  background-color: #090d16;
  color: #f8fafc;
  font-family: ui-sans-serif, system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, sans-serif;
}
```

Create `triage_app/src/app/layout.tsx`:
```tsx
import './globals.css'
import { ReactNode } from 'react'

export const metadata = {
  title: 'Clinical Triage Monitor | SiLabs ICU',
  description: 'Hospital Triage & Adverse Event Real-Time Simulator',
}

export default function RootLayout({ children }: { children: ReactNode }) {
  return (
    <html lang="en" className="dark">
      <body className="bg-slate-950 text-slate-100 min-h-screen antialiased">
        {children}
      </body>
    </html>
  )
}
```

- [ ] **Step 2: Install dependencies & verify Next.js build**

Run: `cd /home/logan78/Desktop/SiLabs/triage_app && npm install`  
Expected: `added packages successfully`

- [ ] **Step 3: Commit Task 1**

```bash
git add triage_app/
git commit -m "feat(triage_app): scaffold Next.js 14 app with Tailwind CSS"
```

---

### Task 2: Define Patient Data Models & Clinical Profile Generator

**Files:**
- Create: `triage_app/src/types/patient.ts`
- Create: `triage_app/src/utils/demographics.ts`

**Interfaces:**
- Consumes: Nothing
- Produces: `PatientProfile`, `VitalFrame`, `IndicatorRisk`, `TriageRank` types and `generateDemographics()` function

- [ ] **Step 1: Write `triage_app/src/types/patient.ts`**

```ts
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
```

- [ ] **Step 2: Write `triage_app/src/utils/demographics.ts`**

```ts
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
```

- [ ] **Step 3: Commit Task 2**

```bash
git add triage_app/src/types/ triage_app/src/utils/
git commit -m "feat(triage_app): add patient state types and clinical demographics generator"
```

---

### Task 3: Implement Triage Engine & Risk Evaluator

**Files:**
- Create: `triage_app/src/utils/triageEngine.ts`

**Interfaces:**
- Consumes: `VitalFrame`, `IndicatorRisk`, `TriageRank` from `types/patient.ts`
- Produces: `evaluatePatientState(vitalsHistory, currentIndex)`

- [ ] **Step 1: Write `triage_app/src/utils/triageEngine.ts`**

```ts
import { VitalFrame, IndicatorRisk, TriageRank, PatientState, PatientDemographics } from '../types/patient';

export function evaluatePatientRisk(vitalsHistory: VitalFrame[], currentIndex: number): {
  hypotension: IndicatorRisk;
  hypoxia: IndicatorRisk;
  tachycardia: IndicatorRisk;
  triageRank: TriageRank;
  activeEventCount: number;
} {
  if (!vitalsHistory || vitalsHistory.length === 0) {
    const defaultRisk: IndicatorRisk = { active: false, probability: 0, status: 'NORMAL', currentValue: 0, unit: '' };
    return { hypotension: defaultRisk, hypoxia: defaultRisk, tachycardia: defaultRisk, triageRank: 'P4_STABLE', activeEventCount: 0 };
  }

  const idx = Math.min(currentIndex, vitalsHistory.length - 1);
  const current = vitalsHistory[idx];

  // 1. Compute rolling 60s/600s window trends
  const windowStart = Math.max(0, idx - 120); // 120 frames (~600s if 5s stride)
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

  // 2. Evaluate Hypotension Risk
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

  // 3. Evaluate Hypoxia Risk
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

  // 4. Evaluate Tachycardia Risk
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

  // 5. Determine Priority Triage Rank
  const activeEventCount = (isHypotensionActive ? 1 : 0) + (isHypoxiaActive ? 1 : 0) + (isTachyActive ? 1 : 0);
  const elevatedCount = (hypoProb >= 40.0 ? 1 : 0) + (hypoxProb >= 40.0 ? 1 : 0) + (tachyProb >= 40.0 ? 1 : 0);

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
```

- [ ] **Step 2: Commit Task 3**

```bash
git add triage_app/src/utils/triageEngine.ts
git commit -m "feat(triage_app): implement 5-second stride triage risk engine"
```

---

### Task 4: Implement Patient Data API Route (`/api/patients`)

**Files:**
- Create: `triage_app/src/app/api/patients/route.ts`

**Interfaces:**
- Consumes: `/home/logan78/Desktop/SiLabs/process_labeled_data/*.csv`
- Produces: JSON payload containing loaded patients, vitals history, and initial state

- [ ] **Step 1: Write `triage_app/src/app/api/patients/route.ts`**

```ts
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
        const row = lines[i].split(',');
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
```

- [ ] **Step 2: Commit Task 4**

```bash
git add triage_app/src/app/api/patients/route.ts
git commit -m "feat(triage_app): add /api/patients CSV reader route"
```

---

### Task 5: Build UI Header & Status Summary Components

**Files:**
- Create: `triage_app/src/components/Header.tsx`

**Interfaces:**
- Consumes: Patient states array
- Produces: Clinical Header with pulsing live stride badge & triage counts

- [ ] **Step 1: Write `triage_app/src/components/Header.tsx`**

```tsx
import React from 'react';
import { Activity, ShieldAlert, AlertTriangle, CheckCircle, HeartPulse } from 'lucide-react';
import { PatientState } from '../types/patient';

interface HeaderProps {
  patients: PatientState[];
  strideCount: number;
}

export const Header: React.FC<HeaderProps> = ({ patients, strideCount }) => {
  const criticalCount = patients.filter(p => p.triageRank === 'P1_CRITICAL').length;
  const highCount = patients.filter(p => p.triageRank === 'P2_HIGH').length;
  const moderateCount = patients.filter(p => p.triageRank === 'P3_MODERATE').length;
  const stableCount = patients.filter(p => p.triageRank === 'P4_STABLE').length;

  return (
    <header className="bg-slate-900 border-b border-slate-800 px-6 py-4">
      <div className="max-w-7xl mx-auto flex flex-col md:flex-row md:items-center md:justify-between gap-4">
        {/* Title & Live Badge */}
        <div className="flex items-center space-x-3">
          <div className="p-2.5 bg-slate-800 rounded-lg border border-slate-700 text-sky-400">
            <HeartPulse className="w-6 h-6 animate-pulse text-sky-400" />
          </div>
          <div>
            <div className="flex items-center space-x-2">
              <h1 className="text-xl font-bold tracking-tight text-slate-100 uppercase">
                Clinical Triage Monitor
              </h1>
              <span className="inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-semibold bg-emerald-950 text-emerald-400 border border-emerald-800">
                <span className="w-1.5 h-1.5 rounded-full bg-emerald-400 mr-1.5 animate-ping" />
                LIVE 5s STRIDE #{strideCount}
              </span>
            </div>
            <p className="text-xs text-slate-400 mt-0.5">
              SiLabs Intraoperative Adverse Event Predictor • Hypotension | Hypoxia | Tachycardia
            </p>
          </div>
        </div>

        {/* Triage Summary Badges */}
        <div className="grid grid-cols-4 gap-3 text-center">
          <div className="bg-rose-950/40 border border-rose-900/60 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-rose-400 uppercase tracking-wider flex items-center justify-center">
              <ShieldAlert className="w-3.5 h-3.5 mr-1" /> P1 Critical
            </div>
            <div className="text-lg font-bold text-rose-300">{criticalCount}</div>
          </div>

          <div className="bg-amber-950/40 border border-amber-900/60 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-amber-400 uppercase tracking-wider flex items-center justify-center">
              <AlertTriangle className="w-3.5 h-3.5 mr-1" /> P2 High
            </div>
            <div className="text-lg font-bold text-amber-300">{highCount}</div>
          </div>

          <div className="bg-yellow-950/30 border border-yellow-900/50 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-yellow-400 uppercase tracking-wider">P3 Moderate</div>
            <div className="text-lg font-bold text-yellow-300">{moderateCount}</div>
          </div>

          <div className="bg-emerald-950/40 border border-emerald-900/60 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-emerald-400 uppercase tracking-wider flex items-center justify-center">
              <CheckCircle className="w-3.5 h-3.5 mr-1" /> P4 Stable
            </div>
            <div className="text-lg font-bold text-emerald-300">{stableCount}</div>
          </div>
        </div>
      </div>
    </header>
  );
};
```

- [ ] **Step 2: Commit Task 5**

```bash
git add triage_app/src/components/Header.tsx
git commit -m "feat(triage_app): add Header component with triage badges"
```

---

### Task 6: Build Main Priority Triage Table Component

**Files:**
- Create: `triage_app/src/components/TriageTable.tsx`

**Interfaces:**
- Consumes: `patients: PatientState[]`, `onSelectPatient(patient: PatientState)`
- Produces: Monochromatic, auto-sorted Priority Triage Table

- [ ] **Step 1: Write `triage_app/src/components/TriageTable.tsx`**

```tsx
import React from 'react';
import { ShieldAlert, AlertTriangle, CheckCircle, ChevronRight, Activity, Droplets, User } from 'lucide-react';
import { PatientState, TriageRank, IndicatorRisk } from '../types/patient';

interface TriageTableProps {
  patients: PatientState[];
  onSelectPatient: (patient: PatientState) => void;
}

const RANK_SORT_ORDER: Record<TriageRank, number> = {
  'P1_CRITICAL': 1,
  'P2_HIGH': 2,
  'P3_MODERATE': 3,
  'P4_STABLE': 4,
};

export const TriageTable: React.FC<TriageTableProps> = ({ patients, onSelectPatient }) => {
  // Sort patients by Triage Rank ascending
  const sortedPatients = [...patients].sort((a, b) => {
    const rankDiff = RANK_SORT_ORDER[a.triageRank] - RANK_SORT_ORDER[b.triageRank];
    if (rankDiff !== 0) return rankDiff;
    return b.activeEventCount - a.activeEventCount;
  });

  const renderRankBadge = (rank: TriageRank) => {
    switch (rank) {
      case 'P1_CRITICAL':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-bold bg-rose-950 text-rose-300 border border-rose-800 shadow-sm shadow-rose-900/50 animate-pulse">
            <ShieldAlert className="w-3.5 h-3.5 mr-1 text-rose-400" /> P1 CRITICAL
          </span>
        );
      case 'P2_HIGH':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-bold bg-amber-950 text-amber-300 border border-amber-800">
            <AlertTriangle className="w-3.5 h-3.5 mr-1 text-amber-400" /> P2 HIGH
          </span>
        );
      case 'P3_MODERATE':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-semibold bg-yellow-950/60 text-yellow-300 border border-yellow-800/80">
            P3 MODERATE
          </span>
        );
      case 'P4_STABLE':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-medium bg-emerald-950/50 text-emerald-300 border border-emerald-900">
            <CheckCircle className="w-3.5 h-3.5 mr-1 text-emerald-400" /> P4 STABLE
          </span>
        );
    }
  };

  const renderIndicatorPill = (risk: IndicatorRisk, label: string) => {
    if (risk.status === 'ACTIVE_ALERT') {
      return (
        <div className="bg-rose-950/60 border border-rose-800/80 rounded-md p-2 text-left">
          <div className="flex items-center justify-between text-xs font-bold text-rose-400">
            <span>{label}</span>
            <span className="bg-rose-900 text-rose-200 px-1.5 py-0.5 rounded text-[10px]">ALERT</span>
          </div>
          <div className="text-sm font-semibold text-slate-100 mt-1">
            {risk.currentValue} {risk.unit}
            <span className="text-xs text-rose-300 font-normal ml-2">({risk.probability}% risk)</span>
          </div>
        </div>
      );
    } else if (risk.status === 'ELEVATED_RISK') {
      return (
        <div className="bg-amber-950/40 border border-amber-900/60 rounded-md p-2 text-left">
          <div className="flex items-center justify-between text-xs font-semibold text-amber-400">
            <span>{label}</span>
            <span className="bg-amber-900/80 text-amber-200 px-1.5 py-0.5 rounded text-[10px]">ELEVATED</span>
          </div>
          <div className="text-sm font-medium text-slate-200 mt-1">
            {risk.currentValue} {risk.unit}
            <span className="text-xs text-amber-300/80 font-normal ml-2">({risk.probability}%)</span>
          </div>
        </div>
      );
    }

    return (
      <div className="bg-slate-900/80 border border-slate-800 rounded-md p-2 text-left">
        <div className="text-[11px] font-medium text-slate-400">{label}</div>
        <div className="text-sm font-medium text-slate-300 mt-0.5">
          {risk.currentValue} {risk.unit}
          <span className="text-[11px] text-slate-500 font-normal ml-1.5">({risk.probability}%)</span>
        </div>
      </div>
    );
  };

  return (
    <div className="max-w-7xl mx-auto px-6 py-6">
      <div className="bg-slate-900 border border-slate-800 rounded-xl overflow-hidden shadow-2xl">
        <div className="px-6 py-4 border-b border-slate-800 flex items-center justify-between">
          <h2 className="text-base font-semibold text-slate-200 flex items-center">
            <Activity className="w-4 h-4 mr-2 text-sky-400" />
            Priority Triage Queue (Auto-Sorted)
          </h2>
          <span className="text-xs text-slate-400">
            Showing {sortedPatients.length} Active Patients
          </span>
        </div>

        <div className="overflow-x-auto">
          <table className="w-full text-left border-collapse">
            <thead>
              <tr className="border-b border-slate-800 bg-slate-950/60 text-xs font-semibold text-slate-400 uppercase tracking-wider">
                <th className="py-3.5 px-4">Priority Rank</th>
                <th className="py-3.5 px-4">Patient Profile</th>
                <th className="py-3.5 px-4">Clinical Metadata</th>
                <th className="py-3.5 px-4">Hypotension (MAP)</th>
                <th className="py-3.5 px-4">Hypoxia (SpO2)</th>
                <th className="py-3.5 px-4">Tachycardia (HR)</th>
                <th className="py-3.5 px-[16px] text-right">Action</th>
              </tr>
            </thead>
            <tbody className="divide-y divide-slate-800/60 text-sm">
              {sortedPatients.map((patient) => {
                const { profile, hypotension, hypoxia, tachycardia, triageRank } = patient;
                return (
                  <tr
                    key={profile.id}
                    onClick={() => onSelectPatient(patient)}
                    className="hover:bg-slate-800/50 transition-colors cursor-pointer group"
                  >
                    {/* Rank */}
                    <td className="py-4 px-4 whitespace-nowrap">
                      {renderRankBadge(triageRank)}
                    </td>

                    {/* Patient Profile */}
                    <td className="py-4 px-4 whitespace-nowrap">
                      <div className="flex items-center space-x-3">
                        <div className="p-2 bg-slate-800 rounded-full border border-slate-700 text-slate-300">
                          <User className="w-4 h-4" />
                        </div>
                        <div>
                          <div className="font-bold text-slate-100 group-hover:text-sky-400 transition-colors">
                            {profile.patientNumber}
                          </div>
                          <div className="text-xs text-slate-400 flex items-center space-x-2 mt-0.5">
                            <span>{profile.age} yrs, {profile.sex}</span>
                            <span>•</span>
                            <span className="text-slate-300 font-medium">{profile.bloodType}</span>
                          </div>
                        </div>
                      </div>
                    </td>

                    {/* Clinical Metadata */}
                    <td className="py-4 px-4 max-w-xs">
                      <div className="text-xs font-semibold text-slate-200 truncate">
                        {profile.primaryDiagnosis}
                      </div>
                      <div className="text-[11px] text-slate-400 truncate mt-0.5">
                        {profile.comorbidities.join(', ')}
                      </div>
                    </td>

                    {/* Indicators */}
                    <td className="py-4 px-4 min-w-[150px]">
                      {renderIndicatorPill(hypotension, 'HYPOTENSION')}
                    </td>
                    <td className="py-4 px-4 min-w-[150px]">
                      {renderIndicatorPill(hypoxia, 'HYPOXIA')}
                    </td>
                    <td className="py-4 px-4 min-w-[150px]">
                      {renderIndicatorPill(tachycardia, 'TACHYCARDIA')}
                    </td>

                    {/* Action */}
                    <td className="py-4 px-4 text-right whitespace-nowrap">
                      <button className="inline-flex items-center px-3 py-1.5 rounded-md text-xs font-medium bg-slate-800 text-slate-300 hover:bg-sky-900/60 hover:text-sky-300 border border-slate-700 transition-colors">
                        Inspect <ChevronRight className="w-3.5 h-3.5 ml-1" />
                      </button>
                    </td>
                  </tr>
                );
              })}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  );
};
```

- [ ] **Step 2: Commit Task 6**

```bash
git add triage_app/src/components/TriageTable.tsx
git commit -m "feat(triage_app): add Priority Triage Queue Table component"
```

---

### Task 7: Build Patient Detail Slide-Over Drawer Component

**Files:**
- Create: `triage_app/src/components/PatientDrawer.tsx`

**Interfaces:**
- Consumes: `patient: PatientState | null`, `onClose()`
- Produces: Slide-over clinical detail panel with full demographics and vitals history

- [ ] **Step 1: Write `triage_app/src/components/PatientDrawer.tsx`**

```tsx
import React from 'react';
import { X, User, Heart, Activity, Thermometer, Stethoscope, AlertCircle, FileText } from 'lucide-react';
import { PatientState } from '../types/patient';

interface PatientDrawerProps {
  patient: PatientState | null;
  onClose: () => void;
}

export const PatientDrawer: React.FC<PatientDrawerProps> = ({ patient, onClose }) => {
  if (!patient) return null;

  const { profile, currentFrame, hypotension, hypoxia, tachycardia, vitalsHistory } = patient;

  // Recent 20 frames for sparkline
  const recentHistory = vitalsHistory.slice(Math.max(0, vitalsHistory.length - 25));

  return (
    <div className="fixed inset-0 z-50 overflow-hidden bg-slate-950/70 backdrop-blur-sm flex justify-end">
      <div className="w-full max-w-xl bg-slate-900 border-l border-slate-800 shadow-2xl flex flex-col h-full overflow-y-auto animate-in slide-in-from-right duration-300">
        
        {/* Header */}
        <div className="p-6 border-b border-slate-800 flex items-center justify-between bg-slate-950">
          <div className="flex items-center space-x-3">
            <div className="p-2.5 bg-slate-800 rounded-lg border border-slate-700 text-sky-400">
              <User className="w-5 h-5" />
            </div>
            <div>
              <h2 className="text-lg font-bold text-slate-100">{profile.patientNumber}</h2>
              <p className="text-xs text-slate-400">{profile.age} yrs • {profile.sex} • Blood Group: <span className="text-slate-200 font-semibold">{profile.bloodType}</span></p>
            </div>
          </div>
          <button
            onClick={onClose}
            className="p-2 rounded-lg text-slate-400 hover:text-slate-100 hover:bg-slate-800 transition-colors"
          >
            <X className="w-5 h-5" />
          </button>
        </div>

        {/* Content */}
        <div className="p-6 space-y-6 flex-1">
          
          {/* Clinical Demographics Card */}
          <div className="bg-slate-950/60 border border-slate-800 rounded-xl p-4 space-y-3">
            <h3 className="text-xs font-bold text-slate-400 uppercase tracking-wider flex items-center">
              <FileText className="w-3.5 h-3.5 mr-1.5 text-sky-400" /> Comprehensive Clinical Profile
            </h3>

            <div className="grid grid-cols-2 gap-4 text-xs">
              <div>
                <span className="text-slate-400">Primary Diagnosis:</span>
                <p className="font-semibold text-slate-200 mt-0.5">{profile.primaryDiagnosis}</p>
              </div>

              <div>
                <span className="text-slate-400">Attending Physician:</span>
                <p className="font-semibold text-slate-200 mt-0.5">{profile.attendingPhysician}</p>
              </div>

              <div>
                <span className="text-slate-400">Height / Weight / BMI:</span>
                <p className="font-semibold text-slate-200 mt-0.5">{profile.heightCm} cm / {profile.weightKg} kg / BMI {profile.bmi}</p>
              </div>

              <div>
                <span className="text-slate-400">Known Allergies:</span>
                <p className="font-semibold text-rose-300 mt-0.5">{profile.allergies.join(', ')}</p>
              </div>
            </div>

            <div className="pt-2 border-t border-slate-800 text-xs">
              <span className="text-slate-400">Comorbidities:</span>
              <div className="flex flex-wrap gap-1.5 mt-1">
                {profile.comorbidities.map((c, i) => (
                  <span key={i} className="px-2 py-0.5 rounded bg-slate-800 text-slate-300 font-medium text-[11px] border border-slate-700">
                    {c}
                  </span>
                ))}
              </div>
            </div>
          </div>

          {/* Current Real-Time Vitals Grid */}
          <div>
            <h3 className="text-xs font-bold text-slate-400 uppercase tracking-wider mb-3 flex items-center">
              <Activity className="w-3.5 h-3.5 mr-1.5 text-emerald-400" /> Live Vital Sign Telemetry
            </h3>

            <div className="grid grid-cols-3 gap-3">
              <div className="bg-slate-950/80 border border-slate-800 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-400 font-medium">Heart Rate</div>
                <div className="text-xl font-bold text-slate-100 mt-1">{currentFrame.hr} <span className="text-xs font-normal text-slate-400">bpm</span></div>
              </div>

              <div className="bg-slate-950/80 border border-slate-800 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-400 font-medium">Blood Pressure (MBP)</div>
                <div className="text-xl font-bold text-slate-100 mt-1">{currentFrame.sbp}/{currentFrame.dbp} <span className="text-xs font-normal font-semibold text-sky-400">({currentFrame.mbp})</span></div>
              </div>

              <div className="bg-slate-950/80 border border-slate-800 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-400 font-medium">Oxygen Saturation</div>
                <div className="text-xl font-bold text-slate-100 mt-1">{currentFrame.spo2} <span className="text-xs font-normal text-slate-400">%</span></div>
              </div>
            </div>
          </div>

          {/* 3 Risk Indicators Breakdown */}
          <div>
            <h3 className="text-xs font-bold text-slate-400 uppercase tracking-wider mb-3 flex items-center">
              <Stethoscope className="w-3.5 h-3.5 mr-1.5 text-amber-400" /> Adverse Event Risk Predictions
            </h3>

            <div className="space-y-3">
              {/* Hypotension */}
              <div className="bg-slate-950/60 border border-slate-800 rounded-lg p-3.5">
                <div className="flex justify-between text-xs font-semibold">
                  <span className="text-slate-200">Future Hypotension (MAP &lt; 65 mmHg)</span>
                  <span className={hypotension.active ? 'text-rose-400 font-bold' : 'text-slate-400'}>
                    {hypotension.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-slate-800 h-2 rounded-full mt-2 overflow-hidden">
                  <div
                    className={`h-full transition-all duration-500 ${hypotension.active ? 'bg-rose-500' : (hypotension.probability >= 40 ? 'bg-amber-500' : 'bg-emerald-500')}`}
                    style={{ width: `${hypotension.probability}%` }}
                  />
                </div>
              </div>

              {/* Hypoxia */}
              <div className="bg-slate-950/60 border border-slate-800 rounded-lg p-3.5">
                <div className="flex justify-between text-xs font-semibold">
                  <span className="text-slate-200">Future Hypoxia (SpO2 &lt; 90%)</span>
                  <span className={hypoxia.active ? 'text-rose-400 font-bold' : 'text-slate-400'}>
                    {hypoxia.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-slate-800 h-2 rounded-full mt-2 overflow-hidden">
                  <div
                    className={`h-full transition-all duration-500 ${hypoxia.active ? 'bg-rose-500' : (hypoxia.probability >= 40 ? 'bg-amber-500' : 'bg-emerald-500')}`}
                    style={{ width: `${hypoxia.probability}%` }}
                  />
                </div>
              </div>

              {/* Tachycardia */}
              <div className="bg-slate-950/60 border border-slate-800 rounded-lg p-3.5">
                <div className="flex justify-between text-xs font-semibold">
                  <span className="text-slate-200">Future Tachycardia (HR &gt; 100 bpm)</span>
                  <span className={tachycardia.active ? 'text-rose-400 font-bold' : 'text-slate-400'}>
                    {tachycardia.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-slate-800 h-2 rounded-full mt-2 overflow-hidden">
                  <div
                    className={`h-full transition-all duration-500 ${tachycardia.active ? 'bg-rose-500' : (tachycardia.probability >= 40 ? 'bg-amber-500' : 'bg-emerald-500')}`}
                    style={{ width: `${tachycardia.probability}%` }}
                  />
                </div>
              </div>
            </div>
          </div>

        </div>
      </div>
    </div>
  );
};
```

- [ ] **Step 2: Commit Task 7**

```bash
git add triage_app/src/components/PatientDrawer.tsx
git commit -m "feat(triage_app): add PatientDrawer slide-over component"
```

---

### Task 8: Assemble Main Dashboard Page & Live Stride Loop (`src/app/page.tsx`)

**Files:**
- Create: `triage_app/src/app/page.tsx`

**Interfaces:**
- Consumes: Header, TriageTable, PatientDrawer, `/api/patients`
- Produces: Live automatic 5-second stride monitoring app

- [ ] **Step 1: Write `triage_app/src/app/page.tsx`**

```tsx
'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';

export default function Home() {
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatient, setSelectedPatient] = useState<PatientState | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);

  // 1. Fetch patient data from API on mount
  useEffect(() => {
    async function loadPatients() {
      try {
        const res = await fetch('/api/patients');
        const data = await res.json();
        if (data.error) {
          setError(data.error);
        } else if (data.patients) {
          setPatients(data.patients);
        }
      } catch (err: any) {
        setError(err.message || 'Failed to load patient telemetry');
      } finally {
        setLoading(false);
      }
    }
    loadPatients();
  }, []);

  // 2. Automatic Continuous 5-Second Stride Loop
  useEffect(() => {
    if (patients.length === 0) return;

    const interval = setInterval(() => {
      setStrideCount(prev => prev + 1);

      setPatients(prevPatients =>
        prevPatients.map(patient => {
          const nextIndex = (patient.currentFrameIndex + 1) % patient.vitalsHistory.length;
          const currentFrame = patient.vitalsHistory[nextIndex];
          const riskEval = evaluatePatientRisk(patient.vitalsHistory, nextIndex);

          const updated: PatientState = {
            ...patient,
            currentFrameIndex: nextIndex,
            currentFrame,
            hypotension: riskEval.hypotension,
            hypoxia: riskEval.hypoxia,
            tachycardia: riskEval.tachycardia,
            triageRank: riskEval.triageRank,
            activeEventCount: riskEval.activeEventCount,
          };

          if (selectedPatient && selectedPatient.profile.id === patient.profile.id) {
            setSelectedPatient(updated);
          }

          return updated;
        })
      );
    }, 5000); // 5-second stride update

    return () => clearInterval(interval);
  }, [patients.length, selectedPatient]);

  if (loading) {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center text-slate-300">
        <div className="w-10 h-10 border-4 border-sky-500 border-t-transparent rounded-full animate-spin mb-4" />
        <p className="text-sm font-medium text-slate-400">Loading Patient Telemetry &amp; Initializing Triage Engine...</p>
      </div>
    );
  }

  if (error) {
    return (
      <div className="min-h-screen bg-slate-950 flex items-center justify-center p-6">
        <div className="bg-rose-950/60 border border-rose-900 text-rose-200 rounded-xl p-6 max-w-md text-center">
          <h2 className="text-lg font-bold mb-2">Failed to Load Telemetry</h2>
          <p className="text-xs text-rose-300/80 mb-4">{error}</p>
        </div>
      </div>
    );
  }

  return (
    <main className="min-h-screen bg-slate-950 flex flex-col">
      <Header patients={patients} strideCount={strideCount} />
      <div className="flex-1">
        <TriageTable patients={patients} onSelectPatient={setSelectedPatient} />
      </div>
      <PatientDrawer patient={selectedPatient} onClose={() => setSelectedPatient(null)} />
    </main>
  );
}
```

- [ ] **Step 2: Test production build of Next.js app**

Run: `cd /home/logan78/Desktop/SiLabs/triage_app && npm run build`  
Expected: `Compiled successfully` with zero errors.

- [ ] **Step 3: Commit Task 8**

```bash
git add triage_app/src/app/page.tsx
git commit -m "feat(triage_app): complete live 5s stride triage dashboard page"
```
