#pragma once
#include <memory>
#include "Vector2.h"
#include "Shape.h"

class RigidBody {
public:
    Vector2 position;
    Vector2 velocity;
    float mass;
    bool isStatic;
    std::unique_ptr<Shape> shape;

    RigidBody(std::unique_ptr<Shape> s, Vector2 pos, float m = 1.0f, bool stat = false);

    void applyImpulse(const Vector2& impulse);
};
