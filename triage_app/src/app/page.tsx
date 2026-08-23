'use client';

import React from 'react';
import Link from 'next/link';
import { HeartPulse, Shield, User, ChevronRight } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';

export default function Home() {
  const { currentUser } = useAuth();

  return (
    <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-6 text-slate-100">
      <div className="w-full max-w-md bg-slate-900 border border-slate-800 rounded-2xl p-8 shadow-2xl space-y-6">
        
        {/* Brand Header */}
        <div className="text-center space-y-2">
          <div className="inline-flex p-3 bg-slate-800 rounded-xl border border-slate-700 text-sky-400 mb-2">
            <HeartPulse className="w-8 h-8 animate-pulse text-sky-400" />
          </div>
          <h1 className="text-2xl font-bold tracking-tight uppercase">Hospital Triage Portal</h1>
          <p className="text-xs text-slate-400">SiLabs Intraoperative Monitoring &amp; Patient Dispatch System</p>
        </div>

        {/* Current Active Session Status if logged in */}
        {currentUser && (
          <div className="p-3 bg-slate-950 border border-slate-800 rounded-xl flex items-center justify-between text-xs">
            <div>
              <span className="text-slate-400">Active Session: </span>
              <span className="font-bold text-sky-300">{currentUser.name}</span>
              <span className="text-slate-400 text-[11px] block">{currentUser.email} ({currentUser.role})</span>
            </div>
            <span className="px-2 py-0.5 rounded bg-emerald-950 text-emerald-400 font-mono text-[10px] border border-emerald-800 font-bold">
              LOGGED IN
            </span>
          </div>
        )}

        {/* Front Portal Selection Buttons (ONLY Admin & User) */}
        <div className="space-y-4 pt-2">
          <div className="text-center text-xs font-semibold text-slate-300 uppercase tracking-wider mb-2">
            Select Access Portal
          </div>

          {/* Option 1: Admin */}
          <Link
            href="/admin"
            className="w-full p-4 bg-rose-950/40 hover:bg-rose-950/80 border border-rose-900/80 hover:border-rose-600 rounded-xl text-left transition-all duration-200 group flex items-center justify-between block"
          >
            <div className="flex items-center space-x-3">
              <div className="p-2.5 bg-rose-900/60 rounded-lg border border-rose-700 text-rose-300 group-hover:scale-105 transition-transform">
                <Shield className="w-6 h-6 text-rose-300" />
              </div>
              <div>
                <div className="font-bold text-slate-100 group-hover:text-rose-300 transition-colors text-sm">
                  Admin
                </div>
                <div className="text-[11px] text-slate-400">
                  System Administrator Login &amp; Dispatch Console (`/admin`)
                </div>
              </div>
            </div>
            <ChevronRight className="w-5 h-5 text-rose-400 group-hover:translate-x-1 transition-transform" />
          </Link>

          {/* Option 2: User */}
          <Link
            href="/user"
            className="w-full p-4 bg-sky-950/40 hover:bg-sky-950/80 border border-sky-900/80 hover:border-sky-600 rounded-xl text-left transition-all duration-200 group flex items-center justify-between block"
          >
            <div className="flex items-center space-x-3">
              <div className="p-2.5 bg-sky-900/60 rounded-lg border border-sky-700 text-sky-300 group-hover:scale-105 transition-transform">
                <User className="w-6 h-6 text-sky-300" />
              </div>
              <div>
                <div className="font-bold text-slate-100 group-hover:text-sky-300 transition-colors text-sm">
                  User
                </div>
                <div className="text-[11px] text-slate-400">
                  Staff User Login (type user1, user2, user3, user4...)
                </div>
              </div>
            </div>
            <ChevronRight className="w-5 h-5 text-sky-400 group-hover:translate-x-1 transition-transform" />
          </Link>
        </div>

      </div>
    </div>
  );
}
