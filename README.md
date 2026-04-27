# Gravity Simulation

Simple 2D real-time gravity simulation for learning rendering, physics, and concurrency.

## Stack

- C++23
- CMake
- raylib
- NVIDIA stdexec

## Requirements

- CMake 3.16+
- C++23-capable compiler (GCC, Clang, or MSVC)
- Git

Dependencies are fetched with CMake.

## Build

```bash
cmake -S . -B build
cmake --build build -j
```

## Run

```bash
./build/gravity_simulation
```

## Layout

- src/main.cpp: app entry
- src/App.cpp: game loop and orchestration
- src/Particles.cpp: particle behavior
- src/Planet.cpp: planet logic
- include/: public headers
