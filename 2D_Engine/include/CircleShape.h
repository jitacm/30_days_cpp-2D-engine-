#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class CircleShape : public Shape {
public:
    float radius;

    explicit CircleShape(float r, const Vector2& pos = {0.f,0.f}, const sf::Color& col = sf::Color::Green)
        : Shape(ShapeType::Circle), radius(r)
    {
        position = pos;
        color = col;
    }

    void render(sf::RenderWindow& window, const sf::Color& colorOverride, bool debugOutline = false) const override {
        sf::CircleShape s(radius);
        s.setOrigin(radius, radius);
        s.setPosition(position.x, position.y);
        s.setFillColor(colorOverride);
        window.draw(s);

        if (debugOutline) {
            sf::CircleShape outline(radius);
            outline.setOrigin(radius, radius);
            outline.setPosition(position.x, position.y);
            outline.setFillColor(sf::Color::Transparent);
            outline.setOutlineColor(sf::Color::Yellow);
            outline.setOutlineThickness(1.f);
            window.draw(outline);
        }
    }

    float getBoundingRadius() const override {
        return radius;
    }
};
