'use client';

import React, { useEffect, useState } from 'react';
import { useRouter } from 'next/navigation';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { DispatchNotificationModal } from '@/components/DispatchNotificationModal';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';
import { User, Lock, ArrowLeft, ShieldAlert, HeartPulse } from 'lucide-react';
import Link from 'next/link';

interface UserPortalPageProps {
  targetSlug?: string; // e.g. 'user1', 'user2', 'user3', 'user4'
}

export const UserPortalPage: React.FC<UserPortalPageProps> = ({ targetSlug = 'user1' }) => {
  const { currentUser, login } = useAuth();
  const router = useRouter();
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);

  // Manual typed login inputs for staff users (no quick buttons)
  const [userIdInput, setUserIdInput] = useState(targetSlug);
  const [passwordInput, setPasswordInput] = useState('');
  const [loginError, setLoginError] = useState('');

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

  const handleStaffLoginSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!userIdInput.trim()) return;

    if (login(userIdInput, passwordInput)) {
      setLoginError('');
      setPasswordInput('');
      const cleanSlug = userIdInput.trim().toLowerCase().replace(/\s+/g, '');
      const userNum = cleanSlug.replace(/\D/g, '');
      const routeSlug = userNum ? `user${userNum}` : cleanSlug;
      router.push(`/${routeSlug}`);
    } else {
      setLoginError(`Invalid User ID or Password for "${userIdInput}". Please try again.`);
    }
  };

  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  // Gated Auth: If not logged in, prompt to TYPE User ID & Password manually
  if (!currentUser) {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
        <div className="w-full max-w-md bg-slate-900 border border-slate-800 rounded-2xl p-8 shadow-2xl space-y-6">
          
          <div className="text-center space-y-2">
            <div className="inline-flex p-3 bg-slate-800 rounded-xl border border-slate-700 text-sky-400 mb-1">
              <HeartPulse className="w-7 h-7 animate-pulse text-sky-400" />
            </div>
            <h1 className="text-xl font-bold tracking-tight uppercase text-slate-100">
              Staff User Login
            </h1>
            <p className="text-xs text-slate-400">Type your User ID (e.g. user1, user2, user3) and password</p>
          </div>

          <form onSubmit={handleStaffLoginSubmit} className="space-y-4 text-xs pt-2">
            {loginError && (
              <div className="p-3 bg-rose-950/80 border border-rose-800 text-rose-200 rounded-lg text-center font-medium flex items-center justify-center space-x-2">
                <ShieldAlert className="w-4 h-4 text-rose-400" />
                <span>{loginError}</span>
              </div>
            )}

            <div>
              <label className="block text-slate-300 font-medium mb-1.5">User ID</label>
              <div className="relative">
                <User className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                <input
                  type="text"
                  required
                  autoFocus
                  value={userIdInput}
                  onChange={e => { setUserIdInput(e.target.value); setLoginError(''); }}
                  placeholder="Type User ID (e.g. user1, user2, user3, user4)"
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-sky-500"
                />
              </div>
            </div>

            <div>
              <label className="block text-slate-300 font-medium mb-1.5">Password</label>
              <div className="relative">
                <Lock className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                <input
                  type="password"
                  required
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
              Sign In as {userIdInput || 'User'}
            </button>
          </form>

          <div className="pt-2 text-center border-t border-slate-800">
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
        <p className="text-sm font-medium text-slate-400">Connecting to Triage Telemetry &amp; Master Clock...</p>
      </div>
    );
  }

  const userNumber = currentUser.name.replace(/\D/g, '') || '1';
  const currentSlug = `user${userNumber}`;

  return (
    <main className="min-h-screen bg-slate-950 flex flex-col">
      {/* Route Indicator Bar */}
      <div className="bg-sky-950 text-sky-200 text-xs py-1 px-6 border-b border-sky-900 flex items-center justify-between font-mono">
        <div className="flex items-center space-x-2">
          <User className="w-3.5 h-3.5 text-sky-400" />
          <span className="font-bold">STAFF USER PORTAL ROUTE: /{currentSlug}</span>
        </div>
        <span>Telemetry Monitoring &amp; Patient Dispatch Alerts Active</span>
      </div>

      {/* Logged-In Staff User Identity Banner */}
      <div className="bg-sky-950/90 border-b border-sky-800/80 px-6 py-2.5 flex items-center justify-between shadow-inner">
        <div className="flex items-center space-x-3 text-xs">
          <div className="p-1.5 bg-sky-900/90 rounded-lg border border-sky-700 text-sky-300 font-bold animate-pulse">
            <User className="w-4 h-4" />
          </div>
          <div>
            <span className="text-slate-400 text-xs uppercase font-semibold mr-1.5">Active Staff User:</span>
            <span className="font-black text-sky-200 text-sm tracking-wide bg-sky-900/60 px-2.5 py-1 rounded-md border border-sky-700">
              {currentUser.name}
            </span>
            <span className="text-slate-400 font-mono text-xs ml-2">({currentUser.email})</span>
          </div>
        </div>
        <div className="text-xs text-emerald-400 font-bold bg-emerald-950/80 px-2.5 py-1 rounded border border-emerald-800 flex items-center space-x-1.5">
          <span className="w-2 h-2 rounded-full bg-emerald-400 animate-ping" />
          <span>CONNECTED AS {currentUser.name.toUpperCase()} ON /{currentSlug}</span>
        </div>
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
};

export default UserPortalPage;
