#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class RectangleShape : public Shape {
public:
    float width, height;

    RectangleShape(float w, float h, const Vector2& pos = {0.f,0.f}, const sf::Color& col = sf::Color::Blue)
        : Shape(ShapeType::Rectangle), width(w), height(h)
    {
        position = pos;
        color = col;
    }

    void render(sf::RenderWindow& window, const sf::Color& colorOverride, bool debugOutline = false) const override {
        sf::RectangleShape s(sf::Vector2f(width, height));
        s.setOrigin(width/2.f, height/2.f);
        s.setPosition(position.x, position.y);
        s.setFillColor(colorOverride);
        window.draw(s);

        if (debugOutline) {
            sf::RectangleShape outline(sf::Vector2f(width, height));
            outline.setOrigin(width/2.f, height/2.f);
            outline.setPosition(position.x, position.y);
            outline.setFillColor(sf::Color::Transparent);
            outline.setOutlineColor(sf::Color::Yellow);
            outline.setOutlineThickness(1.f);
            window.draw(outline);
        }
    }

    sf::Vector2f getHalfExtents() const override {
        return { width / 2.f, height / 2.f };
    }
};
