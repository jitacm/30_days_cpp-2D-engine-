#include "RigidBody.h"
#include "Config.h"

RigidBody::RigidBody(Shape* s, float m, float r)
    : shape(s), mass(m), restitution(r),
      velocity(0.f, 0.f), acceleration(0.f, 0.f), totalForces(0.f, 0.f)
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
    // Apply global gravity
    totalForces += Config::gravity * mass;

    // Acceleration = Force / Mass
    acceleration = totalForces / mass;

    // Integrate velocity
    velocity += acceleration * dt;

    // Update position
    shape->setPosition(shape->getPosition() + velocity * dt);

    // --- Simple Ground Collision ---
    float groundLevel = 550.f;
    Vector2 pos = shape->getPosition();

    if (shape->getType() == ShapeType::Circle)
    {
        float radius = shape->getBoundingRadius();
        if (pos.y + radius > groundLevel)
        {
            pos.y = groundLevel - radius;
            velocity.y *= -restitution;
            if (std::abs(velocity.y) < 1.f) velocity.y = 0.f;
        }
    }
    else if (shape->getType() == ShapeType::Rectangle)
    {
        float halfHeight = shape->getHalfExtents().y;
        if (pos.y + halfHeight > groundLevel)
        {
            pos.y = groundLevel - halfHeight;
            velocity.y *= -restitution;
            if (std::abs(velocity.y) < 1.f) velocity.y = 0.f;
        }
    }

    shape->setPosition(pos);

    // Reset forces
    totalForces = {0.f, 0.f};
}

Vector2 RigidBody::getPosition() const
{
    return shape->getPosition();
}

ShapeType RigidBody::getShapeType() const
{
    return shape->getType();
}
