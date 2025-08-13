# ⚙️ 2D Physics Engine in C++ with SFML

A modular **2D rigid body physics engine** written in modern C++17 and powered by the **SFML** (Simple and Fast Multimedia Library) framework for real-time rendering and input handling.  
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
9. [Educational Value](#-educational-value)
10. [License](#-license)

---

## 📜 Overview

The 2D Physics Engine is built to simulate rigid body motion in a **closed environment**. The engine supports:

- Circle and rectangle rigid bodies with configurable physical properties
- Automatic collision detection and resolution
- Real-time rendering with SFML
- Modular, extensible, and clean architecture for future enhancements

This project emphasizes **clean architecture**, **scalability**, and **readability** while implementing fundamental concepts of classical mechanics.

---

## ✨ Features

- **Rigid Body Simulation** — Circle and rectangle shapes with mass, velocity, and position.
- **Elastic Collisions** — Impulse-based collision resolution for both circles and rectangles.
- **Boundary-safe & Constraints** — Objects won’t overlap after resolution and bounce off screen edges using reflection physics.
- **Configurable Physics Constants** — Gravity, restitution, window size in `Config.h`.
- **Random Utilities** — Random colors, numbers, and initialization helpers.
- **Non-Overlapping Spawns** — Ensures new objects do not spawn overlapping existing ones.
- **Real-Time Logging** — Outputs positions and velocities of all bodies periodically to the console for debugging.
- **Clean OOP Design** — Separate headers and implementations for maintainability.

---

## 🛠 Technical Design

- **Encapsulation**: Each class manages its own data and logic.
- **Modularity**: Physics, shapes, and utilities are split into dedicated files.
- **Single Responsibility Principle**: Each class serves a focused purpose.
- **Extensibility**: Adding new shapes or physics rules is straightforward.
- The rendering layer (SFML) is decoupled from the physics logic, enabling potential replacement with other graphics libraries.

---

## 📚 Core Components

| Component   | Location                       | Description |
|-------------|--------------------------------|-------------|
| `Vector2`   | `include/Vector2.h`            | Custom 2D vector math class with addition, scaling, normalization, and dot product. |
| `Shape`     | `include/Shape.h`              | Abstract base class for all shapes. |
| `CircleShape` / `RectangleShape` | `include/CircleShape.h`, `include/RectangleShape.h` | Shape types with radius or width/height. |
| `RigidBody` | `include/RigidBody.h`          | Represents a physical object with position, velocity, and shape. |
| `World`     | `include/World.h`              | Simulation manager: updates positions, checks collisions, resolves overlaps. |
| `Collision` | `include/Collision.h` & `.cpp` | Collision detection & impulse resolution for circles and rectangles. |
| `Utils`     | `include/Utils.h`              | Random number generation, colors, initialization. |

### Example Details

#### `Vector2` (in `Utils.h/.cpp`)
Custom 2D vector utility for:
- Vector addition, subtraction, scaling
- Magnitude (length) calculation
- Normalization
- Dot product for collision calculations

#### `RigidBody` (in `RigidBody.h/.cpp`)
Represents a physics object:
- Properties: `position`, `velocity`, `acceleration`, `radius`, `mass`, `color`
- Methods for updating motion using Newton's laws
- Handles rendering via SFML's shape API

#### `World` (in `World.h/.cpp`)
Simulation manager:
- Updates all bodies each frame
- Applies gravity and resolves collisions
- Maintains boundary constraints
- Handles object spawning with overlap checks

#### `Utils` (in `Utils.h/.cpp`)
General-purpose helpers for:
- Random number and color generation
- Collision overlap checks
- Time-based logging triggers

---

## ⚙️ Physics Concepts Used

1. **Newtonian Motion**  
   Objects move according to:
   ```cpp
   velocity += acceleration * deltaTime
   position += velocity * deltaTime
   ```
2. **Elastic Collisions**  
   For two colliding circles:
   - Normal vector between centers
   - Relative velocity along normal, inverted based on restitution
   - Impulse applied based on mass

3. **Boundary Reflection**  
   - Velocity component perpendicular to the boundary is inverted
   - Position clamped to stay within screen

4. **Vector Math**  
   - Dot products, normalization, magnitude for collision and movement

5. **Impulse Resolution**  
   - Adjusts velocities after collisions based on mass & elasticity

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
│   ├── Shape.h            # Abstract base class for shapes
│   ├── CircleShape.h      # Circle shape implementation
│   ├── RectangleShape.h   # Rectangle shape implementation
│   ├── World.h            # Simulation manager
│   └── Collision.h        # Collision detection/resolution
│
├── src/                   # Implementation files
│   ├── RigidBody.cpp
│   ├── Utils.cpp
│   ├── Vector2.cpp
│   ├── World.cpp
│   └── Collision.cpp
│   └── main.cpp               # Entry point 
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

**MacOS (Homebrew):**
```bash
brew install sfml
```

### Compile

```bash
g++ -std=c++17 src/*.cpp main.cpp -Iinclude \
    -lsfml-graphics -lsfml-window -lsfml-system -o physics_engine
```

---

## 🎮 Usage

Run the compiled executable:

```bash
./physics_engine
```

- Simulation starts automatically.
- Two circles and two rectangles will collide and react based on the physics engine.
- New circles are spawned automatically without overlap.

---

## 🎓 Educational Value

### 📚 Physics Concepts Demonstrated

#### **Classical Mechanics in Action**

- **Newton's First Law** — Objects at rest stay at rest until you click to create them, then remain in motion until forces act upon them.
- **Newton's Second Law** — F = ma, heavier objects accelerate more slowly under the same force.
- **Newton's Third Law** — Every collision shows action-reaction pairs.
- **Conservation of Momentum** — Total momentum remains constant during collisions.
- **Conservation of Energy** — Kinetic energy is transferred and partially conserved in collisions.
- **Gravitational Acceleration** — All objects fall at the same rate regardless of mass.

#### **Vector Mathematics Applications**

- **Vector Addition/Subtraction** — Forces combined via vector math.
- **Dot Product Calculations** — Used in collision detection and response.
- **Vector Normalization** — Unit direction vectors for collision normals.
- **Magnitude Calculations** — Distance and speed computations.

#### **Numerical Methods in Practice**

- **Differential Equations** — Position and velocity updated in real-time.
- **Integration Techniques** — Euler method for time stepping.
- **Discrete Time Stepping** — Real-time simulation via discrete updates.
- **Numerical Stability** — Parameter choices affect simulation stability.

---

## Example Simulation

- Two circles collide elastically and bounce apart.
- Two rectangles collide and separate without overlap.

---

## 📜 License

This project is licensed under the MIT License — feel free to modify and use it.
