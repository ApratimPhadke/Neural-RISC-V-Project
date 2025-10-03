# Neural RISC-V Development Environment
FROM ubuntu:22.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Set working directory
WORKDIR /workspace

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    python3 \
    python3-pip \
    python3-venv \
    verilator \
    iverilog \
    gtkwave \
    vim \
    nano \
    curl \
    wget \
    make \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Create Python virtual environment
RUN python3 -m venv /opt/neural-riscv-env

# Activate virtual environment and install Python packages
RUN /opt/neural-riscv-env/bin/pip install --upgrade pip && \
    /opt/neural-riscv-env/bin/pip install \
    cocotb \
    pytest \
    numpy \
    matplotlib \
    jupyter

# Set up environment variables
ENV PATH="/opt/neural-riscv-env/bin:$PATH"
ENV VIRTUAL_ENV="/opt/neural-riscv-env"

# Copy project files
COPY . /workspace/

# Set default shell to bash
SHELL ["/bin/bash", "-c"]

# Default command
CMD ["bash"]
