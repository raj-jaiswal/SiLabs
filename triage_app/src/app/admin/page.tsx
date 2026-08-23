'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { AdminSidebar } from '@/components/AdminSidebar';
import { LoginPage } from '@/components/LoginPage';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';
import { Shield, ArrowLeft } from 'lucide-react';
import Link from 'next/link';

export default function AdminPage() {
  const { currentUser } = useAuth();
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);
  const [isAdminSidebarOpen, setIsAdminSidebarOpen] = useState<boolean>(true); // Open by default for Admin

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

  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  // Gated Auth: If not logged in as Admin, show login prompt
  if (!currentUser || currentUser.role !== 'ADMIN') {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
        <div className="w-full max-w-md bg-slate-900 border border-rose-950 rounded-2xl p-8 shadow-2xl text-center space-y-4">
          <div className="inline-flex p-3 bg-rose-950/80 rounded-xl border border-rose-800 text-rose-300">
            <Shield className="w-8 h-8" />
          </div>
          <h1 className="text-xl font-bold text-slate-100 uppercase">Admin Access Required</h1>
          <p className="text-xs text-slate-400">
            You must be logged in as an Administrator (`admin@hospital.com`) to access `/admin`.
          </p>
          <div className="pt-2 flex flex-col space-y-2">
            <Link
              href="/"
              className="py-2.5 bg-sky-600 hover:bg-sky-500 font-bold text-white rounded-lg transition-colors text-xs inline-flex items-center justify-center"
            >
              <ArrowLeft className="w-4 h-4 mr-1.5" /> Return to Login Portal
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

      <Header
        patients={patients}
        strideCount={strideCount}
        onOpenAdminSidebar={() => setIsAdminSidebarOpen(true)}
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
