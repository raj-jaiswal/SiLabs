# Auth & Admin Sidebar Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use `superpowers:subagent-driven-development` (recommended) or `superpowers:executing-plans` to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add a simple Authentication System (Admin + 3 Users), an Admin Sidebar (Active User Tracking, Dynamic User Creation, Patient Dispatch), and a User Notification Toast System to `triage_app`.

**Architecture:** A React Context (`AuthContext.tsx`) managing logged-in state, active user tracking, dynamic user additions, and patient assignment dispatches. Includes a simple `LoginPage.tsx` with 1-click demo logins, an `AdminSidebar.tsx` for Admin monitoring/management, and a `DispatchNotificationModal.tsx` for staff users receiving patient assignments.

**Tech Stack:** React Context, Next.js 14, TypeScript, Tailwind CSS, Lucide React Icons.

## Global Constraints

- App Root: `/home/logan78/Desktop/SiLabs/triage_app`
- Default Accounts:
  - Admin: `admin@hospital.com` / `admin`
  - User 1: `user1@hospital.com` / `user1`
  - User 2: `user2@hospital.com` / `user2`
  - User 3: `user3@hospital.com` / `user3`
- Theme: Monochromatic Slate/Zinc hospital aesthetic

---

### Task 1: Create Auth Types & Auth Context (`src/context/AuthContext.tsx`)

**Files:**
- Create: `triage_app/src/types/auth.ts`
- Create: `triage_app/src/context/AuthContext.tsx`

**Interfaces:**
- Consumes: Nothing
- Produces: `AuthContext`, `useAuth()` hook, `User` type, `DispatchAssignment` type

- [ ] **Step 1: Write `triage_app/src/types/auth.ts`**

```ts
export type UserRole = 'ADMIN' | 'USER';

export interface UserAccount {
  id: string;
  name: string;
  email: string;
  password: string;
  role: UserRole;
  createdAt: string;
}

export interface ActiveSession {
  user: UserAccount;
  loginTime: string;
}

export interface PatientDispatchAssignment {
  id: string;
  targetUserId: string;
  patientId: string;
  patientNumber: string;
  note: string;
  dispatchedAt: string;
  status: 'PENDING' | 'ACKNOWLEDGED';
}
```

- [ ] **Step 2: Write `triage_app/src/context/AuthContext.tsx`**

