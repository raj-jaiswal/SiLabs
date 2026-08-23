import React from 'react';
import { ShieldAlert, AlertCircle, ChevronRight, X, HeartPulse, Activity } from 'lucide-react';
import { PatientState } from '../types/patient';

interface CriticalAlertBarProps {
  criticalPatients: PatientState[];
  onSelectPatient: (patientId: string) => void;
  onDismiss?: () => void;
}

export const CriticalAlertBar: React.FC<CriticalAlertBarProps> = ({
  criticalPatients,
  onSelectPatient,
  onDismiss,
}) => {
  if (!criticalPatients || criticalPatients.length === 0) return null;

  return (
    <div className="bg-rose-950/95 border-y border-rose-700/80 px-6 py-3.5 text-rose-100 shadow-xl shadow-rose-950/50 transition-all duration-300 animate-in slide-in-from-top">
      <div className="max-w-7xl mx-auto flex flex-col md:flex-row md:items-center md:justify-between gap-3">
        
        {/* Left: Alert Icon & Summary */}
        <div className="flex items-start md:items-center space-x-3">
          <div className="p-2 bg-rose-900/90 rounded-lg border border-rose-600 text-rose-200 flex-shrink-0 animate-bounce">
            <ShieldAlert className="w-5 h-5 text-rose-200" />
          </div>
          <div>
            <div className="flex items-center space-x-2">
              <span className="text-xs font-black uppercase tracking-widest px-2 py-0.5 rounded bg-rose-900 text-rose-100 border border-rose-600 animate-pulse">
                🚨 P1 CRITICAL EMERGENCY ALERT
              </span>
              <span className="text-xs text-rose-300 font-semibold">
                ({criticalPatients.length} {criticalPatients.length === 1 ? 'Patient' : 'Patients'} at Risk)
              </span>
            </div>
            <p className="text-xs text-rose-200 mt-1 font-medium">
              Multiple simultaneous adverse events detected (Hypotension / Hypoxia / Tachycardia). Immediate clinical intervention required!
            </p>
          </div>
        </div>

        {/* Right: Critical Patient Quick Actions */}
        <div className="flex items-center space-x-2 flex-wrap gap-y-1">
          {criticalPatients.map((patient) => {
            const activeEvents = [
              patient.hypotension.active ? `MAP ${patient.hypotension.currentValue}` : null,
              patient.hypoxia.active ? `SpO2 ${patient.hypoxia.currentValue}%` : null,
              patient.tachycardia.active ? `HR ${patient.tachycardia.currentValue}` : null,
            ].filter(Boolean).join(' | ');

            return (
              <button
                key={patient.profile.id}
                onClick={() => onSelectPatient(patient.profile.id)}
                className="inline-flex items-center px-3 py-1.5 rounded-md text-xs font-bold bg-rose-900/80 hover:bg-rose-800 text-white border border-rose-600 transition-all hover:scale-105 shadow-md"
              >
                <Activity className="w-3.5 h-3.5 mr-1.5 text-rose-300 animate-pulse" />
                {patient.profile.patientNumber} ({activeEvents})
                <ChevronRight className="w-3.5 h-3.5 ml-1 text-rose-300" />
              </button>
            );
          })}

          {onDismiss && (
            <button
              onClick={onDismiss}
              className="p-1.5 rounded-lg text-rose-400 hover:text-rose-100 hover:bg-rose-900/60 transition-colors ml-1"
              title="Dismiss Alert Bar"
            >
              <X className="w-4 h-4" />
            </button>
          )}
        </div>

      </div>
    </div>
  );
};

export default CriticalAlertBar;
