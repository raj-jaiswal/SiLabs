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
    <div className="bg-red-50 border-y border-red-200 px-6 py-2.5 flex items-center justify-between text-xs select-none">
      <div className="flex items-center space-x-3">
        <div className="flex items-center space-x-1.5 font-mono font-bold text-red-700">
          <ShieldAlert className="w-4 h-4 text-red-700" />
          <span className="uppercase tracking-wider">P1 Critical Alert ({criticalPatients.length})</span>
        </div>

        <div className="hidden sm:flex items-center space-x-2">
          <span className="text-red-300">|</span>
          <span className="text-red-900 font-medium">Requires Immediate Bedside Evaluation:</span>
          <div className="flex items-center space-x-1.5">
            {criticalPatients.map((p) => (
              <button
                key={p.profile.id}
                onClick={() => onSelectPatient(p.profile.id)}
                className="px-2 py-0.5 bg-red-100 hover:bg-red-200 text-red-800 border border-red-300 rounded text-[11px] font-mono font-semibold transition-colors"
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
        className="p-1 text-red-700 hover:text-red-900 rounded transition-colors"
      >
        <X className="w-4 h-4" />
      </button>
    </div>
  );
};
