'use client';

import React from 'react';
import { Activity, User, LogOut, Shield, RefreshCw } from 'lucide-react';
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
    <header className="bg-[#131926] border-b border-[#1E2638] px-6 py-3.5 select-none">
      <div className="max-w-7xl mx-auto flex flex-col md:flex-row md:items-center md:justify-between gap-4">
        
        {/* Title & Static Live Status Pill */}
        <div className="flex items-center space-x-3">
          <div className="p-2 bg-[#1C2537] rounded-lg border border-[#2A354D] text-sky-400">
            <Activity className="w-5 h-5 text-sky-400" />
          </div>
          <div>
            <div className="flex items-center space-x-2.5 flex-wrap">
              <h1 className="text-lg font-bold tracking-tight text-slate-100 uppercase font-sans">
                Clinical Triage Monitor
              </h1>
              <span className="inline-flex items-center px-2 py-0.5 rounded text-xs font-mono font-semibold bg-emerald-500/10 text-emerald-400 border border-emerald-500/20 tabular-nums">
                <span className="w-1.5 h-1.5 rounded-full bg-emerald-400 mr-1.5" />
                Stride #{strideCount} • {elapsedSec}s ({formattedTime})
              </span>
            </div>
            <p className="text-xs text-slate-400 mt-0.5">
              SiLabs Intraoperative Adverse Event Predictor • Real-Time Telemetry
            </p>
          </div>
        </div>

        {/* Right Section: Inline Segmented Triage Counts + Admin & User Controls */}
        <div className="flex flex-wrap items-center gap-3">
          {/* Consolidated Segmented Triage Counts */}
          <div className="inline-flex items-center bg-[#0B0F17] border border-[#1E2638] rounded-lg px-3 py-1.5 text-xs font-mono tabular-nums space-x-3">
            <span className="flex items-center space-x-1">
              <span className="text-slate-400">P1:</span>
              <span className={`font-bold ${criticalCount > 0 ? 'text-rose-400' : 'text-slate-300'}`}>{criticalCount}</span>
            </span>
            <span className="text-[#1E2638]">|</span>
            <span className="flex items-center space-x-1">
              <span className="text-slate-400">P2:</span>
              <span className={`font-bold ${highCount > 0 ? 'text-amber-400' : 'text-slate-300'}`}>{highCount}</span>
            </span>
            <span className="text-[#1E2638]">|</span>
            <span className="flex items-center space-x-1">
              <span className="text-slate-400">P3:</span>
              <span className="font-bold text-yellow-400/90">{moderateCount}</span>
            </span>
            <span className="text-[#1E2638]">|</span>
            <span className="flex items-center space-x-1">
              <span className="text-slate-400">P4:</span>
              <span className="font-bold text-emerald-400">{stableCount}</span>
            </span>
          </div>

          {/* Admin Re-Sync Clock Button */}
          {onReSyncClock && (
            <button
              onClick={onReSyncClock}
              title="Reset master clock stride timer to T=0s"
              className="px-2.5 py-1.5 bg-rose-500/10 hover:bg-rose-500/20 text-rose-300 border border-rose-500/30 rounded-lg text-xs font-mono font-medium transition-colors flex items-center space-x-1.5"
            >
              <RefreshCw className="w-3.5 h-3.5 text-rose-400" />
              <span>Re-Sync (T=0)</span>
            </button>
          )}

          {/* User Session Badge & Controls */}
          {currentUser && (
            <div className="flex items-center space-x-2">
              <div className="flex items-center space-x-2 bg-[#0B0F17] border border-[#1E2638] rounded-lg px-2.5 py-1.5 text-xs">
                <User className="w-3.5 h-3.5 text-sky-400" />
                <span className="font-medium text-slate-200">{currentUser.name}</span>
                <span className={`text-[10px] font-mono px-1.5 py-0.2 rounded border ${
                  currentUser.role === 'ADMIN' ? 'bg-rose-500/10 text-rose-300 border-rose-500/20' : 'bg-sky-500/10 text-sky-300 border-sky-500/20'
                }`}>
                  {currentUser.role}
                </span>
              </div>

              {currentUser.role === 'ADMIN' && onOpenAdminSidebar && (
                <button
                  onClick={onOpenAdminSidebar}
                  className="px-2.5 py-1.5 bg-[#1C2537] hover:bg-[#253047] border border-[#2A354D] text-slate-200 rounded-lg text-xs font-medium transition-colors flex items-center space-x-1"
                >
                  <Shield className="w-3.5 h-3.5 text-rose-400" />
                  <span>Admin Panel</span>
                </button>
              )}

              <button
                onClick={logout}
                title="Sign out"
                className="p-1.5 bg-[#0B0F17] hover:bg-[#1C2537] border border-[#1E2638] text-slate-400 hover:text-rose-400 rounded-lg transition-colors"
              >
                <LogOut className="w-3.5 h-3.5" />
              </button>
            </div>
          )}
        </div>

      </div>
    </header>
  );
};
