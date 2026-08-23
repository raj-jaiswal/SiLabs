import React from 'react';
import { HeartPulse, ShieldAlert, AlertTriangle, CheckCircle } from 'lucide-react';
import { PatientState } from '../types/patient';

interface HeaderProps {
  patients: PatientState[];
  strideCount: number;
}

export const Header: React.FC<HeaderProps> = ({ patients, strideCount }) => {
  const criticalCount = patients.filter(p => p.triageRank === 'P1_CRITICAL').length;
  const highCount = patients.filter(p => p.triageRank === 'P2_HIGH').length;
  const moderateCount = patients.filter(p => p.triageRank === 'P3_MODERATE').length;
  const stableCount = patients.filter(p => p.triageRank === 'P4_STABLE').length;

  const elapsedSec = strideCount * 5;
  const mins = Math.floor(elapsedSec / 60);
  const secs = elapsedSec % 60;
  const formattedTime = `${String(mins).padStart(2, '0')}:${String(secs).padStart(2, '0')}`;

  return (
    <header className="bg-slate-900 border-b border-slate-800 px-6 py-4">
      <div className="max-w-7xl mx-auto flex flex-col md:flex-row md:items-center md:justify-between gap-4">
        {/* Title & Live Status Pill */}
        <div className="flex items-center space-x-3">
          <div className="p-2.5 bg-slate-800 rounded-lg border border-slate-700 text-sky-400">
            <HeartPulse className="w-6 h-6 animate-pulse text-sky-400" />
          </div>
          <div>
            <div className="flex items-center space-x-2 flex-wrap gap-y-1">
              <h1 className="text-xl font-bold tracking-tight text-slate-100 uppercase">
                Clinical Triage Monitor
              </h1>
              <span className="inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-semibold bg-emerald-950 text-emerald-400 border border-emerald-800">
                <span className="relative flex h-2 w-2 mr-1.5">
                  <span className="animate-ping absolute inline-flex h-full w-full rounded-full bg-emerald-400 opacity-75"></span>
                  <span className="relative inline-flex rounded-full h-2 w-2 bg-emerald-500"></span>
                </span>
                LIVE 5s STRIDE #{strideCount} • {elapsedSec} SECONDS ({formattedTime})
              </span>
            </div>
            <p className="text-xs text-slate-400 mt-0.5">
              SiLabs Intraoperative Adverse Event Predictor • Hypotension | Hypoxia | Tachycardia
            </p>
          </div>
        </div>

        {/* Triage Summary Badges */}
        <div className="grid grid-cols-4 gap-3 text-center">
          <div className="bg-rose-950/40 border border-rose-900/60 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-rose-400 uppercase tracking-wider flex items-center justify-center">
              <ShieldAlert className="w-3.5 h-3.5 mr-1" /> P1 Critical
            </div>
            <div className="text-lg font-bold text-rose-300">{criticalCount}</div>
          </div>

          <div className="bg-amber-950/40 border border-amber-900/60 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-amber-400 uppercase tracking-wider flex items-center justify-center">
              <AlertTriangle className="w-3.5 h-3.5 mr-1" /> P2 High
            </div>
            <div className="text-lg font-bold text-amber-300">{highCount}</div>
          </div>

          <div className="bg-yellow-950/30 border border-yellow-900/50 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-yellow-400 uppercase tracking-wider flex items-center justify-center">
              P3 Moderate
            </div>
            <div className="text-lg font-bold text-yellow-300">{moderateCount}</div>
          </div>

          <div className="bg-emerald-950/40 border border-emerald-900/60 rounded-lg px-3 py-1.5">
            <div className="text-xs font-semibold text-emerald-400 uppercase tracking-wider flex items-center justify-center">
              <CheckCircle className="w-3.5 h-3.5 mr-1" /> P4 Stable
            </div>
            <div className="text-lg font-bold text-emerald-300">{stableCount}</div>
          </div>
        </div>
      </div>
    </header>
  );
};

export default Header;
