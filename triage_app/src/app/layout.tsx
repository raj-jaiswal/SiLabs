import './globals.css'
import { ReactNode } from 'react'
import { AuthProvider } from '@/context/AuthContext'

export const metadata = {
  title: 'Clinical Triage Monitor | SiLabs ICU',
  description: 'Hospital Triage & Adverse Event Real-Time Telemetry Monitor',
}

export default function RootLayout({ children }: { children: ReactNode }) {
  return (
    <html lang="en">
      <body className="bg-white text-slate-900 min-h-screen antialiased">
        <AuthProvider>
          {children}
        </AuthProvider>
      </body>
    </html>
  )
}
