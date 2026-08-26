#!/usr/bin/env python3
"""
Raspberry Pi USB Connection Detector
------------------------------------
Detects any connected Raspberry Pi (Pico, Pico W, RP2040, Zero, Zero W, RPi 4/5 OTG Gadget)
via USB ports on Linux.

Matches:
- USB Vendor ID: 0x2e8a (Raspberry Pi Ltd / RP2040)
- Manufacturer / Product String: "Raspberry Pi", "RP2040", "Pico"
- USB Ethernet Gadget: 0x0525 (Linux CDC Ethernet / RNDIS)
- Serial Ports: /dev/ttyACM* or /dev/ttyUSB*
- Network Interfaces: usb0, enp0s20f0u*
"""

import os
import sys
import time
import argparse

# Official Raspberry Pi Vendor ID
RPI_VENDOR_ID = "2e8a"
# Linux Gadget Vendor ID (used by RPi Zero/4/5 OTG ethernet/serial gadget mode)
GADGET_VENDOR_ID = "0525"

def get_serial_ports_for_sys_device(dev_path):
    """Find tty ports associated with a USB device in /sys/bus/usb/devices/"""
    tty_ports = []
    for root, dirs, _ in os.walk(dev_path):
        for d in dirs:
            if d.startswith("ttyACM") or d.startswith("ttyUSB"):
                tty_ports.append(f"/dev/{d}")
            elif d == "tty":
                tty_dir = os.path.join(root, d)
                try:
                    for sub in os.listdir(tty_dir):
                        if sub.startswith("ttyACM") or sub.startswith("ttyUSB"):
                            tty_ports.append(f"/dev/{sub}")
                except Exception:
                    pass
    return sorted(list(set(tty_ports)))


def get_net_interfaces_for_sys_device(dev_path):
    """Find network interfaces (e.g. usb0) associated with a USB device"""
    net_ifaces = []
    net_dir = os.path.join(dev_path, "net")
    if os.path.exists(net_dir):
        try:
            net_ifaces = os.listdir(net_dir)
        except Exception:
            pass
    return net_ifaces


def detect_raspberry_pi():
    """
    Scans USB devices on the system and returns a list of connected Raspberry Pi devices.
    """
    rpi_list = []
    usb_base = "/sys/bus/usb/devices"

    if not os.path.exists(usb_base):
        print("Error: /sys/bus/usb/devices not found. This script requires a Linux system.", file=sys.stderr)
        return rpi_list

    for dev_name in sorted(os.listdir(usb_base)):
        dev_path = os.path.join(usb_base, dev_name)

        vid_path = os.path.join(dev_path, "idVendor")
        pid_path = os.path.join(dev_path, "idProduct")

        if not (os.path.exists(vid_path) and os.path.exists(pid_path)):
            continue

        try:
            with open(vid_path, "r") as f:
                vid = f.read().strip().lower()
            with open(pid_path, "r") as f:
                pid = f.read().strip().lower()
        except Exception:
            continue

        mfg = ""
        mfg_path = os.path.join(dev_path, "manufacturer")
        if os.path.exists(mfg_path):
            try:
                with open(mfg_path, "r") as f:
                    mfg = f.read().strip()
            except Exception:
                pass

        product = ""
        prod_path = os.path.join(dev_path, "product")
        if os.path.exists(prod_path):
            try:
                with open(prod_path, "r") as f:
                    product = f.read().strip()
            except Exception:
                pass

        serial_num = ""
        serial_path = os.path.join(dev_path, "serial")
        if os.path.exists(serial_path):
            try:
                with open(serial_path, "r") as f:
                    serial_num = f.read().strip()
            except Exception:
                pass

        # Identify Raspberry Pi / RP2040 match
        is_rpi = False
        match_reason = ""

        if vid == RPI_VENDOR_ID:
            is_rpi = True
            match_reason = f"Raspberry Pi Vendor ID (0x{vid})"
        elif "raspberry" in mfg.lower() or "raspberry" in product.lower():
            is_rpi = True
            match_reason = f"Manufacturer/Product string ('{mfg}' / '{product}')"
        elif "rp2040" in product.lower() or "pico" in product.lower():
            is_rpi = True
            match_reason = f"RP2040/Pico Product string ('{product}')"
        elif vid == GADGET_VENDOR_ID and ("gadget" in product.lower() or "ethernet" in product.lower() or "raspberry" in mfg.lower()):
            is_rpi = True
            match_reason = f"Linux USB OTG Gadget Mode (0x{vid}:0x{pid})"

        if is_rpi:
            serial_ports = get_serial_ports_for_sys_device(dev_path)
            net_interfaces = get_net_interfaces_for_sys_device(dev_path)

            rpi_list.append({
                "sys_path": dev_path,
                "bus_dev": dev_name,
                "vid": vid,
                "pid": pid,
                "manufacturer": mfg or "Unknown",
                "product": product or "Raspberry Pi / RP2040 Device",
                "serial_number": serial_num,
                "serial_ports": serial_ports,
                "net_interfaces": net_interfaces,
                "reason": match_reason
            })

    return rpi_list


