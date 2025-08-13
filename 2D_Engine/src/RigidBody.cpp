#include "RigidBody.h"
#include "Config.h"

RigidBody::RigidBody(std::shared_ptr<Shape> s, float m, float r, bool isStatic_)
    : shape(std::move(s)), mass(m), restitution(r), isStatic(isStatic_)
{
    if (mass <= 0.f) mass = 1.f;
}
void RigidBody::applyForce(const Vector2& force)
{
    if (isStatic) return;
    // accumulate as acceleration contribution via update
    // We'll use a simple approach: treat as immediate impulse scaled by dt in update
    // For clarity we keep forces per-frame style using a local static container in update.
    // But to keep API, just convert to velocity change proportionally (simple).
    velocity += force / mass;
}

void RigidBody::applyImpulse(const Vector2& impulse)
{
    if (isStatic) return;
    velocity += impulse / mass;
}

void RigidBody::update(float dt)
{
    if (!isStatic) {
        // apply gravity
        acceleration = Config::gravity;
        velocity += acceleration * dt;
        Vector2 newPos = shape->getPosition() + velocity * dt;
        shape->setPosition(newPos);
    }
}
