'use client';

import React, { useState } from 'react';
import { HeartPulse, Lock, Mail, ShieldAlert } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';

export const LoginPage: React.FC = () => {
  const { login } = useAuth();
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!login(email, password)) {
      setError('Invalid Email or Password. Please try again.');
    }
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

        {/* Credentials Form */}
        <form onSubmit={handleSubmit} className="space-y-4 text-xs">
          {error && (
            <div className="p-3 bg-rose-950/80 border border-rose-800 text-rose-200 rounded-lg text-center font-medium flex items-center justify-center space-x-2">
              <ShieldAlert className="w-4 h-4 text-rose-400" />
              <span>{error}</span>
            </div>
          )}

          <div>
            <label className="block text-slate-300 font-medium mb-1.5">User Email ID</label>
            <div className="relative">
              <Mail className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
              <input
                type="email"
                required
                value={email}
                onChange={e => { setEmail(e.target.value); setError(''); }}
                placeholder="Enter your Email ID (e.g. admin@hospital.com)"
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
                placeholder="Enter your password"
                className="w-full bg-slate-950 border border-slate-800 rounded-lg pl-9 pr-4 py-2.5 text-slate-100 placeholder-slate-600 focus:outline-none focus:border-sky-500"
              />
            </div>
          </div>

          <button
            type="submit"
            className="w-full py-3 bg-sky-600 hover:bg-sky-500 text-white font-bold rounded-lg transition-colors shadow-lg shadow-sky-950 text-sm"
          >
            Sign In to Dashboard
          </button>
        </form>

      </div>
    </div>
  );
};

export default LoginPage;
