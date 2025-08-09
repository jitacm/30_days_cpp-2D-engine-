# 🚀 CPP-Physics: Advanced 2D Physics Engine

<div align="center">

*An Interactive Real-Time 2D Physics Simulation Engine Built with Modern C++ and SFML*

---

## 🌟 Project Overview

### 🎯 What is CPP-Physics Engine?
**CPP-Physics** is a sophisticated, real-time 2D physics simulation engine designed specifically for educational purposes and game development prototyping. This project demonstrates the fundamental principles of physics simulation using modern C++17 programming techniques combined with the powerful SFML (Simple and Fast Multimedia Library) graphics framework.

### 🎓 Purpose & Objectives
This project serves multiple educational and practical purposes:

#### **📚 Educational Goals**
- **Physics Understanding**: Demonstrate real-world physics concepts through interactive simulation
- **Programming Skills**: Showcase modern C++ programming techniques and best practices
- **Game Development**: Provide hands-on experience with game physics implementation
- **Mathematical Applications**: Apply vector mathematics and calculus in practical scenarios
- **Software Architecture**: Illustrate proper object-oriented design patterns

#### **🔬 What This Engine Accomplishes**
- **Real-Time Simulation**: Processes physics calculations at 60 FPS for smooth, realistic motion
- **Interactive Learning**: Allows users to experiment with physics concepts through mouse interaction
- **Visual Feedback**: Provides immediate visual representation of physics principles
- **Scalable Architecture**: Designed to handle multiple objects simultaneously without performance degradation
- **Cross-Platform Compatibility**: Runs on Windows, Linux, and macOS systems

#### **🌍 Target Audience**
- **Students**: Learning physics, mathematics, or computer science
- **Game Developers**: Understanding physics engine implementation
- **Educators**: Teaching physics concepts through interactive demonstration
- **Hobbyists**: Interested in physics simulation and game development
- **Professionals**: Prototyping physics-based applications

---

## ✨ Features & Capabilities

### 🔬 Core Physics Features

#### **⚡ Rigid Body Dynamics System**
- **Mass-Based Calculations**: Each object has configurable mass affecting its behavior
  - Heavier objects require more force to accelerate
  - Mass influences collision response and momentum transfer
  - Inverse mass calculations for efficient physics computation
- **Position Tracking**: Precise coordinate management with sub-pixel accuracy
- **Velocity Management**: Real-time velocity updates based on applied forces
- **Acceleration Handling**: Dynamic acceleration from gravity and collision forces

#### **🌍 Gravitational Force System**
- **Consistent Gravity**: Universal gravitational acceleration (200 pixels/second²)
- **Mass-Independent**: All objects fall at the same rate (realistic physics)
- **Configurable Direction**: Gravity vector can be modified for different effects
- **Force Accumulation**: Gravity combines with other forces naturally

#### **💥 Advanced Collision Detection**
- **Circle-Circle Detection**: Precise mathematical collision detection between circular objects
- **Distance-Based Algorithm**: Uses Euclidean distance formula for accuracy
- **Continuous Detection**: Checks collisions every frame to prevent tunneling
- **Broad Phase Optimization**: Efficiently handles multiple object interactions
- **Penetration Calculation**: Determines exact overlap amount for realistic separation

#### **🏀 Collision Resolution System**
- **Impulse-Based Response**: Realistic collision responses using momentum conservation
- **Restitution Factor**: Configurable bounciness (0.8 coefficient for realistic bouncing)
- **Velocity Exchange**: Proper momentum transfer between colliding objects
- **Separation Algorithm**: Prevents objects from sticking together after collision
- **Energy Conservation**: Maintains realistic energy distribution in collisions

#### **🔄 Numerical Integration**
- **Euler Integration Method**: Simple yet effective integration technique
- **Frame-Rate Independent**: Physics calculations adjust to varying frame rates
- **Position Updates**: Smooth object movement based on velocity calculations
- **Stability Measures**: Prevents simulation instability and object tunneling

### 🎮 Interactive Features

#### **🖱️ Mouse Interaction System**
- **Click-to-Spawn**: Create new physics objects by clicking anywhere in the window
- **Real-Time Creation**: Objects appear instantly at mouse cursor position
- **Dynamic Properties**: Each new object has randomly generated size and color
- **Unlimited Spawning**: No limit to the number of objects that can be created
- **Immediate Physics**: New objects immediately respond to gravity and collisions

