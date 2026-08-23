'use client';

import React, { useState } from 'react';
import { HeartPulse, Lock, Mail, UserCheck, Shield } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';

export const LoginPage: React.FC = () => {
  const { login } = useAuth();
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!login(email, password)) {
      setError('Invalid email or password');
    }
  };

  const handleQuickLogin = (quickEmail: string, quickPass: string) => {
    setEmail(quickEmail);
    setPassword(quickPass);
    login(quickEmail, quickPass);
  };

  return (
    <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
      <div className="w-full max-w-md bg-slate-900 border border-slate-800 rounded-2xl p-8 shadow-2xl space-y-6">
        
        {/* Header */}
        <div className="text-center space-y-2">
          <div className="inline-flex p-3 bg-slate-800 rounded-xl border border-slate-700 text-sky-400 mb-2">
            <HeartPulse className="w-8 h-8 animate-pulse" />
          </div>
          <h1 className="text-2xl font-bold tracking-tight uppercase">Hospital Triage Login</h1>
          <p className="text-xs text-slate-400">SiLabs Intraoperative Monitoring &amp; Patient Dispatch System</p>
        </div>

        {/* Quick Demo Logins */}
        <div className="space-y-2 bg-slate-950/60 p-4 rounded-xl border border-slate-800 text-xs">
          <div className="text-[11px] font-bold text-slate-400 uppercase tracking-wider mb-2 flex items-center">
            <UserCheck className="w-3.5 h-3.5 mr-1.5 text-sky-400" /> Quick Demo Login (1-Click)
          </div>
          <div className="grid grid-cols-2 gap-2">
            <button
              onClick={() => handleQuickLogin('admin@hospital.com', 'admin')}
              className="px-3 py-2 bg-rose-950/70 hover:bg-rose-900 text-rose-200 rounded-lg font-semibold border border-rose-800 transition-colors text-left flex items-center justify-between"
            >
              <span>Admin</span>
              <Shield className="w-3.5 h-3.5 text-rose-400" />
            </button>
            <button
              onClick={() => handleQuickLogin('user1@hospital.com', 'user1')}
              className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 rounded-lg font-medium border border-slate-700 transition-colors text-left"
            >
              User 1
            </button>
            <button
              onClick={() => handleQuickLogin('user2@hospital.com', 'user2')}
              className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 rounded-lg font-medium border border-slate-700 transition-colors text-left"
            >
              User 2
            </button>
            <button
              onClick={() => handleQuickLogin('user3@hospital.com', 'user3')}
              className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 rounded-lg font-medium border border-slate-700 transition-colors text-left"
            >
              User 3
            </button>
          </div>
        </div>

        {/* Manual Form */}
        <form onSubmit={handleSubmit} className="space-y-4 text-xs">
          {error && (
            <div className="p-3 bg-rose-950/80 border border-rose-800 text-rose-200 rounded-lg text-center font-medium">
              {error}
            </div>
          )}

          <div>
            <label className="block text-slate-300 font-medium mb-1.5">Email Address</label>
            <div className="relative">
              <Mail className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
              <input
                type="email"
                required
                value={email}
                onChange={e => setEmail(e.target.value)}
                placeholder="admin@hospital.com"
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
                onChange={e => setPassword(e.target.value)}
                placeholder="••••••••"
                className="w-full bg-slate-950 border border-slate-800 rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-sky-500"
              />
            </div>
          </div>

          <button
            type="submit"
            className="w-full py-3 bg-sky-600 hover:bg-sky-500 text-white font-bold rounded-lg transition-colors shadow-lg shadow-sky-950"
          >
            Sign In to Dashboard
          </button>
        </form>

      </div>
    </div>
  );
};
