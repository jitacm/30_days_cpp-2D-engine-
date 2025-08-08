#include <SFML/Graphics.hpp>
#include "World.h"
#include "RigidBody.h"
#include "Config.h"
#include "Utils.h"
#include <iostream>

int main() {
    Utils::initRandom();

    sf::RenderWindow window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "C++ 2D Physics Engine");
    window.setFramerateLimit(60);

    World world(window.getSize());

    unsigned int attempts = 0;
    while (world.bodies.size() < Config::INITIAL_OBJECT_COUNT && attempts < Config::INITIAL_OBJECT_COUNT * Config::MAX_SPAWN_ATTEMPTS) {
        float r = Utils::randomFloat(10.0f, 30.0f);
        float x = Utils::randomFloat(r, Config::WINDOW_WIDTH - r);
        float y = Utils::randomFloat(r, Config::WINDOW_HEIGHT / 2.0f);
        if (world.canSpawnAt({x, y}, r)) {
            world.addBody(std::make_unique<RigidBody>(x, y, r, r * r * 0.1f));
        }
        attempts++;
    }

    if (attempts >= Config::INITIAL_OBJECT_COUNT * Config::MAX_SPAWN_ATTEMPTS) {
        std::cout << "Warning: Could not place all objects without overlap.\n";
    }

    sf::Clock clock;
    float logTimer = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                float r = Utils::randomFloat(10.0f, 30.0f);
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (world.canSpawnAt({(float)mousePos.x, (float)mousePos.y}, r)) {
                    world.addBody(std::make_unique<RigidBody>(mousePos.x, mousePos.y, r, r * r * 0.1f));
                } else {
                    std::cout << "Cannot spawn object: space occupied.\n";
                }
            }
        }

        float dt = clock.restart().asSeconds();
        world.update(dt);

        logTimer += dt;
        if (logTimer >= 1.0f) {
            world.logState();
            logTimer = 0.0f;
        }

        window.clear(sf::Color(13, 17, 23));
        world.draw(window);
        window.display();
    }

    return 0;
}
