CPP-Physics: A 2D Physics Engine
---------------------
A simple 2D physics engine built in modern C++ that simulates rigid body dynamics for simple shapes. The engine handles concepts like gravity, collision detection, and collision resolution. It uses the SFML library for visualization, making it easy to see the physics in action.

This project is designed as a hands-on introduction to game physics, focusing on core principles rather than complex optimizations.

Features
----------
Rigid Body Dynamics: Simulates objects with properties like mass, position, velocity, and acceleration.

Vector Math: Includes a simple Vector2 class for 2D calculations.

Euler Integration: Uses a basic integration method to update object positions over time.

Collision Detection: Implements Circle-Circle collision detection.

Collision Resolution: Calculates and applies impulse-based responses to make objects bounce realistically.

Simple World Management: A World class manages all objects, applies gravity, and handles boundary constraints.

Interactive: Add new objects to the simulation by clicking the mouse.

Prerequisites
To compile and run this project, you must have the SFML library installed on your system.

On Debian/Ubuntu:
----------------

sudo apt-get install libsfml-dev

On other systems:
Please refer to the official SFML download page.

You will also need a C++ compiler that supports C++17 (like g++).

Getting Started
1. Clone the Repository
First, clone this repository to your local machine.

2. Compile the Project
A Makefile is included for easy compilation. Simply run the make command.

make

Alternatively, you can compile it manually with g++:

g++ -std=c++17 physics_engine.cpp -o physics_engine -lsfml-graphics -lsfml-window -lsfml-system

This will create an executable file named physics_engine.

3. Run the Simulation
Launch the application to see the physics simulation.

./physics_engine

You can click anywhere in the window to spawn new circles.

How It Works
--------------
The simulation runs in a loop that is updated every frame. Each frame, the following steps occur:

Apply Forces: A constant gravitational force is applied to all objects, modifying their acceleration.

Update Positions (Integration): The velocity of each object is updated based on its acceleration, and its position is updated based on its new velocity. This process moves the objects through the world.

Handle Collisions:
-----------------

The engine checks every pair of objects to see if they are overlapping.

If a collision is detected, the engine first separates the objects to prevent them from sticking together.

It then calculates and applies an impulse to their velocities, causing them to bounce off each other in a physically plausible way.

Handle Boundaries: The engine checks if any objects have moved outside the window boundaries and reverses their velocity to keep them on screen.

Render: The visual representation of each object is drawn to the screen.

License
-----------------
This project is open sourced.