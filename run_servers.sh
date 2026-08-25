#!/usr/bin/env bash
# run_servers.sh
# -----------------------------------------------------------
# Script to launch both the Python Telemetry Server (Port 5000)
# and the Next.js Hospital Triage Dashboard (Port 3000)
# -----------------------------------------------------------

set -e

# Stop any existing processes on ports 5000 and 3000
echo "[Init] Clearing ports 5000 and 3000..."
fuser -k 5000/tcp 3000/tcp 2>/dev/null || true

echo "============================================================"
echo " LAUNCHING BOTH SILABS SERVERS"
echo "============================================================"

# 1. Start Python Telemetry Server on Port 5000
echo "[Server 1] Starting Python Telemetry Server on Port 5000..."
python3 server.py &
SERVER1_PID=$!
echo "✓ Python Server started (PID: $SERVER1_PID) at http://localhost:5000/"

# 2. Start Next.js Triage App on Port 3000
echo "[Server 2] Starting Next.js Triage Web Dashboard on Port 3000..."
cd triage_app
npm run dev &
SERVER2_PID=$!
echo "✓ Next.js Triage App started (PID: $SERVER2_PID) at http://localhost:3000/"

echo "============================================================"
echo " BOTH SERVERS RUNNING IN BACKGROUND!"
echo "   • Telemetry Server  : http://localhost:5000/"
echo "   • Triage Dashboard  : http://localhost:3000/"
echo " Press Ctrl+C to stop both servers."
echo "============================================================"

# Wait for both processes
trap "kill $SERVER1_PID $SERVER2_PID 2>/dev/null; exit 0" INT TERM
wait
