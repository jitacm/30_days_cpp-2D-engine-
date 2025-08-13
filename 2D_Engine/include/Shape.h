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
    explicit Shape(ShapeType t) : type(t) {}
    virtual ~Shape() = default;

    // Render the shape at given world position with given color
    virtual void render(sf::RenderWindow& window, const Vector2& position, const sf::Color& color) const = 0;

    // Helper queries used by physics/world logic:
    // For circles -> bounding radius; for rectangles -> half extents.
    virtual float getBoundingRadius() const { return 0.0f; }
    virtual sf::Vector2f getHalfExtents() const { return {0.f, 0.f}; }
};
