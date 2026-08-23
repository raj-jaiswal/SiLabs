import React from 'react';

interface SiliconLabsLogoProps {
  className?: string;
  size?: 'sm' | 'md' | 'lg';
}

export const SiliconLabsLogo: React.FC<SiliconLabsLogoProps> = ({ className = '', size = 'md' }) => {
  const heightClass = size === 'sm' ? 'h-7' : size === 'lg' ? 'h-10' : 'h-8';

  return (
    <div className={`flex items-center space-x-2.5 select-none ${className}`}>
      {/* Official Stylized Silicon Labs Flame/Wave Icon Mark */}
      <svg className={`${heightClass} w-auto`} viewBox="0 0 70 70" fill="none" xmlns="http://www.w3.org/2000/svg">
        <path d="M 35 0 C 15 15 0 35 0 50 C 0 65 15 70 30 70 C 45 70 65 55 65 40 C 65 25 50 20 35 0 Z" fill="#DC2626"/>
        <path d="M 25 15 C 38 28 50 38 50 48 C 50 58 40 62 30 62 C 20 62 10 52 10 40 C 10 28 20 22 25 15 Z" fill="#EF4444"/>
        <path d="M 20 25 C 30 35 40 42 40 50 C 40 56 32 58 26 58 C 18 58 12 50 12 42 Z" fill="#FFFFFF"/>
      </svg>
      <div className="flex flex-col justify-center">
        <span className="font-sans font-extrabold tracking-wider text-slate-900 leading-none text-sm">
          SILICON LABS
        </span>
        <span className="font-sans font-semibold tracking-widest text-[9px] text-slate-500 uppercase mt-0.5 leading-none">
          Clinical Systems
        </span>
      </div>
    </div>
  );
};
