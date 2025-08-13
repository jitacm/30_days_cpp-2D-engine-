#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Shape.h"

class RigidBody {
public:
    Vector2 position;
    Vector2 velocity;
    float mass;
    bool isStatic;
    std::unique_ptr<Shape> shape;
    sf::Color color;

    RigidBody(std::unique_ptr<Shape> s, Vector2 pos, float m = 1.0f, bool stat = false, sf::Color col = sf::Color::White);

    void applyImpulse(const Vector2& impulse);

    // Render helper that delegates to shape
    void render(sf::RenderWindow& window) const {
        if (shape)
            shape->render(window, position, color);
    }
};