#### **🎨 Visual Representation**
- **Colorful Objects**: Each physics object has a unique random color for easy identification
- **Smooth Animation**: 60 FPS rendering for fluid motion visualization
- **Circle Shapes**: Clean, simple geometric representation using SFML CircleShape
- **Real-Time Updates**: Visual position updates match physics calculations perfectly
- **Dark Theme Interface**: Professional dark background (RGB: 13, 17, 23) for better visibility

#### **🚧 Boundary Management**
- **Screen Edge Collision**: Objects bounce off window boundaries realistically
- **Configurable Boundaries**: Window size determines physics world limits
- **Velocity Reversal**: Proper bouncing behavior when hitting edges
- **Energy Loss**: Realistic energy dissipation during boundary collisions (0.8 factor)

### 🛡️ Advanced Technical Features

#### **📊 Memory Management**
- **Smart Pointers**: Uses std::unique_ptr for automatic memory management
- **RAII Principles**: Resource Acquisition Is Initialization for safe resource handling
- **Dynamic Allocation**: Efficient object creation and destruction
- **Memory Safety**: Prevents memory leaks and dangling pointers

#### **⚙️ Performance Optimization**
- **Efficient Collision Checking**: O(n²) collision detection optimized for real-time performance
- **Frame Rate Limiting**: Maintains consistent 60 FPS for smooth simulation
- **Delta Time Integration**: Handles variable frame rates gracefully
- **Minimal Overhead**: Lightweight implementation focusing on core physics concepts

---

## 🛠️ Installation Guide

### 📋 System Requirements

#### **💻 Hardware Requirements**
- **CPU**: Any modern processor (Intel i3/AMD Ryzen 3 or better recommended)
- **RAM**: Minimum 512 MB available memory
- **Graphics**: OpenGL 2.0+ compatible graphics card
- **Storage**: 50 MB free disk space for compilation and execution
- **Display**: Monitor with minimum 800x600 resolution

#### **🖥️ Operating System Support**
- **Linux**: Ubuntu 18.04+, Debian 10+, Fedora 30+, or equivalent distributions
- **Windows**: Windows 10/11 (64-bit recommended)
- **macOS**: macOS 10.14+ (Mojave or later)

#### **🔧 Development Tools Required**
- **C++ Compiler**: 
  - GCC 7.0 or later (Linux/macOS)
  - Clang 5.0 or later (macOS/Linux)
  - Visual Studio 2019+ (Windows)
  - MinGW-w64 (Windows alternative)
- **C++ Standard**: C++17 support mandatory
- **Build System**: Make utility (optional but recommended)
- **Version Control**: Git (for repository cloning)

### 📦 SFML Library Installation

#### **🐧 Linux Installation (Ubuntu/Debian)**
```bash
# Update package repositories
sudo apt-get update

# Install SFML development libraries
sudo apt-get install libsfml-dev

# Install build tools
sudo apt-get install build-essential

# Install Git (if not already installed)
sudo apt-get install git

# Verify installation
pkg-config --libs sfml-all
```

#### **🐧 Linux Installation (Fedora/CentOS/RHEL)**
```bash
# For Fedora
sudo dnf install SFML-devel gcc-c++ make git

# For CentOS/RHEL (Enable EPEL repository first)
sudo yum install epel-release
sudo yum install SFML-devel gcc-c++ make git
```

#### **🍎 macOS Installation**
```bash
# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install SFML
brew install sfml

# Install development tools
xcode-select --install

# Verify installation
brew list sfml
```

#### **🪟 Windows Installation**

**Method 1: Using vcpkg (Recommended)**
```cmd
# Clone vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg

# Bootstrap vcpkg
.\bootstrap-vcpkg.bat

# Install SFML
.\vcpkg install sfml:x64-windows

# Integrate with Visual Studio
.\vcpkg integrate install
```

