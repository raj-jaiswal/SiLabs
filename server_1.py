#!/usr/bin/env python3
"""
ESP32 / EFR32 Meta Neural Network Telemetry Server & Web Dashboard (server_1.py)
----------------------------------------------------------------------------------
Serves:
1. POST /api/pred: Accepts telemetry JSON with device_id and 6 base scores (3 CNN + 3 DT)
                   Runs 3 Meta Neural Networks (Hypotension, Hypoxia, Tachycardia)
                   fusing Patient Clinical Metadata (Patient Case ID 427 for PATIENT-000)
2. GET  /api/devices: Returns JSON of all registered devices, latest 6 base scores,
                      and 3 final Meta Neural Network risk scores.
3. GET  /: Serves a responsive, live-updating Glassmorphism Dashboard with Chart.js visualization
"""

import os
import json
import time
import datetime
import threading
import numpy as np
import pandas as pd
from http.server import HTTPServer, BaseHTTPRequestHandler
from socketserver import ThreadingMixIn

# Port and Host Configuration
HOST = '0.0.0.0'
PORT = 5000
MAX_HISTORY_LENGTH = 10

# Paths
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
META_CSV_PATH = os.path.join(BASE_DIR, "preprocessed_patient_metadata.csv")
MODEL_DIR = os.path.join(BASE_DIR, "models/meta_neural_network")

# Thread-safe in-memory device registry
devices_lock = threading.Lock()
DEVICES = {}

# ------------------------------------------------------------------
# META NEURAL NETWORK INFERENCE ENGINE
# ------------------------------------------------------------------
class MetaNNInferenceEngine:
    def __init__(self, meta_csv_path, models_dir):
        self.meta_csv_path = meta_csv_path
        self.models_dir = models_dir
        self.is_ready = False
        self.p427_vec = None
        self.df_meta = None
        self.meta_cols = []
        
        try:
            import tensorflow as tf
            # Suppress verbose TF logging
            tf.get_logger().setLevel('ERROR')
            os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
            
            if os.path.exists(meta_csv_path):
                self.df_meta = pd.read_csv(meta_csv_path)
                self.meta_cols = [c for c in self.df_meta.columns if c not in ['caseid', 'subjectid']]
                p427_row = self.df_meta[self.df_meta['caseid'] == 427]
                if len(p427_row) > 0:
                    self.p427_vec = p427_row[self.meta_cols].values[0].astype(np.float32)
                else:
                    self.p427_vec = self.df_meta[self.meta_cols].iloc[0].values.astype(np.float32)
                print(f"[Meta-NN Engine] Loaded Patient 427 Metadata Vector ({len(self.p427_vec)} clinical features)")

            hypo_path = os.path.join(models_dir, 'meta_nn_Future_Hypotension.keras')
            hypox_path = os.path.join(models_dir, 'meta_nn_Future_Hypoxia.keras')
            tachy_path = os.path.join(models_dir, 'meta_nn_Future_Tachycardia.keras')
            
            if os.path.exists(hypo_path) and os.path.exists(hypox_path) and os.path.exists(tachy_path):
                self.model_hypo = tf.keras.models.load_model(hypo_path, compile=False)
                self.model_hypox = tf.keras.models.load_model(hypox_path, compile=False)
                self.model_tachy = tf.keras.models.load_model(tachy_path, compile=False)
                self.is_ready = True
                print("[Meta-NN Engine] Successfully loaded 3 Meta Neural Networks (Hypotension, Hypoxia, Tachycardia)!")
            else:
                print("[Meta-NN Engine] Warning: Meta-NN model files not found in models/meta_neural_network/")
        except Exception as e:
            print(f"[Meta-NN Engine] Initialization Error: {e}")

    def predict(self, scores_6, caseid=427):
        if not self.is_ready or self.p427_vec is None:
            # Fallback heuristic if TF or models unavailable
            return [round(scores_6[0]*0.5 + scores_6[3]*0.5, 4),
                    round(scores_6[1]*0.5 + scores_6[4]*0.5, 4),
                    round(scores_6[2]*0.5 + scores_6[5]*0.5, 4)]
        try:
            if caseid == 427 or self.df_meta is None:
                meta_vec = self.p427_vec
            else:
                p_row = self.df_meta[self.df_meta['caseid'] == caseid]
                if len(p_row) > 0:
                    meta_vec = p_row[self.meta_cols].values[0].astype(np.float32)
                else:
                    meta_vec = self.p427_vec
                    
            input_71 = np.concatenate([meta_vec, scores_6]).reshape(1, -1).astype(np.float32)
            h_prob = float(self.model_hypo(input_71, training=False).numpy()[0][0])
            hx_prob = float(self.model_hypox(input_71, training=False).numpy()[0][0])
            t_prob = float(self.model_tachy(input_71, training=False).numpy()[0][0])
            
            return [round(h_prob, 4), round(hx_prob, 4), round(t_prob, 4)]
        except Exception as e:
            print(f"[Meta-NN Predict Error] {e}")
            return [round(scores_6[0], 4), round(scores_6[1], 4), round(scores_6[2], 4)]

