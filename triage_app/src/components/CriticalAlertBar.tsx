'use client';

import React from 'react';
import { PatientState } from '../types/patient';

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
    <div className="bg-error-container border border-error/20 rounded-xl p-4 mb-margin mx-4 md:mx-6 mt-4 md:mt-6 flex flex-col md:flex-row items-start md:items-center justify-between shadow-[0_4px_12px_rgba(186,26,26,0.05)] select-none gap-4 md:gap-0">
      <div className="flex items-start md:items-center gap-4">
        <div className="bg-error text-on-error w-10 h-10 rounded-full flex items-center justify-center animate-pulse shrink-0">
          <span className="material-symbols-outlined font-bold">warning</span>
        </div>
        <div>
          <h3 className="text-on-error-container font-headline-md text-headline-md text-[18px] leading-tight mb-1 flex items-center gap-2">
            P1 CRITICAL ALERT ({criticalPatients.length})
            <span className="bg-error text-on-error text-[10px] px-2 py-0.5 rounded font-label-mono uppercase tracking-wider">Immediate Eval</span>
          </h3>
          <p className="text-on-error-container/80 text-body-md font-body-md flex items-center flex-wrap gap-2">
            {criticalPatients.map((p, index) => (
              <React.Fragment key={p.profile.id}>
                <span 
                  onClick={() => onSelectPatient(p.profile.id)}
                  className="cursor-pointer hover:underline hover:text-error transition-colors font-semibold"
                >
                  {p.profile.patientNumber} ({p.profile.primaryDiagnosis})
                </span>
                {index < criticalPatients.length - 1 && <span className="opacity-50">•</span>}
              </React.Fragment>
            ))}
          </p>
        </div>
      </div>
      <button 
        onClick={onDismiss}
        className="w-full md:w-auto px-4 py-2 bg-error text-on-error rounded-lg font-label-mono text-label-mono hover:bg-on-error-container transition-colors shadow-sm whitespace-nowrap shrink-0"
      >
        Acknowledge All
      </button>
    </div>
  );
};
