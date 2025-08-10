# ⚙️ 2D Physics Engine in C++ with SFML

A modular **2D rigid body physics engine** written in modern C++ (C++17) and powered by the **SFML** (Simple and Fast Multimedia Library) framework for real-time rendering and input handling.  
This engine simulates basic rigid body dynamics with realistic motion, elastic collisions, and boundary constraints — forming a solid foundation for building games, simulations, or physics-based interactive applications.

---

## 📌 Table of Contents

1. [Overview](#-overview)
2. [Features](#-features)
3. [Technical Design](#-technical-design)
4. [Core Components](#-core-components)
5. [Physics Concepts Used](#-physics-concepts-used)
6. [Directory Structure](#-directory-structure)
7. [Building the Project](#-building-the-project)
8. [Usage](#-usage)
9. [License](#-license)

---

## 📜 Overview

The 2D Physics Engine is built to simulate rigid body motion in a **closed environment**. The engine supports:

- Creation of multiple circular bodies with configurable physical properties.
- Automatic collision detection and resolution.
- Real-time rendering with SFML.
- Modular and extensible code structure for future enhancements.

This project emphasizes **clean architecture**, **scalability**, and **readability** while implementing fundamental concepts of classical mechanics.

---

## ✨ Features

- **Rigid Body Simulation**  
  Circular rigid bodies with velocity, acceleration, and gravity.

- **Elastic Collisions**  
  Impulse-based collision resolution for circle-to-circle interactions.

- **Boundary Constraints**  
  Objects bounce off the screen edges using reflection physics.

- **Non-Overlapping Spawns**  
  Ensures new objects do not spawn overlapping existing ones.

- **Configurable Physics Constants**  
  Gravity, restitution (bounciness), and update frequency can be adjusted from a single config file.

- **Real-Time Logging**  
  Outputs positions and velocities of all bodies periodically to the console for debugging.

- **Modular Architecture**  
  Separation of logic into dedicated classes and source/header files for maintainability.

---

## 🧠 Technical Design

This project follows **Object-Oriented Programming (OOP)** principles and is split into self-contained components:

- **Encapsulation**: Each class manages its own data and logic.
- **Modularity**: Independent files for utilities, physics bodies, and world management.
- **Single Responsibility Principle**: Each class serves a focused purpose.

The rendering layer (SFML) is decoupled from the physics logic, enabling potential replacement with other graphics libraries in the future.

---

## 🛠 Core Components

### `Vector2` (in `Utils.h/.cpp`)

A custom 2D vector math utility providing:

- Vector addition, subtraction, scaling
- Magnitude (length) calculation
- Normalization
- Dot product for collision calculations

**Why custom instead of `sf::Vector2f`?**  
Custom vectors give more control and allow integration with non-SFML environments if needed.

---

### `RigidBody` (in `RigidBody.h/.cpp`)

Represents a **physics object**:

- Properties: `position`, `velocity`, `acceleration`, `radius`, `mass`, `color`
- Methods for updating motion using **Newton's laws of motion**:
  - `v = u + at` (velocity update)
  - `s = s0 + vt` (position update)
- Handles rendering itself via SFML's shape API.

---

### `World` (in `World.h/.cpp`)

The **simulation manager**:

- Updates all bodies each frame.
- Applies gravity and resolves collisions.
- Maintains boundary constraints.
- Handles object spawning with overlap checks.

---

### `Utils` (in `Utils.h/.cpp`)

General-purpose helper functions:

- Random number and color generation
- Collision overlap checks
- Time-based logging triggers

---

## 📚 Physics Concepts Used

### 1. **Newtonian Motion**

Objects move according to:

```cpp
velocity += acceleration * deltaTime
position += velocity * deltaTime
```

### 2. **Elastic Collisions**

For two colliding circles:

- Normal vector is calculated between centers.
- Relative velocity along the normal is inverted based on restitution.
- Impulse is applied proportionally to each body's mass.

### 3. **Boundary Reflection**

When an object reaches the screen edge:

- Velocity component perpendicular to the boundary is inverted.
- Position is clamped to avoid sticking outside the screen.

---

## 📂 Directory Structure

```
2d_engine/
│
├── include/                # Header files
│   ├── Config.h           # Physics constants (gravity, restitution, etc.)
│   ├── RigidBody.h        # Physics object class
│   ├── Utils.h            # Math and utility functions
│   ├── Vector2.h          # 2D vector operations
│   └── World.h            # Simulation manager
│
├── src/                   # Implementation files
│   ├── RigidBody.cpp
│   ├── Utils.cpp
│   ├── Vector2.cpp
│   └── World.cpp
│
├── main.cpp               # Entry point
└── README.md
```

---

## 🖥 Building the Project

### Install SFML

On Ubuntu / WSL:

```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

### Compile

```bash
g++ -std=c++17 src/*.cpp main.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system -o physics_engine
```

---

## 🎮 Usage

Run the compiled executable:

```bash
./physics_engine
```

**Controls:**

- The simulation runs automatically on start.
- New circles are spawned automatically without overlap.

---

## 📜 License

This project is open-source and available under the MIT License.
