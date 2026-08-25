'use client';

import React from 'react';
import { useAuth } from '@/context/AuthContext';
import { ShieldAlert, ArrowRight, X } from 'lucide-react';

interface DispatchNotificationModalProps {
  onInspectPatient: (patientId: string) => void;
}

export const DispatchNotificationModal: React.FC<DispatchNotificationModalProps> = ({ onInspectPatient }) => {
  const { currentUser, assignments, acknowledgeAssignment } = useAuth();

  if (!currentUser) return null;

  const pending = assignments.filter(
    a => a.targetUserId === currentUser.id && a.status === 'PENDING'
  );

  if (pending.length === 0) return null;

  const currentDispatch = pending[0];

  const handleAction = () => {
    acknowledgeAssignment(currentDispatch.id);
    onInspectPatient(currentDispatch.patientId);
  };

  const handleDismiss = () => {
    acknowledgeAssignment(currentDispatch.id);
  };

  return (
    <div className="fixed bottom-6 right-6 z-50 w-full max-w-sm bg-white border border-slate-300 rounded-xl p-4 shadow-xl space-y-3 font-sans select-none animate-in fade-in slide-in-from-bottom-5">
      <div className="flex items-start justify-between">
        <div className="flex items-center space-x-2">
          <div className="p-1.5 bg-red-50 border border-red-200 text-red-700 rounded-lg">
            <ShieldAlert className="w-5 h-5" />
          </div>
          <div>
            <h4 className="text-xs font-bold text-slate-900 uppercase tracking-wider font-mono">
              Admin Dispatch Assignment
            </h4>
            <p className="text-[11px] text-slate-600">Urgent patient action required</p>
          </div>
        </div>

        <button
          onClick={handleDismiss}
          className="text-slate-400 hover:text-slate-700 transition-colors p-1"
        >
          <X className="w-4 h-4" />
        </button>
      </div>

      <div className="bg-slate-50 border border-slate-200 rounded-lg p-3 space-y-1 text-xs">
        <div className="font-bold text-slate-900 font-mono">
          Patient: {currentDispatch.patientNumber}
        </div>
        {currentDispatch.note && (
          <div className="text-slate-700 italic">
            &quot;{currentDispatch.note}&quot;
          </div>
        )}
      </div>

      <div className="flex items-center space-x-2 pt-1">
        <button
          onClick={handleAction}
          className="flex-1 py-2 bg-slate-900 hover:bg-black text-white rounded-lg text-xs font-semibold transition-colors flex items-center justify-center space-x-1.5"
        >
          <span>Inspect Patient</span>
          <ArrowRight className="w-3.5 h-3.5" />
        </button>
        <button
          onClick={handleDismiss}
          className="px-3 py-2 bg-slate-100 hover:bg-slate-200 border border-slate-300 text-slate-700 rounded-lg text-xs font-medium transition-colors"
        >
          Dismiss
        </button>
      </div>
    </div>
  );
};