```tsx
'use client';

import React, { createContext, useContext, useState, useEffect, ReactNode } from 'react';
import { UserAccount, PatientDispatchAssignment } from '../types/auth';

const DEFAULT_USERS: UserAccount[] = [
  { id: '1', name: 'Admin', email: 'admin@hospital.com', password: 'admin', role: 'ADMIN', createdAt: new Date().toISOString() },
  { id: '2', name: 'User 1', email: 'user1@hospital.com', password: 'user1', role: 'USER', createdAt: new Date().toISOString() },
  { id: '3', name: 'User 2', email: 'user2@hospital.com', password: 'user2', role: 'USER', createdAt: new Date().toISOString() },
  { id: '4', name: 'User 3', email: 'user3@hospital.com', password: 'user3', role: 'USER', createdAt: new Date().toISOString() },
];

interface AuthContextType {
  currentUser: UserAccount | null;
  users: UserAccount[];
  assignments: PatientDispatchAssignment[];
  login: (email: string, pass: string) => boolean;
  logout: () => void;
  addUser: (name: string, email: string, pass: string) => boolean;
  dispatchUserToPatient: (targetUserId: string, patientId: string, patientNumber: string, note: string) => void;
  acknowledgeAssignment: (assignmentId: string) => void;
}

const AuthContext = createContext<AuthContextType | undefined>(undefined);

export const AuthProvider: React.FC<{ children: ReactNode }> = ({ children }) => {
  const [users, setUsers] = useState<UserAccount[]>(DEFAULT_USERS);
  const [currentUser, setCurrentUser] = useState<UserAccount | null>(null);
  const [assignments, setAssignments] = useState<PatientDispatchAssignment[]>([]);

  // Load state from localStorage on mount
  useEffect(() => {
    const savedUsers = localStorage.getItem('silabs_users');
    if (savedUsers) {
      try { setUsers(JSON.parse(savedUsers)); } catch (e) {}
    }
    const savedCurUser = localStorage.getItem('silabs_current_user');
    if (savedCurUser) {
      try { setCurrentUser(JSON.parse(savedCurUser)); } catch (e) {}
    }
    const savedAssignments = localStorage.getItem('silabs_assignments');
    if (savedAssignments) {
      try { setAssignments(JSON.parse(savedAssignments)); } catch (e) {}
    }
  }, []);

  const login = (email: string, pass: string): boolean => {
    const found = users.find(u => u.email.toLowerCase() === email.toLowerCase() && u.password === pass);
    if (found) {
      setCurrentUser(found);
      localStorage.setItem('silabs_current_user', JSON.stringify(found));
      return true;
    }
    return false;
  };

  const logout = () => {
    setCurrentUser(null);
    localStorage.removeItem('silabs_current_user');
  };

  const addUser = (name: string, email: string, pass: string): boolean => {
    if (users.some(u => u.email.toLowerCase() === email.toLowerCase())) {
      return false;
    }
    const newUser: UserAccount = {
      id: String(Date.now()),
      name,
      email,
      password: pass,
      role: 'USER',
      createdAt: new Date().toISOString(),
    };
    const updated = [...users, newUser];
    setUsers(updated);
    localStorage.setItem('silabs_users', JSON.stringify(updated));
    return true;
  };

  const dispatchUserToPatient = (targetUserId: string, patientId: string, patientNumber: string, note: string) => {
    const newAssign: PatientDispatchAssignment = {
      id: String(Date.now()),
      targetUserId,
      patientId,
      patientNumber,
      note,
      dispatchedAt: new Date().toLocaleTimeString(),
      status: 'PENDING',
    };
    const updated = [newAssign, ...assignments];
    setAssignments(updated);
    localStorage.setItem('silabs_assignments', JSON.stringify(updated));
  };

  const acknowledgeAssignment = (assignmentId: string) => {
    const updated = assignments.map(a => a.id === assignmentId ? { ...a, status: 'ACKNOWLEDGED' as const } : a);
    setAssignments(updated);
    localStorage.setItem('silabs_assignments', JSON.stringify(updated));
  };

  return (
    <AuthContext.Provider value={{
      currentUser,
      users,
      assignments,
      login,
      logout,
      addUser,
      dispatchUserToPatient,
      acknowledgeAssignment
    }}>
      {children}
    </AuthContext.Provider>
  );
};

export const useAuth = () => {
  const context = useContext(AuthContext);
  if (!context) throw new Error('useAuth must be used within an AuthProvider');
  return context;
};
```

- [ ] **Step 3: Commit Task 1**

```bash
git add triage_app/src/types/auth.ts triage_app/src/context/AuthContext.tsx
git commit -m "feat(triage_app): add AuthContext with user management and patient dispatching"
```

---

### Task 2: Build Simple Login Screen (`src/components/LoginPage.tsx`)

**Files:**
- Create: `triage_app/src/components/LoginPage.tsx`

**Interfaces:**
- Consumes: `useAuth()`
- Produces: Simple Login Screen with 1-click demo login buttons

- [ ] **Step 1: Write `triage_app/src/components/LoginPage.tsx`**

```tsx
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
```

- [ ] **Step 2: Commit Task 2**

```bash
git add triage_app/src/components/LoginPage.tsx
git commit -m "feat(triage_app): add LoginPage component with quick demo logins"
```

---

### Task 3: Build Admin Sidebar & Dispatch Console (`src/components/AdminSidebar.tsx`)

**Files:**
- Create: `triage_app/src/components/AdminSidebar.tsx`

**Interfaces:**
- Consumes: `useAuth()`, patient list
- Produces: Admin Control Panel with Active User Monitor, Add User Form, and Patient Dispatch Console

- [ ] **Step 1: Write `triage_app/src/components/AdminSidebar.tsx`**

