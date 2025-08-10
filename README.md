# 🚀 CPP-Physics: Advanced 2D Physics Engine

*An Interactive Real-Time 2D Physics Simulation Engine Built with Modern C++ and SFML*

## 🌟 Project Overview

### 🎯 What is CPP-Physics Engine?

**CPP-Physics** is a sophisticated, real-time 2D physics simulation engine I designed specifically for educational purposes and game development prototyping. This project demonstrates fundamental physics simulation principles using modern C++17 programming techniques combined with the powerful SFML (Simple and Fast Multimedia Library) graphics framework.

What makes this special? It's not just another bouncing ball demo - it's a fully functional physics engine that handles realistic collisions, momentum transfer, and gravitational forces, all running smoothly at 60 FPS.

### 🎓 Purpose & Educational Goals

I built this project to serve multiple educational and practical purposes:

**For Learning Physics** - There's something incredible about watching physics equations come to life on screen. Instead of just reading about momentum conservation in textbooks, you can actually see it happen when objects collide and transfer energy to each other.

**For Programming Skills** - This showcases modern C++ programming techniques and best practices. You'll find smart pointers, proper memory management, clean object-oriented design, and efficient algorithms throughout the codebase.

**For Game Development** - Understanding physics engines is crucial for game development. This provides hands-on experience with game physics implementation without getting lost in overly complex 3D mathematics.

**For Mathematical Applications** - Vector mathematics and calculus aren't just abstract concepts here - they're practical tools that create realistic motion and collision responses.

**For Software Architecture** - The project illustrates proper object-oriented design patterns that you can apply to larger, more complex projects.

### 🔬 What This Engine Accomplishes

**Real-Time Simulation** - Processes physics calculations at 60 FPS for smooth, realistic motion. No stuttering, no lag - just fluid physics simulation.

**Interactive Learning** - Users can experiment with physics concepts through direct mouse interaction. Click to create objects, watch them fall, see them collide - physics becomes intuitive and engaging.

**Visual Feedback** - Provides immediate visual representation of physics principles. Every force, every collision, every motion follows real physics laws that you can observe and understand.

**Scalable Architecture** - Designed to handle multiple objects simultaneously without performance degradation. Start with one object, add fifty more, and watch the engine handle complex multi-body interactions gracefully.

**Cross-Platform Compatibility** - Runs on Windows, Linux, and macOS systems without modification. Write once, run everywhere.

### 🌍 Perfect For

**Students** learning physics, mathematics, or computer science who want to see theory in action
**Game Developers** who need to understand physics engine implementation from the ground up
**Educators** teaching physics concepts through interactive demonstration
**Hobbyists** interested in physics simulation and game development
**Professionals** prototyping physics-based applications or testing physics concepts

## ✨ Features & Capabilities

### 🔬 Core Physics Features

#### **⚡ Rigid Body Dynamics System**

The heart of any physics engine lies in how it handles object behavior. Here's what makes this system special:

**Mass-Based Calculations** - Each object has configurable mass that directly affects its behavior. Heavier objects require more force to accelerate, influence collision responses differently, and transfer momentum realistically. The system uses inverse mass calculations for efficient physics computation, which is a technique used in professional game engines.

**Precision Position Tracking** - The engine maintains precise coordinate management with sub-pixel accuracy. This prevents the visual jitter you see in simpler physics demonstrations and ensures smooth, professional-looking motion.

**Real-Time Velocity Management** - Velocity updates happen in real-time based on applied forces. Whether it's gravity pulling objects down or collision forces pushing them apart, the velocity system responds immediately and accurately.

**Dynamic Acceleration Handling** - Acceleration from gravity, collision forces, and any other applied forces gets properly integrated into the motion calculations using proper numerical methods.

#### **🌍 Gravitational Force System**

**Consistent Universal Gravity** - All objects experience the same gravitational acceleration (200 pixels/second²), just like in real life. A feather and a hammer would fall at the same rate in a vacuum, and they do here too.

**Mass-Independent Acceleration** - This is one of the most counterintuitive physics principles that the engine demonstrates beautifully. Regardless of how big or small an object is, gravity affects them equally.

**Configurable Direction** - While gravity points downward by default, the system is designed so you can easily modify the gravity vector for different effects or experiments.

**Proper Force Accumulation** - Gravity combines naturally with other forces in the system, following the principle of force superposition.

