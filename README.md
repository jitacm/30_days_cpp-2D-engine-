# ⚡ 2D Physics Engine with Scene Management & Advanced Debug Tools

A custom-built **2D Physics Engine** implemented in C++ using SFML, featuring **rigid body dynamics**, **collision detection**, **scene management**, **debug visualization**, and **runtime debugging tools**.  
This engine is designed for **learning, demonstration, and small-scale game prototypes**.  
It demonstrates best practices in C++ architecture, real-time simulation, and extensibility for advanced users and educators.

---

## 📖 Table of Contents

- [Overview](#overview)
- [Motivation & Educational Goals](#motivation--educational-goals)
- [Features](#features)
  - [Physics Core](#physics-core)
  - [Collision Detection](#collision-detection)
  - [Scene Management](#scene-management)
  - [Debugging Tools](#debugging-tools)
  - [User Interface & HUD](#user-interface--hud)
- [Project Structure](#project-structure)
- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Cloning](#cloning)
  - [Build Instructions](#build-instructions)
- [Usage](#usage)
  - [Controls](#controls)
  - [Sample Session](#sample-session)
- [Code Examples](#code-examples)
- [Technical Details](#technical-details)
  - [Physics Engine Core](#physics-engine-core)
  - [Collision Handling](#collision-handling)
  - [Scene System](#scene-system)
  - [Debug Visualization](#debug-visualization)
  - [Performance Considerations](#performance-considerations)
- [Extending the Engine](#extending-the-engine)
- [Key Terms](#key-terms)
- [Contribution Guidelines](#contribution-guidelines)
- [License](#license)
- [Credits & Acknowledgements](#credits--acknowledgements)
- [FAQ](#faq)
- [References](#references)

---

## 📌 Overview

This project is a **lightweight yet powerful** 2D physics simulation engine that can:

- Simulate rigid body motion under gravity and custom force fields.
- Detect and resolve collisions between multiple shape types.
- Organize and manage multiple **scenes** (e.g., Test Scene, Demo Scene) for different simulation setups.
- Provide **real-time debugging** through visualization tools, pause controls, step-through updates, and a dynamic HUD.
- Serve as an educational platform for physics, mathematics, and game development concepts.
- Be extended for actual games or interactive simulations.

---

## 🎯 Motivation & Educational Goals

The engine was created to:

- **Teach core physics concepts** (Newtonian mechanics, collision resolution, energy conservation, etc.).
- **Demonstrate clean C++ project architecture** for real-time applications.
- **Encourage experimentation**: users can easily modify scenes, add shapes, and tweak physics constants.
- **Provide a visual platform** to understand motion, collision, and debugging techniques.
- **Enable rapid prototyping** of simple games and physics-based demos.

---

## ✨ Features

### 🔹 Physics Core

- **Rigid Body Simulation**
  - Real-time updates for velocity, acceleration, mass, restitution, and gravity.
  - Supports both static and dynamic objects.
  - Customizable physics constants.
- **Shape Support**
  - Circle shapes with configurable radius and color.
  - Rectangle shapes (AABB) with configurable dimensions and color.
  - Easily extendable to polygons or custom shapes.
- **Gravity & Force Application**
  - Global gravity vector.
  - Per-object force and impulse application.
  - Mass-based acceleration (`F = m * a`).
- **Configurable Restitution**
  - Controls "bounciness" on collisions.
- **Velocity Damping**
  - Prevents jittering and simulates friction.

---

### 🔹 Collision Detection

- **Multiple Collision Types**
  - Circle–Circle: Distance-based detection and resolution.
  - Rectangle–Rectangle (AABB): Overlap and separation along axes.
  - Circle–Rectangle (NEW): Closest-point projection for mixed collision.
- **Impulse-Based Resolution**
  - Calculates post-collision velocities using mass and restitution.
  - Prevents overlap and maintains physical accuracy.
- **Collision Event Tracking**
  - Per-frame collision marking for debug visualization.
  - Collision count tracked for HUD.

---

### 🔹 Scene Management

- **Scene Class**
  - Encapsulates all world objects and logic for a particular simulation.
  - Supports custom setups, backgrounds, and event hooks.
- **Scene Manager**
  - Switches between multiple scenes at runtime.
  - Keyboard shortcuts for instant scene transitions.
  - Sample scenes provided: Test Scene, Demo Scene.
- **Runtime Scene Switching**
  - Enables comparative demonstrations and multi-level experiments.

---

### 🔹 Debugging Tools

- **Debug Visualization Mode** (`D`)
  - Bounding outlines for all shapes (yellow).
  - Velocity vectors drawn as arrows (cyan).
  - Real-time collision state highlighting (red).
- **Pause & Step Controls** (`P` / `O`)
  - Pause simulation at any time.
  - Step one frame at a time for detailed inspection.
- **On-Screen Debug HUD**
  - Frames Per Second (FPS)
  - Object count
  - Collision count
  - Active scene name
  - Performance metrics
- **Error & State Logging**
  - Console output for key events, errors, and state changes.

---

### 🔹 User Interface & HUD

- **Minimal UI Overlay**
  - Unobtrusive SFML-based HUD in the top-left corner.
  - Live updates of simulation state.
  - Customizable font and colors.
- **Keyboard Shortcuts**
  - All debug and scene functions mapped for rapid workflow.
- **Visual Feedback**
  - Color-coded states for easy diagnostics.

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

## 📥 Installation

### Prerequisites

- **C++17** or higher
- [SFML 2.5+](https://www.sfml-dev.org/)
- A C++ build system (CMake, g++, Visual Studio, etc.)

### Cloning

```bash
git clone https://github.com/yourusername/2D_Engine.git
cd 2D_Engine
```

### Build Instructions

**Using g++ (direct):**

```bash
g++ -std=c++17 src/*.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system -o 2D_Engine
```

**Using CMake (recommended):**

```bash
mkdir build
cd build
cmake ..
make
```

### Run the Engine

```bash
./2D_Engine
```

---

## 🎮 Usage

### Controls

| Key / Action      | Description                                           |
|-------------------|------------------------------------------------------|
| `1` / `2`         | Switch between Test and Demo scenes                  |
| `P`               | Pause / Resume simulation                            |
| `O`               | Step forward one frame (only works when paused)      |
| `D`               | Toggle debug visualization mode                      |
| `Space`           | Apply upward impulse to the main test object         |
| `Esc` or Close    | Exit simulation                                      |

### Sample Session

- Launch the engine and observe the default Test Scene.
- Press `2` to switch to the Demo Scene with more objects.
- Press `P` to pause simulation, then `O` to step frame-by-frame.
- Press `D` to enable debug visualization; examine shapes and velocity vectors.
- Apply impulses and watch the HUD update in real time.
- Experiment with collisions and transitions for learning and demonstration.

---

## 💻 Code Examples

**Minimal Setup:**

```cpp
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "RigidBody.h"

World world;

CircleShape* circle = new CircleShape(20.f, {400.f, 100.f}, sf::Color::Green);
RigidBody* circleBody = new RigidBody(circle, 5.f, 0.3f);
world.addRigidBody(circleBody);

RectangleShape* rect = new RectangleShape({50.f, 30.f}, {200.f, 50.f}, sf::Color::Blue);
RigidBody* rectBody = new RigidBody(rect, 10.f, 0.0f);
world.addRigidBody(rectBody);
```

**Applying Force Example:**

```cpp
circleBody->applyForce({0.0f, -200.0f}); // Upward force
```

**Main Loop Structure:**

```cpp
while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    world.update(dt);
    window.clear();
    world.render(window);
    window.display();
}
```

---

## 🧠 Technical Details

### ⚙ Physics Engine Core

- **RigidBody** objects store mass, velocity, position, restitution, and force accumulators.
- **World** manages all rigid bodies and updates them each frame.
- **Config.h** provides central control of global constants (gravity, time step, etc.).

### 🔍 Collision Handling

- **Circle–Circle:**  
  Checks distance between centers, applies impulse if overlapping.
- **Rectangle–Rectangle (AABB):**  
  Checks overlap on x and y axes, resolves separation and velocity.
- **Circle–Rectangle:**  
  Projects circle center onto rectangle bounds, detects proximity, resolves contact.
- **Collision Loop:**  
  All bodies tested pairwise for interactions each frame.
- **Impulse Resolution:**  
  Applies velocity changes, updates positions, and marks collision states.

### 🗂 Scene System

- **Scene Class:**  
  Contains all world objects, manages creation, update, and rendering.
- **SceneManager:**  
  Stores multiple scenes, enables runtime switching via keyboard.
- **Extensible:**  
  Add new scenes for experiments, demos, or game levels.

### 🖼 Debug Visualization

- **Mode Toggle:**  
  All debug rendering is conditional—no cost when off.
- **Bounding Outlines:**  
  Circles and rectangles drawn in contrasting color.
- **Velocity Vectors:**  
  Arrows scaled to current velocity.
- **Collision Highlight:**  
  Colliding bodies colored red for instant feedback.
- **HUD Overlay:**  
  SFML text showing FPS, object count, collision count, and scene name.

### ⚡ Performance Considerations

- **Efficient Update Loop:**  
  Uses time step for stable simulation.
- **Minimal Allocation:**  
  Scene objects reused where possible.
- **Debug Rendering:**  
  Only enabled when necessary.

---

## 🛠 Extending the Engine

- **Add New Shape Types:**  
  Implement polygons, ellipses, or custom forms by extending Shape.
- **Enhance Collision Detection:**  
  Add broad-phase (spatial partitioning) for large scenes.
- **Rotational Physics:**  
  Support angular velocity, torque, and moment of inertia.
- **Particle Systems:**  
  Simulate fluids, gases, or granular materials.
- **Constraints & Joints:**  
  Implement springs, hinges, or sliders for advanced simulations.
- **Scripting Integration:**  
  Connect with Lua or Python for rapid prototyping.

---

## 🗝 Key Terms

- **Rigid Body:**  
  An object with mass and velocity that responds to forces and collisions.
- **Restitution:**  
  How “bouncy” a collision is (1.0 = perfectly elastic, 0 = perfectly inelastic).
- **Impulse Resolution:**  
  Instant velocity change applied at collision to prevent overlap.
- **Scene:**  
  A self-contained environment containing its own set of game/physics objects.
- **HUD:**  
  Heads-Up Display, an on-screen overlay providing live information.
- **Step Debugging:**  
  Running the simulation one frame at a time for analysis.
- **AABB:**  
  Axis-Aligned Bounding Box, a rectangle aligned with the screen axes for collision checking.

---

## 🤝 Contribution Guidelines

We welcome all contributions:

1. **Fork the repository**  
   Create your own branch for new features or fixes.

2. **Implement and document**  
   Follow the modular design and comment your code.

3. **Submit a pull request**  
   Describe your changes, reference issues, and explain impact.

4. **Review and feedback**  
   Collaborate with maintainers and community for improvements.

5. **Testing**  
   Ensure code builds and runs on target platforms.

---

## 📜 License

This project is released under the MIT License — see the [LICENSE](LICENSE) file for details.

---

## 🙏 Credits & Acknowledgements

- SFML for windowing, graphics, and input.
- Physics and math foundations from open game engines and simulation research.
- The C++ and open-source community for continual support and innovation.
- Contributors, educators, and students who use and extend the engine.

---

## ❓ FAQ

**Q: Can I use this engine for a real game?**  
A: Yes, it's suitable for small games and prototypes. For commercial use, consider extending with robust collision and broad-phase algorithms.

**Q: Is rotational physics supported?**  
A: Not yet, but the architecture allows for easy addition.

**Q: How can I add a new scene?**  
A: Create a new Scene subclass, add to SceneManager, and bind a keyboard shortcut.

**Q: What platforms are supported?**  
A: All platforms supported by SFML and a C++17 compiler (Windows, Linux, MacOS).

**Q: Who do I contact for help?**  
A: Open an issue on GitHub or reach out to project maintainers.

---

## 📚 References

- [SFML Documentation](https://www.sfml-dev.org/documentation/2.5.1/)
- [Game Physics Engine Development](https://www.crashcoursephysics.com/)
- [Real-Time Collision Detection](https://www.realtimerendering.com/)
- [Wikipedia: Rigid Body Dynamics](https://en.wikipedia.org/wiki/Rigid_body_dynamics)

---

## 🌱 Final Notes

This engine is a living project—intended for experimentation, learning, and collaboration.  
Feel free to fork, modify, and share your own scenes, extensions, or educational materials.

Happy simulating! 🚀

---