**Method 2: Manual Installation**
1. Download SFML from official website (https://www.sfml-dev.org/download.php)
2. Extract to C:\SFML\ directory
3. Configure your IDE to link against SFML libraries
4. Add necessary DLL files to your project output directory

### 📥 Project Installation from GitHub

#### **🔽 Clone the Repository**
```bash
# Clone the repository
git clone https://github.com/Ashleesh/30_days_cpp-2D-engine-.git

# Navigate to project directory
cd 30_days_cpp-2D-engine-

# Check project contents
ls -la
```

#### **⚙️ Compilation Process**

**Method 1: Using Make (Recommended)**
```bash
# Compile using Makefile
make

# Clean build files (if needed)
make clean

# Rebuild completely
make clean && make
```

**Method 2: Manual Compilation**
```bash
# Compile manually with g++
g++ -std=c++17 Game.cpp -o physics_engine \
    -lsfml-graphics -lsfml-window -lsfml-system

# For debug build
g++ -std=c++17 -g -Wall -Wextra Game.cpp -o physics_engine_debug \
    -lsfml-graphics -lsfml-window -lsfml-system

# For optimized release build
g++ -std=c++17 -O3 -DNDEBUG Game.cpp -o physics_engine_release \
    -lsfml-graphics -lsfml-window -lsfml-system
```

#### **🚀 Running the Simulation**
```bash
# Execute the compiled program
./physics_engine

# Run debug version (if compiled)
./physics_engine_debug

# Run with verbose output (Linux/macOS)
./physics_engine --verbose

# Check if executable has proper permissions
chmod +x physics_engine
```

#### **🔍 Troubleshooting Installation**

**Common Issues and Solutions:**

1. **SFML Not Found Error**
   ```bash
   # Check SFML installation
   pkg-config --modversion sfml-all
   
   # If not found, reinstall SFML
   sudo apt-get install --reinstall libsfml-dev
   ```

2. **Compilation Errors**
   ```bash
   # Check GCC version (must support C++17)
   gcc --version
   
   # Update GCC if version is too old
   sudo apt-get install gcc-9 g++-9
   ```

3. **Runtime Errors**
   ```bash
   # Check shared library dependencies
   ldd physics_engine
   
   # Install missing dependencies
   sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
   ```

---

## 🎮 Usage & Controls

### 🖱️ Mouse Controls

**Left Click** - 🆕 **Spawn Physics Object**
- Creates a new circular object at cursor position
- Object has random size (10-30 pixels radius)
- Each object gets a unique random color
- Immediately responds to physics simulation

**Right Click** - 🚫 **No Action**
- Reserved for future features
- Currently has no assigned functionality

**Mouse Movement** - 📍 **Target Selection**
- Move cursor to choose spawn location for new objects
- Visual feedback shows exact spawn position
- No restrictions on spawn location within window bounds

### ⌨️ Keyboard Controls

**ESC Key** - 🚪 **Close Window**
- Safely exits the simulation
- Properly cleans up all resources
- Immediate response to user input

**Alt + F4** - 🚪 **Force Exit**
- Alternative exit method
- Standard Windows/Linux exit combination
- Emergency exit if window becomes unresponsive

**Space Key** - ⏸️ **Reserved**
- Planned for pause/resume functionality
- Currently has no assigned action
- Future feature implementation

### 🎯 Interactive Elements

#### **🔴 Physics Objects**
Each spawned object appears as a colored circle with unique properties:
- **Appearance**: Randomly colored circles with smooth edges
- **Behavior**: Falls under gravity influence, bounces realistically
- **Properties**: Unique mass based on radius, individual color identification
- **Interaction**: Collides with other objects and transfers momentum naturally

#### **🌍 Simulation Environment**
The simulation world provides a controlled physics environment:
- **Window Size**: Default 800x600 pixel resolution
- **Background**: Professional dark theme (RGB values: 13, 17, 23)
- **Boundaries**: All four window edges act as solid collision surfaces
- **Gravity**: Constant downward gravitational acceleration affecting all objects

#### **⚡ Real-Time Features**
The engine provides smooth, responsive simulation:
- **Frame Rate**: Locked to 60 frames per second for consistent behavior
- **Physics Updates**: Real-time calculation of forces, velocities, and positions
- **Visual Synchronization**: Graphics perfectly match physics calculations
- **Memory Management**: Automatic cleanup and efficient resource usage

---

## 🔧 Technical Implementation

### 🏗️ Architecture Overview

#### **📐 Vector2 Mathematics Class**
```cpp
struct Vector2 {
    float x, y;                           // 2D coordinate components
    
    // Constructors
    Vector2();                            // Default constructor (0,0)
    Vector2(float x, float y);           // Parameterized constructor
    
    // Operators
    Vector2 operator+(const Vector2&);    // Vector addition
    Vector2 operator-(const Vector2&);    // Vector subtraction  
    Vector2 operator*(float);             // Scalar multiplication
    
    // Utility Functions
    float length();                       // Calculate magnitude
    Vector2 normalized();                 // Get unit vector
    static float dot(Vector2&, Vector2&); // Dot product calculation
}
```

**Key Features:**
- **Memory Efficient**: Simple struct with minimal overhead
- **Mathematically Complete**: All essential 2D vector operations
- **Performance Optimized**: Inline functions for maximum speed
- **Robust Design**: Handles edge cases like zero-length vectors safely

#### **🎯 RigidBody Physics Class**
```cpp
class RigidBody {
    // Physics Properties
    Vector2 position;         // Current position in world space
    Vector2 velocity;         // Current velocity vector
    Vector2 acceleration;     // Current acceleration vector
    float radius;             // Object radius for collision detection
    float mass;               // Object mass for physics calculations
    float inverseMass;        // Cached inverse mass for performance
    
    // Visual Properties
    sf::CircleShape shape;    // SFML shape for rendering
    
    // Methods
    void applyForce(Vector2&);        // Apply force to object
    void update(float deltaTime);      // Update physics state
}
```

**Implementation Details:**
- **Force Integration**: Accumulates all forces before applying to acceleration
- **Euler Integration**: Updates velocity and position using discrete time steps
- **Visual Synchronization**: Keeps SFML shape position perfectly matched with physics position
- **Mass Management**: Uses precomputed inverse mass for efficient collision calculations

#### **🌍 World Management System**
```cpp
class World {
    // Container Management
    std::vector<std::unique_ptr<RigidBody>> bodies;  // Object storage
    Vector2 gravity;                                 // Global gravity vector
    sf::Vector2u windowSize;                        // Window dimensions
    
    // Core Methods
    void addBody(std::unique_ptr<RigidBody>);       // Add new object
    void update(float deltaTime);                    // Main simulation loop
    void resolveCollision(RigidBody*, RigidBody*);  // Handle collisions
    void handleBoundaries();                        // Boundary collision
}
```

**System Responsibilities:**
- **Object Lifecycle**: Manages creation, updating, and destruction of physics objects
- **Force Application**: Applies global forces like gravity to all objects uniformly
- **Collision Processing**: Handles both broad-phase and narrow-phase collision detection
- **Boundary Management**: Ensures all objects remain within simulation bounds
- **Memory Management**: Uses smart pointers for automatic resource cleanup and safety

---

## 📂 Project Structure

```
📁 30_days_cpp-2D-engine-/
├── 📄 Game.cpp                    # Main engine implementation
├── 📋 README.md                   # Comprehensive documentation

```

### 📄 File Descriptions

#### **🎮 Game.cpp (Core Implementation)**
The main implementation file contains the complete physics engine:
- **Line Count**: Over 450 lines of well-structured modern C++ code
- **Organization**: Clear class separation with logical method grouping
- **Standards**: Follows C++17 best practices and modern coding conventions
- **Documentation**: Comprehensive inline comments explaining complex physics calculations
- **Dependencies**: Requires SFML graphics, window, and system modules

#### **🛠️ Makefile (Build Configuration)**
Automated build system for easy compilation:
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = physics_engine
SOURCE = Game.cpp

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET) $(SFML_FLAGS)

