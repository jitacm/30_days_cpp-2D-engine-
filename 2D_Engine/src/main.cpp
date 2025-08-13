#include <SFML/Graphics.hpp>
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Engine with Gravity & Forces");

    World world;

    // Circle object
    CircleShape* circle = new CircleShape(20.f, {400.f, 100.f}, sf::Color::Green);
    RigidBody* circleBody = new RigidBody(circle, 5.f);
    world.addRigidBody(circleBody);

    // Rectangle object
    RectangleShape* rect = new RectangleShape({50.f, 30.f}, {200.f, 50.f}, sf::Color::Blue);
    RigidBody* rectBody = new RigidBody(rect, 10.f);
    world.addRigidBody(rectBody);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Apply impulse when space is pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                circleBody->applyImpulse({200.f, -300.f}); // Push right & up
        }

        float dt = clock.restart().asSeconds();
        world.update(dt);

        window.clear();
        circle->draw(window);
        rect->draw(window);
        window.display();
    }
}
