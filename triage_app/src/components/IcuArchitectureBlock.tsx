'use client';

import React, { useState } from 'react';
import { Cpu, Wifi, Radio, Server, Activity, ArrowRight, Layers, Database, CpuIcon } from 'lucide-react';
import { SiliconLabsLogo } from './SiliconLabsLogo';

export const IcuArchitectureBlock: React.FC = () => {
  const [selectedParam, setSelectedParam] = useState<number | null>(null);

  // 9 Clean, Meaningful Extracted Parameters from ICU Monitor
  const extractedParameters = [
    { id: 1, rawTag: 'Solar8000/HR', title: 'Heart Rate (HR)', unit: 'bpm', range: '60 - 100 bpm', desc: 'Continuous cardiac cycle frequency monitored from Solar 8000 multi-parameter module.' },
    { id: 2, rawTag: 'Solar8000/ART_SBP', title: 'Systolic Blood Pressure (SBP)', unit: 'mmHg', range: '90 - 120 mmHg', desc: 'Peak arterial pressure during ventricular contraction derived from invasive arterial line.' },
    { id: 3, rawTag: 'Solar8000/ART_DBP', title: 'Diastolic Blood Pressure (DBP)', unit: 'mmHg', range: '60 - 80 mmHg', desc: 'Minimum arterial pressure during cardiac relaxation and ventricular filling.' },
    { id: 4, rawTag: 'Solar8000/ART_MBP', title: 'Mean Arterial Pressure (MAP)', unit: 'mmHg', range: '70 - 105 mmHg', desc: 'Calculated average organ perfusion pressure; primary trigger for hypotension alerts (< 65 mmHg).' },
    { id: 5, rawTag: 'Solar8000/PLETH_SPO2', title: 'Oxygen Saturation (SpO2)', unit: '%', range: '95 - 100%', desc: 'Pulse oximetry arterial oxygen saturation; primary trigger for hypoxia alerts (< 90%).' },
    { id: 6, rawTag: 'Solar8000/ETCO2', title: 'End-Tidal CO2 (EtCO2)', unit: 'mmHg', range: '35 - 45 mmHg', desc: 'Capnography peak carbon dioxide concentration at the end of expiration.' },
    { id: 7, rawTag: 'Primus/FIO2', title: 'Fraction of Inspired O2 (FiO2)', unit: '%', range: '21 - 100%', desc: 'Oxygen concentration delivered by Dräger Primus anesthesia ventilation system.' },
    { id: 8, rawTag: 'Solar8000/BT', title: 'Body Temperature (BT)', unit: '°C', range: '36.5 - 37.5 °C', desc: 'Continuous core patient body temperature measured via esophageal/rectal probe.' },
    { id: 9, rawTag: 'SNUADC/ECG_II', title: 'ECG Lead II Waveform', unit: 'mV', range: '0.5 - 2.0 mV', desc: 'Primary electrical cardiac conduction waveform sampled via high-speed SNUADC A/D channel.' },
  ];

  return (
    <div className="bg-white border border-slate-300 p-6 space-y-6 font-sans text-slate-900 select-none">
      
      {/* Block Header */}
      <div className="flex flex-col md:flex-row md:items-center justify-between pb-4 border-b border-slate-300 gap-3">
        <div className="flex items-center space-x-3">
          <SiliconLabsLogo size="md" />
          <div className="h-6 w-px bg-slate-300 hidden sm:block" />
          <div>
            <h2 className="text-base font-bold uppercase tracking-wider text-slate-900 font-sans">
              ICU Monitor Hardware Architecture &amp; Telemetry Extractor
            </h2>
            <p className="text-xs text-slate-600">
              Silicon Labs Wireless EFR32/BGM Pipeline • Multi-Patient Serial Ingestion &amp; Parameter Parsing
            </p>
          </div>
        </div>
        <span className="px-2.5 py-1 text-xs font-mono font-bold bg-slate-100 border border-slate-300 text-slate-800 self-start md:self-auto">
          PPT ARCHITECTURE SPECIFICATION
        </span>
      </div>

      {/* SECTION 1: Modern Multi-Channel Hardware Architecture Flow */}
      <div className="space-y-3">
        <div className="text-xs font-bold uppercase tracking-wider text-slate-700 font-mono flex items-center justify-between">
          <span>1. Multi-Patient Wireless Ingestion Pipeline</span>
          <span className="text-slate-500 font-normal">4 Parallel ICU Nodes &rarr; Central Hub</span>
        </div>

        {/* 4 Parallel Nodes Grid */}
        <div className="space-y-2">
          {[1, 2, 3, 4].map((nodeNum) => (
            <div
              key={nodeNum}
              className="bg-slate-50 border border-slate-300 p-3 flex flex-col md:flex-row items-center justify-between gap-2 text-xs font-mono"
            >
              {/* Step 1: ICU Monitor */}
              <div className="flex items-center space-x-2 bg-white border border-slate-300 px-3 py-1.5 w-full md:w-44 justify-center">
                <Activity className="w-4 h-4 text-slate-800" />
                <span className="font-bold text-slate-900">ICU MONITOR #{nodeNum}</span>
              </div>

              <ArrowRight className="w-4 h-4 text-slate-400 hidden md:block shrink-0" />

              {/* Step 2: RS232 to UART */}
              <div className="flex items-center space-x-1.5 bg-white border border-slate-300 px-2.5 py-1.5 w-full md:w-36 justify-center text-[11px]">
                <span className="text-slate-600 font-sans">Bridge:</span>
                <span className="font-semibold text-slate-900">RS232 &rarr; UART</span>
              </div>

              <ArrowRight className="w-4 h-4 text-slate-400 hidden md:block shrink-0" />

              {/* Step 3: Silicon Labs BGM 220 */}
              <div className="flex items-center space-x-1.5 bg-red-50 border border-red-200 px-2.5 py-1.5 w-full md:w-40 justify-center">
                <Cpu className="w-3.5 h-3.5 text-red-700" />
                <span className="font-bold text-red-800">SiLabs BGM220</span>
              </div>

              <ArrowRight className="w-4 h-4 text-slate-400 hidden md:block shrink-0" />

              {/* Step 4: Silicon Labs EFR32X G26 */}
              <div className="flex items-center space-x-1.5 bg-red-50 border border-red-200 px-2.5 py-1.5 w-full md:w-44 justify-center">
                <Radio className="w-3.5 h-3.5 text-red-700" />
                <span className="font-bold text-red-800">SiLabs EFR32X G26</span>
              </div>

              <ArrowRight className="w-4 h-4 text-slate-400 hidden md:block shrink-0" />

              {/* Step 5: WiFi Adapter */}
              <div className="flex items-center space-x-1.5 bg-white border border-slate-300 px-2.5 py-1.5 w-full md:w-36 justify-center text-[11px]">
                <Wifi className="w-3.5 h-3.5 text-slate-700" />
                <span className="font-semibold text-slate-900">WiFi Adapter</span>
              </div>
            </div>
          ))}
        </div>

        {/* Central Ingestion Hub (Raspberry Pi 4 / Next.js Server) */}
        <div className="bg-slate-900 text-white p-3.5 border border-slate-900 flex items-center justify-between font-mono text-xs mt-3">
          <div className="flex items-center space-x-3">
            <Server className="w-5 h-5 text-red-400" />
            <div>
              <span className="font-bold text-white uppercase">CENTRAL TELEMETRY NODE (RASPBERRY PI 4 / SERVER PORT 5000)</span>
              <p className="text-[11px] text-slate-300 font-sans mt-0.5">Aggregates all 4 incoming wireless ICU streams into 5-second stride inference engine</p>
            </div>
          </div>
          <span className="px-2.5 py-1 bg-emerald-700 text-white font-bold text-[11px]">
            ACTIVE HUB
          </span>
        </div>
      </div>

      {/* SECTION 2: 9 Extracted Clinical ICU Parameters Block */}
      <div className="space-y-3 pt-4 border-t border-slate-300">
        <div className="flex items-center justify-between">
          <div className="flex items-center space-x-2">
            <Layers className="w-4 h-4 text-slate-800" />
            <h3 className="text-xs font-bold uppercase tracking-wider text-slate-900 font-mono">
              2. Extracted ICU Monitor Telemetry Channels (9 Key Parameters)
            </h3>
          </div>
          <span className="text-xs text-slate-500 font-mono">Normalized from Raw Solar 8000 / Primus / SNUADC Channels</span>
        </div>

        {/* 9 Parameters Grid */}
        <div className="grid grid-cols-1 md:grid-cols-3 gap-3">
          {extractedParameters.map((param) => (
            <div
              key={param.id}
              onClick={() => setSelectedParam(selectedParam === param.id ? null : param.id)}
              className={`p-3 border transition-colors cursor-pointer text-xs ${
                selectedParam === param.id
                  ? 'bg-red-50 border-red-300'
                  : 'bg-slate-50 hover:bg-slate-100 border-slate-300'
              }`}
            >
              <div className="flex items-center justify-between mb-1">
                <span className="font-mono text-[10px] text-slate-500 font-semibold bg-white border border-slate-200 px-1.5 py-0.5">
                  {param.rawTag}
                </span>
                <span className="font-mono font-bold text-slate-700 text-[11px] bg-slate-200 px-1.5 py-0.5">
                  {param.unit}
                </span>
              </div>

              <div className="font-bold text-slate-900 text-sm mt-1">
                {param.title}
              </div>

              <div className="text-[11px] text-slate-600 font-mono mt-1">
                Normal Range: <span className="font-bold text-slate-900">{param.range}</span>
              </div>

              <p className="text-[11px] text-slate-600 font-sans mt-1.5 leading-snug">
                {param.desc}
              </p>
            </div>
          ))}
        </div>
      </div>

    </div>
  );
};
