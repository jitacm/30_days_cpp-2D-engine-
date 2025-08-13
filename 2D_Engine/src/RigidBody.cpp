#include "RigidBody.h"
#include "Utils.h"

RigidBody::RigidBody(std::unique_ptr<Shape> s, Vector2 pos, float m, bool stat, sf::Color col)
    : shape(std::move(s)), position(pos), mass(m), isStatic(stat), velocity(0,0), color(col) {
    // ensure mass > 0 for non-static bodies
    if (!isStatic && mass <= 0.0f) mass = 1.0f;
}

void RigidBody::applyImpulse(const Vector2& impulse) {
    if (!isStatic)
        velocity += impulse * (1.0f / mass);
}
