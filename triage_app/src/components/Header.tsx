'use client';

import React from 'react';
import { User, LogOut, Shield, RefreshCw, Cpu } from 'lucide-react';
import { PatientState } from '../types/patient';
import { useAuth } from '@/context/AuthContext';
import { SiliconLabsLogo } from './SiliconLabsLogo';

interface HeaderProps {
  patients: PatientState[];
  strideCount: number;
  onOpenAdminSidebar?: () => void;
  onReSyncClock?: () => void;
  onToggleArchitecture?: () => void;
  isArchitectureOpen?: boolean;
}

export const Header: React.FC<HeaderProps> = ({
  patients,
  strideCount,
  onOpenAdminSidebar,
  onReSyncClock,
  onToggleArchitecture,
  isArchitectureOpen,
}) => {
  const { currentUser, logout } = useAuth();

  const elapsedSec = strideCount * 5;
  const mins = Math.floor(elapsedSec / 60);
  const secs = elapsedSec % 60;
  const formattedTime = `${String(mins).padStart(2, '0')}:${String(secs).padStart(2, '0')}`;

  return (
    <header className="bg-surface docked full-width top-0 sticky border-b border-outline-variant flex justify-between items-center w-full px-6 py-4 z-40 select-none">
      {/* Brand Logo & Global Search Context */}
      <div className="flex items-center gap-8">
        <div className="flex items-center gap-3">
          <SiliconLabsLogo size="md" />
          <h1 className="text-headline-md font-headline-md font-black text-primary tracking-tight">ICU Sentinel</h1>
        </div>
      </div>

      {/* Trailing Actions & Search */}
      <div className="flex items-center gap-4">
        {/* Search Bar on Left of Actions */}
        <div className="relative hidden lg:block w-64">
          <span className="material-symbols-outlined absolute left-3 top-1/2 -translate-y-1/2 text-outline" style={{ fontSize: '18px' }}>search</span>
          <input className="w-full pl-10 pr-4 py-2 bg-surface-container-low border border-outline-variant rounded-full text-body-md font-body-md focus:border-primary focus:ring-1 focus:ring-primary outline-none transition-all placeholder:text-outline-variant" placeholder="Search patients, ID, rooms..." type="text" />
        </div>

        <div className="flex items-center gap-2">
          {/* Stride Status - Integrated into Header Actions */}
          <div className="hidden xl:flex items-center space-x-2 mr-2 bg-surface-container-low border border-outline-variant px-3 py-1.5 rounded-full text-body-md">
            <span className="w-2 h-2 rounded-full bg-primary animate-pulse" />
            <span className="font-label-mono text-label-mono text-on-surface-variant tabular-nums">
              T={elapsedSec}s ({formattedTime})
            </span>
          </div>

          {/* Architecture Button */}
          {onToggleArchitecture && (
            <button
              onClick={onToggleArchitecture}
              title="Hardware Architecture & Extracted ICU Parameters"
              className={`p-2 rounded-full transition-colors ${isArchitectureOpen
                ? 'bg-primary-container text-on-primary-container'
                : 'text-on-surface-variant hover:bg-surface-container-high hover:text-primary'
                }`}
            >
              <span className="material-symbols-outlined">memory</span>
            </button>
          )}

          {/* Admin Re-Sync Clock Button */}
          {onReSyncClock && (
            <button
              onClick={onReSyncClock}
              title="Reset master clock"
              className="p-2 rounded-full text-on-surface-variant hover:bg-surface-container-high hover:text-primary transition-colors"
            >
              <span className="material-symbols-outlined">sync</span>
            </button>
          )}


          {/* Admin specific action */}
          {currentUser?.role === 'ADMIN' && onOpenAdminSidebar && (
            <button
              onClick={onOpenAdminSidebar}
              title="Admin Panel"
              className="p-2 rounded-full text-on-surface-variant hover:bg-surface-container-high hover:text-primary transition-colors"
            >
              <span className="material-symbols-outlined">admin_panel_settings</span>
            </button>
          )}

          {/* Auth Button */}
          {currentUser && (
            <button
              onClick={logout}
              title="Sign out"
              className="p-2 rounded-full text-on-surface-variant hover:bg-error hover:text-on-error transition-colors ml-2"
            >
              <span className="material-symbols-outlined">logout</span>
            </button>
          )}
        </div>
      </div>
    </header>
  );
};