#### **💥 Advanced Collision Detection**

**Precise Circle-Circle Detection** - Uses exact mathematical collision detection between circular objects. No approximations or "close enough" solutions - if objects are touching, the system knows it immediately.

**Distance-Based Algorithm** - Employs the Euclidean distance formula for accuracy. Every collision calculation is mathematically precise.

**Continuous Detection** - Checks collisions every frame to prevent the dreaded "tunneling" effect where fast-moving objects pass through each other.

**Broad Phase Optimization** - While the current implementation checks all possible pairs, the architecture is designed to easily accommodate spatial partitioning optimizations for scenes with many objects.

**Exact Penetration Calculation** - When objects do overlap, the system calculates exactly how much they're overlapping, which is crucial for realistic separation and collision response.

#### **🏀 Collision Resolution System**

**Impulse-Based Response** - This is where the real physics magic happens. The system uses momentum conservation principles to calculate exactly how objects should respond to collisions.

**Configurable Restitution Factor** - The bounciness coefficient (set to 0.8 for realistic bouncing) determines how much energy is preserved in collisions. You can easily modify this to create perfectly bouncy or completely inelastic collisions.

**Proper Velocity Exchange** - When objects collide, they don't just bounce off randomly. The system calculates proper momentum transfer based on the objects' masses and velocities before collision.

**Smart Separation Algorithm** - Prevents objects from getting stuck together after collision, which is a common problem in physics simulations that aren't properly implemented.

**Energy Conservation** - The system maintains realistic energy distribution in collisions, preventing the artificial energy gain or loss that plagues simpler physics implementations.

#### **🔄 Numerical Integration**

**Euler Integration Method** - Uses a simple yet effective integration technique that's perfect for educational purposes. While more advanced engines might use Runge-Kutta or other methods, Euler integration is easier to understand and implement correctly.

**Frame-Rate Independence** - Physics calculations adjust to varying frame rates, ensuring consistent behavior whether the game runs at 30, 60, or 120 FPS.

**Smooth Position Updates** - Object movement is based on proper velocity calculations, creating smooth, natural-looking motion.

**Stability Measures** - The system includes safeguards to prevent simulation instability and object tunneling that can occur with poor integration implementations.

### 🎮 Interactive Features

#### **🖱️ Mouse Interaction System**

**Click-to-Spawn** - Create new physics objects by clicking anywhere in the window. It's that simple - point, click, and watch physics happen.

**Real-Time Object Creation** - Objects appear instantly at the mouse cursor position with no delay or loading time.

**Dynamic Properties** - Each new object gets randomly generated size and color, making it easy to track individual objects through complex interactions.

**Unlimited Spawning** - There's no artificial limit to the number of objects you can create. The only limitation is your computer's processing power.

**Immediate Physics Response** - New objects immediately respond to gravity and can collide with existing objects from the moment they're created.

#### **🎨 Visual Representation**

**Unique Object Colors** - Each physics object has a randomly generated color, making it easy to follow individual objects through complex multi-body interactions.

**Smooth 60 FPS Animation** - The visual rendering is perfectly synchronized with the physics calculations, creating fluid motion that's pleasant to watch.

**Clean Geometric Representation** - Objects are rendered as clean circles using SFML's optimized CircleShape class.

**Perfect Physics-Graphics Sync** - Visual position updates match physics calculations exactly - no lag, no approximation, no visual artifacts.

**Professional Dark Theme** - The background uses a carefully chosen dark color (RGB: 13, 17, 23) that provides excellent contrast for the colorful objects without causing eye strain.

#### **🚧 Boundary Management**

**Realistic Screen Edge Collision** - Objects don't just disappear or stop at window boundaries - they bounce off realistically with proper momentum and energy transfer.

**Configurable Boundaries** - The window size determines the physics world limits, and you can easily modify this in the code.

**Proper Velocity Reversal** - When objects hit edges, they don't just reverse direction - they respond based on real collision physics.

**Energy Dissipation** - Boundary collisions include realistic energy loss (0.8 factor) just like real-world collisions with walls.

### 🛡️ Advanced Technical Features

#### **📊 Memory Management**

**Smart Pointers Everywhere** - The entire system uses std::unique_ptr for automatic memory management, preventing memory leaks and dangling pointer bugs that plague traditional C++ projects.

