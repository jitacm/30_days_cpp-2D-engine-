#pragma once
#include "Vector2.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>

class RigidBody
{
public:
    Shape* shape;
    float mass;
    float restitution; // 0 = no bounce, 1 = full bounce
    Vector2 velocity;
    Vector2 acceleration;
    bool isColliding{false}; // NEW: track collision state

    RigidBody(Shape* s, float m, float r = 0.0f);

    void applyForce(const Vector2& force);
    void applyImpulse(const Vector2& impulse);
    void update(float dt);

    Vector2 getPosition() const;
    ShapeType getShapeType() const;

private:
    Vector2 totalForces;
};
