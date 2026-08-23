#!/usr/bin/env python3
"""
ESP32 Multi-Device Prediction Telemetry Server & Web Dashboard
------------------------------------------------------------------
Serves:
1. POST /api/pred: Accepts telemetry JSON with device_id and pred/pred_data
2. GET  /api/devices: Returns JSON of all registered devices, latest predictions, and historical trend data
3. GET  /: Serves a responsive, live-updating Glassmorphism Dashboard with Chart.js visualization
"""

import json
import time
import datetime
import threading
from http.server import HTTPServer, BaseHTTPRequestHandler
from socketserver import ThreadingMixIn

# Port and Host Configuration
HOST = '0.0.0.0'
PORT = 5000

# ------------------------------------------------------------------
# CONFIGURABLE PARAMETER: MAX_HISTORY_LENGTH
# Controls the maximum number of recent telemetry samples preserved per device for graphing.
# Change this integer to increase or decrease the graph memory window (e.g. 10, 20, 50).
# ------------------------------------------------------------------
MAX_HISTORY_LENGTH = 10

# Thread-safe in-memory device registry
devices_lock = threading.Lock()
now_init = datetime.datetime.now().strftime("%H:%M:%S")
now_init_epoch = time.time()
DEVICES = {
    "PATIENT-000": {
        "device_id": "PATIENT-000",
        "prediction_str": "Hypotension: 0.8850 | Hypoxia: 0.9420 | Tachycardia: 0.1200",
        "pred_raw": "",
        "scores": [0.885, 0.942, 0.12],
        "update_count": 1,
        "last_updated": now_init,
        "last_updated_epoch": now_init_epoch,
        "ip_address": "127.0.0.1",
        "history": [{
            "timestamp": now_init,
            "pred": "Hypotension: 0.8850 | Hypoxia: 0.9420 | Tachycardia: 0.1200",
            "scores": [0.885, 0.942, 0.12]
        }]
    }
}

