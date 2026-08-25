# ESP32 AI Telemetry Server & Dashboard (`server.py`) Technical Documentation

This document provides a comprehensive developer and AI reference guide for `/home/kridega/esp32/wifi/server.py`. It details the architecture, data structures, HTTP endpoints, thread-safety model, embedded frontend dashboard, and guidelines for extending or refactoring the server.

---

## 1. System Overview & Purpose

`server.py` is a lightweight, zero-dependency Python multi-device HTTP telemetry server and web dashboard designed for real-time AI inference monitoring from ESP32 edge devices.

### Primary Functions:
1. **Telemetry Data Ingestion (`POST /api/pred`)**: Ingests structured JSON inference telemetry (probability scores, device IDs, raw text predictions) sent asynchronously by ESP32 microcontrollers over Wi-Fi.
2. **Real-Time Data Querying (`GET /api/devices`)**: Exposes an in-memory JSON registry containing all active edge devices, their latest predictions, and sliding window historical trend samples.
3. **Embedded Live Dashboard (`GET /`)**: Serves a responsive, single-page web dashboard with Glassmorphism aesthetics and Chart.js multi-line graphing to visualize probability scores in real time.

---

## 2. Technical Stack & Dependencies

- **Language**: Python 3.x
- **Standard Library Modules Only** (No `pip install` required):
  - `http.server.HTTPServer` & `http.server.BaseHTTPRequestHandler`
  - `socketserver.ThreadingMixIn` (Concurrent request handling)
  - `threading` (`threading.Lock` for thread-safe state)
  - `json`, `time`, `datetime`, `socket`
- **Frontend Dependencies (CDN Loaded)**:
  - Google Fonts (`Inter` & `JetBrains Mono`)
  - `Chart.js` (v4+ for line charts)

---

## 3. Configuration Variables

Defined at the top of `server.py` (lines 18–31):

| Variable | Type | Default Value | Description |
| :--- | :--- | :--- | :--- |
| `HOST` | `str` | `'0.0.0.0'` | Binds server to all local network interfaces (LAN/Wi-Fi accessible). |
| `PORT` | `int` | `5000` | Port number on which the server listens. |
| `MAX_HISTORY_LENGTH` | `int` | `10` | Maximum number of historical telemetry samples retained per device for charting. |
| `DEVICES` | `dict` | `{}` | Global in-memory dictionary storing device state and history. |
| `devices_lock` | `threading.Lock` | `Lock()` | Thread-lock protecting concurrent read/write access to `DEVICES`. |

---

## 4. Architecture & Threading Model

```
               +----------------------------------+
               |      ESP32 Microcontrollers      |
               +----------------------------------+
                                |
                   HTTP POST /api/pred (JSON)
                                |
                                v
               +----------------------------------+
               |     ThreadedHTTPServer (5000)    |
               +----------------------------------+
                                |
            Spawn Worker Thread per HTTP Request
                                |
                                v
               +----------------------------------+
               |       RequestHandler Class       |
               +----------------------------------+
                                |
             Mutex Lock (devices_lock.acquire())
                                |
                                v
               +----------------------------------+
               |      DEVICES Registry (RAM)      |
               +----------------------------------+
                                ^
                                |
                   HTTP GET /api/devices (JSON)
                   HTTP GET /           (HTML UI)
                                |
               +----------------------------------+
               |      Web Dashboard / Clients     |
               +----------------------------------+
```

### Multithreaded Request Processing:
- `ThreadedHTTPServer(ThreadingMixIn, HTTPServer)`: Inherits from `ThreadingMixIn` to create a separate thread for every incoming HTTP request. This prevents high-rate ESP32 telemetry posts from blocking web dashboard rendering requests.
- `devices_lock`: Prevents race conditions when multiple ESP32 devices post telemetry simultaneously or when web clients poll `/api/devices`.

---

## 5. API Reference & Endpoints

### 5.1 Ingest Telemetry (`POST /api/pred`)

- **URL**: `http://<SERVER_IP>:5000/api/pred`
- **Method**: `POST`
- **Content-Type**: `application/json`

#### Primary JSON Payload Format (Recommended):
```json
{
  "esp32_deviceid": "ESP32_28372FE94FC0",
  "scores": [0.8721, 1.0000, 0.9360]
}
```

