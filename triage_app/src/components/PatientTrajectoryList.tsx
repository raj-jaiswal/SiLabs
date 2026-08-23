import React from 'react';
import { PatientState } from '../types/patient';
import { User, AlertTriangle, Activity, ArrowRight } from 'lucide-react';

interface PatientTrajectoryListProps {
  patients: PatientState[];
  onSelectPatient: (patient: PatientState) => void;
}

export const PatientTrajectoryList: React.FC<PatientTrajectoryListProps> = ({
  patients,
  onSelectPatient,
}) => {
  // Sort by Triage Rank ascending
  const sortedPatients = [...patients].sort((a, b) => {
    const rankOrder = { P1_CRITICAL: 1, P2_HIGH: 2, P3_MODERATE: 3, P4_STABLE: 4 };
    const rA = rankOrder[a.triageRank] || 4;
    const rB = rankOrder[b.triageRank] || 4;
    if (rA !== rB) return rA - rB;
    return b.activeEventCount - a.activeEventCount;
  });

  return (
    <div className="bg-[#0D1117] border border-[#1E2631] rounded-xl p-6 shadow-xl space-y-4">
      <div className="flex items-center justify-between pb-3 border-b border-[#1E2631]">
        <div>
          <h3 className="text-sm font-bold text-[#F5F7FA] uppercase tracking-wider font-mono flex items-center space-x-2">
            <Activity className="w-4 h-4 text-cyan-400" />
            <span>PATIENT PREDICTIVE TRAJECTORIES (MISSION-CONTROL)</span>
          </h3>
          <p className="text-xs text-[#9AA4B2] font-sans">Horizontal vital risk vectors &amp; projected 600s outcome convergence</p>
        </div>
        <div className="text-xs font-mono text-[#9AA4B2]">
          Showing <span className="text-[#F5F7FA] font-bold">{sortedPatients.length}</span> Active Trajectories
        </div>
      </div>

      {/* Trajectories Container */}
      <div className="space-y-3 font-mono">
        {sortedPatients.map((patient) => {
          const { profile, hypotension, hypoxia, tachycardia, triageRank, isStale } = patient;
          const isEsp32 = profile.isEsp32Live || profile.id === 'PATIENT-000';

          const maxProb = Math.max(hypotension.probability, hypoxia.probability, tachycardia.probability);

          const isCritical = triageRank === 'P1_CRITICAL';
          const isHigh = triageRank === 'P2_HIGH';

          const cardStyle = isEsp32
            ? 'bg-[#151A21] border-slate-600 shadow-lg'
            : isCritical
            ? 'bg-rose-950/20 border-rose-900/60 glow-red'
            : isHigh
            ? 'bg-amber-950/20 border-amber-900/60 glow-amber'
            : 'bg-[#080B10] border-[#1E2631] hover:border-slate-700';

          return (
            <div
              key={profile.id}
              onClick={() => onSelectPatient(patient)}
              className={`p-4 rounded-xl border transition-all cursor-pointer flex items-center justify-between group ${cardStyle}`}
            >
              {/* Left Column: Patient Profile */}
              <div className="flex items-center space-x-4 w-64">
                <div className={`p-2.5 rounded-lg border ${isEsp32 ? 'bg-slate-800 border-slate-600 text-amber-300' : 'bg-[#151A21] border-[#1E2631] text-slate-300'}`}>
                  <User className="w-4 h-4" />
                </div>
                <div>
                  <div className="flex items-center space-x-2">
                    <span className="font-bold text-[#F5F7FA] group-hover:text-cyan-400 transition-colors">
                      {profile.patientNumber}
                    </span>
                    {isEsp32 && isStale ? (
                      <span className="px-2 py-0.5 rounded text-[9px] font-bold bg-amber-950 text-amber-300 border border-amber-800 flex items-center animate-pulse">
                        <AlertTriangle className="w-3 h-3 mr-1 text-amber-400" />
                        NO DATA (&gt;20s)
                      </span>
                    ) : isEsp32 ? (
                      <span className="px-2 py-0.5 rounded text-[9px] font-black bg-slate-700 text-slate-200 border border-slate-500 flex items-center">
                        <span className="w-1.5 h-1.5 rounded-full bg-emerald-400 animate-ping mr-1" />
                        ESP32 LIVE
                      </span>
                    ) : null}
                  </div>
                  <div className="text-[11px] text-[#9AA4B2] mt-0.5 font-sans">
                    {profile.age}y • {profile.sex} • {profile.bloodType}
                  </div>
                </div>
              </div>

              {/* Middle Trajectory Vector Line */}
              <div className="flex-1 mx-6 flex items-center space-x-3">
                <span className="text-[10px] text-cyan-400 uppercase tracking-widest font-bold">PAST</span>
                <div className="flex-1 h-1.5 bg-[#151A21] rounded-full overflow-hidden relative">
                  <div
                    className={`h-full rounded-full transition-all duration-500 ${
                      isCritical ? 'bg-rose-500 glow-red' : isHigh ? 'bg-amber-500 glow-amber' : 'bg-cyan-500 glow-cyan'
                    }`}
                    style={{ width: `${Math.max(15, maxProb)}%` }}
                  />
                </div>
                <ArrowRight className="w-4 h-4 text-slate-600" />
                <span className="text-[10px] text-rose-400 uppercase tracking-widest font-bold">FUTURE</span>
              </div>

              {/* Right Column: Probabilities & Triage Badge */}
              <div className="flex items-center space-x-6 text-xs">
                {/* Risk Indicators */}
                <div className="flex items-center space-x-4">
                  <div>
                    <div className="text-[10px] text-[#9AA4B2] uppercase">Hypotension</div>
                    <div className={`font-bold ${hypotension.probability >= 50 ? 'text-rose-400' : 'text-slate-300'}`}>
                      {hypotension.probability}%
                    </div>
                  </div>

                  <div>
                    <div className="text-[10px] text-[#9AA4B2] uppercase">Hypoxia</div>
                    <div className={`font-bold ${hypoxia.probability >= 50 ? 'text-rose-400' : 'text-slate-300'}`}>
                      {hypoxia.probability}%
                    </div>
                  </div>

                  <div>
                    <div className="text-[10px] text-[#9AA4B2] uppercase">Tachycardia</div>
                    <div className={`font-bold ${tachycardia.probability >= 50 ? 'text-rose-400' : 'text-slate-300'}`}>
                      {tachycardia.probability}%
                    </div>
                  </div>
                </div>

                {/* Triage Badge */}
                <div className="w-28 text-right">
                  {triageRank === 'P1_CRITICAL' && (
                    <span className="px-2.5 py-1 rounded-md text-[10px] font-extrabold bg-rose-950/80 text-rose-300 border border-rose-800 glow-red">
                      P1 CRITICAL
                    </span>
                  )}
                  {triageRank === 'P2_HIGH' && (
                    <span className="px-2.5 py-1 rounded-md text-[10px] font-extrabold bg-amber-950/80 text-amber-300 border border-amber-800 glow-amber">
                      P2 HIGH
                    </span>
                  )}
                  {triageRank === 'P3_MODERATE' && (
                    <span className="px-2.5 py-1 rounded-md text-[10px] font-extrabold bg-yellow-950/80 text-yellow-300 border border-yellow-800">
                      P3 MODERATE
                    </span>
                  )}
                  {triageRank === 'P4_STABLE' && (
                    <span className="px-2.5 py-1 rounded-md text-[10px] font-extrabold bg-emerald-950/80 text-emerald-300 border border-emerald-800">
                      P4 STABLE
                    </span>
                  )}
                </div>
              </div>
            </div>
          );
        })}
      </div>
    </div>
  );
};
