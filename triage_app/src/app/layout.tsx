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

