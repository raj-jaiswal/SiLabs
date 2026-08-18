#!/bin/bash

# Path to the virtual environment where we installed the NVIDIA libraries
VENV_DIR="$PWD/venv/lib/python3.14/site-packages/nvidia"

export LD_LIBRARY_PATH="\
$VENV_DIR/cublas/lib:\
$VENV_DIR/cuda_runtime/lib:\
$VENV_DIR/cudnn/lib:\
$VENV_DIR/cufft/lib:\
$VENV_DIR/curand/lib:\
$VENV_DIR/cusolver/lib:\
$VENV_DIR/cusparse/lib:\
$VENV_DIR/nccl/lib:\
$LD_LIBRARY_PATH"

echo "Running with CUDA 12 libraries from: $VENV_DIR"

# Run with the system python (which has TensorFlow installed)
/usr/bin/python train_1d_cnn.py