# Global Meta-NN Engine Instance
META_ENGINE = MetaNNInferenceEngine(META_CSV_PATH, MODEL_DIR)

# Initialize Default PATIENT-000 (Patient Case ID 427)
now_init = datetime.datetime.now().strftime("%H:%M:%S")
now_init_epoch = time.time()
base_scores_000 = [0.8850, 0.9420, 0.1200, 0.7500, 0.9800, 0.0500]
meta_scores_000 = META_ENGINE.predict(base_scores_000, caseid=427)

pred_str_000 = (
    f"★ META-NN RISK (Patient 427): Hypo={meta_scores_000[0]*100:.1f}% | Hypox={meta_scores_000[1]*100:.1f}% | Tachy={meta_scores_000[2]*100:.1f}% "
    f"(Base CNN: {base_scores_000[0]*100:.1f}%, {base_scores_000[1]*100:.1f}%, {base_scores_000[2]*100:.1f}% | "
    f"Base DT: {base_scores_000[3]*100:.1f}%, {base_scores_000[4]*100:.1f}%, {base_scores_000[5]*100:.1f}%)"
)

DEVICES["PATIENT-000"] = {
    "device_id": "PATIENT-000",
    "case_id": 427,
    "prediction_str": pred_str_000,
    "pred_raw": "",
    "scores": base_scores_000,       # 6 Base Model Scores (3 CNN + 3 DT)
    "meta_scores": meta_scores_000, # 3 Final Meta-NN Risk Probabilities
    "update_count": 1,
    "last_updated": now_init,
    "last_updated_epoch": now_init_epoch,
    "ip_address": "127.0.0.1",
    "history": [{
        "timestamp": now_init,
        "pred": pred_str_000,
        "scores": base_scores_000,
        "meta_scores": meta_scores_000
    }]
}