def monitor_hotplug(interval=1.0):
    """Continuously monitors USB ports for Raspberry Pi connection/disconnection."""
    print("🔍 Starting Raspberry Pi USB Hotplug Monitor (Press Ctrl+C to stop)...")
    known_devices = set()

    try:
        while True:
            current_devices = detect_raspberry_pi()
            current_ids = {d["sys_path"]: d for d in current_devices}

            # Check new connections
            for dev_path, info in current_ids.items():
                if dev_path not in known_devices:
                    print("\n🟢 [CONNECTED] Raspberry Pi USB Device Detected!")
                    print(f"   • Device      : {info['product']} ({info['manufacturer']})")
                    print(f"   • USB ID      : 0x{info['vid']}:0x{info['pid']}")
                    print(f"   • Serial Ports: {', '.join(info['serial_ports']) if info['serial_ports'] else 'None'}")
                    print(f"   • Network     : {', '.join(info['net_interfaces']) if info['net_interfaces'] else 'None'}")
                    print(f"   • Reason      : {info['reason']}")
                    known_devices.add(dev_path)

            # Check disconnections
            removed = known_devices - set(current_ids.keys())
            for dev_path in list(removed):
                print(f"\n🔴 [DISCONNECTED] Raspberry Pi at {dev_path} was unplugged.")
                known_devices.remove(dev_path)

            time.sleep(interval)
    except KeyboardInterrupt:
        print("\nStopping USB Monitor.")


def main():
    parser = argparse.ArgumentParser(description="Detect connected Raspberry Pi USB devices.")
    parser.add_argument("-w", "--watch", action="store_true", help="Monitor USB ports continuously for insertion/removal")
    args = parser.parse_args()

    if args.watch:
        monitor_hotplug()
    else:
        devices = detect_raspberry_pi()
        if not devices:
            print("❌ No Raspberry Pi USB device detected.")
            print("   (Ensure your Pi / Pico is powered on and connected via a USB data cable)")
        else:
            print(f"✅ Detected {len(devices)} Raspberry Pi USB Device(s):\n")
            for idx, dev in enumerate(devices, 1):
                print(f"[{idx}] {dev['product']}")
                print(f"    Manufacturer : {dev['manufacturer']}")
                print(f"    USB VID:PID  : 0x{dev['vid']}:0x{dev['pid']}")
                print(f"    Serial Num   : {dev['serial_number'] or 'N/A'}")
                print(f"    Serial Ports : {', '.join(dev['serial_ports']) if dev['serial_ports'] else 'None'}")
                print(f"    Network Net  : {', '.join(dev['net_interfaces']) if dev['net_interfaces'] else 'None'}")
                print(f"    Match Reason : {dev['reason']}")
                print("-" * 50)


if __name__ == "__main__":
    main()
