'use client';

import React from 'react';
import { Activity, ShieldAlert, AlertTriangle, CheckCircle, User, LogOut, Shield, RefreshCw } from 'lucide-react';
import { PatientState } from '../types/patient';
import { useAuth } from '@/context/AuthContext';

interface HeaderProps {
  patients: PatientState[];
  strideCount: number;
  onOpenAdminSidebar?: () => void;
  onReSyncClock?: () => void;
}

export const Header: React.FC<HeaderProps> = ({ patients, strideCount, onOpenAdminSidebar, onReSyncClock }) => {
  const { currentUser, logout } = useAuth();

  const criticalCount = patients.filter(p => p.triageRank === 'P1_CRITICAL').length;
  const highCount = patients.filter(p => p.triageRank === 'P2_HIGH').length;
  const moderateCount = patients.filter(p => p.triageRank === 'P3_MODERATE').length;
  const stableCount = patients.filter(p => p.triageRank === 'P4_STABLE').length;

  const elapsedSec = strideCount * 5;
  const mins = Math.floor(elapsedSec / 60);
  const secs = elapsedSec % 60;
  const formattedTime = `${String(mins).padStart(2, '0')}:${String(secs).padStart(2, '0')}`;

  return (
    <header className="bg-[#0D1117] border-b border-[#1E2631] px-6 py-4 select-none">
      <div className="flex flex-col lg:flex-row lg:items-center lg:justify-between gap-4">
        {/* Title & Live Status Pill */}
        <div className="flex items-center space-x-3">
          <div className="p-2.5 bg-[#151A21] rounded-xl border border-cyan-500/30 text-cyan-400 glow-cyan">
            <Activity className="w-6 h-6 animate-pulse text-cyan-400" />
          </div>
          <div>
            <div className="flex items-center space-x-3 flex-wrap gap-y-1">
              <h1 className="text-xl font-extrabold tracking-wider text-[#F5F7FA] uppercase font-sans">
                HOSPITAL INTELLIGENCE
              </h1>
              <span className="inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-mono font-bold bg-cyan-950/80 text-cyan-300 border border-cyan-800">
                <span className="relative flex h-2 w-2 mr-1.5">
                  <span className="animate-ping absolute inline-flex h-full w-full rounded-full bg-cyan-400 opacity-75"></span>
                  <span className="relative inline-flex rounded-full h-2 w-2 bg-cyan-400"></span>
                </span>
                LIVE 5s STRIDE #{strideCount} • {elapsedSec}s ({formattedTime})
              </span>
            </div>
            <p className="text-xs text-[#9AA4B2] mt-0.5 font-sans">
              SiLabs Intraoperative Adverse Event Predictor • Hypotension | Hypoxia | Tachycardia
            </p>
          </div>
        </div>

        {/* Right Controls: Summary Badges + User Session & Admin Controls */}
        <div className="flex flex-wrap items-center gap-3 justify-between lg:justify-end font-mono">
          {/* Triage Summary Badges */}
          <div className="grid grid-cols-4 gap-2 text-center text-xs">
            <div className="bg-rose-950/40 border border-rose-900/60 rounded-lg px-2.5 py-1 glow-red">
              <div className="text-[10px] font-semibold text-rose-400 uppercase tracking-wider flex items-center justify-center">
                <ShieldAlert className="w-3 h-3 mr-1" /> P1
              </div>
              <div className="text-sm font-bold text-rose-300">{criticalCount}</div>
            </div>

            <div className="bg-amber-950/40 border border-amber-900/60 rounded-lg px-2.5 py-1 glow-amber">
              <div className="text-[10px] font-semibold text-amber-400 uppercase tracking-wider flex items-center justify-center">
                <AlertTriangle className="w-3 h-3 mr-1" /> P2
              </div>
              <div className="text-sm font-bold text-amber-300">{highCount}</div>
            </div>

            <div className="bg-yellow-950/30 border border-yellow-900/50 rounded-lg px-2.5 py-1">
              <div className="text-[10px] font-semibold text-yellow-400 uppercase tracking-wider flex items-center justify-center">
                P3
              </div>
              <div className="text-sm font-bold text-yellow-300">{moderateCount}</div>
            </div>

            <div className="bg-emerald-950/30 border border-emerald-900/50 rounded-lg px-2.5 py-1">
              <div className="text-[10px] font-semibold text-emerald-400 uppercase tracking-wider flex items-center justify-center">
                <CheckCircle className="w-3 h-3 mr-1" /> P4
              </div>
              <div className="text-sm font-bold text-emerald-300">{stableCount}</div>
            </div>
          </div>

          <div className="h-6 w-px bg-[#1E2631] hidden sm:block" />

          {/* Admin Re-Sync Clock Button */}
          {onReSyncClock && (
            <button
              onClick={onReSyncClock}
              title="Reset master clock stride timer back to T=0s"
              className="px-3 py-1.5 bg-rose-950/80 hover:bg-rose-900 text-rose-200 border border-rose-700 rounded-lg text-xs font-bold transition-all flex items-center space-x-1.5 shadow-md hover:shadow-rose-900/50"
            >
              <RefreshCw className="w-3.5 h-3.5 text-rose-400 animate-spin-slow" />
              <span>🔄 RE-SYNC CLOCK (T=0)</span>
            </button>
          )}

          {/* Logged in User Badge & Actions */}
          {currentUser && (
            <div className="flex items-center space-x-2">
              <div className="flex items-center space-x-2 bg-[#151A21] border border-[#1E2631] rounded-lg px-3 py-1.5">
                <User className="w-4 h-4 text-cyan-400" />
                <span className="text-xs font-semibold text-[#F5F7FA]">{currentUser.name}</span>
                <span className={`text-[10px] font-bold px-1.5 py-0.2 rounded ${
                  currentUser.role === 'ADMIN' ? 'bg-rose-900/80 text-rose-300 border border-rose-700' : 'bg-cyan-900/80 text-cyan-300 border border-cyan-700'
                }`}>
                  {currentUser.role}
                </span>
              </div>

              {currentUser.role === 'ADMIN' && onOpenAdminSidebar && (
                <button
                  onClick={onOpenAdminSidebar}
                  className="px-3 py-1.5 bg-rose-900/40 hover:bg-rose-900/70 border border-rose-700 text-rose-200 rounded-lg text-xs font-semibold transition-all flex items-center space-x-1"
                >
                  <Shield className="w-3.5 h-3.5 text-rose-400" />
                  <span>Admin Panel</span>
                </button>
              )}

              <button
                onClick={logout}
                title="Sign out"
                className="p-2 bg-[#151A21] hover:bg-[#1E2631] border border-[#1E2631] text-slate-400 hover:text-rose-400 rounded-lg transition-all"
              >
                <LogOut className="w-4 h-4" />
              </button>
            </div>
          )}
        </div>
      </div>
    </header>
  );
};
