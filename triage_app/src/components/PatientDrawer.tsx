import React from 'react';
import { X, User, Activity, Stethoscope, FileText } from 'lucide-react';
import { PatientState } from '../types/patient';

interface PatientDrawerProps {
  patient: PatientState | null;
  onClose: () => void;
}

export const PatientDrawer: React.FC<PatientDrawerProps> = ({ patient, onClose }) => {
  if (!patient) return null;

  const { profile, currentFrame, hypotension, hypoxia, tachycardia, vitalsHistory } = patient;

  return (
    <div
      className="fixed inset-0 z-50 overflow-hidden bg-slate-950/70 backdrop-blur-sm flex justify-end"
      onClick={onClose}
    >
      <div
        className="w-full max-w-xl bg-slate-900 border-l border-slate-800 shadow-2xl flex flex-col h-full overflow-y-auto animate-in slide-in-from-right duration-300"
        onClick={(e) => e.stopPropagation()}
      >
        {/* Header */}
        <div className="p-6 border-b border-slate-800 flex items-center justify-between bg-slate-950">
          <div className="flex items-center space-x-3">
            <div className="p-2.5 bg-slate-800 rounded-lg border border-slate-700 text-sky-400">
              <User className="w-5 h-5" />
            </div>
            <div>
              <div className="flex items-center space-x-2">
                <h2 className="text-lg font-bold text-slate-100">{profile.patientNumber}</h2>
                {(profile.isEsp32Live || profile.id === 'PATIENT-000') && (
                  <span className="px-2 py-0.5 rounded text-[10px] font-black bg-slate-700 text-slate-200 border border-slate-500 shadow-sm font-mono flex items-center">
                    <span className="w-1.5 h-1.5 rounded-full bg-emerald-400 animate-ping mr-1" />
                    ESP32 LIVE STREAM
                  </span>
                )}
              </div>
              <p className="text-xs text-slate-400">
                {profile.age} yrs • {profile.sex} • Blood Group: <span className="text-slate-200 font-semibold">{profile.bloodType}</span>
              </p>
            </div>
          </div>
          <button
            onClick={onClose}
            aria-label="Close drawer"
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
                <p className="font-semibold text-slate-200 mt-0.5">
                  {profile.heightCm} cm / {profile.weightKg} kg / BMI {profile.bmi}
                </p>
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
                  <span
                    key={i}
                    className="px-2 py-0.5 rounded bg-slate-800 text-slate-300 font-medium text-[11px] border border-slate-700"
                  >
                    {c}
                  </span>
                ))}
              </div>
            </div>
          </div>

          {/* Current Real-Time Vitals Grid */}
          <div>
            <div className="flex items-center justify-between mb-3">
              <h3 className="text-xs font-bold text-slate-400 uppercase tracking-wider flex items-center">
                <Activity className="w-3.5 h-3.5 mr-1.5 text-emerald-400" /> Live Vital Sign Telemetry
              </h3>
              <span className="text-[11px] font-mono text-emerald-400 bg-emerald-950/80 px-2 py-0.5 rounded border border-emerald-800">
                T + {currentFrame.timestampSec} SECONDS
              </span>
            </div>

            <div className="grid grid-cols-3 gap-3">
              <div className="bg-slate-950/80 border border-slate-800 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-400 font-medium">Heart Rate</div>
                <div className="text-xl font-bold text-slate-100 mt-1">
                  {currentFrame.hr} <span className="text-xs font-normal text-slate-400">bpm</span>
                </div>
              </div>

              <div className="bg-slate-950/80 border border-slate-800 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-400 font-medium">Blood Pressure (MBP)</div>
                <div className="text-xl font-bold text-slate-100 mt-1">
                  {currentFrame.sbp}/{currentFrame.dbp}{' '}
                  <span className="text-xs font-semibold text-sky-400">({currentFrame.mbp})</span>
                </div>
              </div>

              <div className="bg-slate-950/80 border border-slate-800 rounded-lg p-3 text-center">
                <div className="text-[11px] text-slate-400 font-medium">Oxygen Saturation</div>
                <div className="text-xl font-bold text-slate-100 mt-1">
                  {currentFrame.spo2} <span className="text-xs font-normal text-slate-400">%</span>
                </div>
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
                    className={`h-full transition-all duration-500 ${
                      hypotension.active
                        ? 'bg-rose-500'
                        : hypotension.probability >= 40
                        ? 'bg-amber-500'
                        : 'bg-emerald-500'
                    }`}
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
                    className={`h-full transition-all duration-500 ${
                      hypoxia.active
                        ? 'bg-rose-500'
                        : hypoxia.probability >= 40
                        ? 'bg-amber-500'
                        : 'bg-emerald-500'
                    }`}
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
                    className={`h-full transition-all duration-500 ${
                      tachycardia.active
                        ? 'bg-rose-500'
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
    </div>
  );
};
