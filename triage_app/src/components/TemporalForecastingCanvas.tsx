import React from 'react';
import { PatientState } from '../types/patient';
import { Activity, Sparkles } from 'lucide-react';

interface TemporalForecastingCanvasProps {
  patients: PatientState[];
  strideCount: number;
}

export const TemporalForecastingCanvas: React.FC<TemporalForecastingCanvasProps> = ({
  patients,
  strideCount,
}) => {
  const criticalCount = patients.filter(p => p.triageRank === 'P1_CRITICAL').length;
  const highCount = patients.filter(p => p.triageRank === 'P2_HIGH').length;

  return (
    <div className="bg-[#0D1117] border border-[#1E2631] rounded-xl p-6 relative overflow-hidden shadow-2xl bg-grid-pattern select-none">
      {/* Visual Ambient Glows */}
      <div className="absolute top-0 right-1/3 w-96 h-96 bg-cyan-500/5 rounded-full blur-3xl pointer-events-none" />
      <div className="absolute bottom-0 left-1/4 w-96 h-96 bg-rose-500/5 rounded-full blur-3xl pointer-events-none" />

      {/* Header Bar */}
      <div className="flex items-center justify-between pb-4 border-b border-[#1E2631] mb-6">
        <div>
          <div className="flex items-center space-x-3">
            <h2 className="text-base font-bold text-[#F5F7FA] tracking-wider uppercase flex items-center space-x-2">
              <span>TEMPORAL ADVERSE EVENT FORECASTING ENGINE</span>
            </h2>
            <span className="px-2 py-0.5 rounded text-[10px] font-mono font-bold bg-cyan-950/80 text-cyan-300 border border-cyan-800/80 flex items-center">
              <Sparkles className="w-3 h-3 mr-1 text-cyan-400 animate-pulse" />
              SUB-SECOND AI INFERENCE
            </span>
          </div>
          <p className="text-xs text-[#9AA4B2] mt-0.5 font-sans">
            Real-Time Intraoperative Trajectories • 600s Predictive Horizon (Hypotension | Hypoxia | Tachycardia)
          </p>
        </div>

        {/* Timeline Horizon Indicator */}
        <div className="flex items-center space-x-6 text-xs font-mono">
          <div className="flex items-center space-x-2">
            <span className="w-2.5 h-2.5 rounded-full bg-cyan-400 shadow-[0_0_8px_#00F0FF]" />
            <span className="text-[#F5F7FA]">PAST (0 - {strideCount * 5}s)</span>
          </div>
          <span className="text-slate-600">|</span>
          <div className="flex items-center space-x-2">
            <span className="w-2.5 h-2.5 rounded-full bg-emerald-400 animate-ping" />
            <span className="text-emerald-400 font-bold">NOW</span>
          </div>
          <span className="text-slate-600">|</span>
          <div className="flex items-center space-x-2">
            <span className="w-2.5 h-2.5 rounded-full bg-rose-500/80 border border-dashed border-rose-300" />
            <span className="text-[#9AA4B2]">FUTURE (+600s FORECAST)</span>
          </div>
        </div>
      </div>

      {/* Hero Forecasting Graph Canvas */}
      <div className="h-64 w-full relative border border-[#1E2631]/80 rounded-lg bg-[#080B10]/90 p-4 font-mono">
        
        {/* Past / Now / Future Overlay Grid Lines */}
        <div className="absolute inset-0 flex pointer-events-none">
          {/* Past Region */}
          <div className="w-1/2 h-full border-r border-dashed border-cyan-500/40 relative bg-gradient-to-r from-cyan-950/10 to-transparent">
            <span className="absolute top-2 left-3 text-[10px] text-cyan-400 font-bold uppercase tracking-widest">
              PAST OBSERVED VITALS (SOLID)
            </span>
          </div>
          
          {/* NOW Vertical Pulse Line */}
          <div className="absolute top-0 bottom-0 left-1/2 w-0.5 bg-emerald-400 shadow-[0_0_12px_#22c55e] z-10 flex flex-col justify-between items-center">
            <span className="px-1.5 py-0.5 bg-emerald-950 text-emerald-300 border border-emerald-500 rounded text-[9px] font-bold tracking-widest -mt-2">
              NOW (T={strideCount * 5}s)
            </span>
            <span className="w-3 h-3 rounded-full bg-emerald-400 animate-ping mb-2" />
          </div>

          {/* Future Region */}
          <div className="w-1/2 h-full relative bg-gradient-to-r from-transparent to-rose-950/10">
            <span className="absolute top-2 right-3 text-[10px] text-rose-400/80 font-bold uppercase tracking-widest">
              FUTURE AI PREDICTION (UNCERTAINTY BAND)
            </span>
          </div>
        </div>

        {/* SVG Flowing Multi-Patient Trajectory Curves */}
        <svg className="w-full h-full overflow-visible relative z-0" viewBox="0 0 1000 200" preserveAspectRatio="none">
          <defs>
            <linearGradient id="uncertaintyGradient" x1="0" y1="0" x2="0" y2="1">
              <stop offset="0%" stopColor="#F43F5E" stopOpacity="0.18" />
              <stop offset="100%" stopColor="#F43F5E" stopOpacity="0.0" />
            </linearGradient>
          </defs>

          {/* Background Grid Horizontal Lines */}
          <line x1="0" y1="40" x2="1000" y2="40" stroke="#1E2631" strokeWidth="1" strokeDasharray="4 4" />
          <line x1="0" y1="100" x2="1000" y2="100" stroke="#1E2631" strokeWidth="1" strokeDasharray="4 4" />
          <line x1="0" y1="160" x2="1000" y2="160" stroke="#1E2631" strokeWidth="1" strokeDasharray="4 4" />

          {/* Uncertainty Band (Future Region) */}
          <polygon points="500,60 1000,20 1000,180 500,140" fill="url(#uncertaintyGradient)" />

          {/* Patient Trajectory 1 (Critical Hypotension Flow) */}
          <path
            d="M 20,160 Q 250,140 500,130"
            fill="none"
            stroke="#00F0FF"
            strokeWidth="2.5"
          />
          <path
            d="M 500,130 Q 750,90 980,40"
            fill="none"
            stroke="#F43F5E"
            strokeWidth="2.5"
            strokeDasharray="6 6"
            className="animate-pulse"
          />

          {/* Patient Trajectory 2 (Moderate Hypoxia Flow) */}
          <path
            d="M 20,80 Q 250,90 500,100"
            fill="none"
            stroke="#00F0FF"
            strokeWidth="2"
          />
          <path
            d="M 500,100 Q 750,120 980,150"
            fill="none"
            stroke="#F59E0B"
            strokeWidth="2"
            strokeDasharray="4 4"
          />

          {/* Event Markers on Timeline */}
          <circle cx="500" cy="130" r="5" fill="#22c55e" className="animate-ping" />
          <circle cx="750" cy="90" r="4" fill="#F59E0B" />
          <circle cx="980" cy="40" r="6" fill="#F43F5E" />
          
          <text x="760" y="85" fill="#F59E0B" fontSize="10" fontFamily="monospace">
            t+300s (Elevated Risk)
          </text>
          <text x="860" y="30" fill="#F43F5E" fontSize="10" fontFamily="monospace" fontWeight="bold">
            t+600s (MAP &lt; 65 mmHg)
          </text>
        </svg>

        {/* Footer Metrics Overlay */}
        <div className="absolute bottom-2 left-4 right-4 flex items-center justify-between text-[11px] text-[#9AA4B2]">
          <div>Trajectory Count: <span className="text-[#F5F7FA] font-bold">{patients.length} Active Patients</span></div>
          <div>Predicted Critical Events (T+600s): <span className="text-rose-400 font-bold">{criticalCount} Patients</span></div>
          <div>Elevated Risks: <span className="text-amber-400 font-bold">{highCount} Patients</span></div>
        </div>
      </div>
    </div>
  );
};
