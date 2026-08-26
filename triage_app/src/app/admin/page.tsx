'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { AdminSidebar } from '@/components/AdminSidebar';
import { IcuArchitectureBlock } from '@/components/IcuArchitectureBlock';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';
import { Shield, Lock, Mail, ArrowLeft, ShieldAlert } from 'lucide-react';
import Link from 'next/link';

export default function AdminPage() {
  const { currentUser, login } = useAuth();
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);
  const [isAdminSidebarOpen, setIsAdminSidebarOpen] = useState<boolean>(false);
  const [showArchitecture, setShowArchitecture] = useState<boolean>(false);

  // Admin Login State for /admin
  const [adminPasswordInput, setAdminPasswordInput] = useState('');
  const [adminLoginError, setAdminLoginError] = useState('');

  // 1. Master Stride Counter (Updates strideCount every second, value changes every 5 seconds)
  useEffect(() => {
    if (!currentUser) return;

    const updateStride = () => {
      let masterStartTime = localStorage.getItem('silabs_master_start_time');
      if (!masterStartTime) {
        masterStartTime = String(Date.now());
        localStorage.setItem('silabs_master_start_time', masterStartTime);
      }
      const startTimeNum = parseInt(masterStartTime, 10);
      const elapsedMs = Math.max(0, Date.now() - startTimeNum);
      const currentStride = Math.floor(elapsedMs / 5000) + 1;
      setStrideCount(currentStride);
    };

    updateStride();
    const interval = setInterval(updateStride, 1000);

    const handleStorageEvent = (e: StorageEvent) => {
      if (e.key === 'silabs_master_start_time') {
        updateStride();
      }
    };

    window.addEventListener('storage', handleStorageEvent);
    window.addEventListener('silabs_resync', updateStride);

    return () => {
      clearInterval(interval);
      window.removeEventListener('storage', handleStorageEvent);
      window.removeEventListener('silabs_resync', updateStride);
    };
  }, [currentUser]);

  // 2. Strict 5-Second Telemetry Sync (Triggers ONLY when strideCount changes every 5 seconds)
  useEffect(() => {
    if (strideCount === 0 || !currentUser) return;

    async function syncTelemetry5s() {
      try {
        const res = await fetch('/api/patients');
        const data = await res.json();
        if (data.patients) {
          const updated = data.patients.map((patient: PatientState) => {
            if (!patient.vitalsHistory || patient.vitalsHistory.length === 0) return patient;
            const targetIndex = (strideCount - 1) % patient.vitalsHistory.length;
            const currentFrame = patient.vitalsHistory[targetIndex];
            const riskEval = evaluatePatientRisk(patient.vitalsHistory, targetIndex);

            return {
              ...patient,
              currentFrameIndex: targetIndex,
              currentFrame,
              hypotension: patient.isEsp32Live ? patient.hypotension : riskEval.hypotension,
              hypoxia: patient.isEsp32Live ? patient.hypoxia : riskEval.hypoxia,
              tachycardia: patient.isEsp32Live ? patient.tachycardia : riskEval.tachycardia,
              triageRank: patient.isEsp32Live ? patient.triageRank : riskEval.triageRank,
              activeEventCount: patient.isEsp32Live ? patient.activeEventCount : riskEval.activeEventCount,
            };
          });
          setPatients(updated);
        }
      } catch (err: any) {
        setError(err.message || 'Failed to load patient telemetry');
      } finally {
        setLoading(false);
      }
    }

    syncTelemetry5s();
  }, [strideCount, currentUser]);

  const handleAdminLoginSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (login('admin@hospital.com', adminPasswordInput)) {
      setAdminLoginError('');
      setAdminPasswordInput('');
    } else {
      setAdminLoginError('Incorrect Administrator password.');
    }
  };

  const handleReSyncClock = () => {
    const now = String(Date.now());
    localStorage.setItem('silabs_master_start_time', now);
    window.dispatchEvent(new CustomEvent('silabs_resync'));
  };

  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  // Gated Auth: If not logged in as Admin, prompt for Admin password
  if (!currentUser || currentUser.role !== 'ADMIN') {
    return (
      <div className="min-h-screen bg-surface-container-low flex flex-col items-center justify-center p-6 text-on-surface font-body-md select-none">
        <div className="w-full max-w-md bg-surface-container-lowest border border-outline-variant rounded-xl p-8 shadow-sm space-y-6">
          
          <div className="text-center space-y-2 select-none">
            <div className="inline-flex p-3 bg-error-container/20 border border-error/20 text-error mb-2 rounded-xl">
              <span className="material-symbols-outlined text-[32px]">admin_panel_settings</span>
            </div>
            <h1 className="text-headline-md font-headline-md font-black tracking-tight uppercase text-on-surface">Administrator Login</h1>
            <p className="text-body-md font-body-md text-on-surface-variant">Enter Admin password to access `/admin` control panel</p>
          </div>

          <div className="p-4 bg-surface-container border border-outline-variant rounded-xl flex items-center space-x-4 text-body-md">
            <div className="p-2 bg-primary-container/20 text-primary rounded-lg">
              <span className="material-symbols-outlined">mail</span>
            </div>
            <div>
              <div className="font-bold text-on-surface">admin@hospital.com</div>
              <div className="text-label-mono font-label-mono text-on-surface-variant text-[11px] mt-0.5">System Administrator</div>
            </div>
          </div>

          <form onSubmit={handleAdminLoginSubmit} className="space-y-4 text-body-md">
            {adminLoginError && (
              <div className="p-3 bg-error-container border border-error/30 rounded-lg text-on-error-container text-center font-bold flex items-center justify-center space-x-2">
                <span className="material-symbols-outlined text-error">error</span>
                <span className="text-[14px]">{adminLoginError}</span>
              </div>
            )}

            <div>
              <label className="block text-on-surface font-semibold mb-1.5">
                Admin Password
              </label>
              <div className="relative">
                <span className="material-symbols-outlined text-on-surface-variant absolute left-3 top-2.5 text-[20px]">lock</span>
                <input
                  type="password"
                  required
                  autoFocus
                  value={adminPasswordInput}
                  onChange={e => { setAdminPasswordInput(e.target.value); setAdminLoginError(''); }}
                  placeholder="Enter admin password"
                  className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg pl-10 pr-4 py-2.5 text-on-surface placeholder:text-outline-variant focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all font-label-mono"
                />
              </div>
            </div>

            <button
              type="submit"
              className="w-full py-3 bg-primary hover:bg-primary/90 text-on-primary rounded-lg font-bold transition-colors text-body-md"
            >
              Sign In as Administrator
            </button>
          </form>

          <div className="pt-2 text-center">
            <Link href="/" className="text-body-md text-on-surface-variant hover:text-primary inline-flex items-center transition-colors">
              <span className="material-symbols-outlined text-[16px] mr-1">arrow_back</span> Return to Main Portal Choice
            </Link>
          </div>

        </div>
      </div>
    );
  }

  if (loading) {
    return (
      <div className="min-h-screen bg-white flex flex-col items-center justify-center text-slate-800 font-mono">
        <div className="w-8 h-8 border-2 border-slate-900 border-t-transparent rounded-full animate-spin mb-3" />
        <p className="text-xs text-slate-600">Loading Clinical Triage Telemetry...</p>
      </div>
    );
  }

  return (
    <div className="flex flex-col h-screen overflow-hidden bg-surface-container-low text-on-surface font-body-md text-body-md antialiased select-none">
      <Header
        patients={patients}
        strideCount={strideCount}
        onOpenAdminSidebar={() => setIsAdminSidebarOpen(true)}
        onReSyncClock={handleReSyncClock}
        onToggleArchitecture={() => setShowArchitecture(!showArchitecture)}
        isArchitectureOpen={showArchitecture}
      />
      
      <main className="flex-1 overflow-y-auto bg-surface-container-low pt-4 relative">
        {!dismissAlertBar && (
          <CriticalAlertBar
            criticalPatients={criticalPatients}
            onSelectPatient={(id) => setSelectedPatientId(id)}
            onDismiss={() => setDismissAlertBar(true)}
          />
        )}

        {/* Slide / Block Toggle for System Architecture & Extracted 9 Parameters */}
        {showArchitecture && (
          <div className="max-w-7xl mx-auto w-full px-6 pt-6 animate-in fade-in slide-in-from-top-4">
            <IcuArchitectureBlock />
          </div>
        )}

        <div className="flex-1 mt-6">
          <TriageTable
            patients={patients}
            onSelectPatient={(patient) => setSelectedPatientId(patient.profile.id)}
          />
        </div>
      </main>

      <PatientDrawer
        patient={selectedPatient}
        onClose={() => setSelectedPatientId(null)}
      />

      <AdminSidebar
        patients={patients}
        isOpen={isAdminSidebarOpen}
        onClose={() => setIsAdminSidebarOpen(false)}
      />
    </div>
  );
}
