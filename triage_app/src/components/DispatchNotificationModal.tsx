'use client';

import React from 'react';
import { Send, ChevronRight, X, Bell } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';

interface DispatchNotificationModalProps {
  onInspectPatient: (patientId: string) => void;
}

export const DispatchNotificationModal: React.FC<DispatchNotificationModalProps> = ({ onInspectPatient }) => {
  const { currentUser, assignments, acknowledgeAssignment } = useAuth();

  if (!currentUser) return null;

  // Filter pending assignments targeting the logged in user
  const pending = assignments.filter(a => a.targetUserId === currentUser.id && a.status === 'PENDING');
  if (pending.length === 0) return null;

  const currentAssignment = pending[0];
  const pendingCount = pending.length;

  const handleInspect = () => {
    acknowledgeAssignment(currentAssignment.id);
    onInspectPatient(currentAssignment.patientId);
  };

  const handleDismiss = () => {
    acknowledgeAssignment(currentAssignment.id);
  };

  return (
    <aside 
      aria-label="Patient Dispatch Notification"
      className="fixed bottom-6 right-6 z-50 w-full max-w-md bg-slate-900 border-2 border-sky-500 rounded-2xl p-5 shadow-2xl animate-in slide-in-from-bottom-5 text-slate-100 shadow-sky-950/60"
    >
      <div className="flex items-start justify-between mb-3">
        <div className="flex items-center space-x-2 text-sky-400 font-bold text-xs uppercase tracking-wider">
          <div className="relative">
            <Send className="w-4 h-4 text-sky-400 animate-bounce" />
            <span className="absolute -top-1 -right-1 w-2 h-2 bg-sky-400 rounded-full animate-ping" />
          </div>
          <span>Admin Patient Dispatch Assignment</span>
          {pendingCount > 1 && (
            <span className="px-1.5 py-0.5 bg-sky-950 text-sky-300 border border-sky-800 rounded text-[10px] font-bold">
              +{pendingCount - 1} more
            </span>
          )}
        </div>
        <button
          onClick={handleDismiss}
          className="text-slate-400 hover:text-white p-1 rounded-lg hover:bg-slate-800 transition-colors"
          title="Dismiss notification"
        >
          <X className="w-4 h-4" />
        </button>
      </div>

      <div className="space-y-3 text-xs">
        <div className="flex items-baseline justify-between">
          <div className="text-base font-bold text-slate-100">
            Assigned to <span className="text-sky-400">{currentAssignment.patientNumber}</span>
          </div>
          {currentAssignment.dispatchedAt && (
            <span className="text-[11px] text-slate-400 font-mono">
              {currentAssignment.dispatchedAt}
            </span>
          )}
        </div>

        <div className="text-slate-300 bg-slate-950 p-3.5 rounded-xl border border-slate-800 italic">
          <div className="text-[10px] uppercase font-bold text-slate-400 not-italic tracking-wider mb-1 flex items-center">
            <Bell className="w-3 h-3 mr-1 text-sky-400" /> Dispatch Instructions:
          </div>
          "{currentAssignment.note}"
        </div>

        <div className="pt-1 flex items-center space-x-3">
          <button
            onClick={handleInspect}
            className="flex-1 py-2.5 bg-sky-600 hover:bg-sky-500 text-white font-bold rounded-lg flex items-center justify-center transition-colors shadow-md shadow-sky-950"
          >
            <span>Inspect {currentAssignment.patientNumber}</span>
            <ChevronRight className="w-4 h-4 ml-1" />
          </button>

          <button
            onClick={handleDismiss}
            className="px-4 py-2.5 bg-slate-800 hover:bg-slate-700 text-slate-300 rounded-lg font-medium transition-colors border border-slate-700 hover:text-white"
          >
            Dismiss
          </button>
        </div>
      </div>
    </aside>
  );
};
