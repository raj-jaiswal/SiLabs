'use client';

import React from 'react';
import Link from 'next/link';
import { Activity, Shield, User, ChevronRight } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';

export default function Home() {
  const { currentUser } = useAuth();

  return (
    <div className="min-h-screen bg-white flex flex-col items-center justify-center p-6 text-slate-900 font-sans select-none">
      <div className="w-full max-w-md bg-white border border-slate-200 rounded-xl p-8 shadow-sm space-y-6">
        
        {/* Brand Header */}
        <div className="text-center space-y-2">
          <div className="inline-flex p-3 bg-slate-100 rounded-xl border border-slate-300 text-slate-900 mb-2">
            <Activity className="w-8 h-8" />
          </div>
          <h1 className="text-2xl font-bold tracking-tight uppercase text-slate-900">Hospital Triage Portal</h1>
          <p className="text-xs text-slate-600">SiLabs Intraoperative Monitoring &amp; Patient Dispatch System</p>
        </div>

        {/* Current Active Session Status if logged in */}
        {currentUser && (
          <div className="p-3 bg-slate-50 border border-slate-200 rounded-xl flex items-center justify-between text-xs">
            <div>
              <span className="text-slate-600">Active Session: </span>
              <span className="font-bold text-slate-900">{currentUser.name}</span>
              <span className="text-slate-500 text-[11px] block">{currentUser.email} ({currentUser.role})</span>
            </div>
            <span className="px-2 py-0.5 rounded bg-emerald-50 text-emerald-700 font-mono text-[10px] border border-emerald-300 font-bold">
              LOGGED IN
            </span>
          </div>
        )}

        {/* Front Portal Selection Buttons (ONLY Admin & User) */}
        <div className="space-y-4 pt-2">
          <div className="text-center text-xs font-semibold text-slate-700 uppercase tracking-wider mb-2">
            Select Access Portal
          </div>

          {/* Option 1: Admin */}
          <Link
            href="/admin"
            className="w-full p-4 bg-slate-50 hover:bg-slate-100 border border-slate-200 hover:border-slate-400 rounded-xl text-left transition-colors group flex items-center justify-between block"
          >
            <div className="flex items-center space-x-3">
              <div className="p-2.5 bg-red-50 rounded-lg border border-red-200 text-red-700">
                <Shield className="w-6 h-6" />
              </div>
              <div>
                <div className="font-bold text-slate-900 group-hover:text-black transition-colors text-sm">
                  Admin
                </div>
                <div className="text-[11px] text-slate-600">
                  System Administrator Login &amp; Dispatch Console (`/admin`)
                </div>
              </div>
            </div>
            <ChevronRight className="w-5 h-5 text-slate-400 group-hover:translate-x-1 transition-transform" />
          </Link>

          {/* Option 2: User */}
          <Link
            href="/user"
            className="w-full p-4 bg-slate-50 hover:bg-slate-100 border border-slate-200 hover:border-slate-400 rounded-xl text-left transition-colors group flex items-center justify-between block"
          >
            <div className="flex items-center space-x-3">
              <div className="p-2.5 bg-slate-200 rounded-lg border border-slate-300 text-slate-800">
                <User className="w-6 h-6" />
              </div>
              <div>
                <div className="font-bold text-slate-900 group-hover:text-black transition-colors text-sm">
                  User
                </div>
                <div className="text-[11px] text-slate-600">
                  Staff User Login (type user1, user2, user3, user4...)
                </div>
              </div>
            </div>
            <ChevronRight className="w-5 h-5 text-slate-400 group-hover:translate-x-1 transition-transform" />
          </Link>
        </div>

      </div>
    </div>
  );
}