```tsx
'use client';

import React, { useState } from 'react';
import { Shield, UserPlus, Send, Users, Activity, X } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';

interface AdminSidebarProps {
  patients: PatientState[];
  isOpen: boolean;
  onClose: () => void;
}

export const AdminSidebar: React.FC<AdminSidebarProps> = ({ patients, isOpen, onClose }) => {
  const { currentUser, users, addUser, dispatchUserToPatient } = useAuth();
  
  // Add User Form State
  const [newName, setNewName] = useState('');
  const [newEmail, setNewEmail] = useState('');
  const [newPassword, setNewPassword] = useState('');
  const [addSuccess, setAddSuccess] = useState('');

  // Dispatch Form State
  const [targetUserId, setTargetUserId] = useState('');
  const [selectedPatientId, setSelectedPatientId] = useState('');
  const [dispatchNote, setDispatchNote] = useState('');
  const [dispatchSuccess, setDispatchSuccess] = useState('');

  if (!isOpen || currentUser?.role !== 'ADMIN') return null;

  const handleAddUser = (e: React.FormEvent) => {
    e.preventDefault();
    if (addUser(newName, newEmail, newPassword)) {
      setAddSuccess(`User "${newName}" created successfully!`);
      setNewName(''); setNewEmail(''); setNewPassword('');
      setTimeout(() => setAddSuccess(''), 3000);
    }
  };

  const handleDispatch = (e: React.FormEvent) => {
    e.preventDefault();
    const patient = patients.find(p => p.profile.id === selectedPatientId);
    if (targetUserId && patient) {
      dispatchUserToPatient(targetUserId, patient.profile.id, patient.profile.patientNumber, dispatchNote);
      setDispatchSuccess(`Dispatched to ${patient.profile.patientNumber}!`);
      setDispatchNote('');
      setTimeout(() => setDispatchSuccess(''), 3000);
    }
  };

  return (
    <div className="fixed inset-y-0 left-0 z-50 w-96 bg-slate-900 border-r border-slate-800 shadow-2xl flex flex-col overflow-y-auto">
      
      {/* Header */}
      <div className="p-5 bg-slate-950 border-b border-slate-800 flex items-center justify-between">
        <div className="flex items-center space-x-2 text-rose-400 font-bold">
          <Shield className="w-5 h-5" />
          <span className="uppercase tracking-wider text-sm">Admin Control Panel</span>
        </div>
        <button onClick={onClose} className="p-1 rounded text-slate-400 hover:text-white">
          <X className="w-5 h-5" />
        </button>
      </div>

      <div className="p-5 space-y-6 flex-1 text-xs">
        
        {/* 1. Active Session Monitor */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-2">
          <h3 className="font-bold text-slate-300 uppercase tracking-wider flex items-center">
            <Users className="w-3.5 h-3.5 mr-1.5 text-emerald-400" /> Active User Session
          </h3>
          <div className="p-3 bg-emerald-950/40 border border-emerald-900 rounded-lg flex items-center justify-between">
            <div>
              <div className="font-bold text-emerald-300">{currentUser.name}</div>
              <div className="text-[11px] text-slate-400">{currentUser.email}</div>
            </div>
            <span className="px-2 py-0.5 rounded bg-emerald-900 text-emerald-200 text-[10px] font-bold uppercase">
              ONLINE NOW
            </span>
          </div>
        </div>

        {/* 2. Dispatch User to Patient */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-3">
          <h3 className="font-bold text-slate-300 uppercase tracking-wider flex items-center">
            <Send className="w-3.5 h-3.5 mr-1.5 text-sky-400" /> Dispatch User to Patient
          </h3>

          {dispatchSuccess && (
            <div className="p-2 bg-emerald-950 text-emerald-300 rounded font-semibold text-center">
              {dispatchSuccess}
            </div>
          )}

          <form onSubmit={handleDispatch} className="space-y-3">
            <div>
              <label className="block text-slate-400 mb-1">Target User</label>
              <select
                required
                value={targetUserId}
                onChange={e => setTargetUserId(e.target.value)}
                className="w-full bg-slate-900 border border-slate-800 rounded px-3 py-2 text-slate-100"
              >
                <option value="">-- Select User --</option>
                {users.filter(u => u.role !== 'ADMIN').map(u => (
                  <option key={u.id} value={u.id}>{u.name} ({u.email})</option>
                ))}
              </select>
            </div>

            <div>
              <label className="block text-slate-400 mb-1">Target Patient</label>
              <select
                required
                value={selectedPatientId}
                onChange={e => setSelectedPatientId(e.target.value)}
                className="w-full bg-slate-900 border border-slate-800 rounded px-3 py-2 text-slate-100"
              >
                <option value="">-- Select Patient --</option>
                {patients.map(p => (
                  <option key={p.profile.id} value={p.profile.id}>
                    {p.profile.patientNumber} ({p.triageRank.replace('P', 'P')})
                  </option>
                ))}
              </select>
            </div>

            <div>
              <label className="block text-slate-400 mb-1">Urgent Clinical Note</label>
              <input
                type="text"
                required
                value={dispatchNote}
                onChange={e => setDispatchNote(e.target.value)}
                placeholder="e.g. Proceed immediately for severe Hypotension"
                className="w-full bg-slate-900 border border-slate-800 rounded px-3 py-2 text-slate-100"
              />
            </div>

            <button
              type="submit"
              className="w-full py-2 bg-sky-600 hover:bg-sky-500 font-bold text-white rounded transition-colors"
            >
              Send Dispatch Notification
            </button>
          </form>
        </div>

        {/* 3. Add New User Form */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-3">
          <h3 className="font-bold text-slate-300 uppercase tracking-wider flex items-center">
            <UserPlus className="w-3.5 h-3.5 mr-1.5 text-amber-400" /> Add New Staff User
          </h3>

          {addSuccess && (
            <div className="p-2 bg-emerald-950 text-emerald-300 rounded font-semibold text-center">
              {addSuccess}
            </div>
          )}

          <form onSubmit={handleAddUser} className="space-y-3">
            <div>
              <label className="block text-slate-400 mb-1">Name</label>
              <input
                type="text"
                required
                value={newName}
                onChange={e => setNewName(e.target.value)}
                placeholder="User 4"
                className="w-full bg-slate-900 border border-slate-800 rounded px-3 py-2 text-slate-100"
              />
            </div>

            <div>
              <label className="block text-slate-400 mb-1">Email</label>
              <input
                type="email"
                required
                value={newEmail}
                onChange={e => setNewEmail(e.target.value)}
                placeholder="user4@hospital.com"
                className="w-full bg-slate-900 border border-slate-800 rounded px-3 py-2 text-slate-100"
              />
            </div>

            <div>
              <label className="block text-slate-400 mb-1">Password</label>
              <input
                type="text"
                required
                value={newPassword}
                onChange={e => setNewPassword(e.target.value)}
                placeholder="user4"
                className="w-full bg-slate-900 border border-slate-800 rounded px-3 py-2 text-slate-100"
              />
            </div>

            <button
              type="submit"
              className="w-full py-2 bg-amber-600 hover:bg-amber-500 font-bold text-white rounded transition-colors"
            >
              Create User Account
            </button>
          </form>
        </div>

        {/* 4. Registered Users Directory */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-4 space-y-2">
          <h3 className="font-bold text-slate-300 uppercase tracking-wider">Registered Accounts &amp; Passwords</h3>
          <div className="divide-y divide-slate-800">
            {users.map(u => (
              <div key={u.id} className="py-2 flex items-center justify-between">
                <div>
                  <div className="font-semibold text-slate-200">{u.name}</div>
                  <div className="text-[11px] text-slate-400">{u.email}</div>
                </div>
                <div className="text-right">
                  <span className="px-1.5 py-0.5 bg-slate-800 rounded font-mono text-[10px] text-slate-300 border border-slate-700">
                    Pass: {u.password}
                  </span>
                </div>
              </div>
            ))}
          </div>
        </div>

      </div>
    </div>
  );
};
```

