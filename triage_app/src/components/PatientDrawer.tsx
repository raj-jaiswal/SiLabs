'use client';

import React from 'react';
import { PatientState } from '../types/patient';
import { X, Activity, User, Stethoscope, AlertTriangle, ShieldAlert } from 'lucide-react';

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
          <span className="px-2.5 py-1 rounded text-xs font-mono font-bold bg-red-50 text-red-700 border border-red-300">
            P1 CRITICAL
          </span>
        );
      case 'P2_HIGH':
        return (
          <span className="px-2.5 py-1 rounded text-xs font-mono font-bold bg-amber-50 text-amber-700 border border-amber-300">
            P2 HIGH
          </span>
        );
      case 'P3_MODERATE':
        return (
          <span className="px-2.5 py-1 rounded text-xs font-mono font-bold bg-yellow-50 text-yellow-800 border border-yellow-300">
            P3 MODERATE
          </span>
        );
      case 'P4_STABLE':
        return (
          <span className="px-2.5 py-1 rounded text-xs font-mono font-bold bg-emerald-50 text-emerald-700 border border-emerald-300">
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
        className="fixed inset-0 z-40 bg-slate-900/40 backdrop-blur-xs transition-opacity"
      />

      {/* Drawer */}
      <div className="fixed inset-y-0 right-0 z-50 w-full max-w-xl bg-white border-l border-slate-200 shadow-2xl flex flex-col font-sans select-none">
        
        {/* Header */}
        <div className="p-6 border-b border-slate-200 flex items-start justify-between bg-slate-50">
          <div>
            <div className="flex items-center space-x-3">
              <h2 className="text-xl font-bold text-slate-900">{profile.patientNumber}</h2>
              {renderRankBadge(triageRank)}
              {isEsp32 && profile.isStale ? (
                <span className="px-2 py-0.5 rounded text-[10px] font-mono font-bold bg-amber-100 text-amber-800 border border-amber-300 flex items-center">
                  <AlertTriangle className="w-3 h-3 mr-1 text-amber-600" />
                  NO DATA (&gt;20s)
                </span>
              ) : isEsp32 ? (
                <span className="px-2 py-0.5 rounded text-[10px] font-mono font-bold bg-emerald-100 text-emerald-800 border border-emerald-300 flex items-center">
                  <span className="w-1.5 h-1.5 rounded-full bg-emerald-600 mr-1" />
                  ESP32 LIVE
                </span>
              ) : null}
            </div>
            <p className="text-xs text-slate-600 mt-1">
              Patient ID: <span className="font-mono text-slate-900 font-semibold">{profile.id}</span>
            </p>
          </div>

          <button
            onClick={onClose}
            className="p-1.5 rounded-lg border border-slate-300 bg-white text-slate-600 hover:text-slate-900 transition-colors"
          >
            <X className="w-5 h-5" />
          </button>
        </div>

        {/* Content Body */}
        <div className="flex-1 overflow-y-auto p-6 space-y-6 text-sm">
          
          {/* Clinical Profile Card */}
          <div className="bg-slate-50 border border-slate-200 rounded-xl p-4 space-y-3">
            <h3 className="text-xs font-bold text-slate-700 uppercase tracking-wider flex items-center">
              <User className="w-4 h-4 mr-1.5 text-slate-800" /> Patient Demographics &amp; Profile
            </h3>

            <div className="grid grid-cols-2 gap-4 text-xs">
              <div>
                <span className="text-slate-500">Age / Sex:</span>
                <div className="font-semibold text-slate-900">{profile.age} yrs, {profile.sex}</div>
              </div>
              <div>
                <span className="text-slate-500">Blood Type:</span>
                <div className="font-semibold text-slate-900">{profile.bloodType}</div>
              </div>
              <div>
                <span className="text-slate-500">Height / Weight / BMI:</span>
                <div className="font-semibold text-slate-900">{profile.heightCm} cm / {profile.weightKg} kg ({profile.bmi} BMI)</div>
              </div>
              <div>
                <span className="text-slate-500">Attending Physician:</span>
                <div className="font-semibold text-slate-900">{profile.attendingPhysician}</div>
              </div>
            </div>

            <div className="pt-2 border-t border-slate-200 space-y-1.5 text-xs">
              <div>
                <span className="text-slate-500 font-medium">Primary Diagnosis:</span>{' '}
                <span className="font-semibold text-slate-900">{profile.primaryDiagnosis}</span>
              </div>
              <div>
                <span className="text-slate-500 font-medium">Comorbidities:</span>{' '}
                <span className="text-slate-800">{profile.comorbidities.join(', ')}</span>
              </div>
              <div>
                <span className="text-slate-500 font-medium">Known Allergies:</span>{' '}
                <span className="text-slate-800">{profile.allergies.join(', ')}</span>
              </div>
            </div>
          </div>

          {/* Current Real-Time Vitals Grid */}
          <div>
            <div className="flex items-center justify-between mb-3">
              <h3 className="text-xs font-bold text-slate-700 uppercase tracking-wider flex items-center">
                <Activity className="w-4 h-4 mr-1.5 text-emerald-700" /> Observed Vital Signs (NOW)
              </h3>
              <span className="text-[11px] font-mono text-slate-800 bg-slate-100 px-2 py-0.5 rounded border border-slate-300">
                T + {currentFrame.timestampSec} SECONDS
              </span>
            </div>

            <div className="grid grid-cols-3 gap-3 font-mono tabular-nums">
              <div className="bg-slate-50 border border-slate-200 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-500 font-medium">Heart Rate</div>
                <div className="text-lg font-bold text-slate-900 mt-1">
                  {currentFrame.hr} <span className="text-xs font-normal text-slate-600">bpm</span>
                </div>
              </div>

              <div className="bg-slate-50 border border-slate-200 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-500 font-medium">BP (MAP)</div>
                <div className="text-lg font-bold text-slate-900 mt-1">
                  {currentFrame.sbp}/{currentFrame.dbp}{' '}
                  <span className="text-xs font-bold text-slate-700">({currentFrame.mbp})</span>
                </div>
              </div>

              <div className="bg-slate-50 border border-slate-200 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-500 font-medium">SpO2</div>
                <div className="text-lg font-bold text-slate-900 mt-1">
                  {currentFrame.spo2} <span className="text-xs font-normal text-slate-600">%</span>
                </div>
              </div>
            </div>
          </div>

          {/* 3 Risk Indicators Breakdown */}
          <div>
            <h3 className="text-xs font-bold text-slate-700 uppercase tracking-wider mb-3 flex items-center">
              <Stethoscope className="w-4 h-4 mr-1.5 text-amber-700" /> Adverse Event Risk Predictions (AI Horizon)
            </h3>

            <div className="space-y-3 font-mono tabular-nums">
              {/* Hypotension */}
              <div className="bg-slate-50 border border-slate-200 rounded-lg p-3.5">
                <div className="flex justify-between text-xs font-semibold">
                  <span className="text-slate-900">Future Hypotension (MAP &lt; 65 mmHg)</span>
                  <span className={hypotension.active ? 'text-red-700 font-bold' : 'text-slate-700'}>
                    {hypotension.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-slate-200 h-2 rounded-full mt-2 overflow-hidden">
                  <div
                    className={`h-full transition-all duration-300 ${
                      hypotension.active
                        ? 'bg-red-600'
                        : hypotension.probability >= 40
                        ? 'bg-amber-500'
                        : 'bg-emerald-500'
                    }`}
                    style={{ width: `${hypotension.probability}%` }}
                  />
                </div>
              </div>

              {/* Hypoxia */}
              <div className="bg-slate-50 border border-slate-200 rounded-lg p-3.5">
                <div className="flex justify-between text-xs font-semibold">
                  <span className="text-slate-900">Future Hypoxia (SpO2 &lt; 90%)</span>
                  <span className={hypoxia.active ? 'text-red-700 font-bold' : 'text-slate-700'}>
                    {hypoxia.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-slate-200 h-2 rounded-full mt-2 overflow-hidden">
                  <div
                    className={`h-full transition-all duration-300 ${
                      hypoxia.active
                        ? 'bg-red-600'
                        : hypoxia.probability >= 40
                        ? 'bg-amber-500'
                        : 'bg-emerald-500'
                    }`}
                    style={{ width: `${hypoxia.probability}%` }}
                  />
                </div>
              </div>

              {/* Tachycardia */}
              <div className="bg-slate-50 border border-slate-200 rounded-lg p-3.5">
                <div className="flex justify-between text-xs font-semibold">
                  <span className="text-slate-900">Future Tachycardia (HR &gt; 100 bpm)</span>
                  <span className={tachycardia.active ? 'text-red-700 font-bold' : 'text-slate-700'}>
                    {tachycardia.probability}% Risk
                  </span>
                </div>
                <div className="w-full bg-slate-200 h-2 rounded-full mt-2 overflow-hidden">
                  <div
                    className={`h-full transition-all duration-300 ${
                      tachycardia.active
                        ? 'bg-red-600'
                        : tachycardia.probability >= 40
                        ? 'bg-amber-500'
                        : 'bg-emerald-500'
                    }`}
                    style={{ width: `${tachycardia.probability}%` }}
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
