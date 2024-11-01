# Hardware-Polynomial-Multiplier

This is the code repositiory for the NAU EE 2024 Capstone Project:\
*Hardware Design for Post-Quantum Cryptography Polynomial Multiplier*

https://ceias.nau.edu/capstone/projects/EE/2025/PolyMult/

## Goals
This project aims to build an optimized polynomial mutliplier hardware design in Verilog for use in post-quantum crytopgrahy algorithms, specfically targeting CRYSTALS-Kyber.

## Design
1. Using SystemVerilog/Verilog, we will implent this hardware design onto an FPGA board. We will utilize the NTT (Number Theoretic Transform) in order to reduce the number of mutliplications per polynomial pair, along with other optimization methods such as parallel-processing, etc.
2. We will utilize high-level software like Python/C to verify our hardware design.
