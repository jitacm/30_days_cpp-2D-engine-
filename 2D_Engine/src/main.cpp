#include <SFML/Graphics.hpp>
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Engine - Collision Demo");

    World world;

    RigidBody circle1(std::make_unique<CircleShape>(40), Vector2(200, 300), 1.0f);
    RigidBody circle2(std::make_unique<CircleShape>(50), Vector2(500, 300), 1.0f);
    circle2.velocity = Vector2(-50, 0);

    RigidBody rect1(std::make_unique<RectangleShape>(100, 60), Vector2(300, 500), 1.0f);
    RigidBody rect2(std::make_unique<RectangleShape>(120, 80), Vector2(600, 500), 1.0f);
    rect2.velocity = Vector2(-60, 0);

    world.addBody(&circle1);
    world.addBody(&circle2);
    world.addBody(&rect1);
    world.addBody(&rect2);

    sf::CircleShape s1(40), s2(50);
    s1.setFillColor(sf::Color::Green);
    s2.setFillColor(sf::Color::Red);

    sf::RectangleShape r1(sf::Vector2f(100, 60)), r2(sf::Vector2f(120, 80));
    r1.setFillColor(sf::Color::Blue);
    r2.setFillColor(sf::Color::Magenta);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        float dt = clock.restart().asSeconds();
        world.step(dt);

        window.clear();

        s1.setPosition(circle1.position.x - 40, circle1.position.y - 40);
        s2.setPosition(circle2.position.x - 50, circle2.position.y - 50);
        r1.setPosition(rect1.position.x - 50, rect1.position.y - 30);
        r2.setPosition(rect2.position.x - 60, rect2.position.y - 40);

        window.draw(s1);
        window.draw(s2);
        window.draw(r1);
        window.draw(r2);

        window.display();
    }
}
