'use client';

import React from 'react';
import { PatientState } from '../types/patient';

interface PatientDrawerProps {
  patient: PatientState | null;
  onClose: () => void;
}

export const PatientDrawer: React.FC<PatientDrawerProps> = ({ patient, onClose }) => {
  if (!patient) return null;

  const { profile, currentFrame, hypotension, hypoxia, tachycardia, triageRank } = patient;
  const isEsp32 = profile.isEsp32Live || profile.id === 'PATIENT-000';

  const renderRankBadge = (rank: typeof triageRank) => {
    switch (rank) {
      case 'P1_CRITICAL':
        return (
          <span className="px-3 py-1.5 text-label-mono font-label-mono bg-error-container/20 text-error border border-error/20 rounded font-bold tracking-widest">
            P1 CRITICAL
          </span>
        );
      case 'P2_HIGH':
        return (
          <span className="px-3 py-1.5 text-label-mono font-label-mono bg-tertiary-container/10 text-tertiary-container border border-tertiary-container/30 rounded font-bold tracking-widest">
            P2 HIGH
          </span>
        );
      case 'P3_MODERATE':
        return (
          <span className="px-3 py-1.5 text-label-mono font-label-mono bg-secondary/10 text-secondary border border-secondary/30 rounded font-bold tracking-widest">
            P3 MODERATE
          </span>
        );
      case 'P4_STABLE':
        return (
          <span className="px-3 py-1.5 text-label-mono font-label-mono bg-primary-container/10 text-primary-container border border-primary-container/30 rounded font-bold tracking-widest">
            P4 STABLE
          </span>
        );
    }
  };

  return (
    <>
      {/* Backdrop */}
      <div
        onClick={onClose}
        className="fixed inset-0 z-40 bg-surface-container-highest/80 backdrop-blur-sm transition-opacity"
      />

      {/* Drawer */}
      <div className="fixed inset-y-0 right-0 z-50 w-full max-w-4xl bg-surface-container-lowest border-l border-outline-variant shadow-xl flex flex-col font-body-md select-none text-on-surface">

        {/* Header */}
        <div className="p-6 md:p-8 border-b border-outline-variant flex items-start justify-between bg-surface-container-low">
          <div>
            <div className="flex flex-col md:flex-row md:items-center gap-2 md:gap-4">
              <h2 className="text-headline-lg font-headline-lg text-on-surface font-black tracking-tight">{profile.patientNumber}</h2>
              {renderRankBadge(triageRank)}
              {isEsp32 && profile.isStale ? (
                <span className="px-3 py-1.5 text-label-mono font-label-mono font-bold bg-tertiary-container/20 text-tertiary-container border border-tertiary-container/50 flex items-center rounded">
                  <span className="material-symbols-outlined text-[16px] mr-1.5">warning</span>
                  NO DATA (&gt;20s)
                </span>
              ) : isEsp32 ? (
                <span className="px-3 py-1.5 text-label-mono font-label-mono font-bold bg-primary-container/20 text-primary border border-primary/30 flex items-center rounded">
                  <span className="w-2 h-2 rounded-full bg-primary mr-2 animate-pulse" />
                  Edge Node LIVE
                </span>
              ) : null}
            </div>
            <p className="text-body-md text-on-surface-variant mt-2 font-label-mono">
              System ID: <span className="text-on-surface font-bold">{profile.id}</span>
            </p>
          </div>

          <button
            onClick={onClose}
            className="p-2.5 bg-surface hover:bg-surface-container-high rounded-full border border-outline-variant text-on-surface-variant hover:text-primary transition-colors"
          >
            <span className="material-symbols-outlined text-[24px]">close</span>
          </button>
        </div>

        {/* Content Body */}
        <div className="flex-1 overflow-y-auto p-4 md:p-8 space-y-6 md:space-y-8 text-body-md">

          {/* Clinical Profile Card */}
          <div className="bg-surface-container border border-outline-variant p-6 rounded-xl space-y-6 shadow-sm">
            <h3 className="text-[14px] font-bold text-on-surface uppercase tracking-wider flex items-center font-label-mono">
              <span className="material-symbols-outlined text-[20px] mr-2">person</span> Patient Demographics &amp; Profile
            </h3>

            <div className="grid grid-cols-2 md:grid-cols-4 gap-6 text-[15px]">
              <div>
                <span className="text-on-surface-variant text-[13px] block mb-1">Age / Sex</span>
                <div className="font-bold text-on-surface text-[16px]">{profile.age} yrs, {profile.sex}</div>
              </div>
              <div>
                <span className="text-on-surface-variant text-[13px] block mb-1">Blood Type</span>
                <div className="font-bold text-on-surface text-[16px] text-primary">{profile.bloodType}</div>
              </div>
              <div>
                <span className="text-on-surface-variant text-[13px] block mb-1">Height / Weight / BMI</span>
                <div className="font-bold text-on-surface text-[16px]">{profile.heightCm} cm / {profile.weightKg} kg ({profile.bmi})</div>
              </div>
              <div>
                <span className="text-on-surface-variant text-[13px] block mb-1">Attending Physician</span>
                <div className="font-bold text-on-surface text-[16px]">{profile.attendingPhysician}</div>
              </div>
            </div>

            <div className="pt-4 border-t border-outline-variant/50 space-y-3 text-[15px]">
              <div>
                <span className="text-on-surface-variant font-medium mr-2">Primary Diagnosis:</span>
                <span className="font-bold text-on-surface text-[16px]">{profile.primaryDiagnosis}</span>
              </div>
              <div>
                <span className="text-on-surface-variant font-medium mr-2">Comorbidities:</span>
                <span className="text-on-surface">{profile.comorbidities.join(', ')}</span>
              </div>
              <div>
                <span className="text-on-surface-variant font-medium mr-2">Known Allergies:</span>
                <span className="text-error font-bold">{profile.allergies.join(', ') || 'None'}</span>
              </div>
            </div>
          </div>

          {/* Current Real-Time Vitals Grid */}
          <div>
            <div className="flex items-center justify-between mb-4">
              <h3 className="text-[14px] font-bold text-on-surface uppercase tracking-wider flex items-center font-label-mono">
                <span className="material-symbols-outlined text-[20px] mr-2 text-primary">vital_signs</span> Observed Vital Signs (NOW)
              </h3>
              <span className="text-[12px] font-mono text-on-surface bg-surface-container-high px-3 py-1 border border-outline-variant font-bold rounded-lg tracking-wider">
                T + {currentFrame.timestampSec} SECONDS
              </span>
            </div>

            <div className="grid grid-cols-1 md:grid-cols-3 gap-4 md:gap-6 font-mono tabular-nums">
              <div className="bg-surface-container border border-outline-variant p-6 text-center rounded-xl shadow-sm">
                <div className="text-[13px] text-on-surface-variant font-bold uppercase tracking-wider mb-2">Heart Rate</div>
                <div className="text-[48px] font-display-vitals text-on-surface leading-none">
                  {currentFrame.hr} <span className="text-[16px] font-normal text-on-surface-variant font-body-md lowercase">bpm</span>
                </div>
              </div>

              <div className="bg-surface-container border border-outline-variant p-6 text-center rounded-xl shadow-sm">
                <div className="text-[13px] text-on-surface-variant font-bold uppercase tracking-wider mb-2">BP (MAP)</div>
                <div className="text-[48px] font-display-vitals text-on-surface leading-none">
                  {currentFrame.sbp}/{currentFrame.dbp}{' '}
                </div>
                <div className="text-[18px] font-bold text-on-surface-variant mt-2 font-label-mono">
                  MAP: {currentFrame.mbp}
                </div>
              </div>

              <div className="bg-surface-container border border-outline-variant p-6 text-center rounded-xl shadow-sm">
                <div className="text-[13px] text-on-surface-variant font-bold uppercase tracking-wider mb-2">SpO2</div>
                <div className="text-[48px] font-display-vitals text-on-surface leading-none">
                  {currentFrame.spo2} <span className="text-[16px] font-normal text-on-surface-variant font-body-md">%</span>
                </div>
              </div>
            </div>
          </div>

          {/* 3 Risk Indicators Breakdown */}
          <div>
            <h3 className="text-[14px] font-bold text-on-surface uppercase tracking-wider mb-4 flex items-center font-label-mono">
              <span className="material-symbols-outlined text-[20px] mr-2 text-tertiary-container">analytics</span> Adverse Event Risk Predictions (AI Horizon)
            </h3>

            <div className="space-y-4 font-mono tabular-nums">
              {/* Hypotension */}
              <div className="bg-surface-container border border-outline-variant p-4 md:p-6 rounded-xl shadow-sm">
                <div className="flex flex-col md:flex-row md:justify-between md:items-center text-[15px] font-bold mb-3 gap-1 md:gap-0">
                  <span className="text-on-surface font-label-mono uppercase">Future Hypotension (MAP &lt; 65 mmHg)</span>
                  <span className={`${hypotension.active ? 'text-error' : 'text-on-surface'} text-[18px]`}>
                    {hypotension.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-surface-container-high h-3 overflow-hidden rounded-full">
                  <div
                    className={`h-full rounded-full transition-all duration-300 ${hypotension.active
                      ? 'bg-error'
                      : hypotension.probability >= 40
                        ? 'bg-tertiary-container'
                        : 'bg-primary-container'
                      }`}
                    style={{ width: `${Math.max(5, hypotension.probability)}%` }}
                  />
                </div>
              </div>

              {/* Hypoxia */}
              <div className="bg-surface-container border border-outline-variant p-4 md:p-6 rounded-xl shadow-sm">
                <div className="flex flex-col md:flex-row md:justify-between md:items-center text-[15px] font-bold mb-3 gap-1 md:gap-0">
                  <span className="text-on-surface font-label-mono uppercase">Future Hypoxia (SpO2 &lt; 90%)</span>
                  <span className={`${hypoxia.active ? 'text-error' : 'text-on-surface'} text-[18px]`}>
                    {hypoxia.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-surface-container-high h-3 overflow-hidden rounded-full">
                  <div
                    className={`h-full rounded-full transition-all duration-300 ${hypoxia.active
                      ? 'bg-error'
                      : hypoxia.probability >= 40
                        ? 'bg-tertiary-container'
                        : 'bg-primary-container'
                      }`}
                    style={{ width: `${Math.max(5, hypoxia.probability)}%` }}
                  />
                </div>
              </div>

              {/* Tachycardia */}
              <div className="bg-surface-container border border-outline-variant p-4 md:p-6 rounded-xl shadow-sm">
                <div className="flex flex-col md:flex-row md:justify-between md:items-center text-[15px] font-bold mb-3 gap-1 md:gap-0">
                  <span className="text-on-surface font-label-mono uppercase">Future Tachycardia (HR &gt; 100 bpm)</span>
                  <span className={`${tachycardia.active ? 'text-error' : 'text-on-surface'} text-[18px]`}>
                    {tachycardia.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-surface-container-high h-3 overflow-hidden rounded-full">
                  <div
                    className={`h-full rounded-full transition-all duration-300 ${tachycardia.active
                      ? 'bg-error'
                      : tachycardia.probability >= 40
                        ? 'bg-tertiary-container'
                        : 'bg-primary-container'
                      }`}
                    style={{ width: `${Math.max(5, tachycardia.probability)}%` }}
                  />
                </div>
              </div>
            </div>
          </div>

        </div>
      </div>
    </>
  );
};
