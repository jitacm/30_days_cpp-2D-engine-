# ⚙️ 2D Physics Engine (SFML-Based)

A lightweight yet extensible 2D physics simulation engine built in C++ with SFML.  
The engine focuses on **clean architecture**, **multiple shape support**, and **realistic motion** powered by a **gravity & force system**.  

This project serves as both a **learning resource** for game physics fundamentals and a **solid base** for building 2D games or simulations.

---

## 📌 Table of Contents

1. [Preview](#preview)
2. [Features](#features)
3. [Project Structure](#project-structure)
4. [Installation & Setup](#installation--setup)
5. [Usage](#usage)
6. [How It Works](#how-it-works)
7. [Physics Concepts Used](#physics-concepts-used)
8. [Extending the Engine](#extending-the-engine)
9. [Contribution Guidelines](#contribution-guidelines)
10. [License](#license)
11. [Acknowledgements](#acknowledgements)

---

## ✨ Features

- **Multiple Shape Support**
  - Circle shapes
  - Rectangle shapes
  - Easily extendable to polygons or custom shapes

- **Physics Engine**
  - Global gravity vector applied to all rigid bodies
  - Continuous force application (`applyForce`)
  - Instant impulse application (`applyImpulse`)
  - Mass-based acceleration (`F = m * a`)
  - Basic restitution (bounciness)
  - Configurable physics constants in one place (`Config.h`)

- **Collision**
  - Ground and shape collision detection
  - Shape-type-aware positioning correction
  - Velocity damping to prevent jittering

- **Architecture**
  - Clean separation of rendering (`Shape` classes) and physics (`RigidBody`, `World`)
  - Modular design for easy extension

---

## 🗂 Project Structure

```
2D_Engine/
│
├── include/
│   ├── CircleShape.h        # Circle shape rendering and position API
│   ├── Collision.h          # Collision detection/resolution
│   ├── Config.h             # Physics constants (gravity, etc.)
│   ├── RectangleShape.h     # Rectangle shape rendering and position API
│   ├── RigidBody.h          # Physics object wrapper for shapes
│   ├── Shape.h              # Shape base class
│   ├── Utils.h              # Math and utility functions
│   ├── Vector2.h            # Custom 2D vector math
│   └── World.h              # Simulation manager
│
├── src/
│   ├── Collision.cpp
│   ├── RigidBody.cpp
│   ├── Utils.cpp
│   ├── World.cpp
│   └── main.cpp             # Entry point and demo
│
└── README.md
```

---

## ⚙️ Installation & Setup

### 1. Clone the Repository
```bash
git clone https://github.com/yourusername/2D_Engine.git
cd 2D_Engine
```

### 2. Install Dependencies

**SFML (>= 2.5)**

- On Ubuntu:
  ```bash
  sudo apt-get install libsfml-dev
  ```
- On Windows:
  - Download SFML from [sfml-dev.org](https://www.sfml-dev.org/)
  - Extract and set up include/lib paths in CMake or Visual Studio

### 3. Build the Project

Using g++ (direct compilation):

```bash
g++ -std=c++17 src/*.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system -o 2D_Engine
```

Or using CMake (recommended):

```bash
mkdir build
cd build
cmake ..
make
```

---

## 🚀 Usage

After building, run:

```bash
./2D_Engine
```

**Controls:**

- Spacebar → Apply an upward impulse to the green circle

---

## 🧠 How It Works

**Physics Flow per Frame:**

- `World::update(dt)` iterates through all rigid bodies.
- Each `RigidBody::update(dt)`:
  - Applies global gravity from `Config::gravity`
  - Computes acceleration using `F = m * a`
  - Updates velocity and position
  - Performs ground and shape collision checks
  - Resets forces for the next frame

---

## Physics Concepts Used

The engine demonstrates several classical mechanics principles and vector mathematics:

### 1. Newtonian Motion
Objects update velocity & position using:
```cpp
velocity += acceleration * deltaTime
position += velocity * deltaTime
```

### 2. Elastic Collisions
- Impulse-based resolution for circles and rectangles
- Restitution controls bounciness

### 3. Boundary Reflection
- Objects bounce off the screen edge by inverting velocity perpendicular to the boundary

### 4. Vector Math
- Custom 2D `Vector2` class for addition, scaling, normalization, dot product
- Used in collision detection, impulse calculations, and motion updates

### 5. Impulse Resolution
- Adjusts velocities after collisions based on mass & elasticity

### 6. Discrete Time Stepping & Integration
- Euler method for real-time physics simulation

### 7. Educational Value
- Demonstrates Newton's laws, conservation of momentum & energy, and practical vector math in real-time simulation

---

## 💻 Example Code

Below is a minimal example using the engine:

```cpp
World world;

CircleShape* circle = new CircleShape(20.f, {400.f, 100.f}, sf::Color::Green);
RigidBody* circleBody = new RigidBody(circle, 5.f, 0.3f);
world.addRigidBody(circleBody);

RectangleShape* rect = new RectangleShape({50.f, 30.f}, {200.f, 50.f}, sf::Color::Blue);
RigidBody* rectBody = new RigidBody(rect, 10.f, 0.0f);
world.addRigidBody(rectBody);
```

---

## 🛠 Extending the Engine

You can extend the engine by:

- Adding new shape classes (e.g., `PolygonShape`)
- Implementing rigid body vs rigid body collision detection
- Adding rotational physics (torque, angular velocity)
- Creating a particle system
- Adding constraints and joints

---

## 🤝 Contribution Guidelines

We welcome contributions!

To contribute:

1. Fork the repository
2. Create a feature branch:
   ```bash
   git checkout -b feature/my-feature
   ```
3. Commit changes:
   ```bash
   git commit -m "Implement my feature"
   ```
4. Push and open a pull request

Please keep code modular, documented, and consistent with the style used.

---

## 📜 License

This project is licensed under the MIT License — see LICENSE for details.

---

## 💡 Acknowledgements

- SFML for windowing, graphics, and input
- Physics fundamentals from game development references and research
- The C++ community for inspiration and guidance
