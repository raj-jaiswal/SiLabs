import React, { useState } from 'react';
import { X, Shield, Send, UserPlus, Eye, EyeOff, User, Lock, Mail } from 'lucide-react';
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
        className="fixed inset-0 z-40 bg-[#0B0F17]/70 backdrop-blur-sm transition-opacity"
      />

      {/* Drawer */}
      <div className="fixed inset-y-0 right-0 z-50 w-full max-w-lg bg-[#131926] border-l border-[#1E2638] shadow-2xl flex flex-col font-sans select-none">
        
        {/* Header */}
        <div className="p-5 border-b border-[#1E2638] flex items-center justify-between bg-[#0B0F17]">
          <div className="flex items-center space-x-2.5">
            <div className="p-2 bg-rose-500/10 rounded-lg border border-rose-500/20 text-rose-400">
              <Shield className="w-5 h-5" />
            </div>
            <div>
              <h2 className="text-base font-bold text-slate-100 uppercase tracking-wider font-mono">
                Admin Dispatch Console
              </h2>
              <p className="text-xs text-slate-400">User account directory &amp; patient assignment portal</p>
            </div>
          </div>

          <button
            onClick={onClose}
            className="p-1.5 rounded-lg border border-[#1E2638] bg-[#131926] text-slate-400 hover:text-white transition-colors"
          >
            <X className="w-5 h-5" />
          </button>
        </div>

        {/* Content */}
        <div className="flex-1 overflow-y-auto p-5 space-y-6 text-xs">
          
          {/* 1. Active User Session Monitor */}
          <div className="bg-[#0B0F17] border border-[#1E2638] rounded-xl p-4 space-y-2">
            <div className="flex items-center justify-between">
              <span className="font-semibold text-slate-300 uppercase tracking-wider font-mono">Active Admin Session</span>
              <span className="px-2 py-0.5 rounded bg-emerald-500/10 text-emerald-400 border border-emerald-500/20 font-mono text-[10px]">
                AUTHENTICATED
              </span>
            </div>
            <div className="text-sm font-bold text-slate-100">{currentUser.name}</div>
            <div className="text-xs text-slate-400 font-mono">{currentUser.email}</div>
          </div>

          {/* 2. Dispatch User to Patient */}
          <div className="bg-[#0B0F17] border border-[#1E2638] rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-200 uppercase tracking-wider font-mono flex items-center">
              <Send className="w-4 h-4 mr-2 text-sky-400" /> Dispatch Staff to Urgent Patient
            </h3>

            {dispatchSuccess && (
              <div className="p-2.5 bg-emerald-500/10 border border-emerald-500/20 text-emerald-300 rounded-lg text-center font-medium">
                {dispatchSuccess}
              </div>
            )}

            <form onSubmit={handleDispatchSubmit} className="space-y-3">
              <div>
                <label className="block text-slate-400 mb-1">Select Staff Member</label>
                <select
                  required
                  value={targetUserId}
                  onChange={e => setTargetUserId(e.target.value)}
                  className="w-full bg-[#131926] border border-[#1E2638] rounded-lg px-3 py-2 text-slate-100 focus:outline-none focus:border-sky-500"
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
                <label className="block text-slate-400 mb-1">Select Target Patient</label>
                <select
                  required
                  value={targetPatientId}
                  onChange={e => setTargetPatientId(e.target.value)}
                  className="w-full bg-[#131926] border border-[#1E2638] rounded-lg px-3 py-2 text-slate-100 focus:outline-none focus:border-sky-500 font-mono"
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
                <label className="block text-slate-400 mb-1">Clinical Instruction Note</label>
                <input
                  type="text"
                  value={dispatchNote}
                  onChange={e => setDispatchNote(e.target.value)}
                  placeholder="e.g. Immediate bedside evaluation required for Hypotension alert"
                  className="w-full bg-[#131926] border border-[#1E2638] rounded-lg px-3 py-2 text-slate-100 placeholder-slate-500 focus:outline-none focus:border-sky-500"
                />
              </div>

              <button
                type="submit"
                className="w-full py-2.5 bg-sky-600 hover:bg-sky-500 text-white font-semibold rounded-lg transition-colors flex items-center justify-center space-x-1.5"
              >
                <Send className="w-3.5 h-3.5" />
                <span>Send Immediate Dispatch Alert</span>
              </button>
            </form>
          </div>

          {/* 3. Add New Staff Account */}
          <div className="bg-[#0B0F17] border border-[#1E2638] rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-200 uppercase tracking-wider font-mono flex items-center">
              <UserPlus className="w-4 h-4 mr-2 text-sky-400" /> Create New Staff User Account
            </h3>

            {userSuccess && (
              <div className="p-2.5 bg-emerald-500/10 border border-emerald-500/20 text-emerald-300 rounded-lg text-center font-medium">
                {userSuccess}
              </div>
            )}

            <form onSubmit={handleAddUserSubmit} className="space-y-3">
              <div>
                <label className="block text-slate-400 mb-1">Staff Name</label>
                <div className="relative">
                  <User className="w-3.5 h-3.5 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="text"
                    required
                    value={newName}
                    onChange={e => setNewName(e.target.value)}
                    placeholder="e.g. Nurse Sarah Jenkins"
                    className="w-full bg-[#131926] border border-[#1E2638] rounded-lg pl-8 pr-3 py-2 text-slate-100 placeholder-slate-500 focus:outline-none focus:border-sky-500"
                  />
                </div>
              </div>

              <div>
                <label className="block text-slate-400 mb-1">Email Address</label>
                <div className="relative">
                  <Mail className="w-3.5 h-3.5 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="email"
                    required
                    value={newEmail}
                    onChange={e => setNewEmail(e.target.value)}
                    placeholder="e.g. user4@hospital.com"
                    className="w-full bg-[#131926] border border-[#1E2638] rounded-lg pl-8 pr-3 py-2 text-slate-100 placeholder-slate-500 focus:outline-none focus:border-sky-500 font-mono"
                  />
                </div>
              </div>

              <div>
                <label className="block text-slate-400 mb-1">Assign Password</label>
                <div className="relative">
                  <Lock className="w-3.5 h-3.5 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="password"
                    required
                    value={newPassword}
                    onChange={e => setNewPassword(e.target.value)}
                    placeholder="Enter password"
                    className="w-full bg-[#131926] border border-[#1E2638] rounded-lg pl-8 pr-3 py-2 text-slate-100 placeholder-slate-500 focus:outline-none focus:border-sky-500"
                  />
                </div>
              </div>

              <button
                type="submit"
                className="w-full py-2.5 bg-[#1C2537] hover:bg-[#253047] border border-[#2A354D] text-slate-200 font-semibold rounded-lg transition-colors flex items-center justify-center space-x-1.5"
              >
                <UserPlus className="w-3.5 h-3.5 text-sky-400" />
                <span>Register Staff Account</span>
              </button>
            </form>
          </div>

          {/* 4. Registered User Accounts Directory (Masked Security Passwords) */}
          <div className="bg-[#0B0F17] border border-[#1E2638] rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-200 uppercase tracking-wider font-mono">
              Registered Accounts Directory
            </h3>
            <div className="divide-y divide-[#1E2638]">
              {users.map(u => {
                const isShowing = !!showPasswords[u.id];
                return (
                  <div key={u.id} className="py-2.5 flex items-center justify-between">
                    <div>
                      <div className="flex items-center space-x-2">
                        <span className="font-semibold text-slate-200">{u.name}</span>
                        <span className={`text-[9px] px-1.5 py-0.2 rounded font-mono font-bold uppercase ${
                          u.role === 'ADMIN' ? 'bg-rose-500/10 text-rose-300 border border-rose-500/20' : 'bg-sky-500/10 text-sky-300 border border-sky-500/20'
                        }`}>
                          {u.role}
                        </span>
                      </div>
                      <div className="text-[11px] text-slate-400 font-mono">{u.email}</div>
                    </div>
                    
                    <div className="flex items-center space-x-2">
                      <span className="px-2 py-1 bg-[#131926] rounded font-mono text-[11px] text-slate-300 border border-[#1E2638] tabular-nums">
                        {isShowing ? u.password : '••••••••'}
                      </span>
                      <button
                        onClick={() => toggleShowPassword(u.id)}
                        title={isShowing ? "Hide Password" : "Show Password"}
                        className="p-1 bg-[#131926] hover:bg-[#1C2537] text-slate-400 hover:text-slate-200 border border-[#1E2638] rounded transition-colors"
                      >
                        {isShowing ? <EyeOff className="w-3.5 h-3.5" /> : <Eye className="w-3.5 h-3.5" />}
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