#### Supported Legacy / Alternative Key Names:
- **Device ID**: Checked in order: `esp32_deviceid` $\rightarrow$ `device_id` $\rightarrow$ `id` $\rightarrow$ Fallback: `"ESP32_UNKNOWN"`.
- **Probability Scores**: `scores` (array of numbers).
- **String Predictions**: `pred_data` or `pred` (e.g. `"PRED:1 SCORES:0.12,0.85,0.03"` or `"Hypotension: 0.8721 | Hypoxia: 1.0000"`).

#### Success Response (`200 OK`):
```json
{
  "status": "success",
  "device_id": "ESP32_28372FE94FC0",
  "update_count": 42,
  "timestamp": "14:32:05"
}
```

---

### 5.2 Query Registered Devices (`GET /api/devices`)

- **URL**: `http://<SERVER_IP>:5000/api/devices`
- **Method**: `GET`
- **Response Format**: `application/json`

#### Response Schema Example:
```json
{
  "ESP32_28372FE94FC0": {
    "device_id": "ESP32_28372FE94FC0",
    "prediction_str": "Hypotension: 0.8721 | Hypoxia: 1.0000 | Tachycardia: 0.9360",
    "pred_raw": "",
    "scores": [0.8721, 1.0000, 0.9360],
    "update_count": 42,
    "last_updated": "14:32:05",
    "ip_address": "192.170.15.105",
    "history": [
      {
        "timestamp": "14:31:55",
        "pred": "Hypotension: 0.8721 | Hypoxia: 1.0000 | Tachycardia: 0.9360",
        "scores": [0.8500, 0.9800, 0.9100]
      },
      {
        "timestamp": "14:32:05",
        "pred": "Hypotension: 0.8721 | Hypoxia: 1.0000 | Tachycardia: 0.9360",
        "scores": [0.8721, 1.0000, 0.9360]
      }
    ]
  }
}
```

---

### 5.3 Web Dashboard UI (`GET /` or `GET /index.html`)

- **URL**: `http://<SERVER_IP>:5000/`
- **Method**: `GET`
- **Response Format**: `text/html`
- **Behavior**: Renders `HTML_TEMPLATE`, an embedded single-page dashboard that auto-polls `/api/devices` every 1000ms.

---

## 6. Code Walkthrough & Functions

### `get_local_ip()`
- **Purpose**: Discovers the primary local network IP of the host machine (e.g. `192.170.15.48`).
- **Implementation**: Opens a UDP socket towards Google DNS (`8.8.8.8:80`) to inspect local routing without sending traffic.

### `RequestHandler.do_GET()`
- Routes `/` and `/index.html` to serve `HTML_TEMPLATE`.
- Routes `/api/devices` to serialize `DEVICES` thread-safely into JSON.
- Returns `404 Not Found` for unrecognized routes.

### `RequestHandler.do_POST()`
- Handles incoming `/api/pred` payloads.
- Parses JSON data, extracts scores & device ID.
- Automatically generates formatted text descriptions for scores (mapping 3 float outputs to `Hypotension`, `Hypoxia`, and `Tachycardia`).
- Updates `DEVICES[device_id]` in RAM, appends sample to `history`, and caps history to `MAX_HISTORY_LENGTH`.

### `main()`
- Initializes `ThreadedHTTPServer((HOST, PORT), RequestHandler)`.
- Displays formatted startup banner with LAN access URLs.
- Executes `server.serve_forever()` and handles graceful shutdown on `KeyboardInterrupt` (Ctrl+C).

---

## 7. Instructions for Extension & Modification

### Adding Persistence (e.g. SQLite / CSV Logging)
To log incoming telemetry to a CSV file or database, modify `do_POST()` inside `with devices_lock:`:
```python
# Example CSV appending snippet inside do_POST():
with open("telemetry_log.csv", "a") as f:
    f.write(f"{now_str},{device_id},{','.join(map(str, scores))}\n")
```

### Changing Historical Chart Window
Modify line 27 of `server.py`:
```python
MAX_HISTORY_LENGTH = 50  # Increase graph memory window to 50 samples
```

### Customizing Score Labels
If your AI model outputs different classes, update line 619 in `do_POST()` and line 359 in `HTML_TEMPLATE`:
```python
labels = ["Condition_A", "Condition_B", "Condition_C"]
```

---

## 8. Quick Execution Commands

To launch the server:
```bash
python3 /home/kridega/esp32/wifi/server.py
```
