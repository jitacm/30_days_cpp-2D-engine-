#pragma once
#include "Shape.h"

class RectangleShape : public Shape {
public:
    float width, height;
    RectangleShape(float w, float h) : Shape(ShapeType::Rectangle), width(w), height(h) {}
};