HTML_TEMPLATE = """<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 AI Telemetry Dashboard</title>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;600;700;800&family=JetBrains+Mono:wght@400;600&display=swap" rel="stylesheet">
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        :root {
            --bg-color: #0d1117;
            --card-bg: rgba(22, 27, 34, 0.75);
            --card-border: rgba(255, 255, 255, 0.1);
            --accent-blue: #38bdf8;
            --accent-purple: #a855f7;
            --accent-green: #22c55e;
            --accent-orange: #f97316;
            --text-main: #f3f4f6;
            --text-muted: #9ca3af;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
            font-family: 'Inter', sans-serif;
        }

        body {
            background-color: var(--bg-color);
            background-image: 
                radial-gradient(at 0% 0%, rgba(56, 189, 248, 0.12) 0px, transparent 50%),
                radial-gradient(at 100% 100%, rgba(168, 85, 247, 0.12) 0px, transparent 50%);
            background-attachment: fixed;
            color: var(--text-main);
            min-height: 100vh;
            padding: 2rem;
        }

        header {
            max-width: 1200px;
            margin: 0 auto 2.5rem auto;
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding-bottom: 1.5rem;
            border-bottom: 1px solid var(--card-border);
        }

        .brand {
            display: flex;
            align-items: center;
            gap: 1rem;
        }

        .brand-icon {
            width: 44px;
            height: 44px;
            background: linear-gradient(135deg, var(--accent-blue), var(--accent-purple));
            border-radius: 12px;
            display: flex;
            align-items: center;
            justify-content: center;
            box-shadow: 0 0 20px rgba(56, 189, 248, 0.4);
            font-size: 1.4rem;
        }

        h1 {
            font-size: 1.75rem;
            font-weight: 800;
            letter-spacing: -0.02em;
            background: linear-gradient(to right, #ffffff, #94a3b8);
            -webkit-background-clip: text;
            -webkit-text-fill-color: transparent;
        }

        .subtitle {
            font-size: 0.875rem;
            color: var(--text-muted);
            margin-top: 0.2rem;
        }

        .stats-bar {
            display: flex;
            gap: 1.5rem;
        }

        .stat-pill {
            background: var(--card-bg);
            border: 1px solid var(--card-border);
            padding: 0.6rem 1.2rem;
            border-radius: 9999px;
            display: flex;
            align-items: center;
            gap: 0.6rem;
            font-size: 0.875rem;
            backdrop-filter: blur(12px);
        }

        .stat-dot {
            width: 8px;
            height: 8px;
            border-radius: 50%;
            background: var(--accent-green);
            box-shadow: 0 0 10px var(--accent-green);
            animation: pulse 2s infinite;
        }

        @keyframes pulse {
            0%, 100% { opacity: 1; transform: scale(1); }
            50% { opacity: 0.4; transform: scale(0.85); }
        }

        main {
            max-width: 1200px;
            margin: 0 auto;
        }

        .devices-grid {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(380px, 1fr));
            gap: 1.5rem;
        }

        .device-card {
            background: var(--card-bg);
            border: 1px solid var(--card-border);
            border-radius: 20px;
            padding: 1.5rem;
            backdrop-filter: blur(16px);
            box-shadow: 0 10px 30px rgba(0,0,0,0.3);
            transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
            position: relative;
            overflow: hidden;
        }

        .device-card:hover {
            transform: translateY(-4px);
            border-color: rgba(56, 189, 248, 0.4);
            box-shadow: 0 15px 35px rgba(56, 189, 248, 0.15);
        }

        .device-card.updated {
            animation: cardHighlight 0.6s ease-out;
        }

        @keyframes cardHighlight {
            0% { border-color: var(--accent-blue); box-shadow: 0 0 25px rgba(56, 189, 248, 0.5); }
            100% { border-color: var(--card-border); }
        }

        .card-header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 1.2rem;
            padding-bottom: 0.8rem;
            border-bottom: 1px solid rgba(255,255,255,0.06);
        }

        .device-id {
            font-family: 'JetBrains Mono', monospace;
            font-weight: 700;
            font-size: 1.1rem;
            color: var(--accent-blue);
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }

        .badge-ip {
            font-size: 0.75rem;
            color: var(--text-muted);
            background: rgba(255,255,255,0.05);
            padding: 0.2rem 0.6rem;
            border-radius: 6px;
            font-weight: 400;
        }

        .pred-section {
            background: rgba(0, 0, 0, 0.3);
            border-radius: 12px;
            padding: 1.2rem;
            margin-bottom: 1rem;
            border: 1px solid rgba(255,255,255,0.04);
        }

        .pred-label {
            font-size: 0.75rem;
            text-transform: uppercase;
            letter-spacing: 0.05em;
            color: var(--text-muted);
            margin-bottom: 0.4rem;
        }

        .pred-value {
            font-size: 1.8rem;
            font-weight: 800;
            font-family: 'JetBrains Mono', monospace;
            color: #ffffff;
            display: flex;
            align-items: baseline;
            gap: 0.5rem;
        }

        .scores-container {
            margin-top: 0.8rem;
            display: flex;
            flex-wrap: wrap;
            gap: 0.4rem;
        }

        .score-chip {
            background: rgba(56, 189, 248, 0.1);
            border: 1px solid rgba(56, 189, 248, 0.2);
            color: var(--accent-blue);
            font-family: 'JetBrains Mono', monospace;
            font-size: 0.8rem;
            padding: 0.2rem 0.6rem;
            border-radius: 6px;
        }

        .chart-wrapper {
            background: rgba(0, 0, 0, 0.25);
            border-radius: 12px;
            padding: 0.8rem;
            margin-bottom: 1.2rem;
            border: 1px solid rgba(255, 255, 255, 0.05);
            height: 170px;
            position: relative;
        }

        .chart-header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            font-size: 0.75rem;
            color: var(--text-muted);
            margin-bottom: 0.4rem;
        }

        .card-footer {
            display: flex;
            justify-content: space-between;
            align-items: center;
            font-size: 0.8rem;
            color: var(--text-muted);
        }

        .empty-state {
            grid-column: 1 / -1;
            text-align: center;
            padding: 4rem 2rem;
            background: var(--card-bg);
            border: 1px dashed var(--card-border);
            border-radius: 20px;
            backdrop-filter: blur(12px);
        }

        .empty-icon {
            font-size: 3rem;
            margin-bottom: 1rem;
            opacity: 0.6;
        }
    </style>
</head>
<body>
    <header>
        <div class="brand">
            <div class="brand-icon">📡</div>
            <div>
                <h1>ESP32 Telemetry Gateway</h1>
                <div class="subtitle">Real-time Inference Monitoring & Live Graph Visualizer</div>
            </div>
        </div>
        <div class="stats-bar">
            <div class="stat-pill">
                <div class="stat-dot"></div>
                <span>Server Active</span>
            </div>
            <div class="stat-pill">
                <span>Devices Connected: <strong id="total-devices">0</strong></span>
            </div>
        </div>
    </header>

    <main>
        <div id="devices-grid" class="devices-grid">
            <div class="empty-state">
                <div class="empty-icon">⏳</div>
                <h2>Waiting for ESP32 Telemetry...</h2>
                <p style="color: var(--text-muted); margin-top: 0.5rem;">POST requests to <code>/api/pred</code> will automatically appear here with real-time graphs.</p>
            </div>
        </div>
    </main>

    <script>
        const previousData = {};
        const deviceCharts = {};

        async function fetchDevices() {
            try {
                const response = await fetch('/api/devices');
                if (!response.ok) return;
                const devices = await response.json();
                renderDevices(devices);
            } catch (err) {
                console.error("Error fetching device telemetry:", err);
            }
        }

        function updateDeviceChart(deviceId, history) {
            const canvas = document.getElementById(`chart-${deviceId}`);
            if (!canvas) return;

            const ctx = canvas.getContext('2d');
            const labels = (history || []).map((h, i) => h.timestamp || `#${i+1}`);

            let datasets = [];

            // Check if scores are available in history
            const hasScores = history && history.length > 0 && history[history.length - 1].scores && history[history.length - 1].scores.length > 0;

            if (hasScores) {
                const numScores = Math.max(...history.map(h => (h.scores ? h.scores.length : 0)));
                const colorPalette = [
                    { border: '#38bdf8', bg: 'rgba(56, 189, 248, 0.15)', name: 'Hypotension' },
                    { border: '#a855f7', bg: 'rgba(168, 85, 247, 0.15)', name: 'Hypoxia' },
                    { border: '#22c55e', bg: 'rgba(34, 197, 94, 0.15)', name: 'Tachycardia' },
                    { border: '#f97316', bg: 'rgba(249, 115, 22, 0.15)', name: 'Score 4' }
                ];

                for (let sIdx = 0; sIdx < numScores; sIdx++) {
                    const dataPoints = history.map(h => (h.scores && h.scores[sIdx] !== undefined ? h.scores[sIdx] : 0));
                    const palette = colorPalette[sIdx % colorPalette.length];
                    const labelName = numScores === 3 ? palette.name : `Score ${sIdx + 1}`;

                    datasets.push({
                        label: labelName,
                        data: dataPoints,
                        borderColor: palette.border,
                        backgroundColor: palette.bg,
                        borderWidth: 2,
                        tension: 0.35,
                        fill: true,
                        pointRadius: 3,
                        pointBackgroundColor: palette.border
                    });
                }
            } else {
                // Single numeric trend from predictions
                const dataPoints = (history || []).map(h => {
                    const match = String(h.pred).match(/-?\\d+(\\.\\d+)?/);
                    return match ? parseFloat(match[0]) : 0;
                });

                datasets.push({
                    label: 'Prediction Class / Score',
                    data: dataPoints,
                    borderColor: '#38bdf8',
                    backgroundColor: 'rgba(56, 189, 248, 0.15)',
                    borderWidth: 2,
                    tension: 0.35,
                    fill: true,
                    pointRadius: 3,
                    pointBackgroundColor: '#38bdf8'
                });
            }

            if (deviceCharts[deviceId]) {
                deviceCharts[deviceId].data.labels = labels;
                deviceCharts[deviceId].data.datasets = datasets;
                deviceCharts[deviceId].update('none'); // Smooth non-flashing update
            } else {
                deviceCharts[deviceId] = new Chart(ctx, {
                    type: 'line',
                    data: { labels, datasets },
                    options: {
                        responsive: true,
                        maintainAspectRatio: false,
                        animation: { duration: 300 },
                        plugins: {
                            legend: {
                                display: true,
                                position: 'top',
                                labels: { color: '#9ca3af', font: { size: 10 }, boxWidth: 10 }
                            },
                            tooltip: {
                                mode: 'index',
                                intersect: false,
                                backgroundColor: 'rgba(13, 17, 23, 0.95)',
                                titleColor: '#38bdf8',
                                bodyColor: '#f3f4f6',
                                borderColor: 'rgba(255, 255, 255, 0.1)',
                                borderWidth: 1
                            }
                        },
                        scales: {
                            x: {
                                ticks: { color: '#6b7280', font: { size: 9 } },
                                grid: { color: 'rgba(255, 255, 255, 0.04)' }
                            },
                            y: {
                                ticks: { color: '#6b7280', font: { size: 9 } },
                                grid: { color: 'rgba(255, 255, 255, 0.04)' }
                            }
                        }
                    }
                });
            }
        }

        function renderDevices(devices) {
            const grid = document.getElementById('devices-grid');
            const totalDevicesElem = document.getElementById('total-devices');
            
            const deviceKeys = Object.keys(devices);
            totalDevicesElem.innerText = deviceKeys.length;

            if (deviceKeys.length === 0) {
                return;
            }

            // Remove empty state if present
            if (grid.querySelector('.empty-state')) {
                grid.innerHTML = '';
            }

            deviceKeys.forEach(deviceId => {
                const dev = devices[deviceId];
                let card = document.getElementById(`card-${deviceId}`);

                const isNew = !card;
                const isUpdated = previousData[deviceId] && previousData[deviceId].update_count !== dev.update_count;

                previousData[deviceId] = dev;

                const scoresHtml = dev.scores && dev.scores.length > 0 
                    ? dev.scores.map(s => `<span class="score-chip">${s}</span>`).join('')
                    : `<span style="color: var(--text-muted); font-size: 0.8rem;">No score breakdown</span>`;

                const historyLength = dev.history ? dev.history.length : 0;

                if (isNew) {
                    card = document.createElement('div');
                    card.id = `card-${deviceId}`;
                    card.className = 'device-card updated';
                    card.innerHTML = `
                        <div class="card-header">
                            <div class="device-id">
                                <span>⚡</span> ${deviceId}
                            </div>
                            <div class="badge-ip badge-ip-val">${dev.ip_address || 'HTTP'}</div>
                        </div>
                        <div class="pred-section">
                            <div class="pred-label">Latest Prediction Result</div>
                            <div class="pred-value pred-val-text">
                                ${dev.prediction_str}
                            </div>
                            <div style="margin-top: 0.8rem;">
                                <div class="pred-label" style="font-size: 0.7rem;">Output Class Scores</div>
                                <div class="scores-container scores-container-val">${scoresHtml}</div>
                            </div>
                        </div>

                        <div class="chart-wrapper">
                            <div class="chart-header">
                                <span>📈 Telemetry Trend</span>
                                <span>Last <strong class="history-count-val">${historyLength}</strong> samples</span>
                            </div>
                            <div style="height: 130px; position: relative;">
                                <canvas id="chart-${deviceId}"></canvas>
                            </div>
                        </div>

                        <div class="card-footer">
                            <span>Updates: <strong class="update-count-val" style="color: var(--accent-blue);">${dev.update_count}</strong></span>
                            <span>Last Seen: <strong class="last-seen-val">${dev.last_updated}</strong></span>
                        </div>
                    `;
                    grid.appendChild(card);
                } else {
                    // Selective DOM updates to preserve the canvas element and Chart.js instance!
                    const badgeElem = card.querySelector('.badge-ip-val');
                    if (badgeElem) badgeElem.innerText = dev.ip_address || 'HTTP';

                    const predElem = card.querySelector('.pred-val-text');
                    if (predElem) predElem.innerHTML = dev.prediction_str;

                    const scoresElem = card.querySelector('.scores-container-val');
                    if (scoresElem) scoresElem.innerHTML = scoresHtml;

                    const histCountElem = card.querySelector('.history-count-val');
                    if (histCountElem) histCountElem.innerText = historyLength;

                    const updateCountElem = card.querySelector('.update-count-val');
                    if (updateCountElem) updateCountElem.innerText = dev.update_count;

                    const lastSeenElem = card.querySelector('.last-seen-val');
                    if (lastSeenElem) lastSeenElem.innerText = dev.last_updated;

                    if (isUpdated) {
                        card.classList.remove('updated');
                        void card.offsetWidth; // Trigger reflow for animation restart
                        card.classList.add('updated');
                    }
                }

                // Render or update chart with last N history values
                updateDeviceChart(deviceId, dev.history || []);
            });
        }

        // Poll every 1 second
        setInterval(fetchDevices, 1000);
        fetchDevices();
    </script>
</body>
</html>
"""

