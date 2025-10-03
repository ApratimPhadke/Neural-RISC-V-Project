#!/bin/bash
echo "Starting Neural RISC-V Development Environment..."
docker run -it --rm -v "$(pwd)":/workspace neural-riscv-env bash