clean:
	rm -f $(TARGET)

.PHONY: clean
```

### 🔗 Dependencies & Libraries

#### **📚 External Libraries**
- **SFML Graphics**: Handles window management and 2D rendering operations
- **SFML System**: Provides time management and system utility functions
- **SFML Window**: Manages event handling and user input processing

#### **🏗️ Standard Libraries**
- **vector**: Dynamic array container for efficient object storage
- **memory**: Smart pointer management for automatic resource handling
- **cmath**: Mathematical functions including square root calculations
- **iostream**: Debug output and error logging capabilities
- **random**: Random number generation for object colors and sizes

---

## 🧮 Physics Algorithms

### 💥 Collision Detection Algorithm

#### **📊 Mathematical Foundation**
```cpp
// Distance calculation between two circles
float distance = sqrt((pos1.x - pos2.x)² + (pos1.y - pos2.y)²);

// Collision condition
if (distance < (radius1 + radius2)) {
    // Collision detected - objects are overlapping
    collision_detected = true;
}
```

#### **🔍 Implementation Details**
- **Computational Complexity**: O(n²) complexity for n objects requiring optimization for large scenes
- **Numerical Accuracy**: Uses double-precision floating-point for exact distance calculations
- **Early Exit Optimizations**: Skips unnecessary calculations when objects are clearly separated
- **Broad Phase Potential**: Could be enhanced with spatial partitioning for improved performance with large object counts

### 🏀 Collision Resolution System

#### **⚡ Impulse-Based Response**
The collision resolution uses momentum conservation principles:
```cpp
// Calculate relative velocity along collision normal
Vector2 relativeVelocity = velocity1 - velocity2;
float velocityAlongNormal = dot(relativeVelocity, collisionNormal);

