#pragma once
#include "Vector2.h"

enum class ShapeType {
    Circle,
    Rectangle
};

class Shape {
public:
    ShapeType type;
    explicit Shape(ShapeType t) : type(t) {}
    virtual ~Shape() = default;
};
