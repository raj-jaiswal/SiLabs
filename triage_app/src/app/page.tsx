'use client';

import React, { useEffect } from 'react';
import { useRouter } from 'next/navigation';
import { useAuth } from '@/context/AuthContext';
import { LoginPage } from '@/components/LoginPage';

export default function Home() {
  const { currentUser } = useAuth();
  const router = useRouter();

  useEffect(() => {
    if (currentUser) {
      if (currentUser.role === 'ADMIN') {
        router.push('/admin');
      } else {
        router.push('/user');
      }
    }
  }, [currentUser, router]);

  if (!currentUser) {
    return <LoginPage />;
  }

  return (
    <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center text-slate-300">
      <div className="w-10 h-10 border-4 border-sky-500 border-t-transparent rounded-full animate-spin mb-4" />
      <p className="text-sm font-medium text-slate-400">Redirecting to your hospital portal...</p>
    </div>
  );
}
