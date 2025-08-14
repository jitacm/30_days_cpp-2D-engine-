#pragma once
#include "Vector2.h"
#include "Shape.h"
#include <memory>

class RigidBody
{
public:
    std::shared_ptr<Shape> shape; // owns shape
    float mass;
    float restitution; // 0..1
    Vector2 velocity{0.f, 0.f};
    Vector2 acceleration{0.f, 0.f};
    bool isStatic{false};
    bool isColliding{false};

    RigidBody(std::shared_ptr<Shape> s, float m, float r = Config::DEFAULT_RESTITUTION, bool isStatic_ = false);

    void applyForce(const Vector2& force);
    void applyImpulse(const Vector2& impulse);
    void update(float dt);

    Vector2 getPosition() const { return shape->getPosition(); }
    void setPosition(const Vector2& p) { shape->setPosition(p); }
    ShapeType getShapeType() const { return shape->getType(); }
};
