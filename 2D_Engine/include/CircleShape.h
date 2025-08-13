#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class CircleShape : public Shape {
public:
    float radius;
    explicit CircleShape(float r) : Shape(ShapeType::Circle), radius(r) {}

    void render(sf::RenderWindow& window, const Vector2& position, const sf::Color& color) const override {
        sf::CircleShape s(radius);
        s.setOrigin(radius, radius);
        s.setPosition(position.x, position.y);
        s.setFillColor(color);
        window.draw(s);
    }

    float getBoundingRadius() const override {
        return radius;
    }
};
