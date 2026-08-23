'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';

export default function Home() {
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);

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

  // 2. Automatic Continuous 5-Second Stride Loop
  useEffect(() => {
    if (patients.length === 0) return;

    const interval = setInterval(() => {
      setStrideCount(prev => prev + 1);

      setPatients(prevPatients =>
        prevPatients.map(patient => {
          if (!patient.vitalsHistory || patient.vitalsHistory.length === 0) return patient;
          const nextIndex = (patient.currentFrameIndex + 1) % patient.vitalsHistory.length;
          const currentFrame = patient.vitalsHistory[nextIndex];
          const riskEval = evaluatePatientRisk(patient.vitalsHistory, nextIndex);

          return {
            ...patient,
            currentFrameIndex: nextIndex,
            currentFrame,
            hypotension: riskEval.hypotension,
            hypoxia: riskEval.hypoxia,
            tachycardia: riskEval.tachycardia,
            triageRank: riskEval.triageRank,
            activeEventCount: riskEval.activeEventCount,
          };
        })
      );
    }, 5000); // 5-second stride update

    return () => clearInterval(interval);
  }, [patients.length]);

  // Derived currently selected patient (keeps drawer synced during live strides)
  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  // Derived list of P1 Critical patients
  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  if (loading) {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center text-slate-300">
        <div className="w-10 h-10 border-4 border-sky-500 border-t-transparent rounded-full animate-spin mb-4" />
        <p className="text-sm font-medium text-slate-400">Loading Patient Telemetry &amp; Initializing Triage Engine...</p>
      </div>
    );
  }

  if (error) {
    return (
      <div className="min-h-screen bg-slate-950 flex items-center justify-center p-6">
        <div className="bg-rose-950/60 border border-rose-900 text-rose-200 rounded-xl p-6 max-w-md text-center">
          <h2 className="text-lg font-bold mb-2">Failed to Load Telemetry</h2>
          <p className="text-xs text-rose-300/80 mb-4">{error}</p>
        </div>
      </div>
    );
  }

  return (
    <main className="min-h-screen bg-slate-950 flex flex-col">
      <Header patients={patients} strideCount={strideCount} />
      
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
    </main>
  );
}
