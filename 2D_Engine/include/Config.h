#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
    constexpr float GRAVITY_Y = 200.0f; // Pixels per second^2
    constexpr float RESTITUTION = 0.8f; // Bounciness
    constexpr unsigned int WINDOW_WIDTH = 800;
    constexpr unsigned int WINDOW_HEIGHT = 600;
    constexpr unsigned int INITIAL_OBJECT_COUNT = 15;
    constexpr unsigned int MAX_SPAWN_ATTEMPTS = 50;
}

#endif
