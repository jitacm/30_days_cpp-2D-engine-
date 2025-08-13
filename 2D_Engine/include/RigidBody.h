#pragma once
#include "Vector2.h"
#include "Shape.h"

class RigidBody
{
public:
    Shape* shape;
    float mass;
    Vector2 velocity;
    Vector2 acceleration;

    RigidBody(Shape* s, float m);

    // Applies a continuous force (accumulates until update)
    void applyForce(const Vector2& force);

    // Applies an instantaneous velocity change
    void applyImpulse(const Vector2& impulse);

    // Updates the rigid body (applies forces, gravity, moves object)
    void update(float dt);

private:
    Vector2 totalForces; // force accumulator
};
