'use client';

import React, { useState } from 'react';
import { Shield, UserPlus, Send, Users, Activity, X, AlertCircle } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';

interface AdminSidebarProps {
  patients: PatientState[];
  isOpen: boolean;
  onClose: () => void;
}

export const AdminSidebar: React.FC<AdminSidebarProps> = ({ patients, isOpen, onClose }) => {
  const { currentUser, users, addUser, dispatchUserToPatient } = useAuth();
  
  // Add User Form State
  const [newName, setNewName] = useState('');
  const [newEmail, setNewEmail] = useState('');
  const [newPassword, setNewPassword] = useState('');
  const [addSuccess, setAddSuccess] = useState('');
  const [addError, setAddError] = useState('');

  // Dispatch Form State
  const [targetUserId, setTargetUserId] = useState('');
  const [selectedPatientId, setSelectedPatientId] = useState('');
  const [dispatchNote, setDispatchNote] = useState('');
  const [dispatchSuccess, setDispatchSuccess] = useState('');

  if (!isOpen || currentUser?.role !== 'ADMIN') return null;

  const handleAddUser = (e: React.FormEvent) => {
    e.preventDefault();
    setAddError('');
    if (addUser(newName, newEmail, newPassword)) {
      setAddSuccess(`User "${newName}" created successfully!`);
      setNewName('');
      setNewEmail('');
      setNewPassword('');
      setTimeout(() => setAddSuccess(''), 3000);
    } else {
      setAddError('User with this email already exists.');
      setTimeout(() => setAddError(''), 3000);
    }
  };

  const handleDispatch = (e: React.FormEvent) => {
    e.preventDefault();
    const patient = patients.find(p => p.profile.id === selectedPatientId);
    if (targetUserId && patient) {
      dispatchUserToPatient(targetUserId, patient.profile.id, patient.profile.patientNumber, dispatchNote);
      setDispatchSuccess(`Dispatched to ${patient.profile.patientNumber}!`);
      setDispatchNote('');
      setTimeout(() => setDispatchSuccess(''), 3000);
    }
  };

  return (
    <>
      {/* Backdrop overlay */}
      <div 
        className="fixed inset-0 bg-black/50 backdrop-blur-sm z-40 transition-opacity"
        onClick={onClose}
        aria-hidden="true"
      />

      {/* Slide-out Left Panel */}
      <div className="fixed inset-y-0 left-0 z-50 w-96 bg-slate-900 border-r border-slate-800 shadow-2xl flex flex-col overflow-y-auto">
        
        {/* Header */}
        <div className="p-5 bg-slate-950 border-b border-slate-800 flex items-center justify-between sticky top-0 z-10">
          <div className="flex items-center space-x-2 text-rose-400 font-bold">
            <Shield className="w-5 h-5" />
            <span className="uppercase tracking-wider text-sm">Admin Control Panel</span>
          </div>
          <button 
            onClick={onClose} 
            className="p-1.5 rounded-lg text-slate-400 hover:text-white hover:bg-slate-800 transition-colors"
            title="Close Sidebar"
          >
            <X className="w-5 h-5" />
          </button>
        </div>

        <div className="p-5 space-y-6 flex-1 text-xs">
          
          {/* 1. Active Session Monitor */}
          <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-2">
            <h3 className="font-bold text-slate-300 uppercase tracking-wider flex items-center">
              <Users className="w-3.5 h-3.5 mr-1.5 text-emerald-400" /> Active User Session Monitor
            </h3>
            <div className="p-3 bg-emerald-950/40 border border-emerald-900 rounded-lg flex items-center justify-between">
              <div>
                <div className="font-bold text-emerald-300">{currentUser.name}</div>
                <div className="text-[11px] text-slate-400">{currentUser.email}</div>
              </div>
              <span className="px-2 py-0.5 rounded bg-emerald-900 text-emerald-200 text-[10px] font-bold uppercase flex items-center">
                <span className="h-1.5 w-1.5 rounded-full bg-emerald-400 mr-1 animate-pulse"></span>
                ONLINE NOW
              </span>
            </div>
          </div>

          {/* 2. Patient Dispatch Console */}
          <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-300 uppercase tracking-wider flex items-center">
              <Send className="w-3.5 h-3.5 mr-1.5 text-sky-400" /> Patient Dispatch Console
            </h3>

            {dispatchSuccess && (
              <div className="p-2 bg-emerald-950 border border-emerald-800 text-emerald-300 rounded font-semibold text-center">
                {dispatchSuccess}
              </div>
            )}

            <form onSubmit={handleDispatch} className="space-y-3">
              <div>
                <label className="block text-slate-400 mb-1 font-medium">Target User</label>
                <select
                  required
                  value={targetUserId}
                  onChange={e => setTargetUserId(e.target.value)}
                  className="w-full bg-slate-900 border border-slate-800 rounded-lg px-3 py-2 text-slate-100 focus:outline-none focus:border-sky-500"
                >
                  <option value="">-- Select User --</option>
                  {users.filter(u => u.role !== 'ADMIN').map(u => (
                    <option key={u.id} value={u.id}>{u.name} ({u.email})</option>
                  ))}
                </select>
              </div>

              <div>
                <label className="block text-slate-400 mb-1 font-medium">Target Patient</label>
                <select
                  required
                  value={selectedPatientId}
                  onChange={e => setSelectedPatientId(e.target.value)}
                  className="w-full bg-slate-900 border border-slate-800 rounded-lg px-3 py-2 text-slate-100 focus:outline-none focus:border-sky-500"
                >
                  <option value="">-- Select Patient --</option>
                  {patients.map(p => (
                    <option key={p.profile.id} value={p.profile.id}>
                      {p.profile.patientNumber} ({p.triageRank.replace('_', ' ')})
                    </option>
                  ))}
                </select>
              </div>

              <div>
                <label className="block text-slate-400 mb-1 font-medium">Urgent Clinical Note</label>
                <input
                  type="text"
                  required
                  value={dispatchNote}
                  onChange={e => setDispatchNote(e.target.value)}
                  placeholder="e.g. Proceed immediately for severe Hypotension"
                  className="w-full bg-slate-900 border border-slate-800 rounded-lg px-3 py-2 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-sky-500"
                />
              </div>

              <button
                type="submit"
                className="w-full py-2 bg-sky-600 hover:bg-sky-500 font-bold text-white rounded-lg transition-colors shadow-md shadow-sky-950"
              >
                Send Dispatch Notification
              </button>
            </form>
          </div>

          {/* 3. Add New Staff User Form */}
          <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-300 uppercase tracking-wider flex items-center">
              <UserPlus className="w-3.5 h-3.5 mr-1.5 text-amber-400" /> Add New Staff User
            </h3>

            {addSuccess && (
              <div className="p-2 bg-emerald-950 border border-emerald-800 text-emerald-300 rounded font-semibold text-center">
                {addSuccess}
              </div>
            )}
            {addError && (
              <div className="p-2 bg-rose-950 border border-rose-800 text-rose-300 rounded font-semibold text-center flex items-center justify-center space-x-1">
                <AlertCircle className="w-3.5 h-3.5 mr-1" />
                <span>{addError}</span>
              </div>
            )}

            <form onSubmit={handleAddUser} className="space-y-3">
              <div>
                <label className="block text-slate-400 mb-1 font-medium">Full Name</label>
                <input
                  type="text"
                  required
                  value={newName}
                  onChange={e => setNewName(e.target.value)}
                  placeholder="e.g. Dr. John Doe"
                  className="w-full bg-slate-900 border border-slate-800 rounded-lg px-3 py-2 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-amber-500"
                />
              </div>

              <div>
                <label className="block text-slate-400 mb-1 font-medium">Email Address</label>
                <input
                  type="email"
                  required
                  value={newEmail}
                  onChange={e => setNewEmail(e.target.value)}
                  placeholder="doctor@hospital.com"
                  className="w-full bg-slate-900 border border-slate-800 rounded-lg px-3 py-2 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-amber-500"
                />
              </div>

              <div>
                <label className="block text-slate-400 mb-1 font-medium">Password</label>
                <input
                  type="text"
                  required
                  value={newPassword}
                  onChange={e => setNewPassword(e.target.value)}
                  placeholder="••••••••"
                  className="w-full bg-slate-900 border border-slate-800 rounded-lg px-3 py-2 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-amber-500"
                />
              </div>

              <button
                type="submit"
                className="w-full py-2 bg-amber-600 hover:bg-amber-500 font-bold text-white rounded-lg transition-colors shadow-md shadow-amber-950"
              >
                Create User Account
              </button>
            </form>
          </div>

          {/* 4. Registered User Accounts & Password Directory */}
          <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-2">
            <h3 className="font-bold text-slate-300 uppercase tracking-wider">Registered Accounts &amp; Passwords</h3>
            <div className="divide-y divide-slate-800/80">
              {users.map(u => (
                <div key={u.id} className="py-2.5 flex items-center justify-between">
                  <div>
                    <div className="flex items-center space-x-2">
                      <span className="font-semibold text-slate-200">{u.name}</span>
                      <span className={`text-[9px] px-1.5 py-0.2 rounded font-bold uppercase ${
                        u.role === 'ADMIN' ? 'bg-rose-950 text-rose-300 border border-rose-800' : 'bg-slate-800 text-slate-400 border border-slate-700'
                      }`}>
                        {u.role}
                      </span>
                    </div>
                    <div className="text-[11px] text-slate-400">{u.email}</div>
                  </div>
                  <div className="text-right">
                    <span className="px-2 py-0.5 bg-slate-800 rounded font-mono text-[10px] text-slate-300 border border-slate-700">
                      Pass: {u.password}
                    </span>
                  </div>
                </div>
              ))}
            </div>
          </div>

        </div>
      </div>
    </>
  );
};
