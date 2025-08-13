#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>

enum class ShapeType {
    Circle,
    Rectangle
};

class Shape {
public:
    ShapeType type;
    Vector2 position{0.f, 0.f};
    sf::Color color{sf::Color::White};

    explicit Shape(ShapeType t) : type(t) {}
    virtual ~Shape() = default;

    virtual void render(sf::RenderWindow& window, const sf::Color& colorOverride, bool debugOutline = false) const = 0;

    virtual float getBoundingRadius() const { return 0.f; }             // for circles
    virtual sf::Vector2f getHalfExtents() const { return {0.f, 0.f}; } // for rects

    // helpers
    void setPosition(const Vector2& p) { position = p; }
    Vector2 getPosition() const { return position; }
    ShapeType getType() const { return type; }
};