HTML_TEMPLATE = """<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 Meta Neural Network Dashboard</title>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;600;700;800&family=JetBrains+Mono:wght@400;600&display=swap" rel="stylesheet">
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        :root {
            --bg-color: #0d1117;
            --card-bg: rgba(22, 27, 34, 0.85);
            --card-border: rgba(255, 255, 255, 0.12);
            --accent-blue: #38bdf8;
            --accent-purple: #a855f7;
            --accent-green: #22c55e;
            --accent-orange: #f97316;
            --accent-red: #ef4444;
            --text-main: #f3f4f6;
            --text-muted: #9ca3af;
        }

        * { box-sizing: border-box; margin: 0; padding: 0; font-family: 'Inter', sans-serif; }
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
            margin: 0 auto 2rem auto;
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding-bottom: 1.5rem;
            border-bottom: 1px solid var(--card-border);
        }

        .brand { display: flex; align-items: center; gap: 1rem; }
        .brand-icon {
            width: 46px; height: 46px;
            background: linear-gradient(135deg, var(--accent-blue), var(--accent-purple));
            border-radius: 12px; display: flex; align-items: center; justify-content: center;
            box-shadow: 0 0 20px rgba(56, 189, 248, 0.4); font-size: 1.5rem;
        }

        h1 {
            font-size: 1.75rem; font-weight: 800; letter-spacing: -0.02em;
            background: linear-gradient(to right, #ffffff, #94a3b8);
            -webkit-background-clip: text; -webkit-text-fill-color: transparent;
        }
        .subtitle { font-size: 0.85rem; color: var(--text-muted); margin-top: 0.2rem; }

        .stat-pill {
            background: var(--card-bg); border: 1px solid var(--card-border);
            padding: 0.6rem 1.2rem; border-radius: 9999px; display: flex; align-items: center;
            gap: 0.6rem; font-size: 0.875rem; backdrop-filter: blur(12px);
        }
        .stat-dot {
            width: 8px; height: 8px; border-radius: 50%; background: var(--accent-green);
            box-shadow: 0 0 10px var(--accent-green); animation: pulse 2s infinite;
        }
        @keyframes pulse { 0%, 100% { opacity: 1; transform: scale(1); } 50% { opacity: 0.4; transform: scale(0.85); } }

        main { max-width: 1200px; margin: 0 auto; }
        .grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(520px, 1fr)); gap: 1.5rem; }

        .device-card {
            background: var(--card-bg); border: 1px solid var(--card-border);
            border-radius: 16px; padding: 1.5rem; backdrop-filter: blur(16px);
            transition: all 0.3s ease; position: relative; overflow: hidden;
        }
        .device-card:hover { transform: translateY(-4px); border-color: rgba(56, 189, 248, 0.4); }

        .card-header { display: flex; justify-content: space-between; align-items: center; margin-bottom: 1rem; }
        .device-id { font-size: 1.15rem; font-weight: 700; font-family: 'JetBrains Mono', monospace; }
        .badge-ip {
            background: rgba(255, 255, 255, 0.06); border: 1px solid var(--card-border);
            padding: 0.25rem 0.6rem; border-radius: 6px; font-size: 0.75rem; color: var(--text-muted);
        }

        .meta-risk-section {
            background: rgba(13, 17, 23, 0.6); border: 1px solid rgba(255, 255, 255, 0.08);
            border-radius: 12px; padding: 1rem; margin-bottom: 1rem;
        }
        .meta-title { font-size: 0.75rem; text-transform: uppercase; letter-spacing: 0.05em; color: var(--accent-blue); font-weight: 700; margin-bottom: 0.6rem; }
        
        .risk-bars { display: flex; flex-direction: column; gap: 0.6rem; }
        .risk-row { display: flex; align-items: center; justify-content: space-between; gap: 1rem; font-size: 0.825rem; }
        .bar-bg { flex: 1; height: 8px; background: rgba(255, 255, 255, 0.08); border-radius: 4px; overflow: hidden; }
        .bar-fill { height: 100%; border-radius: 4px; transition: width 0.4s ease; }

        .pred-section { margin-bottom: 1rem; }
        .pred-label { font-size: 0.75rem; text-transform: uppercase; color: var(--text-muted); margin-bottom: 0.3rem; }
        .pred-value { font-size: 0.85rem; line-height: 1.4; color: var(--text-main); font-weight: 500; }

        .scores-container { display: flex; flex-wrap: wrap; gap: 0.4rem; margin-top: 0.5rem; }
        .score-chip {
            background: rgba(255, 255, 255, 0.05); border: 1px solid var(--card-border);
            padding: 0.2rem 0.5rem; border-radius: 6px; font-size: 0.725rem; font-family: 'JetBrains Mono', monospace;
        }

        .chart-wrapper { margin-top: 1rem; padding-top: 1rem; border-top: 1px solid var(--card-border); }
        .card-footer { display: flex; justify-content: space-between; font-size: 0.75rem; color: var(--text-muted); margin-top: 1rem; }
    </style>
</head>
<body>
    <header>
        <div class="brand">
            <div class="brand-icon">🧠</div>
            <div>
                <h1>ESP32 Meta Neural Network Dashboard</h1>
                <div class="subtitle">Stacking 6 Base Predictors + Clinical Patient 427 Metadata</div>
            </div>
        </div>
        <div class="stats-bar">
            <div class="stat-pill"><div class="stat-dot"></div><span>Devices: <strong id="total-devices">1</strong></span></div>
        </div>
    </header>

    <main>
        <div id="device-grid" class="grid"></div>
    </main>

    <script>
        const deviceCharts = {};
        const previousData = {};

        function getRiskColor(prob) {
            if (prob >= 0.5) return 'var(--accent-red)';
            if (prob >= 0.3) return 'var(--accent-orange)';
            return 'var(--accent-green)';
        }

        async function fetchDevices() {
            try {
                const response = await fetch('/api/devices');
                if (!response.ok) return;
                const devices = await response.json();
                renderDevices(devices);
            } catch (e) { console.error('Fetch error:', e); }
        }

        function renderDevices(devices) {
            const grid = document.getElementById('device-grid');
            const deviceKeys = Object.keys(devices);
            document.getElementById('total-devices').innerText = deviceKeys.length;

            if (deviceKeys.length === 0) return;

            deviceKeys.forEach(deviceId => {
                const dev = devices[deviceId];
                let card = document.getElementById(`card-${deviceId}`);
                const isNew = !card;

                const meta = dev.meta_scores || [0, 0, 0];
                const base = dev.scores || [0, 0, 0, 0, 0, 0];

                const chipLabels = ["Hypo (CNN)", "Hypox (CNN)", "Tachy (CNN)", "Hypo (DT)", "Hypox (DT)", "Tachy (DT)"];
                const scoresHtml = base.map((s, i) => `<span class="score-chip">${chipLabels[i] || 'S'+(i+1)}: ${s}</span>`).join('');

                const hypoProb = (meta[0] * 100).toFixed(1);
                const hypoxProb = (meta[1] * 100).toFixed(1);
                const tachyProb = (meta[2] * 100).toFixed(1);

                const metaRiskHtml = `
                    <div class="meta-title">★ Stacking Meta Neural Network Risk (Patient ${dev.case_id || 427})</div>
                    <div class="risk-bars">
                        <div class="risk-row">
                            <span style="width: 110px;">Hypotension Risk</span>
                            <div class="bar-bg"><div class="bar-fill" style="width: ${hypoProb}%; background: ${getRiskColor(meta[0])};"></div></div>
                            <span style="width: 45px; text-align: right; font-weight: 700;">${hypoProb}%</span>
                        </div>
                        <div class="risk-row">
                            <span style="width: 110px;">Hypoxia Risk</span>
                            <div class="bar-bg"><div class="bar-fill" style="width: ${hypoxProb}%; background: ${getRiskColor(meta[1])};"></div></div>
                            <span style="width: 45px; text-align: right; font-weight: 700;">${hypoxProb}%</span>
                        </div>
                        <div class="risk-row">
                            <span style="width: 110px;">Tachycardia Risk</span>
                            <div class="bar-bg"><div class="bar-fill" style="width: ${tachyProb}%; background: ${getRiskColor(meta[2])};"></div></div>
                            <span style="width: 45px; text-align: right; font-weight: 700;">${tachyProb}%</span>
                        </div>
                    </div>
                `;

                if (isNew) {
                    card = document.createElement('div');
                    card.id = `card-${deviceId}`;
                    card.className = 'device-card';
                    card.innerHTML = `
                        <div class="card-header">
                            <div class="device-id">⚡ ${deviceId}</div>
                            <div class="badge-ip">${dev.ip_address || 'HTTP'}</div>
                        </div>
                        <div class="meta-risk-section">${metaRiskHtml}</div>
                        <div class="pred-section">
                            <div class="pred-label">6 Base Model Breakdown</div>
                            <div class="scores-container">${scoresHtml}</div>
                        </div>
                        <div class="chart-wrapper">
                            <div style="height: 140px; position: relative;"><canvas id="chart-${deviceId}"></canvas></div>
                        </div>
                        <div class="card-footer">
                            <span>Updates: <strong style="color: var(--accent-blue);">${dev.update_count}</strong></span>
                            <span>Last Seen: <strong>${dev.last_updated}</strong></span>
                        </div>
                    `;
                    grid.appendChild(card);
                } else {
                    card.querySelector('.meta-risk-section').innerHTML = metaRiskHtml;
                    card.querySelector('.scores-container').innerHTML = scoresHtml;
                }

                updateDeviceChart(deviceId, dev.history || []);
            });
        }

        function updateDeviceChart(deviceId, history) {
            const canvas = document.getElementById(`chart-${deviceId}`);
            if (!canvas) return;
            const ctx = canvas.getContext('2d');
            const labels = history.map(h => h.timestamp);

            const datasets = [
                { label: 'Meta-NN Hypo Risk', data: history.map(h => h.meta_scores ? h.meta_scores[0] : 0), borderColor: '#ef4444', borderWidth: 2, tension: 0.3 },
                { label: 'Meta-NN Hypox Risk', data: history.map(h => h.meta_scores ? h.meta_scores[1] : 0), borderColor: '#a855f7', borderWidth: 2, tension: 0.3 },
                { label: 'Meta-NN Tachy Risk', data: history.map(h => h.meta_scores ? h.meta_scores[2] : 0), borderColor: '#38bdf8', borderWidth: 2, tension: 0.3 }
            ];

            if (deviceCharts[deviceId]) {
                deviceCharts[deviceId].data.labels = labels;
                deviceCharts[deviceId].data.datasets = datasets;
                deviceCharts[deviceId].update('none');
            } else {
                deviceCharts[deviceId] = new Chart(ctx, {
                    type: 'line',
                    data: { labels, datasets },
                    options: {
                        responsive: true, maintainAspectRatio: false,
                        plugins: { legend: { labels: { color: '#9ca3af', font: { size: 9 } } } },
                        scales: { x: { ticks: { color: '#6b7280' } }, y: { min: 0, max: 1, ticks: { color: '#6b7280' } } }
                    }
                });
            }
        }

        setInterval(fetchDevices, 1000);
        fetchDevices();
    </script>
</body>
</html>
"""

