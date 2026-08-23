'use client';

import React from 'react';
import { PatientState } from '../types/patient';
import { ShieldAlert, X } from 'lucide-react';

interface CriticalAlertBarProps {
  criticalPatients: PatientState[];
  onSelectPatient: (patientId: string) => void;
  onDismiss: () => void;
}

export const CriticalAlertBar: React.FC<CriticalAlertBarProps> = ({
  criticalPatients,
  onSelectPatient,
  onDismiss,
}) => {
  if (!criticalPatients || criticalPatients.length === 0) return null;

  return (
    <div className="bg-rose-500/10 border-y border-rose-500/20 px-6 py-2.5 flex items-center justify-between text-xs select-none">
      <div className="flex items-center space-x-3">
        <div className="flex items-center space-x-1.5 font-mono font-bold text-rose-400">
          <ShieldAlert className="w-4 h-4 text-rose-400" />
          <span className="uppercase tracking-wider">P1 Critical Alert ({criticalPatients.length})</span>
        </div>

        <div className="hidden sm:flex items-center space-x-2">
          <span className="text-slate-500">|</span>
          <span className="text-slate-300">Requires Immediate Bedside Evaluation:</span>
          <div className="flex items-center space-x-1.5">
            {criticalPatients.map((p) => (
              <button
                key={p.profile.id}
                onClick={() => onSelectPatient(p.profile.id)}
                className="px-2 py-0.5 bg-rose-500/20 hover:bg-rose-500/30 text-rose-200 border border-rose-500/40 rounded text-[11px] font-mono font-semibold transition-colors"
              >
                {p.profile.patientNumber} ({p.profile.primaryDiagnosis})
              </button>
            ))}
          </div>
        </div>
      </div>

      <button
        onClick={onDismiss}
        title="Dismiss banner"
        className="p-1 text-slate-400 hover:text-slate-200 rounded transition-colors"
      >
        <X className="w-4 h-4" />
      </button>
    </div>
  );
};
