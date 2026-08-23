'use client';

import React, { useState } from 'react';
import { useAuth } from '@/context/AuthContext';
import { Activity, Lock, Mail, ShieldAlert, CheckCircle, Shield } from 'lucide-react';

export const LoginPage: React.FC = () => {
  const { login } = useAuth();

  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleFormSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (login(email, password)) {
      setError('');
    } else {
      setError('Invalid email or password. Please try again.');
    }
  };

  const handleQuickLogin = (demoEmail: string, demoPass: string) => {
    setEmail(demoEmail);
    setPassword(demoPass);
    if (login(demoEmail, demoPass)) {
      setError('');
    }
  };

  return (
    <div className="min-h-screen bg-white flex flex-col items-center justify-center p-6 text-slate-900 font-sans select-none">
      <div className="w-full max-w-md bg-white border border-slate-300 p-8 shadow-none space-y-6">
        
        {/* Header */}
        <div className="text-center space-y-2">
          <div className="inline-flex p-3 bg-slate-100 border border-slate-300 text-slate-900 mb-1">
            <Activity className="w-7 h-7" />
          </div>
          <h1 className="text-xl font-bold tracking-tight uppercase text-slate-900">
            Clinical Telemetry Login
          </h1>
          <p className="text-xs text-slate-600">
            SiLabs Intraoperative Adverse Event Predictor
          </p>
        </div>

        {/* Demo Quick Logins */}
        <div className="bg-slate-50 border border-slate-300 p-3.5 space-y-2">
          <div className="text-[11px] font-mono font-bold text-slate-700 uppercase tracking-wider text-center">
            Quick Demo Logins (1-Click)
          </div>
          <div className="grid grid-cols-2 gap-2 text-xs font-mono">
            <button
              onClick={() => handleQuickLogin('admin@hospital.com', 'admin')}
              className="px-2.5 py-1.5 bg-red-50 hover:bg-red-100 border border-red-200 text-red-800 font-bold transition-colors flex items-center justify-center space-x-1"
            >
              <Shield className="w-3 h-3 text-red-600" />
              <span>Admin</span>
            </button>
            <button
              onClick={() => handleQuickLogin('user1@hospital.com', 'user1')}
              className="px-2.5 py-1.5 bg-slate-100 hover:bg-slate-200 border border-slate-300 text-slate-900 font-bold transition-colors flex items-center justify-center space-x-1"
            >
              <CheckCircle className="w-3 h-3 text-slate-700" />
              <span>User 1</span>
            </button>
            <button
              onClick={() => handleQuickLogin('user2@hospital.com', 'user2')}
              className="px-2.5 py-1.5 bg-slate-100 hover:bg-slate-200 border border-slate-300 text-slate-900 font-bold transition-colors flex items-center justify-center space-x-1"
            >
              <CheckCircle className="w-3 h-3 text-slate-700" />
              <span>User 2</span>
            </button>
            <button
              onClick={() => handleQuickLogin('user3@hospital.com', 'user3')}
              className="px-2.5 py-1.5 bg-slate-100 hover:bg-slate-200 border border-slate-300 text-slate-900 font-bold transition-colors flex items-center justify-center space-x-1"
            >
              <CheckCircle className="w-3 h-3 text-slate-700" />
              <span>User 3</span>
            </button>
          </div>
        </div>

        {/* Manual Form */}
        <form onSubmit={handleFormSubmit} className="space-y-4 text-xs">
          {error && (
            <div className="p-3 bg-red-50 border border-red-200 text-red-800 text-center font-bold flex items-center justify-center space-x-2">
              <ShieldAlert className="w-4 h-4 text-red-600" />
              <span>{error}</span>
            </div>
          )}

          <div>
            <label className="block text-slate-700 font-semibold mb-1.5 font-sans">Email Address</label>
            <div className="relative font-mono">
              <Mail className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
              <input
                type="email"
                required
                value={email}
                onChange={e => setEmail(e.target.value)}
                placeholder="e.g. admin@hospital.com or user1@hospital.com"
                className="w-full bg-white border border-slate-300 pl-9 pr-4 py-2.5 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
              />
            </div>
          </div>

          <div>
            <label className="block text-slate-700 font-semibold mb-1.5 font-sans">Password</label>
            <div className="relative font-mono">
              <Lock className="w-4 h-4 text-slate-500 absolute left-3 top-3" />
              <input
                type="password"
                required
                value={password}
                onChange={e => setPassword(e.target.value)}
                placeholder="Enter password"
                className="w-full bg-white border border-slate-300 pl-9 pr-4 py-2.5 text-slate-900 placeholder-slate-400 focus:outline-none focus:border-slate-900"
              />
            </div>
          </div>

          <button
            type="submit"
            className="w-full py-2.5 bg-slate-900 hover:bg-slate-800 text-white font-bold transition-colors text-xs"
          >
            Sign In to Telemetry System
          </button>
        </form>

      </div>
    </div>
  );
};
