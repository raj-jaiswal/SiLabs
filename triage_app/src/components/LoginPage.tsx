'use client';

import React, { useState } from 'react';
import { useRouter } from 'next/navigation';
import { HeartPulse, Lock, Mail, ShieldAlert, Shield, User, ArrowLeft, ChevronRight } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';
import { UserRole } from '@/types/auth';

export const LoginPage: React.FC = () => {
  const { login } = useAuth();
  const router = useRouter();
  const [selectedRole, setSelectedRole] = useState<UserRole | null>(null);
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (login(email, password)) {
      if (selectedRole === 'ADMIN') {
        router.push('/admin');
      } else {
        router.push('/user');
      }
    } else {
      setError('Invalid Email ID or Password for the selected account.');
    }
  };

  const handleSelectRole = (role: UserRole) => {
    setSelectedRole(role);
    setError('');
    setEmail('');
    setPassword('');
  };

  return (
    <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
      <div className="w-full max-w-md bg-slate-900 border border-slate-800 rounded-2xl p-8 shadow-2xl space-y-6">
        
        {/* Brand Header */}
        <div className="text-center space-y-2">
          <div className="inline-flex p-3 bg-slate-800 rounded-xl border border-slate-700 text-sky-400 mb-2">
            <HeartPulse className="w-8 h-8 animate-pulse" />
          </div>
          <h1 className="text-2xl font-bold tracking-tight uppercase">Hospital Triage Portal</h1>
          <p className="text-xs text-slate-400">SiLabs Intraoperative Monitoring &amp; Patient Dispatch System</p>
        </div>

        {/* STEP 1: Front Page Role Choice Selection */}
        {selectedRole === null ? (
          <div className="space-y-4 pt-2">
            <div className="text-center text-xs font-semibold text-slate-300 uppercase tracking-wider mb-2">
              Select Your Access Portal
            </div>

            {/* Admin Role Choice */}
            <button
              onClick={() => handleSelectRole('ADMIN')}
              className="w-full p-4 bg-rose-950/40 hover:bg-rose-950/80 border border-rose-900/80 hover:border-rose-600 rounded-xl text-left transition-all duration-200 group flex items-center justify-between"
            >
              <div className="flex items-center space-x-3">
                <div className="p-2.5 bg-rose-900/60 rounded-lg border border-rose-700 text-rose-300 group-hover:scale-105 transition-transform">
                  <Shield className="w-6 h-6 text-rose-300" />
                </div>
                <div>
                  <div className="font-bold text-slate-100 group-hover:text-rose-300 transition-colors">
                    Login as Administrator
                  </div>
                  <div className="text-[11px] text-slate-400">
                    User creation, telemetry control, &amp; patient dispatching
                  </div>
                </div>
              </div>
              <ChevronRight className="w-5 h-5 text-rose-400 group-hover:translate-x-1 transition-transform" />
            </button>

            {/* User Role Choice */}
            <button
              onClick={() => handleSelectRole('USER')}
              className="w-full p-4 bg-sky-950/40 hover:bg-sky-950/80 border border-sky-900/80 hover:border-sky-600 rounded-xl text-left transition-all duration-200 group flex items-center justify-between"
            >
              <div className="flex items-center space-x-3">
                <div className="p-2.5 bg-sky-900/60 rounded-lg border border-sky-700 text-sky-300 group-hover:scale-105 transition-transform">
                  <User className="w-6 h-6 text-sky-300" />
                </div>
                <div>
                  <div className="font-bold text-slate-100 group-hover:text-sky-300 transition-colors">
                    Login as Staff User / Nurse
                  </div>
                  <div className="text-[11px] text-slate-400">
                    Real-time triage telemetry &amp; assigned patient updates
                  </div>
                </div>
              </div>
              <ChevronRight className="w-5 h-5 text-sky-400 group-hover:translate-x-1 transition-transform" />
            </button>
          </div>
        ) : (
          /* STEP 2: Credentials Form for Selected Role */
          <div className="space-y-4 pt-2">
            <button
              onClick={() => setSelectedRole(null)}
              className="inline-flex items-center text-xs font-semibold text-slate-400 hover:text-slate-200 transition-colors mb-2"
            >
              <ArrowLeft className="w-3.5 h-3.5 mr-1" /> Change Access Portal
            </button>

            <div className={`p-3 rounded-lg border flex items-center space-x-2 text-xs font-bold ${
              selectedRole === 'ADMIN' 
                ? 'bg-rose-950/60 border-rose-800 text-rose-200' 
                : 'bg-sky-950/60 border-sky-800 text-sky-200'
            }`}>
              {selectedRole === 'ADMIN' ? <Shield className="w-4 h-4 text-rose-400" /> : <User className="w-4 h-4 text-sky-400" />}
              <span>{selectedRole === 'ADMIN' ? 'ADMINISTRATOR PORTAL LOGIN' : 'STAFF USER PORTAL LOGIN'}</span>
            </div>

            <form onSubmit={handleSubmit} className="space-y-4 text-xs">
              {error && (
                <div className="p-3 bg-rose-950/80 border border-rose-800 text-rose-200 rounded-lg text-center font-medium flex items-center justify-center space-x-2">
                  <ShieldAlert className="w-4 h-4 text-rose-400" />
                  <span>{error}</span>
                </div>
              )}

              <div>
                <label className="block text-slate-300 font-medium mb-1.5">
                  {selectedRole === 'ADMIN' ? 'Admin Email ID' : 'User Email ID'}
                </label>
                <div className="relative">
                  <Mail className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
                  <input
                    type="email"
                    required
                    value={email}
                    onChange={e => { setEmail(e.target.value); setError(''); }}
                    placeholder={selectedRole === 'ADMIN' ? 'admin@hospital.com' : 'user1@hospital.com'}
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
                    value={password}
                    onChange={e => { setPassword(e.target.value); setError(''); }}
                    placeholder="Enter password"
                    className="w-full bg-slate-950 border border-slate-800 rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-sky-500"
                  />
                </div>
              </div>

              <button
                type="submit"
                className={`w-full py-3 text-white font-bold rounded-lg transition-colors text-sm shadow-lg ${
                  selectedRole === 'ADMIN'
                    ? 'bg-rose-600 hover:bg-rose-500 shadow-rose-950'
                    : 'bg-sky-600 hover:bg-sky-500 shadow-sky-950'
                }`}
              >
                Sign In as {selectedRole === 'ADMIN' ? 'Admin' : 'Staff User'}
              </button>
            </form>
          </div>
        )}

      </div>
    </div>
  );
};

export default LoginPage;
