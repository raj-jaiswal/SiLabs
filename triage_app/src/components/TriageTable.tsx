'use client';

import React from 'react';
import { PatientState, TriageRank, IndicatorRisk } from '../types/patient';

interface TriageTableProps {
  patients: PatientState[];
  onSelectPatient: (patient: PatientState) => void;
}

export const TriageTable: React.FC<TriageTableProps> = ({ patients, onSelectPatient }) => {
  // Sort by Triage Rank ascending
  const sortedPatients = [...patients].sort((a, b) => {
    const rankOrder: Record<TriageRank, number> = {
      P1_CRITICAL: 1,
      P2_HIGH: 2,
      P3_MODERATE: 3,
      P4_STABLE: 4,
    };
    const rA = rankOrder[a.triageRank] || 4;
    const rB = rankOrder[b.triageRank] || 4;
    if (rA !== rB) return rA - rB;
    return b.activeEventCount - a.activeEventCount;
  });

  const p1Count = patients.filter(p => p.triageRank === 'P1_CRITICAL').length;
  const p2Count = patients.filter(p => p.triageRank === 'P2_HIGH').length;
  const p3Count = patients.filter(p => p.triageRank === 'P3_MODERATE').length;
  const p4Count = patients.filter(p => p.triageRank === 'P4_STABLE').length;

  const renderVitalCard = (risk: IndicatorRisk, label: string, isP1: boolean) => {
    const isAlert = risk.status === 'ACTIVE_ALERT';
    const isElevated = risk.status === 'ELEVATED_RISK';

    const labelColor = isAlert ? 'text-error' : 'text-on-surface-variant';
    const valueColor = isAlert ? 'text-error' : 'text-on-surface';
    const barBgColor = isAlert ? 'bg-error-container' : 'bg-surface-container-high';
    const barFillColor = isAlert ? 'bg-error' : isElevated ? 'bg-tertiary-container' : 'bg-primary-container';
    
    return (
      <div className={isP1 && !isAlert ? 'opacity-90' : ''}>
        <p className={`text-label-mono font-label-mono ${labelColor} mb-1 uppercase text-[10px] ${isAlert ? 'font-bold' : ''} flex items-center gap-1`}>
          {isAlert && <span className="material-symbols-outlined text-[14px]">warning</span>}
          {label}
        </p>
        <div className="flex items-end gap-2">
          <span className={`text-display-vitals font-display-vitals text-[32px] md:text-[24px] lg:text-[32px] leading-none ${valueColor}`}>
            {risk.currentValue.toFixed(1)}
          </span>
          <span className="text-body-md font-body-md text-on-surface-variant mb-1">
            {risk.unit}
          </span>
        </div>
        <div className={`mt-2 h-1.5 w-full ${barBgColor} rounded-full overflow-hidden`}>
          <div className={`h-full ${barFillColor} rounded-full transition-all duration-300`} style={{ width: `${Math.max(5, risk.probability)}%` }}></div>
        </div>
        <p className={`text-label-mono font-label-mono ${labelColor} mt-1 text-[10px] text-right ${isAlert ? 'font-bold' : ''}`}>
          {risk.probability}% risk
        </p>
      </div>
    );
  };

  const getRankStyles = (rank: TriageRank) => {
    switch(rank) {
      case 'P1_CRITICAL':
        return {
          cardBorder: 'border-error/30 hover:border-error/60 shadow-[0_4px_12px_rgba(186,26,26,0.05)]',
          stripe: 'bg-error',
          badge: 'bg-error/10 text-error border-error/20',
          badgeText: 'P1 CRITICAL',
          leftBg: 'bg-error-container/10',
        };
      case 'P2_HIGH':
        return {
          cardBorder: 'border-outline-variant hover:border-outline shadow-sm',
          stripe: 'bg-tertiary-container',
          badge: 'bg-tertiary-container/5 text-tertiary-container border-tertiary-container/30',
          badgeText: 'P2 HIGH',
          leftBg: 'bg-surface-bright',
        };
      case 'P3_MODERATE':
        return {
          cardBorder: 'border-outline-variant hover:border-outline shadow-sm',
          stripe: 'bg-secondary',
          badge: 'bg-secondary/5 text-secondary border-secondary/30',
          badgeText: 'P3 MODERATE',
          leftBg: 'bg-surface-bright',
        };
      case 'P4_STABLE':
      default:
        return {
          cardBorder: 'border-outline-variant hover:border-outline shadow-sm opacity-90',
          stripe: 'bg-primary-container',
          badge: 'bg-primary-container/5 text-primary-container border-primary-container/30',
          badgeText: 'P4 STABLE',
          leftBg: 'bg-surface-bright',
        };
    }
  };

  return (
    <div className="max-w-7xl mx-auto px-6 pb-margin">
      {/* Page Header / Context */}
      <div className="flex flex-col md:flex-row justify-between items-start md:items-end mb-6 gap-4">
        <div>
          <h2 className="text-headline-lg font-headline-lg text-on-surface">Priority Triage Queue</h2>
          <p className="text-on-surface-variant text-body-md font-body-md mt-1">
            Auto-sorted by real-time telemetry risk score. Showing {sortedPatients.length} active patients.
          </p>
        </div>
        <div className="flex flex-wrap gap-3">
          <div className="bg-surface-container-highest px-4 py-2 rounded-lg flex items-center gap-4 border border-outline-variant/50 shrink-0">
            <div className="flex items-center gap-1.5"><span className="w-2 h-2 rounded-full bg-error"></span><span className="text-label-mono font-label-mono text-on-surface-variant">P1: {p1Count}</span></div>
            <div className="flex items-center gap-1.5"><span className="w-2 h-2 rounded-full bg-tertiary-container"></span><span className="text-label-mono font-label-mono text-on-surface-variant">P2: {p2Count}</span></div>
            <div className="flex items-center gap-1.5"><span className="w-2 h-2 rounded-full bg-secondary"></span><span className="text-label-mono font-label-mono text-on-surface-variant">P3: {p3Count}</span></div>
            <div className="flex items-center gap-1.5"><span className="w-2 h-2 rounded-full bg-primary-container"></span><span className="text-label-mono font-label-mono text-on-surface-variant">P4: {p4Count}</span></div>
          </div>
        </div>
      </div>

      {/* Bento Grid / Card Layout */}
      <div className="grid grid-cols-12 gap-gutter">
        {sortedPatients.map(patient => {
          const { profile, hypotension, hypoxia, tachycardia, triageRank } = patient;
          const styles = getRankStyles(triageRank);
          const isP1 = triageRank === 'P1_CRITICAL';
          const isStale = (profile.isEsp32Live || profile.id === 'PATIENT-000') && profile.isStale;

          return (
            <div key={profile.id} className={`col-span-12 bg-surface-container-lowest rounded-xl border ${styles.cardBorder} overflow-hidden flex flex-col md:flex-row relative group transition-colors`}>
              <div className={`absolute left-0 top-0 bottom-0 w-1.5 ${styles.stripe}`}></div>

              {/* Patient Identity Profile */}
              <div className={`p-6 md:w-[30%] border-b md:border-b-0 md:border-r border-outline-variant/30 flex flex-col justify-center ${styles.leftBg} relative`}>
                {isStale && (
                  <div className="absolute inset-0 bg-surface-container/50 backdrop-blur-[1px] z-10 flex items-center justify-center flex-col gap-2">
                    <div className="bg-surface-container text-on-surface border border-outline-variant px-3 py-1.5 rounded-md flex items-center gap-2 text-label-mono font-label-mono font-bold shadow-sm">
                      <span className="material-symbols-outlined text-tertiary-container text-[16px]">warning</span> NO DATA (&gt;20s)
                    </div>
                  </div>
                )}
                
                <div className={`flex items-start justify-between mb-3 ${isStale ? 'opacity-50' : ''}`}>
                  <span className={`${styles.badge} border px-2 py-1 rounded text-label-mono font-label-mono font-bold tracking-widest text-[10px]`}>
                    {styles.badgeText}
                  </span>
                  <span className="text-on-surface-variant text-label-mono font-label-mono">
                    {profile.isEsp32Live ? 'ESP32 Live' : 'Simulated'}
                  </span>
                </div>

                <div className={`flex items-center gap-4 ${isStale ? 'opacity-50' : ''}`}>
                  <div className="w-12 h-12 rounded-full bg-surface-container-high border border-outline-variant flex items-center justify-center text-on-surface-variant shrink-0">
                    <span className="material-symbols-outlined text-[24px]">person</span>
                  </div>
                  <div className="min-w-0">
                    <h3 className="text-headline-md font-headline-md text-[20px] text-on-surface truncate">{profile.patientNumber}</h3>
                    <p className="text-body-md font-body-md text-on-surface-variant truncate">
                      {profile.age} yrs, {profile.sex} • <span className="font-bold text-on-surface">{profile.bloodType}</span>
                    </p>
                  </div>
                </div>

                <div className={`mt-4 text-body-md font-body-md ${isStale ? 'opacity-50' : ''}`}>
                  <p className="font-semibold text-on-surface truncate" title={profile.primaryDiagnosis}>{profile.primaryDiagnosis}</p>
                  <p className="text-on-surface-variant text-[12px] mt-0.5 truncate" title={profile.comorbidities.join(', ')}>
                    {profile.comorbidities.join(', ')}
                  </p>
                </div>
              </div>

              {/* Vitals Data Visualizations */}
              <div className={`p-6 md:w-[55%] grid grid-cols-3 gap-6 items-center ${isStale ? 'opacity-50 grayscale' : ''}`}>
                {renderVitalCard(hypotension, 'Hypotension (MAP)', isP1)}
                {renderVitalCard(hypoxia, 'Hypoxia (SpO2)', isP1)}
                {renderVitalCard(tachycardia, 'Tachycardia (HR)', isP1)}
              </div>

              {/* Actions */}
              <div className="p-6 md:w-[15%] flex items-center justify-end border-t md:border-t-0 md:border-l border-outline-variant/30 bg-surface-bright">
                <button 
                  onClick={() => onSelectPatient(patient)}
                  className="w-full md:w-auto bg-surface text-primary border border-outline-variant px-6 py-3 rounded-lg font-label-mono text-label-mono hover:bg-surface-container-high transition-colors shadow-sm whitespace-nowrap"
                >
                  Inspect
                </button>
              </div>
            </div>
          );
        })}
      </div>
    </div>
  );
};
