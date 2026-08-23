'use client';

import React from 'react';
import { User, LogOut, Shield, RefreshCw } from 'lucide-react';
import { PatientState } from '../types/patient';
import { useAuth } from '@/context/AuthContext';
import { SiliconLabsLogo } from './SiliconLabsLogo';

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
    <header className="bg-white border-b border-slate-200 px-6 py-3 select-none">
      <div className="max-w-7xl mx-auto flex flex-col md:flex-row md:items-center md:justify-between gap-4">
        
        {/* Silicon Labs Logo & Title */}
        <div className="flex items-center space-x-4">
          <SiliconLabsLogo size="md" />
          <div className="h-7 w-px bg-slate-200 hidden sm:block" />
          <div>
            <div className="flex items-center space-x-2.5 flex-wrap">
              <h1 className="text-base font-bold tracking-tight text-slate-900 uppercase font-sans">
                Clinical Triage Monitor
              </h1>
              <span className="inline-flex items-center px-2.5 py-0.5 rounded text-xs font-mono font-semibold bg-emerald-50 text-emerald-700 border border-emerald-300 tabular-nums">
                <span className="w-2 h-2 rounded-full bg-emerald-600 mr-1.5" />
                Stride #{strideCount} • {elapsedSec}s ({formattedTime})
              </span>
            </div>
            <p className="text-xs text-slate-500 font-sans mt-0.5">
              Silicon Labs Intraoperative Telemetry &amp; AI Predictor System
            </p>
          </div>
        </div>

        {/* Right Section: Inline Segmented Triage Counts + Admin & User Controls */}
        <div className="flex flex-wrap items-center gap-3">
          {/* Consolidated Segmented Triage Counts */}
          <div className="inline-flex items-center bg-slate-50 border border-slate-300 rounded-lg px-3 py-1.5 text-xs font-mono tabular-nums space-x-3">
            <span className="flex items-center space-x-1">
              <span className="text-slate-600 font-sans font-medium">P1:</span>
              <span className={`font-bold ${criticalCount > 0 ? 'text-[#CC0000]' : 'text-slate-700'}`}>{criticalCount}</span>
            </span>
            <span className="text-slate-300">|</span>
            <span className="flex items-center space-x-1">
              <span className="text-slate-600 font-sans font-medium">P2:</span>
              <span className={`font-bold ${highCount > 0 ? 'text-amber-600' : 'text-slate-700'}`}>{highCount}</span>
            </span>
            <span className="text-slate-300">|</span>
            <span className="flex items-center space-x-1">
              <span className="text-slate-600 font-sans font-medium">P3:</span>
              <span className="font-bold text-amber-600">{moderateCount}</span>
            </span>
            <span className="text-slate-300">|</span>
            <span className="flex items-center space-x-1">
              <span className="text-slate-600 font-sans font-medium">P4:</span>
              <span className="font-bold text-emerald-600">{stableCount}</span>
            </span>
          </div>

          {/* Admin Re-Sync Clock Button */}
          {onReSyncClock && (
            <button
              onClick={onReSyncClock}
              title="Reset master clock stride timer to T=0s"
              className="px-2.5 py-1.5 bg-slate-100 hover:bg-slate-200 text-slate-800 border border-slate-300 rounded-lg text-xs font-mono font-medium transition-colors flex items-center space-x-1.5 tabular-nums"
            >
              <RefreshCw className="w-3.5 h-3.5 text-slate-700" />
              <span>Re-Sync (T=0)</span>
            </button>
          )}

          {/* User Session Badge & Controls */}
          {currentUser && (
            <div className="flex items-center space-x-2">
              <div className="flex items-center space-x-2 bg-slate-50 border border-slate-300 rounded-lg px-2.5 py-1.5 text-xs font-sans">
                <User className="w-3.5 h-3.5 text-slate-700" />
                <span className="font-semibold text-slate-900">{currentUser.name}</span>
                <span className={`text-[10px] font-mono px-1.5 py-0.2 rounded font-bold border ${
                  currentUser.role === 'ADMIN' ? 'bg-red-50 text-[#CC0000] border-red-300' : 'bg-slate-200 text-slate-800 border-slate-300'
                }`}>
                  {currentUser.role}
                </span>
              </div>

              {currentUser.role === 'ADMIN' && onOpenAdminSidebar && (
                <button
                  onClick={onOpenAdminSidebar}
                  className="px-2.5 py-1.5 bg-[#0F172A] hover:bg-[#CC0000] text-white border border-[#0F172A] rounded-lg text-xs font-semibold transition-colors flex items-center space-x-1 font-sans"
                >
                  <Shield className="w-3.5 h-3.5 text-white" />
                  <span>Admin Panel</span>
                </button>
              )}

              <button
                onClick={logout}
                title="Sign out"
                className="p-1.5 bg-slate-100 hover:bg-slate-200 border border-slate-300 text-slate-700 hover:text-[#CC0000] rounded-lg transition-colors"
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
