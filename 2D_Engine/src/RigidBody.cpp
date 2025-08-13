#include "RigidBody.h"
#include "Config.h"

RigidBody::RigidBody(Shape* s, float m)
    : shape(s), mass(m), velocity(0.f, 0.f), acceleration(0.f, 0.f), totalForces(0.f, 0.f)
{
}

void RigidBody::applyForce(const Vector2& force)
{
    totalForces += force;
}

void RigidBody::applyImpulse(const Vector2& impulse)
{
    velocity += impulse / mass;
}

void RigidBody::update(float dt)
{
    // Apply global gravity (scaled by mass)
    totalForces += Config::gravity * mass;

    // Acceleration = Force / Mass
    acceleration = totalForces / mass;

    // Integrate velocity
    velocity += acceleration * dt;

    // Update position via shape
    shape->setPosition(shape->getPosition() + velocity * dt);

    // Reset forces for next frame
    totalForces = {0.f, 0.f};
}
