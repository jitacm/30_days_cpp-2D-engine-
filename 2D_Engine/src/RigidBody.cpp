#include "RigidBody.h"
#include "Utils.h"

RigidBody::RigidBody(float x, float y, float r, float m, BodyType t)
    : position(x, y), radius(r), mass(m), type(t) {
    
    inverseMass = (mass > 0.0f && type == BodyType::Dynamic) ? 1.0f / mass : 0.0f;

    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(position.x, position.y);
    shape.setFillColor(Utils::randomColor());
}

void RigidBody::applyForce(const Vector2& force) {
    if (type == BodyType::Dynamic) {
        acceleration = acceleration + force * inverseMass;
    }
}

void RigidBody::update(float dt) {
    if (type == BodyType::Dynamic) {
        velocity = velocity + acceleration * dt;
        position = position + velocity * dt;
        acceleration = {0.0f, 0.0f};
    }
    shape.setPosition(position.x, position.y);
}
