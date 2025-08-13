#include "RigidBody.h"

RigidBody::RigidBody(std::unique_ptr<Shape> s, Vector2 pos, float m, bool stat)
    : shape(std::move(s)), position(pos), mass(m), isStatic(stat), velocity(0,0) {}

void RigidBody::applyImpulse(const Vector2& impulse) {
    if (!isStatic)
        velocity += impulse * (1.0f / mass);
}
