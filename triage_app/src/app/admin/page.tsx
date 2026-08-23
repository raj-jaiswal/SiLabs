'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { AdminSidebar } from '@/components/AdminSidebar';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';
import { Shield, Lock, Mail, ArrowLeft, ShieldAlert, HeartPulse } from 'lucide-react';
import Link from 'next/link';

export default function AdminPage() {
  const { currentUser, login } = useAuth();
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);
  const [isAdminSidebarOpen, setIsAdminSidebarOpen] = useState<boolean>(true);

  // Admin Login State for /admin
  const [adminPasswordInput, setAdminPasswordInput] = useState('');
  const [adminLoginError, setAdminLoginError] = useState('');

  // 1. Fetch patient data from API on mount
  useEffect(() => {
    async function loadPatients() {
      try {
        const res = await fetch('/api/patients');
        const data = await res.json();
        if (data.error) {
          setError(data.error);
        } else if (data.patients) {
          setPatients(data.patients);
        }
      } catch (err: any) {
        setError(err.message || 'Failed to load patient telemetry');
      } finally {
        setLoading(false);
      }
    }
    loadPatients();
  }, []);

  // 2. Master Synchronized 5-Second Stride Clock Loop
  useEffect(() => {
    if (patients.length === 0 || !currentUser) return;

    let masterStartTime = localStorage.getItem('silabs_master_start_time');
    if (!masterStartTime) {
      masterStartTime = String(Date.now());
      localStorage.setItem('silabs_master_start_time', masterStartTime);
    }
    const startTimeNum = parseInt(masterStartTime, 10);

    const syncTelemetry = () => {
      const elapsedMs = Math.max(0, Date.now() - startTimeNum);
      const currentStride = Math.floor(elapsedMs / 5000) + 1;
      setStrideCount(currentStride);

      setPatients(prevPatients =>
        prevPatients.map(patient => {
          if (!patient.vitalsHistory || patient.vitalsHistory.length === 0) return patient;
          const targetIndex = (currentStride - 1) % patient.vitalsHistory.length;
          const currentFrame = patient.vitalsHistory[targetIndex];
          const riskEval = evaluatePatientRisk(patient.vitalsHistory, targetIndex);

          return {
            ...patient,
            currentFrameIndex: targetIndex,
            currentFrame,
            hypotension: riskEval.hypotension,
            hypoxia: riskEval.hypoxia,
            tachycardia: riskEval.tachycardia,
            triageRank: riskEval.triageRank,
            activeEventCount: riskEval.activeEventCount,
          };
        })
      );
    };

    syncTelemetry();
    const interval = setInterval(syncTelemetry, 1000);
    return () => clearInterval(interval);
  }, [patients.length, currentUser]);

  const handleAdminLoginSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (login('admin@hospital.com', adminPasswordInput)) {
      setAdminLoginError('');
      setAdminPasswordInput('');
    } else {
      setAdminLoginError('Incorrect Administrator password.');
    }
  };

  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  // Gated Auth: If not logged in as Admin, prompt for Admin password
  if (!currentUser || currentUser.role !== 'ADMIN') {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
        <div className="w-full max-w-md bg-slate-900 border border-rose-950 rounded-2xl p-8 shadow-2xl space-y-6">
          
          <div className="text-center space-y-2">
            <div className="inline-flex p-3 bg-rose-950/80 rounded-xl border border-rose-800 text-rose-300 mb-1">
              <Shield className="w-7 h-7" />
            </div>
            <h1 className="text-xl font-bold tracking-tight uppercase text-rose-100">Administrator Login</h1>
            <p className="text-xs text-slate-400">Enter Admin password to access `/admin` control panel</p>
          </div>

          <div className="p-3 bg-rose-950/40 border border-rose-900 rounded-lg flex items-center space-x-3 text-xs">
            <div className="p-2 bg-rose-900/60 rounded text-rose-300">
              <Mail className="w-4 h-4" />
            </div>
            <div>
              <div className="font-bold text-rose-200">Admin (`admin@hospital.com`)</div>
              <div className="text-[11px] text-rose-400/80">System Administrator Account</div>
            </div>
          </div>

          <form onSubmit={handleAdminLoginSubmit} className="space-y-4 text-xs">
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
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-rose-500"
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
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center text-slate-300">
        <div className="w-10 h-10 border-4 border-sky-500 border-t-transparent rounded-full animate-spin mb-4" />
        <p className="text-sm font-medium text-slate-400">Initializing Admin Telemetry &amp; Dispatch Console...</p>
      </div>
    );
  }

  const handleReSyncClock = () => {
    const now = String(Date.now());
    localStorage.setItem('silabs_master_start_time', now);
    window.dispatchEvent(new Event('storage'));
    setStrideCount(1);
  };

  return (
    <main className="min-h-screen bg-slate-950 flex flex-col">
      {/* Route Indicator Bar */}
      <div className="bg-rose-950 text-rose-200 text-xs py-1 px-6 border-b border-rose-900 flex items-center justify-between font-mono">
        <div className="flex items-center space-x-2">
          <Shield className="w-3.5 h-3.5 text-rose-400" />
          <span className="font-bold">ADMIN PORTAL ROUTE: /admin</span>
        </div>
        <span>Master Control &amp; Dispatch Active</span>
      </div>

      {/* Logged-In Administrator Identity Banner */}
      <div className="bg-rose-950/90 border-b border-rose-800/80 px-6 py-2.5 flex items-center justify-between shadow-inner">
        <div className="flex items-center space-x-3 text-xs">
          <div className="p-1.5 bg-rose-900/90 rounded-lg border border-rose-700 text-rose-300 font-bold animate-pulse">
            <Shield className="w-4 h-4" />
          </div>
          <div>
            <span className="text-slate-400 text-xs uppercase font-semibold mr-1.5">Active Admin Account:</span>
            <span className="font-black text-rose-200 text-sm tracking-wide bg-rose-900/60 px-2.5 py-1 rounded-md border border-rose-700">
              {currentUser.name} (SYSTEM ADMINISTRATOR)
            </span>
            <span className="text-slate-400 font-mono text-xs ml-2">({currentUser.email})</span>
          </div>
        </div>
        <div className="text-xs text-rose-300 font-bold bg-rose-900/60 px-2.5 py-1 rounded border border-rose-700 flex items-center space-x-1.5">
          <span className="w-2 h-2 rounded-full bg-rose-400 animate-ping" />
          <span>ADMIN MASTER CONTROL ACTIVE</span>
        </div>
      </div>

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

      <div className="flex-1">
        <TriageTable
          patients={patients}
          onSelectPatient={(patient) => setSelectedPatientId(patient.profile.id)}
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
    </main>
  );
}
