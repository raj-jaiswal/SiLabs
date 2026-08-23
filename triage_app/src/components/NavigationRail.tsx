import React from 'react';
import { Activity, Shield, Layers, Radio, Cpu, Sparkles } from 'lucide-react';

interface NavigationRailProps {
  activeTab: string;
  onSelectTab: (tab: string) => void;
  onOpenAdminSidebar?: () => void;
  isAdmin?: boolean;
}

export const NavigationRail: React.FC<NavigationRailProps> = ({
  activeTab,
  onSelectTab,
  onOpenAdminSidebar,
  isAdmin,
}) => {
  return (
    <aside className="w-16 bg-[#080B10] border-r border-[#1E2631] flex flex-col items-center py-5 space-y-6 z-30 select-none h-full">
      {/* Brand Icon */}
      <div className="w-10 h-10 rounded-xl bg-[#151A21] border border-cyan-500/40 flex items-center justify-center text-cyan-400 glow-cyan">
        <Activity className="w-5 h-5 animate-pulse" />
      </div>

      <div className="w-8 h-px bg-[#1E2631]" />

      {/* Navigation Items */}
      <nav className="flex-1 flex flex-col space-y-4">
        <button
          onClick={() => onSelectTab('forecast')}
          title="Temporal Forecasting Canvas"
          className={`p-2.5 rounded-lg border transition-all ${
            activeTab === 'forecast'
              ? 'bg-cyan-950/60 border-cyan-500/50 text-cyan-300 shadow-[0_0_10px_rgba(0,240,255,0.2)]'
              : 'border-transparent text-slate-400 hover:text-slate-200 hover:bg-[#151A21]'
          }`}
        >
          <Layers className="w-5 h-5" />
        </button>

        <button
          onClick={() => onSelectTab('trajectories')}
          title="Patient Mission Control Trajectories"
          className={`p-2.5 rounded-lg border transition-all ${
            activeTab === 'trajectories'
              ? 'bg-cyan-950/60 border-cyan-500/50 text-cyan-300 shadow-[0_0_10px_rgba(0,240,255,0.2)]'
              : 'border-transparent text-slate-400 hover:text-slate-200 hover:bg-[#151A21]'
          }`}
        >
          <Activity className="w-5 h-5" />
        </button>

        <button
          onClick={() => onSelectTab('esp32')}
          title="ESP32 Hardware Live Stream"
          className={`p-2.5 rounded-lg border transition-all ${
            activeTab === 'esp32'
              ? 'bg-cyan-950/60 border-cyan-500/50 text-cyan-300 shadow-[0_0_10px_rgba(0,240,255,0.2)]'
              : 'border-transparent text-slate-400 hover:text-slate-200 hover:bg-[#151A21]'
          }`}
        >
          <Radio className="w-5 h-5" />
        </button>

        {isAdmin && onOpenAdminSidebar && (
          <button
            onClick={onOpenAdminSidebar}
            title="Admin Control & Dispatch Console"
            className="p-2.5 rounded-lg border border-rose-900/50 bg-rose-950/40 text-rose-300 hover:bg-rose-900/60 transition-all"
          >
            <Shield className="w-5 h-5" />
          </button>
        )}
      </nav>

      {/* System Status Indicator */}
      <div className="flex flex-col items-center space-y-1">
        <span className="w-2 h-2 rounded-full bg-emerald-400 animate-ping" />
        <span className="text-[9px] font-mono text-slate-500 uppercase tracking-widest">SYS</span>
      </div>
    </aside>
  );
};
