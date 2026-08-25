'use client';

import React, { useState } from 'react';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '../types/patient';

interface AdminSidebarProps {
  patients: PatientState[];
  isOpen: boolean;
  onClose: () => void;
}

export const AdminSidebar: React.FC<AdminSidebarProps> = ({ patients, isOpen, onClose }) => {
  const { currentUser, users, addUser, dispatchUserToPatient } = useAuth();

  // Dispatch state
  const [targetUserId, setTargetUserId] = useState('');
  const [targetPatientId, setTargetPatientId] = useState('');
  const [dispatchNote, setDispatchNote] = useState('');
  const [dispatchSuccess, setDispatchSuccess] = useState('');

  // Add User State
  const [newName, setNewName] = useState('');
  const [newEmail, setNewEmail] = useState('');
  const [newPassword, setNewPassword] = useState('');
  const [userSuccess, setUserSuccess] = useState('');

  // Show/Hide Password State per user ID
  const [showPasswords, setShowPasswords] = useState<Record<string, boolean>>({});

  if (!isOpen || currentUser?.role !== 'ADMIN') return null;

  const toggleShowPassword = (userId: string) => {
    setShowPasswords(prev => ({ ...prev, [userId]: !prev[userId] }));
  };

  const handleDispatchSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!targetUserId || !targetPatientId) return;

    const patient = patients.find(p => p.profile.id === targetPatientId);
    const patientNum = patient ? patient.profile.patientNumber : targetPatientId;

    dispatchUserToPatient(targetUserId, targetPatientId, patientNum, dispatchNote);
    setDispatchSuccess(`Successfully dispatched user to ${patientNum}`);
    setDispatchNote('');
    setTimeout(() => setDispatchSuccess(''), 4000);
  };

  const handleAddUserSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!newName || !newEmail || !newPassword) return;

    if (addUser(newName, newEmail, newPassword)) {
      setUserSuccess(`Staff account "${newName}" created successfully.`);
      setNewName('');
      setNewEmail('');
      setNewPassword('');
      setTimeout(() => setUserSuccess(''), 4000);
    }
  };

  const staffUsers = users.filter(u => u.role === 'USER');

  return (
    <>
      {/* Backdrop */}
      <div
        onClick={onClose}
        className="fixed inset-0 z-40 bg-surface-container-highest/80 backdrop-blur-sm transition-opacity"
      />

      {/* Drawer */}
      <div className="fixed inset-y-0 right-0 z-50 w-full max-w-lg bg-surface-container-lowest border-l border-outline-variant shadow-xl flex flex-col font-body-md select-none text-on-surface">
        
        {/* Header */}
        <div className="p-6 border-b border-outline-variant flex items-center justify-between bg-surface-container-low">
          <div className="flex items-center space-x-4">
            <div className="p-2 bg-error-container/20 text-error border border-error/20 rounded-lg">
              <span className="material-symbols-outlined text-[24px]">admin_panel_settings</span>
            </div>
            <div>
              <h2 className="text-headline-md font-headline-md font-bold text-on-surface uppercase tracking-wider">
                Admin Dispatch Console
              </h2>
              <p className="text-body-md text-[13px] text-on-surface-variant">User account directory &amp; patient assignment portal</p>
            </div>
          </div>

          <button
            onClick={onClose}
            className="p-2 bg-surface-container-lowest hover:bg-surface-container-high rounded-full text-on-surface-variant hover:text-primary transition-colors"
          >
            <span className="material-symbols-outlined">close</span>
          </button>
        </div>

        {/* Content */}
        <div className="flex-1 overflow-y-auto p-6 space-y-8 text-body-md">
          
          {/* 1. Active User Session Monitor */}
          <div className="bg-surface-container border border-outline-variant rounded-xl p-5 space-y-2 shadow-sm">
            <div className="flex items-center justify-between">
              <span className="font-bold text-on-surface uppercase tracking-wider font-label-mono">Active Admin Session</span>
              <span className="px-2 py-0.5 bg-tertiary-container/10 text-tertiary-container border border-tertiary-container/30 font-label-mono text-[10px] font-bold rounded">
                AUTHENTICATED
              </span>
            </div>
            <div className="text-[16px] font-bold text-on-surface">{currentUser.name}</div>
            <div className="text-body-md text-on-surface-variant font-label-mono">{currentUser.email}</div>
          </div>

          {/* 2. Dispatch User to Patient */}
          <div className="bg-surface-container border border-outline-variant rounded-xl p-5 space-y-4 shadow-sm">
            <h3 className="font-bold text-on-surface uppercase tracking-wider font-label-mono flex items-center">
              <span className="material-symbols-outlined mr-2 text-[18px]">send</span> Dispatch Staff to Urgent Patient
            </h3>

            {dispatchSuccess && (
              <div className="p-3 bg-primary-container border border-primary text-primary-container text-center font-bold rounded-lg text-on-primary-container">
                {dispatchSuccess}
              </div>
            )}

            <form onSubmit={handleDispatchSubmit} className="space-y-4">
              <div>
                <label className="block text-on-surface font-semibold mb-1.5">Select Staff Member</label>
                <select
                  required
                  value={targetUserId}
                  onChange={e => setTargetUserId(e.target.value)}
                  className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg px-3 py-2.5 text-on-surface focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all"
                >
                  <option value="">Choose User...</option>
                  {staffUsers.map(u => (
                    <option key={u.id} value={u.id}>
                      {u.name} ({u.email})
                    </option>
                  ))}
                </select>
              </div>

              <div>
                <label className="block text-on-surface font-semibold mb-1.5">Select Target Patient</label>
                <select
                  required
                  value={targetPatientId}
                  onChange={e => setTargetPatientId(e.target.value)}
                  className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg px-3 py-2.5 text-on-surface focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all font-label-mono"
                >
                  <option value="">Choose Patient...</option>
                  {patients.map(p => (
                    <option key={p.profile.id} value={p.profile.id}>
                      {p.profile.patientNumber} — {p.triageRank.replace('_', ' ')} ({p.profile.primaryDiagnosis})
                    </option>
                  ))}
                </select>
              </div>

              <div>
                <label className="block text-on-surface font-semibold mb-1.5">Clinical Instruction Note</label>
                <input
                  type="text"
                  value={dispatchNote}
                  onChange={e => setDispatchNote(e.target.value)}
                  placeholder="e.g. Immediate bedside evaluation required for Hypotension alert"
                  className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg px-3 py-2.5 text-on-surface placeholder:text-outline-variant focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all"
                />
              </div>

              <button
                type="submit"
                className="w-full py-3 bg-primary hover:bg-primary/90 text-on-primary rounded-lg font-bold transition-colors flex items-center justify-center space-x-2 shadow-sm"
              >
                <span className="material-symbols-outlined text-[18px]">emergency_share</span>
                <span>Send Immediate Dispatch Alert</span>
              </button>
            </form>
          </div>

          {/* 3. Add New Staff Account */}
          <div className="bg-surface-container border border-outline-variant rounded-xl p-5 space-y-4 shadow-sm">
            <h3 className="font-bold text-on-surface uppercase tracking-wider font-label-mono flex items-center">
              <span className="material-symbols-outlined mr-2 text-[18px]">person_add</span> Create New Staff User Account
            </h3>

            {userSuccess && (
              <div className="p-3 bg-primary-container border border-primary text-primary-container text-center font-bold rounded-lg text-on-primary-container">
                {userSuccess}
              </div>
            )}

            <form onSubmit={handleAddUserSubmit} className="space-y-4">
              <div>
                <label className="block text-on-surface font-semibold mb-1.5">Staff Name</label>
                <div className="relative">
                  <span className="material-symbols-outlined text-outline-variant absolute left-3 top-2.5 text-[20px]">person</span>
                  <input
                    type="text"
                    required
                    value={newName}
                    onChange={e => setNewName(e.target.value)}
                    placeholder="e.g. Nurse Sarah Jenkins"
                    className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg pl-10 pr-3 py-2.5 text-on-surface placeholder:text-outline-variant focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all"
                  />
                </div>
              </div>

              <div>
                <label className="block text-on-surface font-semibold mb-1.5">Email Address</label>
                <div className="relative">
                  <span className="material-symbols-outlined text-outline-variant absolute left-3 top-2.5 text-[20px]">mail</span>
                  <input
                    type="email"
                    required
                    value={newEmail}
                    onChange={e => setNewEmail(e.target.value)}
                    placeholder="e.g. user4@hospital.com"
                    className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg pl-10 pr-3 py-2.5 text-on-surface placeholder:text-outline-variant focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all font-label-mono"
                  />
                </div>
              </div>

              <div>
                <label className="block text-on-surface font-semibold mb-1.5">Assign Password</label>
                <div className="relative">
                  <span className="material-symbols-outlined text-outline-variant absolute left-3 top-2.5 text-[20px]">lock</span>
                  <input
                    type="password"
                    required
                    value={newPassword}
                    onChange={e => setNewPassword(e.target.value)}
                    placeholder="Enter password"
                    className="w-full bg-surface-container-lowest border border-outline-variant rounded-lg pl-10 pr-3 py-2.5 text-on-surface placeholder:text-outline-variant focus:outline-none focus:border-primary focus:ring-1 focus:ring-primary transition-all"
                  />
                </div>
              </div>

              <button
                type="submit"
                className="w-full py-3 bg-surface-container-high hover:bg-surface-container-highest border border-outline-variant text-on-surface rounded-lg font-bold transition-colors flex items-center justify-center space-x-2"
              >
                <span className="material-symbols-outlined text-[18px]">person_add</span>
                <span>Register Staff Account</span>
              </button>
            </form>
          </div>

          {/* 4. Registered User Accounts Directory */}
          <div className="bg-surface-container border border-outline-variant rounded-xl p-5 space-y-4 shadow-sm">
            <h3 className="font-bold text-on-surface uppercase tracking-wider font-label-mono">
              Registered Accounts Directory
            </h3>
            <div className="divide-y divide-outline-variant">
              {users.map(u => {
                const isShowing = !!showPasswords[u.id];
                return (
                  <div key={u.id} className="py-3 flex items-center justify-between">
                    <div>
                      <div className="flex items-center space-x-2">
                        <span className="font-bold text-on-surface">{u.name}</span>
                        <span className={`text-[9px] px-2 py-0.5 rounded font-label-mono font-bold uppercase tracking-wider ${
                          u.role === 'ADMIN' ? 'bg-error-container/20 text-error border border-error/20' : 'bg-surface-container-high text-on-surface-variant border border-outline-variant'
                        }`}>
                          {u.role}
                        </span>
                      </div>
                      <div className="text-[12px] text-on-surface-variant font-label-mono mt-0.5">{u.email}</div>
                    </div>
                    
                    <div className="flex items-center space-x-2">
                      <span className="px-2 py-1 bg-surface-container-lowest rounded font-label-mono text-[12px] text-on-surface border border-outline-variant tabular-nums min-w-[80px] text-center">
                        {isShowing ? u.password : '••••••••'}
                      </span>
                      <button
                        onClick={() => toggleShowPassword(u.id)}
                        title={isShowing ? "Hide Password" : "Show Password"}
                        className="p-1.5 bg-surface-container-lowest hover:bg-surface-container-high rounded-lg text-on-surface-variant border border-outline-variant transition-colors"
                      >
                        <span className="material-symbols-outlined text-[18px]">{isShowing ? 'visibility_off' : 'visibility'}</span>
                      </button>
                    </div>
                  </div>
                );
              })}
            </div>
          </div>

        </div>
      </div>
    </>
  );
};
