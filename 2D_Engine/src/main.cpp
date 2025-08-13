#include <SFML/Graphics.hpp>
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "RigidBody.h"
#include "Utils.h"
#include "Config.h"

int main() {
    Utils::initRandom();

    sf::RenderWindow window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "2D Engine - Multiple Shapes Demo");
    window.setFramerateLimit(60);

    World world;

    // Create bodies using the new polymorphic rendering approach
    RigidBody circle1(std::make_unique<CircleShape>(40.0f), Vector2(200, 300), 1.0f, false, Utils::randomColor());
    RigidBody circle2(std::make_unique<CircleShape>(50.0f), Vector2(500, 300), 1.0f, false, Utils::randomColor());
    circle2.velocity = Vector2(-120.0f, 0.0f);

    RigidBody rect1(std::make_unique<RectangleShape>(100.0f, 60.0f), Vector2(300, 500), 2.0f, false, Utils::randomColor());
    RigidBody rect2(std::make_unique<RectangleShape>(120.0f, 80.0f), Vector2(600, 500), 1.5f, false, Utils::randomColor());
    rect2.velocity = Vector2(-90.0f, 0.0f);

    world.addBody(&circle1);
    world.addBody(&circle2);
    world.addBody(&rect1);
    world.addBody(&rect2);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        float dt = clock.restart().asSeconds();
        world.step(dt);

        window.clear(sf::Color::Black);

        // Render all bodies (delegates to shape->render)
        circle1.render(window);
        circle2.render(window);
        rect1.render(window);
        rect2.render(window);

        window.display();
    }
    return 0;
}
