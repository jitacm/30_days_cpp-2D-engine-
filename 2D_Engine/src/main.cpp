#include <SFML/Graphics.hpp>
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "Utils.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Engine with Debug Visualization");
    World world;

    // Create bodies
    auto* circle = new CircleShape(20.f);
    auto* circleBody = new RigidBody(circle, 5.f, 0.3f);
    world.addRigidBody(circleBody);

    auto* rect = new RectangleShape(50.f, 30.f);
    auto* rectBody = new RigidBody(rect, 10.f, 0.0f);
    world.addRigidBody(rectBody);

    bool debugMode = false;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                    circleBody->applyImpulse({200.f, -300.f});

                if (event.key.code == sf::Keyboard::D)
                    debugMode = !debugMode;
            }
        }

        float dt = clock.restart().asSeconds();
        world.update(dt);

        window.clear(sf::Color::Black);

        // Draw all bodies
        for (auto* body : world.getBodies())
        {
            sf::Color color = body->isColliding ? sf::Color::Red : sf::Color::Green;
            body->shape->render(window, body->getPosition(), color);

            if (debugMode)
            {
                // Bounding box
                if (body->getShapeType() == ShapeType::Circle)
                {
                    float r = body->shape->getBoundingRadius();
                    sf::CircleShape outline(r);
                    outline.setOrigin(r, r);
                    outline.setPosition(body->getPosition().x, body->getPosition().y);
                    outline.setFillColor(sf::Color::Transparent);
                    outline.setOutlineColor(sf::Color::Yellow);
                    outline.setOutlineThickness(1.f);
                    window.draw(outline);
                }
                else if (body->getShapeType() == ShapeType::Rectangle)
                {
                    sf::Vector2f half = body->shape->getHalfExtents();
                    sf::RectangleShape outline(sf::Vector2f(half.x * 2, half.y * 2));
                    outline.setOrigin(half);
                    outline.setPosition(body->getPosition().x, body->getPosition().y);
                    outline.setFillColor(sf::Color::Transparent);
                    outline.setOutlineColor(sf::Color::Yellow);
                    outline.setOutlineThickness(1.f);
                    window.draw(outline);
                }

                // Velocity vector
                sf::VertexArray arrow(sf::Lines, 2);
                arrow[0].position = sf::Vector2f(body->getPosition().x, body->getPosition().y);
                arrow[0].color = sf::Color::Cyan;
                arrow[1].position = sf::Vector2f(body->getPosition().x + body->velocity.x,
                                                 body->getPosition().y + body->velocity.y);
                arrow[1].color = sf::Color::Cyan;
                window.draw(arrow);
            }
        }

        window.display();
    }
}
