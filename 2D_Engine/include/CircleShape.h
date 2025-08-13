#pragma once
#include "Shape.h"

class CircleShape : public Shape {
public:
    float radius;
    explicit CircleShape(float r) : Shape(ShapeType::Circle), radius(r) {}
};
