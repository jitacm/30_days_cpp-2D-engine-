#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class RectangleShape : public Shape {
public:
    float width, height;
    RectangleShape(float w, float h) : Shape(ShapeType::Rectangle), width(w), height(h) {}

    void render(sf::RenderWindow& window, const Vector2& position, const sf::Color& color) const override {
        sf::RectangleShape s(sf::Vector2f(width, height));
        s.setOrigin(width / 2.0f, height / 2.0f);
        s.setPosition(position.x, position.y);
        s.setFillColor(color);
        window.draw(s);
    }

    sf::Vector2f getHalfExtents() const override {
        return { width / 2.0f, height / 2.0f };
    }
};
