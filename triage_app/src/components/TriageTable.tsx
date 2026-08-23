import React from 'react';
import { ShieldAlert, AlertTriangle, CheckCircle, ChevronRight, Activity, User } from 'lucide-react';
import { PatientState, TriageRank, IndicatorRisk } from '../types/patient';

interface TriageTableProps {
  patients: PatientState[];
  onSelectPatient: (patient: PatientState) => void;
}

const RANK_SORT_ORDER: Record<TriageRank, number> = {
  'P1_CRITICAL': 1,
  'P2_HIGH': 2,
  'P3_MODERATE': 3,
  'P4_STABLE': 4,
};

export const TriageTable: React.FC<TriageTableProps> = ({ patients, onSelectPatient }) => {
  // Sort patients by Triage Rank ascending, then activeEventCount descending
  const sortedPatients = [...patients].sort((a, b) => {
    const rankDiff = RANK_SORT_ORDER[a.triageRank] - RANK_SORT_ORDER[b.triageRank];
    if (rankDiff !== 0) return rankDiff;
    return b.activeEventCount - a.activeEventCount;
  });

  const renderRankBadge = (rank: TriageRank) => {
    switch (rank) {
      case 'P1_CRITICAL':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-bold bg-rose-950 text-rose-300 border border-rose-800 shadow-sm shadow-rose-900/50 animate-pulse">
            <ShieldAlert className="w-3.5 h-3.5 mr-1 text-rose-400" /> P1 CRITICAL
          </span>
        );
      case 'P2_HIGH':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-bold bg-amber-950 text-amber-300 border border-amber-800">
            <AlertTriangle className="w-3.5 h-3.5 mr-1 text-amber-400" /> P2 HIGH
          </span>
        );
      case 'P3_MODERATE':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-semibold bg-yellow-950/60 text-yellow-300 border border-yellow-800/80">
            P3 MODERATE
          </span>
        );
      case 'P4_STABLE':
        return (
          <span className="inline-flex items-center px-3 py-1 rounded-md text-xs font-medium bg-emerald-950/50 text-emerald-300 border border-emerald-900">
            <CheckCircle className="w-3.5 h-3.5 mr-1 text-emerald-400" /> P4 STABLE
          </span>
        );
    }
  };

  const renderIndicatorPill = (risk: IndicatorRisk, label: string) => {
    if (risk.status === 'ACTIVE_ALERT') {
      return (
        <div className="bg-rose-950/60 border border-rose-800/80 rounded-md p-2 text-left">
          <div className="flex items-center justify-between text-xs font-bold text-rose-400">
            <span>{label}</span>
            <span className="bg-rose-900 text-rose-200 px-1.5 py-0.5 rounded text-[10px]">ALERT</span>
          </div>
          <div className="text-sm font-semibold text-slate-100 mt-1">
            {risk.currentValue} {risk.unit}
            <span className="text-xs text-rose-300 font-normal ml-2">({risk.probability}% risk)</span>
          </div>
        </div>
      );
    } else if (risk.status === 'ELEVATED_RISK') {
      return (
        <div className="bg-amber-950/40 border border-amber-900/60 rounded-md p-2 text-left">
          <div className="flex items-center justify-between text-xs font-semibold text-amber-400">
            <span>{label}</span>
            <span className="bg-amber-900/80 text-amber-200 px-1.5 py-0.5 rounded text-[10px]">ELEVATED</span>
          </div>
          <div className="text-sm font-medium text-slate-200 mt-1">
            {risk.currentValue} {risk.unit}
            <span className="text-xs text-amber-300/80 font-normal ml-2">({risk.probability}%)</span>
          </div>
        </div>
      );
    }

    return (
      <div className="bg-slate-900/80 border border-slate-800 rounded-md p-2 text-left">
        <div className="text-[11px] font-medium text-slate-400">{label}</div>
        <div className="text-sm font-medium text-slate-300 mt-0.5">
          {risk.currentValue} {risk.unit}
          <span className="text-[11px] text-slate-500 font-normal ml-1.5">({risk.probability}%)</span>
        </div>
      </div>
    );
  };

  return (
    <div className="max-w-7xl mx-auto px-6 py-6">
      <div className="bg-slate-900 border border-slate-800 rounded-xl overflow-hidden shadow-2xl">
        <div className="px-6 py-4 border-b border-slate-800 flex items-center justify-between">
          <h2 className="text-base font-semibold text-slate-200 flex items-center">
            <Activity className="w-4 h-4 mr-2 text-sky-400" />
            Priority Triage Queue (Auto-Sorted)
          </h2>
          <div className="flex items-center space-x-3 text-xs text-slate-400">
            <span className="inline-flex items-center px-2 py-0.5 rounded bg-slate-800 text-sky-400 border border-slate-700 font-mono text-[11px]">
              5s Stride Interval
            </span>
            <span>Showing {sortedPatients.length} Active Patients</span>
          </div>
        </div>

        <div className="overflow-x-auto">
          <table className="w-full text-left border-collapse">
            <thead>
              <tr className="border-b border-slate-800 bg-slate-950/60 text-xs font-semibold text-slate-400 uppercase tracking-wider">
                <th className="py-3.5 px-4">Priority Rank</th>
                <th className="py-3.5 px-4">Patient Profile</th>
                <th className="py-3.5 px-4">Clinical Metadata</th>
                <th className="py-3.5 px-4">Hypotension (MAP)</th>
                <th className="py-3.5 px-4">Hypoxia (SpO2)</th>
                <th className="py-3.5 px-4">Tachycardia (HR)</th>
                <th className="py-3.5 px-4 text-right">Action</th>
              </tr>
            </thead>
            <tbody className="divide-y divide-slate-800/60 text-sm">
              {sortedPatients.map((patient) => {
                const { profile, hypotension, hypoxia, tachycardia, triageRank } = patient;
                return (
                  <tr
                    key={profile.id}
                    onClick={() => onSelectPatient(patient)}
                    className="hover:bg-slate-800/50 transition-colors cursor-pointer group"
                  >
                    {/* Rank */}
                    <td className="py-4 px-4 whitespace-nowrap">
                      {renderRankBadge(triageRank)}
                    </td>

                    {/* Patient Profile */}
                    <td className="py-4 px-4 whitespace-nowrap">
                      <div className="flex items-center space-x-3">
                        <div className="p-2 bg-slate-800 rounded-full border border-slate-700 text-slate-300">
                          <User className="w-4 h-4" />
                        </div>
                        <div>
                          <div className="font-bold text-slate-100 group-hover:text-sky-400 transition-colors">
                            {profile.patientNumber}
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
                    <td className="py-4 px-4 max-w-xs">
                      <div className="text-xs font-semibold text-slate-200 truncate">
                        {profile.primaryDiagnosis}
                      </div>
                      <div className="text-[11px] text-slate-400 truncate mt-0.5">
                        {profile.comorbidities.join(', ')}
                      </div>
                    </td>

                    {/* Indicators */}
                    <td className="py-4 px-4 min-w-[150px]">
                      {renderIndicatorPill(hypotension, 'HYPOTENSION')}
                    </td>
                    <td className="py-4 px-4 min-w-[150px]">
                      {renderIndicatorPill(hypoxia, 'HYPOXIA')}
                    </td>
                    <td className="py-4 px-4 min-w-[150px]">
                      {renderIndicatorPill(tachycardia, 'TACHYCARDIA')}
                    </td>

                    {/* Action */}
                    <td className="py-4 px-4 text-right whitespace-nowrap">
                      <button
                        onClick={(e) => {
                          e.stopPropagation();
                          onSelectPatient(patient);
                        }}
                        className="inline-flex items-center px-3 py-1.5 rounded-md text-xs font-medium bg-slate-800 text-slate-300 hover:bg-sky-900/60 hover:text-sky-300 border border-slate-700 transition-colors"
                      >
                        Inspect Vitals <ChevronRight className="w-3.5 h-3.5 ml-1" />
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
