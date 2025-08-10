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

## 🎓 Educational Value

### 📚 Physics Concepts Demonstrated

#### **⚡ Classical Mechanics in Action**

**Newton's First Law** - Objects at rest stay at rest until you click to create them, then they remain in motion until forces act upon them. You can observe this clearly when objects settle and stop moving.

**Newton's Second Law** - The fundamental F = ma relationship is visible everywhere. Heavier objects (larger mass) accelerate more slowly under the same gravitational force, and collision forces create accelerations inversely proportional to mass.

**Newton's Third Law** - Every collision shows action-reaction pairs perfectly. When two objects collide, they exert equal and opposite forces on each other, which you can observe in their post-collision velocities.

**Conservation of Momentum** - The total momentum of the system remains constant during collisions. Watch carefully as momentum transfers between objects - what one loses, the other gains.

**Conservation of Energy** - Kinetic energy is properly transferred and partially conserved in collisions, with some energy lost to the restitution factor to simulate real-world energy dissipation.

**Gravitational Acceleration** - All objects fall at the same rate regardless of mass, demonstrating one of the most counterintuitive physics principles in a visual, interactive way.

#### **🧮 Vector Mathematics Applications**

**Vector Addition and Subtraction** - Forces from different sources (gravity, collisions) get combined using vector mathematics, showing how multiple influences affect object motion.

**Dot Product Calculations** - Used extensively in collision detection and response to project velocity vectors onto collision normal vectors.

**Vector Normalization** - Converting direction vectors to unit length for collision normal calculations and force applications.

**Magnitude Calculations** - Distance computations and speed measurements using the Pythagorean theorem in practical applications.

#### **🔢 Numerical Methods in Practice**

**Differential Equations** - Position is the integral of velocity, velocity is the integral of acceleration, all solved numerically in real-time.

**Integration Techniques** - Euler method demonstrates how continuous mathematical processes get converted into discrete computational steps.

**Discrete Time Stepping** - Shows how real-time simulations handle the transition from continuous mathematics to discrete computer calculations.

**Numerical Stability** - Understanding why certain parameters and time steps work better than others, and recognizing stability issues when they occur.

## 📜 License

This project is open-source and available under the MIT License.