// Calculate impulse scalar
float restitution = 0.8f;  // Bounciness factor
float impulseScalar = -(1 + restitution) * velocityAlongNormal;
impulseScalar /= (inverseMass1 + inverseMass2);

// Apply impulse to both objects
Vector2 impulse = collisionNormal * impulseScalar;
velocity1 += impulse * inverseMass1;
velocity2 -= impulse * inverseMass2;
```

#### **🔧 Separation Algorithm**
Prevents object overlap and sticking:
```cpp
// Calculate penetration depth
float penetration = (radius1 + radius2) - distance;
Vector2 separation = collisionNormal * (penetration / 2.0f);

// Move objects apart to prevent overlap
position1 += separation;
position2 -= separation;
```

### 🔄 Euler Integration Method

#### **📐 Mathematical Basis**
The simulation uses first-order Euler integration:
```cpp
// Update velocity using acceleration
velocity = velocity + acceleration * deltaTime;

// Update position using velocity  
position = position + velocity * deltaTime;

// Reset acceleration for next frame
acceleration = Vector2(0, 0);
```

#### **⚙️ Advantages & Limitations**

**Advantages of Euler Integration:**
- **Simplicity**: Easy to implement and understand for educational purposes
- **Computational Efficiency**: Minimal CPU overhead for real-time simulation
- **Numerical Stability**: Stable for most common physics scenarios
- **Educational Value**: Excellent for learning integration concepts and numerical methods

**Known Limitations:**
- **Energy Drift**: Can accumulate energy over time leading to unrealistic behavior
- **Accuracy**: Less precise than higher-order methods like Runge-Kutta
- **Stability Issues**: May become unstable with very small time steps
- **Stiff Equations**: Not suitable for stiff differential equations

---

## 🎓 Educational Value

### 📚 Physics Concepts Demonstrated

#### **⚡ Classical Mechanics Principles**
- **Newton's First Law**: Objects at rest remain at rest until acted upon by force (demonstrated when no user input)
- **Newton's Second Law**: Force equals mass times acceleration (F = ma) shown in gravity and collision responses
- **Newton's Third Law**: Action-reaction pairs clearly visible in collision interactions
- **Conservation of Momentum**: Total momentum preserved in all collision interactions
- **Conservation of Energy**: Kinetic energy properly transferred between colliding objects
- **Gravitational Acceleration**: Constant downward acceleration affecting all objects equally regardless of mass

#### **🧮 Vector Mathematics Applications**
- **Vector Addition and Subtraction**: Combining multiple forces and velocity components
- **Dot Product Calculations**: Computing velocity components along collision normal vectors
- **Vector Normalization**: Creating unit direction vectors for collision response calculations
- **Magnitude Calculations**: Distance computations and speed measurements using Pythagorean theorem

#### **🔢 Numerical Methods in Practice**
- **Differential Equations**: Position as the time derivative of velocity, velocity as derivative of acceleration
- **Integration Techniques**: Euler method for solving ordinary differential equations in real-time
- **Discrete Time Stepping**: Converting continuous mathematical processes into discrete computational steps
- **Numerical Stability**: Understanding limitations and stability conditions of integration methods

### 🎯 Programming Concepts Illustrated

#### **🏗️ Object-Oriented Design Patterns**
- **Encapsulation**: Data and related methods grouped together in logical classes
- **Abstraction**: Complex physics calculations hidden behind simple, intuitive interfaces  
- **Inheritance Potential**: Architecture designed for easy extension to different object types
- **Polymorphism**: Uniform treatment of different physics objects through common interfaces

#### **💾 Modern Memory Management**
- **RAII Principles**: Resource Acquisition Is Initialization for automatic resource management
- **Smart Pointers**: std::unique_ptr usage for automatic memory cleanup and exception safety
- **Container Management**: Dynamic object storage using std::vector with efficient memory usage
- **Performance Optimization**: Memory-friendly patterns and cache-conscious data structures

#### **🎮 Game Development Architecture**
- **Game Loop Pattern**: Standard update-render cycle running at fixed frame rate
- **Component System Design**: Clear separation between physics simulation and visual rendering
- **Event-Driven Programming**: Responsive user input processing and system event handling
- **State Management**: Tracking and updating object properties consistently over time

---

## 🚀 Getting Started Tutorial

### 👶 Beginner Tutorial (First 5 Minutes)

#### **Step 1: Launch the Application**
```bash
# Navigate to project directory
cd 30_days_cpp-2D-engine-

