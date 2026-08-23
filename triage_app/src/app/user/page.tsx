'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { DispatchNotificationModal } from '@/components/DispatchNotificationModal';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';
import { UserAccount } from '@/types/auth';
import { evaluatePatientRisk } from '@/utils/triageEngine';
import { User, Lock, ArrowLeft, ShieldAlert, ChevronRight, HeartPulse } from 'lucide-react';
import Link from 'next/link';

export default function UserPage() {
  const { currentUser, users, login } = useAuth();
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);

  // User Selection & Password Login State for /user
  const [selectedStaffUser, setSelectedStaffUser] = useState<UserAccount | null>(null);
  const [passwordInput, setPasswordInput] = useState('');
  const [loginError, setLoginError] = useState('');

  // Filter staff users (non-admin)
  const staffUsers = users.filter(u => u.role !== 'ADMIN');

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

  const handleStaffLoginSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!selectedStaffUser) return;
    if (login(selectedStaffUser.email, passwordInput)) {
      setLoginError('');
      setPasswordInput('');
    } else {
      setLoginError(`Incorrect password for ${selectedStaffUser.name}.`);
    }
  };

  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  // Gated Auth: If not logged in, prompt to select staff user & enter password
  if (!currentUser) {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
        <div className="w-full max-w-md bg-slate-900 border border-slate-800 rounded-2xl p-8 shadow-2xl space-y-6">
          
          <div className="text-center space-y-2">
            <div className="inline-flex p-3 bg-slate-800 rounded-xl border border-slate-700 text-sky-400 mb-1">
              <HeartPulse className="w-7 h-7 animate-pulse" />
            </div>
            <h1 className="text-xl font-bold tracking-tight uppercase text-slate-100">Staff User Login</h1>
            <p className="text-xs text-slate-400">Select your account and enter your password to access `/user`</p>
          </div>

          {!selectedStaffUser ? (
            /* Step 1: Select Staff User Account */
            <div className="space-y-3 pt-2">
              <div className="text-xs font-semibold text-slate-400 uppercase tracking-wider mb-2">
                Select Which User You Are:
              </div>
              
              <div className="grid grid-cols-1 gap-2">
                {staffUsers.map((user) => (
                  <button
                    key={user.id}
                    onClick={() => { setSelectedStaffUser(user); setLoginError(''); setPasswordInput(''); }}
                    className="w-full p-3 bg-slate-950/80 hover:bg-slate-800 border border-slate-800 hover:border-sky-600 rounded-xl text-left transition-all flex items-center justify-between group"
                  >
                    <div className="flex items-center space-x-3">
                      <div className="p-2 bg-slate-900 rounded-lg border border-slate-700 text-sky-400">
                        <User className="w-4 h-4" />
                      </div>
                      <div>
                        <div className="font-bold text-slate-100 group-hover:text-sky-400 transition-colors text-sm">
                          {user.name}
                        </div>
                        <div className="text-[11px] text-slate-400">{user.email}</div>
                      </div>
                    </div>
                    <ChevronRight className="w-4 h-4 text-slate-500 group-hover:text-sky-400 group-hover:translate-x-1 transition-all" />
                  </button>
                ))}
              </div>

              <div className="pt-2 text-center">
                <Link href="/" className="text-xs text-slate-400 hover:text-slate-200 inline-flex items-center">
                  <ArrowLeft className="w-3.5 h-3.5 mr-1" /> Return to Main Portal Choice
                </Link>
              </div>
            </div>
          ) : (
            /* Step 2: Enter Password for Selected User */
            <div className="space-y-4 pt-2">
              <button
                onClick={() => setSelectedStaffUser(null)}
                className="inline-flex items-center text-xs font-semibold text-slate-400 hover:text-slate-200 transition-colors"
              >
                <ArrowLeft className="w-3.5 h-3.5 mr-1" /> Change User Selection
              </button>

              <div className="p-3 bg-sky-950/60 border border-sky-800 rounded-lg flex items-center space-x-3">
                <div className="p-2 bg-sky-900 rounded border border-sky-700 text-sky-300">
                  <User className="w-4 h-4" />
                </div>
                <div>
                  <div className="font-bold text-sky-200 text-sm">{selectedStaffUser.name}</div>
                  <div className="text-[11px] text-sky-400">{selectedStaffUser.email}</div>
                </div>
              </div>

              <form onSubmit={handleStaffLoginSubmit} className="space-y-4 text-xs">
                {loginError && (
                  <div className="p-3 bg-rose-950/80 border border-rose-800 text-rose-200 rounded-lg text-center font-medium flex items-center justify-center space-x-2">
                    <ShieldAlert className="w-4 h-4 text-rose-400" />
                    <span>{loginError}</span>
                  </div>
                )}

                <div>
                  <label className="block text-slate-300 font-medium mb-1.5">
                    Password for {selectedStaffUser.name}
                  </label>
                  <div className="relative">
                    <Lock className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                    <input
                      type="password"
                      required
                      autoFocus
                      value={passwordInput}
                      onChange={e => { setPasswordInput(e.target.value); setLoginError(''); }}
                      placeholder="Enter password"
                      className="w-full bg-slate-950 border border-slate-800 rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-sky-500"
                    />
                  </div>
                </div>

                <button
                  type="submit"
                  className="w-full py-3 bg-sky-600 hover:bg-sky-500 text-white font-bold rounded-lg transition-colors text-sm shadow-lg shadow-sky-950"
                >
                  Sign In as {selectedStaffUser.name}
                </button>
              </form>
            </div>
          )}

        </div>
      </div>
    );
  }

  if (loading) {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center text-slate-300">
        <div className="w-10 h-10 border-4 border-sky-500 border-t-transparent rounded-full animate-spin mb-4" />
        <p className="text-sm font-medium text-slate-400">Connecting to Triage Telemetry &amp; Master Clock...</p>
      </div>
    );
  }

  return (
    <main className="min-h-screen bg-slate-950 flex flex-col">
      {/* Route Indicator Bar */}
      <div className="bg-sky-950 text-sky-200 text-xs py-1 px-6 border-b border-sky-900 flex items-center justify-between font-mono">
        <div className="flex items-center space-x-2">
          <User className="w-3.5 h-3.5 text-sky-400" />
          <span className="font-bold">STAFF USER PORTAL ROUTE: /user</span>
        </div>
        <span>Telemetry Monitoring &amp; Patient Dispatch Alerts Active</span>
      </div>

      <Header
        patients={patients}
        strideCount={strideCount}
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

      <DispatchNotificationModal
        onInspectPatient={(patientId) => setSelectedPatientId(patientId)}
      />
    </main>
  );
}
