'use client';

import React from 'react';
import { PatientState, TriageRank, IndicatorRisk } from '../types/patient';
import { User, Activity, AlertTriangle } from 'lucide-react';

interface TriageTableProps {
  patients: PatientState[];
  onSelectPatient: (patient: PatientState) => void;
}

export const TriageTable: React.FC<TriageTableProps> = ({ patients, onSelectPatient }) => {
  // Sort by Triage Rank ascending
  const sortedPatients = [...patients].sort((a, b) => {
    const rankOrder: Record<TriageRank, number> = {
      P1_CRITICAL: 1,
      P2_HIGH: 2,
      P3_MODERATE: 3,
      P4_STABLE: 4,
    };
    const rA = rankOrder[a.triageRank] || 4;
    const rB = rankOrder[b.triageRank] || 4;
    if (rA !== rB) return rA - rB;
    return b.activeEventCount - a.activeEventCount;
  });

  const renderRankBadge = (rank: TriageRank) => {
    switch (rank) {
      case 'P1_CRITICAL':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-red-50 text-red-700 border border-red-300">
            P1 CRITICAL
          </span>
        );
      case 'P2_HIGH':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-amber-50 text-amber-700 border border-amber-300">
            P2 HIGH
          </span>
        );
      case 'P3_MODERATE':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-yellow-50 text-yellow-800 border border-yellow-300">
            P3 MODERATE
          </span>
        );
      case 'P4_STABLE':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-emerald-50 text-emerald-700 border border-emerald-300">
            P4 STABLE
          </span>
        );
    }
  };

  const renderCleanVitalCell = (risk: IndicatorRisk, label: string) => {
    const isAlert = risk.status === 'ACTIVE_ALERT';
    const isElevated = risk.status === 'ELEVATED_RISK';

    const valueColor = isAlert ? 'text-red-600 font-bold' : isElevated ? 'text-amber-600 font-bold' : 'text-slate-900 font-medium';
    const barColor = isAlert ? 'bg-red-600' : isElevated ? 'bg-amber-500' : 'bg-emerald-500';

    return (
      <div className="space-y-1 font-mono tabular-nums text-xs">
        <div className="flex items-center justify-between space-x-2">
          <span className={`text-sm ${valueColor}`}>
            {risk.currentValue} <span className="text-[11px] text-slate-500 font-normal">{risk.unit}</span>
          </span>
          <span className={`text-[11px] ${isAlert ? 'text-red-700 font-bold' : isElevated ? 'text-amber-700 font-bold' : 'text-slate-600'}`}>
            {risk.probability}% risk
          </span>
        </div>
        
        {/* Subtle 2px Micro Progress Bar (Red, Yellow, Green ONLY) */}
        <div className="w-full bg-slate-100 h-1.5 rounded-full overflow-hidden border border-slate-200">
          <div
            className={`h-full rounded-full transition-all duration-300 ${barColor}`}
            style={{ width: `${Math.max(5, risk.probability)}%` }}
          />
        </div>
      </div>
    );
  };

  return (
    <div className="max-w-7xl mx-auto px-6 py-6">
      <div className="bg-white border border-slate-200 rounded-xl overflow-hidden shadow-sm">
        {/* Table Header Controls */}
        <div className="px-6 py-3.5 border-b border-slate-200 flex items-center justify-between select-none bg-slate-50">
          <h2 className="text-sm font-bold text-slate-900 uppercase tracking-wider flex items-center">
            <Activity className="w-4 h-4 mr-2 text-slate-700" />
            Priority Triage Queue (Auto-Sorted)
          </h2>
          <div className="flex items-center space-x-3 text-xs text-slate-600 font-mono">
            <span className="inline-flex items-center px-2 py-0.5 rounded bg-white text-slate-800 border border-slate-300 text-[11px]">
              5s Stride Sampling
            </span>
            <span>Showing {sortedPatients.length} Active Patients</span>
          </div>
        </div>

        {/* Data Table */}
        <div className="overflow-x-auto">
          <table className="w-full text-left border-collapse select-none">
            <thead>
              <tr className="border-b border-slate-200 bg-slate-100 text-[11px] font-mono font-bold text-slate-700 uppercase tracking-wider">
                <th className="py-3 px-4">Priority Rank</th>
                <th className="py-3 px-4">Patient Profile</th>
                <th className="py-3 px-4">Clinical Metadata</th>
                <th className="py-3 px-4">Hypotension (MAP)</th>
                <th className="py-3 px-4">Hypoxia (SpO2)</th>
                <th className="py-3 px-4">Tachycardia (HR)</th>
                <th className="py-3 px-4 text-right">Action</th>
              </tr>
            </thead>
            <tbody className="divide-y divide-slate-200 text-sm">
              {sortedPatients.map((patient) => {
                const { profile, hypotension, hypoxia, tachycardia, triageRank } = patient;
                const isEsp32 = profile.isEsp32Live || profile.id === 'PATIENT-000';

                return (
                  <tr
                    key={profile.id}
                    onClick={() => onSelectPatient(patient)}
                    className={`table-row-hover cursor-pointer group ${
                      isEsp32
                        ? 'bg-amber-50/60 border-l-4 border-amber-500'
                        : ''
                    }`}
                  >
                    {/* Priority Rank */}
                    <td className="py-3.5 px-4 whitespace-nowrap">
                      {renderRankBadge(triageRank)}
                    </td>

                    {/* Patient Profile */}
                    <td className="py-3.5 px-4 whitespace-nowrap">
                      <div className="flex items-center space-x-3">
                        <div className={`p-2 rounded-lg border ${isEsp32 ? 'bg-amber-100 border-amber-300 text-amber-800' : 'bg-slate-100 border-slate-200 text-slate-700'}`}>
                          <User className="w-4 h-4" />
                        </div>
                        <div>
                          <div className="font-bold text-slate-900 group-hover:text-black transition-colors flex items-center space-x-2">
                            <span>{profile.patientNumber}</span>
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
                          <div className="text-xs text-slate-600 flex items-center space-x-2 mt-0.5">
                            <span>{profile.age} yrs, {profile.sex}</span>
                            <span>•</span>
                            <span className="text-slate-800 font-semibold">{profile.bloodType}</span>
                          </div>
                        </div>
                      </div>
                    </td>

                    {/* Clinical Metadata */}
                    <td className="py-3.5 px-4 max-w-xs">
                      <div className="text-xs font-semibold text-slate-900 truncate">
                        {profile.primaryDiagnosis}
                      </div>
                      <div className="text-[11px] text-slate-600 truncate mt-0.5">
                        {profile.comorbidities.join(', ')}
                      </div>
                    </td>

                    {/* Numerical Vital Cells */}
                    <td className="py-3.5 px-4 min-w-[140px]">
                      {renderCleanVitalCell(hypotension, 'HYPOTENSION')}
                    </td>
                    <td className="py-3.5 px-4 min-w-[140px]">
                      {renderCleanVitalCell(hypoxia, 'HYPOXIA')}
                    </td>
                    <td className="py-3.5 px-4 min-w-[140px]">
                      {renderCleanVitalCell(tachycardia, 'TACHYCARDIA')}
                    </td>

                    {/* Action Button */}
                    <td className="py-3.5 px-4 text-right whitespace-nowrap">
                      <button
                        onClick={(e) => {
                          e.stopPropagation();
                          onSelectPatient(patient);
                        }}
                        className="px-3 py-1.5 bg-slate-100 hover:bg-slate-200 text-slate-800 border border-slate-300 rounded-lg text-xs font-semibold transition-colors"
                      >
                        Inspect Vitals
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