class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""
    daemon_threads = True

class RequestHandler(BaseHTTPRequestHandler):

    def log_message(self, format, *args):
        # Silence default HTTP server access logs to keep terminal output clean
        return

    def do_GET(self):
        if self.path == '/' or self.path == '/index.html':
            self.send_response(200)
            self.send_header('Content-Type', 'text/html; charset=utf-8')
            self.end_headers()
            self.wfile.write(HTML_TEMPLATE.encode('utf-8'))
        elif self.path == '/api/devices':
            self.send_response(200)
            self.send_header('Content-Type', 'application/json')
            self.end_headers()
            with devices_lock:
                json_data = json.dumps(DEVICES)
            self.wfile.write(json_data.encode('utf-8'))
        else:
            self.send_response(404)
            self.end_headers()

    def do_POST(self):
        if self.path == '/api/pred':
            content_length = int(self.headers.get('Content-Length', 0))
            post_data = self.rfile.read(content_length).decode('utf-8', errors='replace')

            try:
                payload = json.loads(post_data)
            except Exception:
                payload = {"pred_data": post_data}

            # Support both "esp32_deviceid" and "device_id"
            device_id = payload.get("esp32_deviceid") or payload.get("device_id") or payload.get("id") or "ESP32_UNKNOWN"

            # Support both "pred_data" and "pred"
            pred_raw = str(payload.get("pred_data") or payload.get("pred") or "")

            # Parse prediction and scores from JSON or string format
            scores = []
            if "scores" in payload and isinstance(payload["scores"], list):
                try:
                    scores = [round(float(x), 4) for x in payload["scores"]]
                except Exception:
                    scores = []

            pred_val = ""
            if "PRED:" in pred_raw:
                try:
                    parts = pred_raw.split()
                    for p in parts:
                        if p.startswith("PRED:"):
                            pred_val = "Class " + p.replace("PRED:", "")
                        elif p.startswith("SCORES:") and not scores:
                            scores_str = p.replace("SCORES:", "")
                            scores = [round(float(x), 4) for x in scores_str.split(",") if x.strip()]
                except Exception:
                    pred_val = pred_raw

            if not pred_val and scores:
                labels = ["Hypotension", "Hypoxia", "Tachycardia"]
                status_parts = []
                for idx, s in enumerate(scores):
                    name = labels[idx] if idx < len(labels) else f"Score_{idx+1}"
                    status_parts.append(f"{name}: {s:.4f}")
                pred_val = " | ".join(status_parts)
            elif not pred_val and pred_raw:
                pred_val = pred_raw
            elif not pred_val:
                pred_val = "Active Telemetry"

            now_str = datetime.datetime.now().strftime("%H:%M:%S")
            now_epoch = time.time()

            with devices_lock:
                if device_id not in DEVICES:
                    DEVICES[device_id] = {
                        "device_id": device_id,
                        "prediction_str": pred_val,
                        "pred_raw": pred_raw,
                        "scores": scores,
                        "update_count": 1,
                        "last_updated": now_str,
                        "last_updated_epoch": now_epoch,
                        "ip_address": self.client_address[0],
                        "history": []
                    }
                    print(f"\n[+] NEW DEVICE DETECTED: [{device_id}] from {self.client_address[0]}")
                else:
                    DEVICES[device_id]["prediction_str"] = pred_val
                    DEVICES[device_id]["pred_raw"] = pred_raw
                    DEVICES[device_id]["scores"] = scores
                    DEVICES[device_id]["update_count"] += 1
                    DEVICES[device_id]["last_updated"] = now_str
                    DEVICES[device_id]["last_updated_epoch"] = now_epoch
                    DEVICES[device_id]["ip_address"] = self.client_address[0]

                # Append history sample
                history_sample = {
                    "timestamp": now_str,
                    "pred": pred_val,
                    "scores": scores
                }
                
                if "history" not in DEVICES[device_id]:
                    DEVICES[device_id]["history"] = []

                DEVICES[device_id]["history"].append(history_sample)

                # Maintain maximum N historical items (configurable via MAX_HISTORY_LENGTH)
                if len(DEVICES[device_id]["history"]) > MAX_HISTORY_LENGTH:
                    DEVICES[device_id]["history"] = DEVICES[device_id]["history"][-MAX_HISTORY_LENGTH:]

                # Also mirror telemetry to PATIENT-000 so device 000 is always updated
                if "PATIENT-000" in DEVICES and device_id != "PATIENT-000":
                    DEVICES["PATIENT-000"]["prediction_str"] = pred_val
                    DEVICES["PATIENT-000"]["pred_raw"] = pred_raw
                    DEVICES["PATIENT-000"]["scores"] = scores
                    DEVICES["PATIENT-000"]["update_count"] += 1
                    DEVICES["PATIENT-000"]["last_updated"] = now_str
                    DEVICES["PATIENT-000"]["last_updated_epoch"] = now_epoch
                    DEVICES["PATIENT-000"]["ip_address"] = self.client_address[0]
                    if "history" not in DEVICES["PATIENT-000"]:
                        DEVICES["PATIENT-000"]["history"] = []
                    DEVICES["PATIENT-000"]["history"].append(history_sample)
                    if len(DEVICES["PATIENT-000"]["history"]) > MAX_HISTORY_LENGTH:
                        DEVICES["PATIENT-000"]["history"] = DEVICES["PATIENT-000"]["history"][-MAX_HISTORY_LENGTH:]

                count = DEVICES[device_id]["update_count"]

            print(f"[{now_str}] 📥 [{device_id}] Update #{count} -> {pred_raw}")

            response = {
                "status": "success",
                "device_id": device_id,
                "update_count": count,
                "timestamp": now_str
            }

            self.send_response(200)
            self.send_header('Content-Type', 'application/json')
            self.end_headers()
            self.wfile.write(json.dumps(response).encode('utf-8'))
        else:
            self.send_response(404)
            self.end_headers()

def main():
    server = ThreadedHTTPServer((HOST, PORT), RequestHandler)
    print("=" * 60)
    print("  ESP32 TELEMETRY HTTP SERVER & DASHBOARD")
    print(f"  Max History Length per Device: {MAX_HISTORY_LENGTH}")
    print(f"  Listening for POST at: http://0.0.0.0:{PORT}/api/pred")
    print(f"  Web Dashboard UI at:   http://localhost:{PORT}/")
    print("=" * 60 + "\n")

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n[Server] Shutting down telemetry server.")
    finally:
        server.server_close()

if __name__ == '__main__':
    main()
