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
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-rose-500/10 text-rose-400 border border-rose-500/20">
            P1 CRITICAL
          </span>
        );
      case 'P2_HIGH':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-amber-500/10 text-amber-400 border border-amber-500/20">
            P2 HIGH
          </span>
        );
      case 'P3_MODERATE':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-yellow-500/10 text-yellow-300 border border-yellow-500/20">
            P3 MODERATE
          </span>
        );
      case 'P4_STABLE':
        return (
          <span className="inline-flex items-center px-2.5 py-1 rounded text-xs font-mono font-bold bg-emerald-500/10 text-emerald-400 border border-emerald-500/20">
            P4 STABLE
          </span>
        );
    }
  };

  const renderCleanVitalCell = (risk: IndicatorRisk, label: string) => {
    const isAlert = risk.status === 'ACTIVE_ALERT';
    const isElevated = risk.status === 'ELEVATED_RISK';

    const valueColor = isAlert ? 'text-rose-400 font-bold' : isElevated ? 'text-amber-400 font-semibold' : 'text-slate-200';
    const barColor = isAlert ? 'bg-rose-500' : isElevated ? 'bg-amber-500' : 'bg-slate-600';

    return (
      <div className="space-y-1 font-mono tabular-nums text-xs">
        <div className="flex items-center justify-between space-x-2">
          <span className={`text-sm ${valueColor}`}>
            {risk.currentValue} <span className="text-[11px] text-slate-400 font-normal">{risk.unit}</span>
          </span>
          <span className={`text-[11px] ${isAlert ? 'text-rose-300 font-bold' : isElevated ? 'text-amber-300/90 font-medium' : 'text-slate-400'}`}>
            {risk.probability}% risk
          </span>
        </div>
        
        {/* Subtle 2px Micro Progress Bar */}
        <div className="w-full bg-[#0B0F17] h-1 rounded-full overflow-hidden border border-[#1E2638]">
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
      <div className="bg-[#131926] border border-[#1E2638] rounded-xl overflow-hidden shadow-lg">
        {/* Table Header Controls */}
        <div className="px-6 py-3.5 border-b border-[#1E2638] flex items-center justify-between select-none">
          <h2 className="text-sm font-bold text-slate-200 uppercase tracking-wider flex items-center">
            <Activity className="w-4 h-4 mr-2 text-sky-400" />
            Priority Triage Queue (Auto-Sorted)
          </h2>
          <div className="flex items-center space-x-3 text-xs text-slate-400 font-mono">
            <span className="inline-flex items-center px-2 py-0.5 rounded bg-[#0B0F17] text-sky-400 border border-[#1E2638] text-[11px]">
              5s Stride Sampling
            </span>
            <span>Showing {sortedPatients.length} Active Patients</span>
          </div>
        </div>

        {/* Data Table */}
        <div className="overflow-x-auto">
          <table className="w-full text-left border-collapse select-none">
            <thead>
              <tr className="border-b border-[#1E2638] bg-[#0B0F17] text-[11px] font-mono font-semibold text-slate-400 uppercase tracking-wider">
                <th className="py-3 px-4">Priority Rank</th>
                <th className="py-3 px-4">Patient Profile</th>
                <th className="py-3 px-4">Clinical Metadata</th>
                <th className="py-3 px-4">Hypotension (MAP)</th>
                <th className="py-3 px-4">Hypoxia (SpO2)</th>
                <th className="py-3 px-4">Tachycardia (HR)</th>
                <th className="py-3 px-4 text-right">Action</th>
              </tr>
            </thead>
            <tbody className="divide-y divide-[#1E2638] text-sm">
              {sortedPatients.map((patient) => {
                const { profile, hypotension, hypoxia, tachycardia, triageRank } = patient;
                const isEsp32 = profile.isEsp32Live || profile.id === 'PATIENT-000';

                return (
                  <tr
                    key={profile.id}
                    onClick={() => onSelectPatient(patient)}
                    className={`table-row-hover cursor-pointer group ${
                      isEsp32
                        ? 'bg-[#182030] border-l-2 border-amber-400/80'
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
                        <div className={`p-2 rounded-lg border ${isEsp32 ? 'bg-[#1C2537] border-amber-500/30 text-amber-300' : 'bg-[#0B0F17] border-[#1E2638] text-slate-400'}`}>
                          <User className="w-4 h-4" />
                        </div>
                        <div>
                          <div className="font-bold text-slate-100 group-hover:text-sky-400 transition-colors flex items-center space-x-2">
                            <span>{profile.patientNumber}</span>
                            {isEsp32 && profile.isStale ? (
                              <span className="px-2 py-0.5 rounded text-[10px] font-mono font-medium bg-amber-500/10 text-amber-300 border border-amber-500/20 flex items-center">
                                <AlertTriangle className="w-3 h-3 mr-1 text-amber-400" />
                                NO DATA (&gt;20s)
                              </span>
                            ) : isEsp32 ? (
                              <span className="px-2 py-0.5 rounded text-[10px] font-mono font-semibold bg-emerald-500/10 text-emerald-300 border border-emerald-500/20 flex items-center">
                                <span className="w-1.5 h-1.5 rounded-full bg-emerald-400 mr-1" />
                                ESP32 LIVE
                              </span>
                            ) : null}
                          </div>
                          <div className="text-xs text-slate-400 flex items-center space-x-2 mt-0.5">
                            <span>{profile.age} yrs, {profile.sex}</span>
                            <span>•</span>
                            <span className="text-slate-300 font-medium">{profile.bloodType}</span>
                          </div>
                        </div>
                      </div>
                    </td>

                    {/* Clinical Metadata */}
                    <td className="py-3.5 px-4 max-w-xs">
                      <div className="text-xs font-semibold text-slate-200 truncate">
                        {profile.primaryDiagnosis}
                      </div>
                      <div className="text-[11px] text-slate-400 truncate mt-0.5">
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
                        className="px-3 py-1.5 bg-[#0B0F17] hover:bg-[#1C2537] text-slate-300 hover:text-white border border-[#1E2638] rounded-lg text-xs font-medium transition-colors"
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
