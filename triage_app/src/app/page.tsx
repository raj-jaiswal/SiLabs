'use client';

import React from 'react';
import Link from 'next/link';
import { Activity, Shield, User, ChevronRight } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';

export default function Home() {
  const { currentUser } = useAuth();

  return (
    <div className="min-h-screen bg-surface-container-low flex flex-col items-center justify-center p-6 text-on-surface font-body-md select-none">
      <div className="w-full max-w-md bg-surface-container-lowest border border-outline-variant rounded-xl p-8 shadow-sm space-y-6">
        
        {/* Brand Header */}
        <div className="text-center space-y-2">
          <div className="inline-flex p-3 bg-primary-container/10 rounded-xl border border-primary-container/20 text-primary mb-2">
            <span className="material-symbols-outlined text-[32px]">monitor_heart</span>
          </div>
          <h1 className="text-headline-md font-headline-md font-black tracking-tight uppercase text-primary">ICU Sentinel Portal</h1>
          <p className="text-body-md font-body-md text-on-surface-variant">SiLabs Intraoperative Monitoring &amp; Patient Dispatch System</p>
        </div>

        {/* Current Active Session Status if logged in */}
        {currentUser && (
          <div className="p-4 bg-surface-container border border-outline-variant rounded-xl flex items-center justify-between text-body-md">
            <div>
              <span className="text-on-surface-variant">Active Session: </span>
              <span className="font-bold text-on-surface">{currentUser.name}</span>
              <span className="text-on-surface-variant text-[12px] block font-label-mono">{currentUser.email} ({currentUser.role})</span>
            </div>
            <span className="px-2 py-0.5 rounded bg-tertiary-container/10 text-tertiary-container font-label-mono text-[10px] border border-tertiary-container/30 font-bold tracking-wider">
              LOGGED IN
            </span>
          </div>
        )}

        {/* Front Portal Selection Buttons (ONLY Admin & User) */}
        <div className="space-y-4 pt-2">
          <div className="text-center text-label-mono font-label-mono text-on-surface-variant uppercase tracking-wider mb-2">
            Select Access Portal
          </div>

          {/* Option 1: Admin */}
          <Link
            href="/admin"
            className="w-full p-4 bg-surface border border-outline-variant hover:border-primary rounded-xl text-left transition-colors group flex items-center justify-between block hover:shadow-sm"
          >
            <div className="flex items-center space-x-4">
              <div className="p-3 bg-error-container/20 rounded-lg border border-error/20 text-error flex items-center justify-center">
                <span className="material-symbols-outlined">admin_panel_settings</span>
              </div>
              <div>
                <div className="font-headline-md text-[16px] text-on-surface group-hover:text-primary transition-colors">
                  Admin
                </div>
                <div className="text-body-md text-[12px] text-on-surface-variant mt-0.5">
                  System Administrator Login &amp; Dispatch Console (`/admin`)
                </div>
              </div>
            </div>
            <span className="material-symbols-outlined text-outline-variant group-hover:text-primary group-hover:translate-x-1 transition-all">chevron_right</span>
          </Link>

          {/* Option 2: User */}
          <Link
            href="/user"
            className="w-full p-4 bg-surface border border-outline-variant hover:border-primary rounded-xl text-left transition-colors group flex items-center justify-between block hover:shadow-sm"
          >
            <div className="flex items-center space-x-4">
              <div className="p-3 bg-primary-container/10 rounded-lg border border-primary-container/20 text-primary flex items-center justify-center">
                <span className="material-symbols-outlined">badge</span>
              </div>
              <div>
                <div className="font-headline-md text-[16px] text-on-surface group-hover:text-primary transition-colors">
                  User
                </div>
                <div className="text-body-md text-[12px] text-on-surface-variant mt-0.5">
                  Staff User Login (type user1, user2, user3, user4...)
                </div>
              </div>
            </div>
            <span className="material-symbols-outlined text-outline-variant group-hover:text-primary group-hover:translate-x-1 transition-all">chevron_right</span>
          </Link>
        </div>

      </div>
    </div>
  );
}
