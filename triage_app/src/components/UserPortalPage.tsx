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
import { User, Lock, ArrowLeft, ShieldAlert, Activity } from 'lucide-react';
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
      <div className="min-h-screen bg-white flex flex-col items-center justify-center p-6 text-slate-900 font-sans select-none">
        <div className="w-full max-w-md bg-white border border-slate-200 rounded-xl p-8 shadow-sm space-y-6">
          
          <div className="text-center space-y-2 select-none">
            <div className="inline-flex p-3 bg-slate-100 rounded-xl border border-slate-300 text-slate-900 mb-1">
              <Activity className="w-6 h-6" />
            </div>
            <h1 className="text-lg font-bold tracking-tight uppercase text-slate-900 font-sans">
              Staff User Login
            </h1>
            <p className="text-xs text-slate-600">Type your User ID (e.g. user1, user2, user3) and password</p>
          </div>

          <form onSubmit={handleStaffLoginSubmit} className="space-y-4 text-xs font-mono pt-2">
            {loginError && (
              <div className="p-3 bg-red-50 border border-red-200 text-red-800 rounded-lg text-center font-semibold flex items-center justify-center space-x-2">
                <ShieldAlert className="w-4 h-4 text-red-600" />
                <span>{loginError}</span>
              </div>
            )}

            <div>
              <label className="block text-slate-700 font-medium mb-1.5 font-sans">User ID</label>
              <div className="relative font-mono">
                <User className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                <input
                  type="text"
                  required
                  autoFocus
                  value={userIdInput}
                  onChange={e => { setUserIdInput(e.target.value); setLoginError(''); }}
                  placeholder="Type User ID (e.g. user1, user2, user3)"
                  className="w-full bg-white border border-slate-300 rounded-lg pl-9 pr-4 py-2.5 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
                />
              </div>
            </div>

            <div>
              <label className="block text-slate-700 font-medium mb-1.5 font-sans">Password</label>
              <div className="relative font-mono">
                <Lock className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                <input
                  type="password"
                  required
                  value={passwordInput}
                  onChange={e => { setPasswordInput(e.target.value); setLoginError(''); }}
                  placeholder="Enter password"
                  className="w-full bg-white border border-slate-300 rounded-lg pl-9 pr-4 py-2.5 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
                />
              </div>
            </div>

            <button
              type="submit"
              className="w-full py-2.5 bg-slate-900 hover:bg-black text-white font-semibold rounded-lg transition-colors text-xs font-sans shadow-sm"
            >
              Sign In as {userIdInput || 'User'}
            </button>
          </form>

          <div className="pt-2 text-center border-t border-slate-200">
            <Link href="/" className="text-xs text-slate-600 hover:text-slate-900 inline-flex items-center">
              <ArrowLeft className="w-3.5 h-3.5 mr-1" /> Return to Main Portal Choice
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
        <p className="text-xs text-slate-600">Connecting to Triage Telemetry...</p>
      </div>
    );
  }

  return (
    <main className="min-h-screen bg-white flex flex-col font-sans text-slate-900">
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
