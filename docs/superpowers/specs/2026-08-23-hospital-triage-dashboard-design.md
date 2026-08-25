# Hospital Triage & Adverse Event Monitoring Dashboard Design Specification

> **Date:** 2026-08-23  
> **Project:** SiLabs Hospital Triage & Vital Sign Monitoring System  
> **Target App:** Next.js 14 (React, TypeScript, Tailwind CSS)  
> **Data Source:** `/home/logan78/Desktop/SiLabs/process_labeled_data` (Patient 1 Hz CSVs)  

---

## 1. Executive Summary

This design specification details a modern, minimalist hospital triage dashboard and multi-patient adverse event monitoring system. The application reads real intraoperative vital sign telemetry from `process_labeled_data` patient CSV files, streams live 1 Hz vitals in **5-second strides**, and evaluates 3 primary clinical risk indicators:
1. **Hypotension** ($\text{MBP} < 65\text{ mmHg}$ or predicted drop within 10-60 min)
2. **Hypoxia** ($\text{SpO}_2 < 90\%$ or predicted drop within 10-60 min)
3. **Tachycardia** ($\text{HR} > 100\text{ bpm}$ or predicted spike within 10-60 min)

The system dynamically ranks patients in a **Priority Triage Queue** based on active adverse events and risk probabilities, rendering a monochromatic, clinical slate/zinc UI designed for high-stress hospital ICUs and operating rooms.

---

## 2. Patient Demographics & Clinical Profile Schema

Each patient is assigned a comprehensive clinical profile:
- **Identifier**: Patient ID (e.g. `PATIENT-1001`, `PATIENT-1004`, `PATIENT-1018`)
- **Demographics**: Age (24–88), Sex (`Male` / `Female`), Blood Type (`A+`, `O-`, `B+`, `AB+`, `A-`, etc.), Weight (`kg`), Height (`cm`), BMI
- **Clinical Profile**:
  - Primary Diagnosis & Comorbidities (e.g., *Post-CABG*, *Severe Sepsis*, *COPD*, *Hypertensive Crisis*, *Type 2 Diabetes*, *Coronary Artery Disease*)
  - Known Allergies (e.g., *Penicillin*, *Latex*, *Sulfa*, *None*)
  - Assigned Attending Physician (e.g., *Dr. Sarah Chen, MD*, *Dr. Marcus Vance, MD*)

*(Note: Bed Number and Ward Unit are explicitly excluded as requested).*

---

## 3. Real-Time 5-Second Stride Simulation & Feature Extraction

1. **Automatic Continuous Simulation**:
   - Updates stride-by-stride every 5 seconds without manual playback controls.
   - Computes rolling 600-second window statistics (Mean, Std, Min, Max, Slope) across 19 vital sign channels.
2. **Clinical Indicator Rules**:
   - **Hypotension**: Active if $\text{MBP} < 65\text{ mmHg}$ or Risk Prob $\ge 40\%$.
   - **Hypoxia**: Active if $\text{SpO}_2 < 90\%$ or Risk Prob $\ge 40\%$.
   - **Tachycardia**: Active if $\text{HR} > 100\text{ bpm}$ or Risk Prob $\ge 40\%$.

---

## 4. Priority Triage Ranking Algorithm

Patients are dynamically re-ordered in the triage table at every 5-second stride:

| Priority Rank | Category | Trigger Condition | Visual Styling |
| :--- | :--- | :--- | :--- |
| **Rank 1 (P1)** | **CRITICAL** | $\ge 2$ Simultaneous Active Adverse Events (e.g., Hypotension + Hypoxia) | Red Badge (`#EF4444`) with subtle pulse animation |
| **Rank 2 (P2)** | **HIGH** | 1 Active Adverse Event ($\text{MBP} < 65$, $\text{SpO}_2 < 90$, or $\text{HR} > 100$) | Amber/Orange Badge (`#F59E0B`) |
| **Rank 3 (P3)** | **MODERATE** | No active event, but 1+ indicator has elevated risk percentage ($\ge 40\%$) | Yellow/Zinc Badge (`#EAB308`) |
| **Rank 4 (P4)** | **STABLE** | All vitals within normal range, low risk across all 3 indicators | Muted Emerald Badge (`#10B981`) |

---

## 5. UI Architecture & Monochromatic Design System

- **Framework**: Next.js 14 App Router, React 18, TypeScript, Tailwind CSS, Lucide Icons.
- **Color Palette**: Clinical Monochromatic Slate/Zinc theme (`slate-900` dark header, `slate-50` background, high-contrast dark text, subtle glowing status pills).
- **Layout Structure**:
  - **Header Bar**: Title (`CLINICAL TRIAGE MONITOR | SILABS ICU`), pulsing `LIVE 5s STRIDE` status badge, patient count breakdown (Critical, High, Moderate, Stable).
  - **Main Triage Table**: Sorted live by Priority Rank. Columns for Rank, Patient Profile, Clinical Metadata, Hypotension Status, Hypoxia Status, Tachycardia Status, and `Inspect Vitals` Action.
  - **Patient Detail Slide-Over Panel**: Slide-over drawer on patient click with full clinical history, allergies, doctor, and live vital sparklines.

---

## 6. Verification & Test Criteria

1. Verify Next.js app builds cleanly with zero TypeScript or lint errors.
2. Verify patient CSV files are parsed correctly from `process_labeled_data`.
3. Verify live 5-second stride updates continuously re-rank patients in real time.
4. Verify monochromatic hospital UI renders crisply across screen sizes.