- [ ] **Step 2: Commit Task 3**

```bash
git add triage_app/src/components/AdminSidebar.tsx
git commit -m "feat(triage_app): add AdminSidebar component with user creation and patient dispatch"
```

---

### Task 4: Build User Dispatch Notification Toast (`src/components/DispatchNotificationModal.tsx`)

**Files:**
- Create: `triage_app/src/components/DispatchNotificationModal.tsx`

**Interfaces:**
- Consumes: `useAuth()`, `onInspectPatient(patientId)`
- Produces: Pop-up notification toast when Admin assigns logged-in user to a patient

- [ ] **Step 1: Write `triage_app/src/components/DispatchNotificationModal.tsx`**

```tsx
'use client';

import React from 'react';
import { Send, ChevronRight, X, AlertCircle } from 'lucide-react';
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

  return (
    <div className="fixed bottom-6 right-6 z-50 w-full max-w-md bg-slate-900 border-2 border-sky-500 rounded-2xl p-5 shadow-2xl animate-in slide-in-from-bottom-5 text-slate-100">
      <div className="flex items-start justify-between mb-3">
        <div className="flex items-center space-x-2 text-sky-400 font-bold text-xs uppercase tracking-wider">
          <Send className="w-4 h-4 animate-bounce" />
          <span>ADMIN PATIENT DISPATCH ASSIGNMENT</span>
        </div>
        <button
          onClick={() => acknowledgeAssignment(currentAssignment.id)}
          className="text-slate-400 hover:text-white p-1"
        >
          <X className="w-4 h-4" />
        </button>
      </div>

      <div className="space-y-2 text-xs">
        <div className="text-base font-bold text-slate-100">
          Assigned to <span className="text-sky-400">{currentAssignment.patientNumber}</span>
        </div>
        <p className="text-slate-300 bg-slate-950 p-3 rounded-lg border border-slate-800 italic">
          "{currentAssignment.note}"
        </p>

        <div className="pt-2 flex items-center space-x-3">
          <button
            onClick={() => {
              acknowledgeAssignment(currentAssignment.id);
              onInspectPatient(currentAssignment.patientId);
            }}
            className="flex-1 py-2 bg-sky-600 hover:bg-sky-500 text-white font-bold rounded-lg flex items-center justify-center transition-colors"
          >
            Inspect {currentAssignment.patientNumber} <ChevronRight className="w-4 h-4 ml-1" />
          </button>

          <button
            onClick={() => acknowledgeAssignment(currentAssignment.id)}
            className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-300 rounded-lg font-medium"
          >
            Dismiss
          </button>
        </div>
      </div>
    </div>
  );
};
```

