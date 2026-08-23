import React from 'react';
import { PatientState } from '../types/patient';
import { Flame, CheckCircle } from 'lucide-react';

interface ClinicalIntelligenceStreamProps {
  patients: PatientState[];
  onSelectPatient: (patientId: string) => void;
}

export const ClinicalIntelligenceStream: React.FC<ClinicalIntelligenceStreamProps> = ({
  patients,
  onSelectPatient,
}) => {
  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');
  const highPatients = patients.filter(p => p.triageRank === 'P2_HIGH');

  return (
    <aside className="w-80 bg-[#0D1117] border-l border-[#1E2631] p-5 flex flex-col space-y-5 select-none font-mono h-full">
      {/* Panel Header */}
      <div className="pb-3 border-b border-[#1E2631]">
        <div className="flex items-center space-x-2">
          <Flame className="w-4 h-4 text-rose-400 animate-pulse" />
          <h3 className="text-xs font-bold text-[#F5F7FA] uppercase tracking-wider">
            CLINICAL INTELLIGENCE STREAM
          </h3>
        </div>
        <p className="text-[11px] text-[#9AA4B2] mt-0.5 font-sans">High-priority adverse event telemetry signals</p>
      </div>

      {/* Stacked Signals */}
      <div className="flex-1 space-y-3 overflow-y-auto pr-1">
        {criticalPatients.map((patient) => (
          <div
            key={patient.profile.id}
            onClick={() => onSelectPatient(patient.profile.id)}
            className="p-3.5 rounded-lg bg-rose-950/30 border border-rose-900/80 glow-red cursor-pointer hover:bg-rose-900/40 transition-all space-y-2"
          >
            <div className="flex items-center justify-between text-xs">
              <span className="font-bold text-rose-200">{patient.profile.patientNumber}</span>
              <span className="px-1.5 py-0.5 bg-rose-900 text-rose-300 rounded text-[9px] font-black">
                CRITICAL SIGNAL
              </span>
            </div>
            <div className="text-[11px] text-rose-300/90 font-sans leading-snug">
              {patient.profile.primaryDiagnosis}
            </div>
            <div className="flex items-center justify-between text-[10px] text-rose-400 pt-1 border-t border-rose-900/40">
              <span>MAP: {patient.currentFrame.mbp.toFixed(1)} mmHg</span>
              <span>Hypotension: {patient.hypotension.probability}%</span>
            </div>
          </div>
        ))}

        {highPatients.map((patient) => (
          <div
            key={patient.profile.id}
            onClick={() => onSelectPatient(patient.profile.id)}
            className="p-3.5 rounded-lg bg-amber-950/20 border border-amber-900/60 glow-amber cursor-pointer hover:bg-amber-900/30 transition-all space-y-2"
          >
            <div className="flex items-center justify-between text-xs">
              <span className="font-bold text-amber-200">{patient.profile.patientNumber}</span>
              <span className="px-1.5 py-0.5 bg-amber-900 text-amber-300 rounded text-[9px] font-black">
                ELEVATED RISK
              </span>
            </div>
            <div className="text-[11px] text-amber-300/90 font-sans leading-snug">
              {patient.profile.primaryDiagnosis}
            </div>
            <div className="flex items-center justify-between text-[10px] text-amber-400 pt-1 border-t border-amber-900/40">
              <span>SpO2: {patient.currentFrame.spo2.toFixed(1)}%</span>
              <span>Hypoxia: {patient.hypoxia.probability}%</span>
            </div>
          </div>
        ))}

        {criticalPatients.length === 0 && highPatients.length === 0 && (
          <div className="p-4 rounded-lg bg-[#080B10] border border-[#1E2631] text-center text-xs text-[#9AA4B2] space-y-2">
            <CheckCircle className="w-5 h-5 text-emerald-400 mx-auto" />
            <p className="font-sans">All patient vitals within normal parameters</p>
          </div>
        )}
      </div>
    </aside>
  );
};
