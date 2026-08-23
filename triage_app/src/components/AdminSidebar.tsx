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
        className="fixed inset-0 z-40 bg-slate-900/40 backdrop-blur-xs transition-opacity"
      />

      {/* Drawer */}
      <div className="fixed inset-y-0 right-0 z-50 w-full max-w-lg bg-white border-l border-slate-200 shadow-2xl flex flex-col font-sans select-none">
        
        {/* Header */}
        <div className="p-5 border-b border-slate-200 flex items-center justify-between bg-slate-50">
          <div className="flex items-center space-x-2.5">
            <div className="p-2 bg-red-50 rounded-lg border border-red-200 text-red-700">
              <Shield className="w-5 h-5" />
            </div>
            <div>
              <h2 className="text-base font-bold text-slate-900 uppercase tracking-wider font-mono">
                Admin Dispatch Console
              </h2>
              <p className="text-xs text-slate-600">User account directory &amp; patient assignment portal</p>
            </div>
          </div>

          <button
            onClick={onClose}
            className="p-1.5 rounded-lg border border-slate-300 bg-white text-slate-600 hover:text-slate-900 transition-colors"
          >
            <X className="w-5 h-5" />
          </button>
        </div>

        {/* Content */}
        <div className="flex-1 overflow-y-auto p-5 space-y-6 text-xs">
          
          {/* 1. Active User Session Monitor */}
          <div className="bg-slate-50 border border-slate-200 rounded-xl p-4 space-y-2">
            <div className="flex items-center justify-between">
              <span className="font-semibold text-slate-700 uppercase tracking-wider font-mono">Active Admin Session</span>
              <span className="px-2 py-0.5 rounded bg-emerald-50 text-emerald-700 border border-emerald-300 font-mono text-[10px] font-bold">
                AUTHENTICATED
              </span>
            </div>
            <div className="text-sm font-bold text-slate-900">{currentUser.name}</div>
            <div className="text-xs text-slate-600 font-mono">{currentUser.email}</div>
          </div>

          {/* 2. Dispatch User to Patient */}
          <div className="bg-slate-50 border border-slate-200 rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-900 uppercase tracking-wider font-mono flex items-center">
              <Send className="w-4 h-4 mr-2 text-slate-700" /> Dispatch Staff to Urgent Patient
            </h3>

            {dispatchSuccess && (
              <div className="p-2.5 bg-emerald-50 border border-emerald-200 text-emerald-800 rounded-lg text-center font-semibold">
                {dispatchSuccess}
              </div>
            )}

            <form onSubmit={handleDispatchSubmit} className="space-y-3">
              <div>
                <label className="block text-slate-700 font-medium mb-1">Select Staff Member</label>
                <select
                  required
                  value={targetUserId}
                  onChange={e => setTargetUserId(e.target.value)}
                  className="w-full bg-white border border-slate-300 rounded-lg px-3 py-2 text-slate-900 focus:outline-none focus:border-slate-900"
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
                <label className="block text-slate-700 font-medium mb-1">Select Target Patient</label>
                <select
                  required
                  value={targetPatientId}
                  onChange={e => setTargetPatientId(e.target.value)}
                  className="w-full bg-white border border-slate-300 rounded-lg px-3 py-2 text-slate-900 focus:outline-none focus:border-slate-900 font-mono"
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
                <label className="block text-slate-700 font-medium mb-1">Clinical Instruction Note</label>
                <input
                  type="text"
                  value={dispatchNote}
                  onChange={e => setDispatchNote(e.target.value)}
                  placeholder="e.g. Immediate bedside evaluation required for Hypotension alert"
                  className="w-full bg-white border border-slate-300 rounded-lg px-3 py-2 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
                />
              </div>

              <button
                type="submit"
                className="w-full py-2.5 bg-slate-900 hover:bg-black text-white font-semibold rounded-lg transition-colors flex items-center justify-center space-x-1.5"
              >
                <Send className="w-3.5 h-3.5" />
                <span>Send Immediate Dispatch Alert</span>
              </button>
            </form>
          </div>

          {/* 3. Add New Staff Account */}
          <div className="bg-slate-50 border border-slate-200 rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-900 uppercase tracking-wider font-mono flex items-center">
              <UserPlus className="w-4 h-4 mr-2 text-slate-700" /> Create New Staff User Account
            </h3>

            {userSuccess && (
              <div className="p-2.5 bg-emerald-50 border border-emerald-200 text-emerald-800 rounded-lg text-center font-semibold">
                {userSuccess}
              </div>
            )}

            <form onSubmit={handleAddUserSubmit} className="space-y-3">
              <div>
                <label className="block text-slate-700 font-medium mb-1">Staff Name</label>
                <div className="relative">
                  <User className="w-3.5 h-3.5 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="text"
                    required
                    value={newName}
                    onChange={e => setNewName(e.target.value)}
                    placeholder="e.g. Nurse Sarah Jenkins"
                    className="w-full bg-white border border-slate-300 rounded-lg pl-8 pr-3 py-2 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
                  />
                </div>
              </div>

              <div>
                <label className="block text-slate-700 font-medium mb-1">Email Address</label>
                <div className="relative">
                  <Mail className="w-3.5 h-3.5 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="email"
                    required
                    value={newEmail}
                    onChange={e => setNewEmail(e.target.value)}
                    placeholder="e.g. user4@hospital.com"
                    className="w-full bg-white border border-slate-300 rounded-lg pl-8 pr-3 py-2 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900 font-mono"
                  />
                </div>
              </div>

              <div>
                <label className="block text-slate-700 font-medium mb-1">Assign Password</label>
                <div className="relative">
                  <Lock className="w-3.5 h-3.5 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="password"
                    required
                    value={newPassword}
                    onChange={e => setNewPassword(e.target.value)}
                    placeholder="Enter password"
                    className="w-full bg-white border border-slate-300 rounded-lg pl-8 pr-3 py-2 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
                  />
                </div>
              </div>

              <button
                type="submit"
                className="w-full py-2.5 bg-slate-100 hover:bg-slate-200 border border-slate-300 text-slate-900 font-semibold rounded-lg transition-colors flex items-center justify-center space-x-1.5"
              >
                <UserPlus className="w-3.5 h-3.5 text-slate-700" />
                <span>Register Staff Account</span>
              </button>
            </form>
          </div>

          {/* 4. Registered User Accounts Directory */}
          <div className="bg-slate-50 border border-slate-200 rounded-xl p-4 space-y-3">
            <h3 className="font-bold text-slate-900 uppercase tracking-wider font-mono">
              Registered Accounts Directory
            </h3>
            <div className="divide-y divide-slate-200">
              {users.map(u => {
                const isShowing = !!showPasswords[u.id];
                return (
                  <div key={u.id} className="py-2.5 flex items-center justify-between">
                    <div>
                      <div className="flex items-center space-x-2">
                        <span className="font-semibold text-slate-900">{u.name}</span>
                        <span className={`text-[9px] px-1.5 py-0.2 rounded font-mono font-bold uppercase ${
                          u.role === 'ADMIN' ? 'bg-red-50 text-red-700 border border-red-300' : 'bg-slate-200 text-slate-800 border border-slate-300'
                        }`}>
                          {u.role}
                        </span>
                      </div>
                      <div className="text-[11px] text-slate-600 font-mono">{u.email}</div>
                    </div>
                    
                    <div className="flex items-center space-x-2">
                      <span className="px-2 py-1 bg-white rounded font-mono text-[11px] text-slate-900 border border-slate-300 tabular-nums">
                        {isShowing ? u.password : '••••••••'}
                      </span>
                      <button
                        onClick={() => toggleShowPassword(u.id)}
                        title={isShowing ? "Hide Password" : "Show Password"}
                        className="p-1 bg-white hover:bg-slate-100 text-slate-600 hover:text-slate-900 border border-slate-300 rounded transition-colors"
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