**RAII Principles** - Resource Acquisition Is Initialization ensures safe resource handling throughout the application lifecycle.

**Efficient Dynamic Allocation** - Objects are created and destroyed efficiently without causing memory fragmentation or performance spikes.

**Memory Safety Guaranteed** - The smart pointer system prevents the memory-related crashes that are common in manual memory management.

#### **⚙️ Performance Optimization**

**Efficient Collision Checking** - While the current O(n²) collision detection works great for educational purposes, the architecture is designed to easily accommodate more advanced optimization techniques.

**Consistent Frame Rate** - The engine maintains a rock-solid 60 FPS for smooth simulation, with frame rate limiting to prevent unnecessary CPU usage.

**Delta Time Integration** - The physics system handles variable frame rates gracefully, ensuring consistent behavior across different hardware.

**Minimal Memory Overhead** - The lightweight implementation focuses on core physics concepts without unnecessary bloat or complex dependencies.

## 🛠️ Installation Guide

### 📋 System Requirements

#### **💻 Hardware Requirements**

You don't need a gaming rig to run this engine. Here's what you'll need:

**CPU** - Any modern processor will do fine. Intel i3/AMD Ryzen 3 or better is recommended, but even older processors can handle the physics calculations.

**RAM** - Just 512 MB of available memory is plenty. The engine is designed to be lightweight and memory-efficient.

**Graphics** - Any OpenGL 2.0+ compatible graphics card, which includes virtually every graphics card made in the last 15 years.

**Storage** - About 50 MB of free disk space for compilation and execution.

**Display** - Any monitor with at least 800x600 resolution will work perfectly.

#### **🖥️ Operating System Support**

**Linux** - Ubuntu 18.04+, Debian 10+, Fedora 30+, or equivalent distributions. Most modern Linux distributions will work without issues.

**Windows** - Windows 10/11 with 64-bit recommended, though 32-bit systems will work too.

**macOS** - macOS 10.14+ (Mojave or later) with full compatibility.

#### **🔧 Development Tools Required**

**C++ Compiler** - You'll need a compiler that supports C++17:
- GCC 7.0 or later (Linux/macOS)
- Clang 5.0 or later (macOS/Linux) 
- Visual Studio 2019+ (Windows)
- MinGW-w64 (Windows alternative)

**Build System** - Make utility is optional but recommended for easy compilation.

**Version Control** - Git for repository cloning (most systems have this installed).

### 📦 SFML Library Installation

#### **🐧 Linux Installation (Ubuntu/Debian)**

Here's the straightforward process for Ubuntu or Debian-based systems:

```bash
# Update your package repositories first
sudo apt-get update

# Install SFML development libraries
sudo apt-get install libsfml-dev

# Install build tools if you don't have them
sudo apt-get install build-essential

# Install Git if needed
sudo apt-get install git

# Verify the installation worked
pkg-config --libs sfml-all
```

#### **🐧 Linux Installation (Fedora/CentOS/RHEL)**

For Red Hat-based distributions:

```bash
# For Fedora users
sudo dnf install SFML-devel gcc-c++ make git

# For CentOS/RHEL (you'll need EPEL repository first)
sudo yum install epel-release
sudo yum install SFML-devel gcc-c++ make git
```

#### **🍎 macOS Installation**

macOS installation is straightforward with Homebrew:

```bash
# Install Homebrew if you haven't already
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install SFML through Homebrew
brew install sfml

# Install Xcode command line tools
xcode-select --install

# Verify everything installed correctly
brew list sfml
```

#### **🪟 Windows Installation**

**Method 1: Using vcpkg (Recommended for most users)**
```cmd
# Clone vcpkg package manager
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg

# Bootstrap vcpkg for Windows
.\bootstrap-vcpkg.bat

# Install SFML for x64 Windows
.\vcpkg install sfml:x64-windows

# Integrate with Visual Studio
.\vcpkg integrate install
```