- [ ] **Step 2: Commit Task 4**

```bash
git add triage_app/src/components/DispatchNotificationModal.tsx
git commit -m "feat(triage_app): add DispatchNotificationModal component"
```

---

### Task 5: Integrate Auth Context & Update Header/Page components

**Files:**
- Modify: `triage_app/src/components/Header.tsx`
- Modify: `triage_app/src/app/page.tsx`
- Modify: `triage_app/src/app/layout.tsx`

**Interfaces:**
- Consumes: All auth components & layout
- Produces: Integrated Auth flow with Admin sidebar and Logout button

- [ ] **Step 1: Update `triage_app/src/app/layout.tsx` to wrap children in `AuthProvider`**

```tsx
import './globals.css'
import { ReactNode } from 'react'
import { AuthProvider } from '@/context/AuthContext'

export const metadata = {
  title: 'Clinical Triage Monitor | SiLabs ICU',
  description: 'Hospital Triage & Adverse Event Real-Time Simulator',
}

export default function RootLayout({ children }: { children: ReactNode }) {
  return (
    <html lang="en" className="dark">
      <body className="bg-slate-950 text-slate-100 min-h-screen antialiased">
        <AuthProvider>
          {children}
        </AuthProvider>
      </body>
    </html>
  )
}
```

- [ ] **Step 2: Update `triage_app/src/components/Header.tsx`**

Add user session badge, Admin Panel toggle, and Logout button.