class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    daemon_threads = True

class RequestHandler(BaseHTTPRequestHandler):
    def log_message(self, format, *args): return

    def do_GET(self):
        if self.path == '/' or self.path == '/index.html':
            body = HTML_TEMPLATE.encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'text/html; charset=utf-8')
            self.send_header('Content-Length', str(len(body)))
            self.end_headers()
            self.wfile.write(body)
        elif self.path == '/api/devices':
            with devices_lock:
                json_data = json.dumps(DEVICES)
            body = json_data.encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'application/json')
            self.send_header('Access-Control-Allow-Origin', '*')
            self.send_header('Content-Length', str(len(body)))
            self.end_headers()
            self.wfile.write(body)
        else:
            self.send_response(404)
            self.end_headers()

    def do_POST(self):
        if self.path == '/api/pred':
            content_length = int(self.headers.get('Content-Length', 0))
            body = self.rfile.read(content_length)
            try:
                payload = json.loads(body.decode('utf-8'))
            except Exception:
                payload = {}

            device_id = payload.get("esp32_deviceid") or payload.get("device_id") or payload.get("id") or "ESP32_UNKNOWN"
            pred_raw = str(payload.get("pred_data") or payload.get("pred") or "")
            case_id = int(payload.get("case_id") or 427)

            scores = []
            if "scores" in payload and isinstance(payload["scores"], list):
                try:
                    scores = [round(float(x), 4) for x in payload["scores"]]
                except Exception:
                    scores = []

            # Ensure 6 scores (3 CNN + 3 DT)
            while len(scores) < 6:
                scores.append(0.0)

            # Run Meta Neural Network Inference fusing Patient Clinical Metadata (Patient Case ID 427)
            meta_scores = META_ENGINE.predict(scores[:6], caseid=case_id)

            pred_val = (
                f"★ META-NN RISK (Patient {case_id}): Hypo={meta_scores[0]*100:.1f}% | Hypox={meta_scores[1]*100:.1f}% | Tachy={meta_scores[2]*100:.1f}% "
                f"(Base CNN: {scores[0]*100:.1f}%, {scores[1]*100:.1f}%, {scores[2]*100:.1f}% | "
                f"Base DT: {scores[3]*100:.1f}%, {scores[4]*100:.1f}%, {scores[5]*100:.1f}%)"
            )

            now_str = datetime.datetime.now().strftime("%H:%M:%S")

            with devices_lock:
                if device_id not in DEVICES:
                    DEVICES[device_id] = {
                        "device_id": device_id,
                        "case_id": case_id,
                        "prediction_str": pred_val,
                        "pred_raw": pred_raw,
                        "scores": scores,
                        "meta_scores": meta_scores,
                        "update_count": 1,
                        "last_updated": now_str,
                        "ip_address": self.client_address[0],
                        "history": []
                    }
                    print(f"\n[+] NEW DEVICE DETECTED: [{device_id}] (Case ID {case_id}) from {self.client_address[0]}")
                else:
                    DEVICES[device_id]["case_id"] = case_id
                    DEVICES[device_id]["prediction_str"] = pred_val
                    DEVICES[device_id]["pred_raw"] = pred_raw
                    DEVICES[device_id]["scores"] = scores
                    DEVICES[device_id]["meta_scores"] = meta_scores
                    DEVICES[device_id]["update_count"] += 1
                    DEVICES[device_id]["last_updated"] = now_str
                    DEVICES[device_id]["ip_address"] = self.client_address[0]

                history_sample = {
                    "timestamp": now_str,
                    "pred": pred_val,
                    "scores": scores,
                    "meta_scores": meta_scores
                }

                if "history" not in DEVICES[device_id]:
                    DEVICES[device_id]["history"] = []

                DEVICES[device_id]["history"].append(history_sample)
                if len(DEVICES[device_id]["history"]) > MAX_HISTORY_LENGTH:
                    DEVICES[device_id]["history"] = DEVICES[device_id]["history"][-MAX_HISTORY_LENGTH:]

                count = DEVICES[device_id]["update_count"]

            print(f"[{now_str}] 📥 [{device_id}] Meta-NN Risk -> Hypo: {meta_scores[0]*100:.1f}%, Hypox: {meta_scores[1]*100:.1f}%, Tachy: {meta_scores[2]*100:.1f}%")

            response = {
                "status": "success",
                "device_id": device_id,
                "case_id": case_id,
                "meta_scores": meta_scores,
                "scores": scores,
                "update_count": count,
                "timestamp": now_str
            }

            resp_bytes = json.dumps(response).encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'application/json')
            self.send_header('Access-Control-Allow-Origin', '*')
            self.send_header('Content-Length', str(len(resp_bytes)))
            self.end_headers()
            self.wfile.write(resp_bytes)

def main():
    server = ThreadedHTTPServer((HOST, PORT), RequestHandler)
    print("=" * 70)
    print("  🚀 ESP32 / EFR32 META NEURAL NETWORK TELEMETRY SERVER")
    print("=" * 70)
    print(f"  - Server Binding     : http://localhost:{PORT}/")
    print(f"  - Meta-NN Models     : models/meta_neural_network/")
    print(f"  - Clinical Metadata  : Patient Case ID 427 (from preprocessed_patient_metadata.csv)")
    print("=" * 70 + "\n")

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n[Server] Shutting down telemetry server.")
    finally:
        server.server_close()

if __name__ == '__main__':
    main()
