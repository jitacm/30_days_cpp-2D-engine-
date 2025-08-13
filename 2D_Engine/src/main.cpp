#include <SFML/Graphics.hpp>
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Engine with Gravity, Forces & Collision");

    World world;

    // Circle with bounce
    CircleShape* circle = new CircleShape(20.f, {400.f, 100.f}, sf::Color::Green);
    RigidBody* circleBody = new RigidBody(circle, 5.f, 0.3f); // restitution = 0.3
    world.addRigidBody(circleBody);

    // Rectangle without bounce
    RectangleShape* rect = new RectangleShape({50.f, 30.f}, {200.f, 50.f}, sf::Color::Blue);
    RigidBody* rectBody = new RigidBody(rect, 10.f, 0.0f); // no bounce
    world.addRigidBody(rectBody);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                circleBody->applyImpulse({200.f, -300.f}); // push up + right
        }

        float dt = clock.restart().asSeconds();
        world.update(dt);

        window.clear(sf::Color::Black);
        circle->draw(window);
        rect->draw(window);
        window.display();
    }
}