```tsx
import React from 'react';
import { HeartPulse, ShieldAlert, AlertTriangle, CheckCircle, User, LogOut, Shield } from 'lucide-react';
import { PatientState } from '../types/patient';
import { useAuth } from '@/context/AuthContext';

interface HeaderProps {
  patients: PatientState[];
  strideCount: number;
  onOpenAdminSidebar?: () => void;
}

export const Header: React.FC<HeaderProps> = ({ patients, strideCount, onOpenAdminSidebar }) => {
  const { currentUser, logout } = useAuth();

  const criticalCount = patients.filter(p => p.triageRank === 'P1_CRITICAL').length;
  const highCount = patients.filter(p => p.triageRank === 'P2_HIGH').length;
  const moderateCount = patients.filter(p => p.triageRank === 'P3_MODERATE').length;
  const stableCount = patients.filter(p => p.triageRank === 'P4_STABLE').length;

  const elapsedSec = strideCount * 5;
  const mins = Math.floor(elapsedSec / 60);
  const secs = elapsedSec % 60;
  const formattedTime = `${String(mins).padStart(2, '0')}:${String(secs).padStart(2, '0')}`;

  return (
    <header className="bg-slate-900 border-b border-slate-800 px-6 py-4">
      <div className="max-w-7xl mx-auto flex flex-col lg:flex-row lg:items-center lg:justify-between gap-4">
        
        {/* Title & Live Status Pill */}
        <div className="flex items-center space-x-3">
          <div className="p-2.5 bg-slate-800 rounded-lg border border-slate-700 text-sky-400">
            <HeartPulse className="w-6 h-6 animate-pulse text-sky-400" />
          </div>
          <div>
            <div className="flex items-center space-x-2 flex-wrap gap-y-1">
              <h1 className="text-xl font-bold tracking-tight text-slate-100 uppercase">
                Clinical Triage Monitor
              </h1>
              <span className="inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-semibold bg-emerald-950 text-emerald-400 border border-emerald-800">
                <span className="relative flex h-2 w-2 mr-1.5">
                  <span className="animate-ping absolute inline-flex h-full w-full rounded-full bg-emerald-400 opacity-75"></span>
                  <span className="relative inline-flex rounded-full h-2 w-2 bg-emerald-500"></span>
                </span>
                LIVE 5s STRIDE #{strideCount} • {elapsedSec} SECONDS ({formattedTime})
              </span>
            </div>
            <p className="text-xs text-slate-400 mt-0.5">
              SiLabs Intraoperative Adverse Event Predictor • Hypotension | Hypoxia | Tachycardia
            </p>
          </div>
        </div>

        {/* User Session & Admin Controls */}
        <div className="flex items-center space-x-3 justify-between lg:justify-end">
          {currentUser && (
            <div className="flex items-center space-x-2 bg-slate-950 px-3 py-1.5 rounded-lg border border-slate-800 text-xs">
              <User className="w-3.5 h-3.5 text-sky-400" />
              <span className="font-semibold text-slate-200">{currentUser.name}</span>
              <span className="text-[10px] px-1.5 py-0.5 rounded bg-slate-800 text-slate-400 uppercase font-bold">
                {currentUser.role}
              </span>
            </div>
          )}

          {currentUser?.role === 'ADMIN' && onOpenAdminSidebar && (
            <button
              onClick={onOpenAdminSidebar}
              className="px-3 py-1.5 bg-rose-950/80 hover:bg-rose-900 text-rose-200 rounded-lg text-xs font-bold border border-rose-800 flex items-center transition-colors"
            >
              <Shield className="w-3.5 h-3.5 mr-1.5 text-rose-400" /> Admin Panel
            </button>
          )}

          <button
            onClick={logout}
            className="p-1.5 bg-slate-800 hover:bg-slate-700 text-slate-300 rounded-lg border border-slate-700 transition-colors"
            title="Sign Out"
          >
            <LogOut className="w-4 h-4" />
          </button>
        </div>

      </div>
    </header>
  );
};

export default Header;
```

- [ ] **Step 3: Update `triage_app/src/app/page.tsx`**

Integrate Auth gate (`LoginPage` if `!currentUser`), `AdminSidebar`, and `DispatchNotificationModal`.

