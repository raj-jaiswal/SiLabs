import React from 'react';

interface SiliconLabsLogoProps {
  className?: string;
  size?: 'sm' | 'md' | 'lg';
}

export const SiliconLabsLogo: React.FC<SiliconLabsLogoProps> = ({ className = '', size = 'md' }) => {
  const heightClass = size === 'sm' ? 'h-6' : size === 'lg' ? 'h-9' : 'h-7';

  return (
    <div className={`flex items-center space-x-3 select-none ${className}`}>
      {/* Official Silicon Labs Red Swirl Emblem from silabs.com */}
      <img
        src="/silabs-logo.png"
        alt="Silicon Labs"
        className={`${heightClass} w-auto object-contain`}
      />
      <div className="flex flex-col justify-center">
        <span className="font-sans font-extrabold tracking-widest text-[#0F172A] leading-none text-sm">
          SILICON LABS
        </span>
        <span className="font-sans font-semibold tracking-widest text-[9px] text-[#CC0000] uppercase mt-0.5 leading-none">
          Clinical Systems
        </span>
      </div>
    </div>
  );
};