# Run the compiled executable  
./physics_engine
```

**What You'll See:**
- A black window opens with dimensions 800x600 pixels
- Window title displays "C++ 2D Physics Engine"
- 15 colorful circles automatically spawn and begin falling due to gravity
- Circles bounce realistically off the bottom and sides of the window
- Each circle has a unique random color for easy identification

#### **Step 2: Basic Interaction**
- **Click anywhere** in the window to spawn a new circle at that exact location
- **Watch carefully** as your new circle immediately falls and interacts with existing objects
- **Try clicking rapidly** in different locations to create multiple circles simultaneously
- **Observe** how circles of different sizes behave differently during collisions due to mass differences

#### **Step 3: Observe Physics Behavior**
- **Gravity Effect**: All circles accelerate downward at the same rate regardless of size or mass
- **Realistic Collisions**: Circles bounce off each other with momentum transfer and energy conservation
- **Boundary Interactions**: Circles bounce off window edges with appropriate energy loss
- **Color Coding**: Each circle maintains its unique color for easy tracking through complex interactions

### 🎯 Intermediate Experiments (Next 15 Minutes)

#### **🌧️ Experiment 1: Create a "Rain" Effect**
1. Position your mouse cursor near the top edge of the window
2. Click rapidly and repeatedly to create multiple falling objects
3. Watch as circles cascade downward like realistic raindrops
4. Observe how they interact when hitting the accumulated "puddle" at the bottom
5. Notice the complex multi-body interactions and realistic physics behavior

#### **🏗️ Experiment 2: Build Object Towers**
1. Allow some circles to settle and come to rest at the bottom of the window
2. Click directly above the settled circles to stack new objects vertically
3. Watch how the tower becomes increasingly unstable as height increases
4. Observe the natural collapse behavior when the tower exceeds stable limits
5. Experiment with different stacking patterns and observe stability differences

#### **⚡ Experiment 3: Collision Chains**
1. Create a horizontal line of circles by clicking in sequence across the window
2. Drop a single circle from high above onto one end of the line
3. Watch the collision energy propagate through the chain like Newton's cradle
4. Compare behavior differences when using circles of varying sizes
5. Notice how momentum and energy transfer through the connected objects

#### **🌪️ Experiment 4: Chaos Testing**
1. Click as rapidly as possible all over the window to create maximum chaos
2. Generate 50+ circles to stress-test the simulation performance
3. Watch complex multi-body interactions with numerous simultaneous collisions
4. Notice how the simulation maintains smooth 60 FPS performance even with many objects
5. Observe emergent behaviors in dense object clusters

### 🔬 Advanced Exploration (Extended Learning)

#### **🔍 Code Exploration**
1. Open the Game.cpp file in your favorite text editor or IDE
2. Locate the `gravity` variable in the World class definition
3. Modify the gravity value (try negative values for upward gravity)
4. Recompile and run to observe the effects of different gravitational forces
5. Experiment with different restitution (bounciness) values in collision resolution

#### **📊 Performance Analysis**
1. Monitor system CPU usage while running the simulation with many objects
2. Test the maximum number of objects before noticeable performance degradation
3. Compare performance characteristics on different hardware configurations
4. Understand computational bottlenecks in collision detection algorithms
5. Analyze frame rate stability under various object density conditions
