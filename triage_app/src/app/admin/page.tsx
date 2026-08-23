'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { NavigationRail } from '@/components/NavigationRail';
import { TemporalForecastingCanvas } from '@/components/TemporalForecastingCanvas';
import { PatientTrajectoryList } from '@/components/PatientTrajectoryList';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { AdminSidebar } from '@/components/AdminSidebar';
import { ClinicalIntelligenceStream } from '@/components/ClinicalIntelligenceStream';
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
  const [activeTab, setActiveTab] = useState<string>('forecast'); // 'forecast' | 'trajectories' | 'esp32'

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
              triageRank: riskEval.triageRank,
              activeEventCount: riskEval.activeEventCount,
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
      <div className="min-h-screen bg-[#080B10] flex flex-col items-center justify-center p-6 text-[#F5F7FA]">
        <div className="w-full max-w-md bg-[#0D1117] border border-rose-950/80 rounded-2xl p-8 shadow-2xl space-y-6">
          
          <div className="text-center space-y-2 select-none">
            <div className="inline-flex p-3 bg-rose-950/80 rounded-xl border border-rose-800 text-rose-300 mb-1">
              <Shield className="w-7 h-7" />
            </div>
            <h1 className="text-xl font-bold tracking-tight uppercase text-rose-100 font-mono">Administrator Login</h1>
            <p className="text-xs text-[#9AA4B2]">Enter Admin password to access `/admin` control panel</p>
          </div>

          <div className="p-3 bg-rose-950/40 border border-rose-900 rounded-lg flex items-center space-x-3 text-xs font-mono">
            <div className="p-2 bg-rose-900/60 rounded text-rose-300">
              <Mail className="w-4 h-4" />
            </div>
            <div>
              <div className="font-bold text-rose-200">Admin (`admin@hospital.com`)</div>
              <div className="text-[11px] text-rose-400/80">System Administrator Account</div>
            </div>
          </div>

          <form onSubmit={handleAdminLoginSubmit} className="space-y-4 text-xs font-mono">
            {adminLoginError && (
              <div className="p-3 bg-rose-950/80 border border-rose-800 text-rose-200 rounded-lg text-center font-medium flex items-center justify-center space-x-2">
                <ShieldAlert className="w-4 h-4 text-rose-400" />
                <span>{adminLoginError}</span>
              </div>
            )}

            <div>
              <label className="block text-slate-300 font-medium mb-1.5">
                Admin Password
              </label>
              <div className="relative">
                <Lock className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                <input
                  type="password"
                  required
                  autoFocus
                  value={adminPasswordInput}
                  onChange={e => { setAdminPasswordInput(e.target.value); setAdminLoginError(''); }}
                  placeholder="Enter admin password"
                  className="w-full bg-[#080B10] border border-[#1E2631] rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-rose-500"
                />
              </div>
            </div>

            <button
              type="submit"
              className="w-full py-3 bg-rose-600 hover:bg-rose-500 text-white font-bold rounded-lg transition-colors text-sm shadow-lg shadow-rose-950"
            >
              Sign In as Administrator
            </button>
          </form>

          <div className="pt-2 text-center">
            <Link href="/" className="text-xs text-slate-400 hover:text-slate-200 inline-flex items-center">
              <ArrowLeft className="w-3.5 h-3.5 mr-1" /> Return to Main Portal Choice
            </Link>
          </div>

        </div>
      </div>
    );
  }

  if (loading) {
    return (
      <div className="min-h-screen bg-[#080B10] flex flex-col items-center justify-center text-slate-300">
        <div className="w-10 h-10 border-4 border-cyan-500 border-t-transparent rounded-full animate-spin mb-4" />
        <p className="text-sm font-medium text-[#9AA4B2] font-mono">Initializing Hospital Intelligence &amp; Command Center...</p>
      </div>
    );
  }

  return (
    <div className="min-h-screen bg-[#080B10] text-[#F5F7FA] flex flex-col">
      {/* Route Indicator Bar */}
      <div className="bg-rose-950/80 text-rose-200 text-xs py-1 px-6 border-b border-rose-900 flex items-center justify-between font-mono select-none">
        <div className="flex items-center space-x-2">
          <Shield className="w-3.5 h-3.5 text-rose-400" />
          <span className="font-bold">ADMIN PORTAL ROUTE: /admin</span>
        </div>
        <span>Master Command &amp; Dispatch Console Active</span>
      </div>

      {/* Main Command Center Header */}
      <Header
        patients={patients}
        strideCount={strideCount}
        onOpenAdminSidebar={() => setIsAdminSidebarOpen(true)}
        onReSyncClock={handleReSyncClock}
      />

      {!dismissAlertBar && (
        <CriticalAlertBar
          criticalPatients={criticalPatients}
          onSelectPatient={(id) => setSelectedPatientId(id)}
          onDismiss={() => setDismissAlertBar(true)}
        />
      )}

      {/* 3-Column Wide Desktop Command-Center Composition */}
      <div className="flex-1 flex overflow-hidden">
        {/* 1. Left Narrow Navigation Rail */}
        <NavigationRail
          activeTab={activeTab}
          onSelectTab={(t) => setActiveTab(t)}
          onOpenAdminSidebar={() => setIsAdminSidebarOpen(true)}
          isAdmin={true}
        />

        {/* 2. Main Center Canvas */}
        <main className="flex-1 p-6 overflow-y-auto space-y-6">
          {/* Hero Temporal Forecasting Canvas */}
          <TemporalForecastingCanvas
            patients={patients}
            strideCount={strideCount}
          />

          {/* Horizontal Patient Trajectory Mission Control */}
          <PatientTrajectoryList
            patients={patients}
            onSelectPatient={(p) => setSelectedPatientId(p.profile.id)}
          />
        </main>

        {/* 3. Right Clinical Intelligence Stream Panel */}
        <ClinicalIntelligenceStream
          patients={patients}
          onSelectPatient={(id) => setSelectedPatientId(id)}
        />
      </div>

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