**Method 2: Manual Installation**
1. Download SFML from the official website (https://www.sfml-dev.org/download.php)
2. Extract to C:\SFML\ directory
3. Configure your IDE to link against SFML libraries
4. Add necessary DLL files to your project output directory

### 📥 Project Installation from GitHub

#### **🔽 Clone the Repository**

Getting the source code is simple:

```bash
# Clone the repository to your local machine
git clone https://github.com/Ashleesh/30_days_cpp-2D-engine-.git

# Navigate into the project directory
cd 30_days_cpp-2D-engine-

# Check what files are in the project
ls -la
```

#### **⚙️ Compilation Process**

**Method 1: Using Make (Easiest approach)**
```bash
# Compile everything with a single command
make

# If you need to clean up build files
make clean

# For a complete rebuild
make clean && make
```

**Method 2: Manual Compilation**
```bash
# Basic compilation command
g++ -std=c++17 Game.cpp -o physics_engine \
    -lsfml-graphics -lsfml-window -lsfml-system

# For debug build with extra error checking
g++ -std=c++17 -g -Wall -Wextra Game.cpp -o physics_engine_debug \
    -lsfml-graphics -lsfml-window -lsfml-system

# For optimized release build
g++ -std=c++17 -O3 -DNDEBUG Game.cpp -o physics_engine_release \
    -lsfml-graphics -lsfml-window -lsfml-system
```

#### **🚀 Running the Simulation**

Once compilation is complete:

```bash
# Execute the compiled program
./physics_engine

# Run debug version if you compiled it
./physics_engine_debug

# Make sure executable has proper permissions if needed
chmod +x physics_engine
```

#### **🔍 Troubleshooting Installation**

**Common Issues and Solutions:**

**SFML Not Found Error**
```bash
# Check if SFML is properly installed
pkg-config --modversion sfml-all

# If not found, reinstall SFML
sudo apt-get install --reinstall libsfml-dev
```

**Compilation Errors**
```bash
# Check GCC version (must support C++17)
gcc --version

# Update GCC if version is too old
sudo apt-get install gcc-9 g++-9
```

**Runtime Errors**
```bash
# Check shared library dependencies
ldd physics_engine

# Install missing OpenGL dependencies
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
```

## 🎮 Usage & Controls

### 🖱️ Mouse Controls

**Left Click - Spawn Physics Object** - This is your primary interaction method. Click anywhere in the window to create a new circular object at that exact location. Each object gets a random size (10-30 pixels radius) and a unique random color, then immediately begins responding to physics simulation.

**Right Click** - Currently reserved for future features. No assigned functionality at the moment, but the architecture supports adding new interactions here.

**Mouse Movement** - Move your cursor to choose the spawn location for new objects. There's visual feedback showing exactly where your new object will appear, and no restrictions on spawn location within window bounds.

### ⌨️ Keyboard Controls

**ESC Key** - Safely exits the simulation with proper resource cleanup. The application responds immediately to this input.

**Alt + F4** - Alternative exit method using standard Windows/Linux exit combination. Useful if the window becomes unresponsive.

**Space Key** - Reserved for future pause/resume functionality. Currently has no assigned action but is planned for implementation.

### 🎯 Interactive Elements

#### **🔴 Physics Objects**

Every object you spawn has these characteristics:

**Visual Appearance** - Randomly colored circles with smooth, anti-aliased edges that look professional and are easy to track.

**Physical Behavior** - Falls under gravity influence, bounces realistically off boundaries and other objects, and maintains momentum through collisions.

**Unique Properties** - Individual mass based on radius, unique color for identification, and independent physics state.

**Realistic Interactions** - Collides with other objects and transfers momentum naturally following conservation laws.

#### **🌍 Simulation Environment**

The physics world provides a controlled environment with these features:

**Window Dimensions** - Default 800x600 pixel resolution that provides plenty of space for experimentation.

**Professional Appearance** - Dark background (RGB: 13, 17, 23) that's easy on the eyes and makes colorful objects pop.

**Solid Boundaries** - All four window edges act as collision surfaces with realistic bounce behavior.

**Consistent Gravity** - Constant downward gravitational acceleration affecting all objects uniformly.

#### **⚡ Real-Time Features**

The engine delivers smooth, responsive simulation through:

**60 FPS Performance** - Locked frame rate ensures consistent behavior and smooth visual experience.

**Real-Time Physics** - Calculations happen every frame with immediate response to user input.

**Perfect Synchronization** - Graphics rendering perfectly matches physics calculations with no lag or visual artifacts.

**Automatic Resource Management** - Memory cleanup and efficient resource usage happen automatically in the background.

## 🔧 Technical Implementation

### 🏗️ Architecture Overview

#### **📐 Vector2 Mathematics Class**

The foundation of any physics engine is solid vector mathematics. Here's how the Vector2 class works:

```cpp
struct Vector2 {
    float x, y;                           // 2D coordinate components
    
    // Constructors for flexibility
    Vector2();                            // Default constructor (0,0)
    Vector2(float x, float y);           // Parameterized constructor
    
    // Mathematical operators
    Vector2 operator+(const Vector2&);    // Vector addition
    Vector2 operator-(const Vector2&);    // Vector subtraction  
    Vector2 operator*(float);             // Scalar multiplication
    
    // Essential utility functions
    float length();                       // Calculate magnitude
    Vector2 normalized();                 // Get unit vector
    static float dot(Vector2&, Vector2&); // Dot product calculation
}
```

**Key Design Features:**
- **Memory Efficient** - Simple struct with minimal overhead and cache-friendly layout
- **Mathematically Complete** - All essential 2D vector operations needed for physics simulation
- **Performance Optimized** - Inline functions for maximum speed in tight physics loops
- **Robust Implementation** - Handles edge cases like zero-length vectors safely without crashing

#### **🎯 RigidBody Physics Class**

This is where individual object physics lives:

```cpp
class RigidBody {
    // Core physics properties
    Vector2 position;         // Current position in world space
    Vector2 velocity;         // Current velocity vector
    Vector2 acceleration;     // Current acceleration vector
    float radius;             // Object radius for collision detection
    float mass;               // Object mass for physics calculations
    float inverseMass;        // Cached inverse mass for performance
    
    // Visual representation
    sf::CircleShape shape;    // SFML shape for rendering
    
    // Essential methods
    void applyForce(Vector2&);        // Apply force to object
    void update(float deltaTime);      // Update physics state
}
```

**Implementation Highlights:**
- **Force Integration** - Accumulates all forces before applying to acceleration for realistic physics
- **Euler Integration** - Updates velocity and position using discrete time steps with proper numerical methods
- **Visual Synchronization** - Keeps SFML shape position perfectly matched with physics calculations
- **Performance Optimization** - Uses precomputed inverse mass for efficient collision calculations

#### **🌍 World Management System**

The World class orchestrates everything:

```cpp
class World {
    // Object management
    std::vector<std::unique_ptr<RigidBody>> bodies;  // Safe object storage
    Vector2 gravity;                                 // Global gravity vector
    sf::Vector2u windowSize;                        // Window dimensions
    
    // Core system methods
    void addBody(std::unique_ptr<RigidBody>);       // Add new object safely
    void update(float deltaTime);                    // Main simulation loop
    void resolveCollision(RigidBody*, RigidBody*);  // Handle object collisions
    void handleBoundaries();                        // Boundary collision management
}
```

**System Responsibilities:**
- **Complete Object Lifecycle** - Manages creation, updating, and destruction of physics objects
- **Universal Force Application** - Applies global forces like gravity to all objects uniformly
- **Collision Management** - Handles both broad-phase and narrow-phase collision detection and resolution
- **Boundary Enforcement** - Ensures all objects remain within simulation bounds with realistic responses
- **Memory Safety** - Uses smart pointers for automatic resource cleanup and exception safety

## 📂 Project Structure

```
📁 30_days_cpp-2D-engine-/
├── 📄 Game.cpp                    # Complete engine implementation
├── 📋 README.md                   # This comprehensive documentation
```

### 📄 File Descriptions

#### **🎮 Game.cpp (Core Implementation)**

This single file contains the complete physics engine implementation:

**Comprehensive Implementation** - Over 450 lines of well-structured, modern C++ code that demonstrates professional programming practices.

**Clear Organization** - Logical class separation with methods grouped by functionality for easy understanding and maintenance.

**Modern Standards** - Follows C++17 best practices and coding conventions throughout.

**Educational Documentation** - Extensive inline comments explaining complex physics calculations and algorithms.

**SFML Integration** - Requires SFML graphics, window, and system modules for rendering and user interaction.


#### **🔧 Object Separation Algorithm**

Prevents objects from getting stuck together:

```cpp
// Calculate how much objects are overlapping
float penetration = (radius1 + radius2) - distance;
Vector2 separation = collisionNormal * (penetration / 2.0f);

// Move objects apart to eliminate overlap
position1 += separation;
position2 -= separation;
```


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

