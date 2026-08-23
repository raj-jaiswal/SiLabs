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