```tsx
'use client';

import React, { useEffect, useState } from 'react';
import { Header } from '@/components/Header';
import { TriageTable } from '@/components/TriageTable';
import { PatientDrawer } from '@/components/PatientDrawer';
import { CriticalAlertBar } from '@/components/CriticalAlertBar';
import { AdminSidebar } from '@/components/AdminSidebar';
import { LoginPage } from '@/components/LoginPage';
import { DispatchNotificationModal } from '@/components/DispatchNotificationModal';
import { useAuth } from '@/context/AuthContext';
import { PatientState } from '@/types/patient';
import { evaluatePatientRisk } from '@/utils/triageEngine';

export default function Home() {
  const { currentUser } = useAuth();
  const [patients, setPatients] = useState<PatientState[]>([]);
  const [selectedPatientId, setSelectedPatientId] = useState<string | null>(null);
  const [strideCount, setStrideCount] = useState<number>(0);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);
  const [dismissAlertBar, setDismissAlertBar] = useState<boolean>(false);
  const [isAdminSidebarOpen, setIsAdminSidebarOpen] = useState<boolean>(false);

  // 1. Fetch patient data from API on mount
  useEffect(() => {
    async function loadPatients() {
      try {
        const res = await fetch('/api/patients');
        const data = await res.json();
        if (data.error) {
          setError(data.error);
        } else if (data.patients) {
          setPatients(data.patients);
        }
      } catch (err: any) {
        setError(err.message || 'Failed to load patient telemetry');
      } finally {
        setLoading(false);
      }
    }
    loadPatients();
  }, []);

  // 2. Automatic Continuous 5-Second Stride Loop
  useEffect(() => {
    if (patients.length === 0 || !currentUser) return;

    const interval = setInterval(() => {
      setStrideCount(prev => prev + 1);

      setPatients(prevPatients =>
        prevPatients.map(patient => {
          if (!patient.vitalsHistory || patient.vitalsHistory.length === 0) return patient;
          const nextIndex = (patient.currentFrameIndex + 1) % patient.vitalsHistory.length;
          const currentFrame = patient.vitalsHistory[nextIndex];
          const riskEval = evaluatePatientRisk(patient.vitalsHistory, nextIndex);

          return {
            ...patient,
            currentFrameIndex: nextIndex,
            currentFrame,
            hypotension: riskEval.hypotension,
            hypoxia: riskEval.hypoxia,
            tachycardia: riskEval.tachycardia,
            triageRank: riskEval.triageRank,
            activeEventCount: riskEval.activeEventCount,
          };
        })
      );
    }, 5000); // 5-second stride update

    return () => clearInterval(interval);
  }, [patients.length, currentUser]);

  // Derived currently selected patient
  const selectedPatient = selectedPatientId
    ? patients.find(p => p.profile.id === selectedPatientId) || null
    : null;

  const criticalPatients = patients.filter(p => p.triageRank === 'P1_CRITICAL');

  // Auth Gate: Show LoginPage if not authenticated
  if (!currentUser) {
    return <LoginPage />;
  }

  if (loading) {
    return (
      <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center text-slate-300">
        <div className="w-10 h-10 border-4 border-sky-500 border-t-transparent rounded-full animate-spin mb-4" />
        <p className="text-sm font-medium text-slate-400">Loading Patient Telemetry &amp; Initializing Triage Engine...</p>
      </div>
    );
  }

  return (
    <main className="min-h-screen bg-slate-950 flex flex-col">
      <Header
        patients={patients}
        strideCount={strideCount}
        onOpenAdminSidebar={() => setIsAdminSidebarOpen(true)}
      />
      
      {!dismissAlertBar && (
        <CriticalAlertBar
          criticalPatients={criticalPatients}
          onSelectPatient={(id) => setSelectedPatientId(id)}
          onDismiss={() => setDismissAlertBar(true)}
        />
      )}

      <div className="flex-1">
        <TriageTable
          patients={patients}
          onSelectPatient={(patient) => setSelectedPatientId(patient.profile.id)}
        />
      </div>

      <PatientDrawer
        patient={selectedPatient}
        onClose={() => setSelectedPatientId(null)}
      />

      <AdminSidebar
        patients={patients}
        isOpen={isAdminSidebarOpen}
        onClose={() => setIsAdminSidebarOpen(false)}
      />

      <DispatchNotificationModal
        onInspectPatient={(patientId) => setSelectedPatientId(patientId)}
      />
    </main>
  );
}
```

- [ ] **Step 4: Verify production build of Next.js app**

Run: `cd /home/logan78/Desktop/SiLabs/triage_app && npm run build`  
Expected: `Compiled successfully` with zero errors.

- [ ] **Step 5: Commit Task 5**

```bash
git add triage_app/src/
git commit -m "feat(triage_app): complete auth flow, admin sidebar, and patient dispatch system"
```
