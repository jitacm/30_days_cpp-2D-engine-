#include "Collision.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "Config.h"
#include <algorithm>
#include <cmath>

static CollisionManifold circleVsCircle(RigidBody& a, RigidBody& b) {
    CollisionManifold m;
    auto* cA = static_cast<CircleShape*>(a.shape.get());
    auto* cB = static_cast<CircleShape*>(b.shape.get());

    Vector2 diff = b.position - a.position;
    float dist = diff.length();
    float r = cA->radius + cB->radius;

    if (dist < r) {
        m.colliding = true;
        m.penetration = r - dist;
        m.normal = dist > 0 ? diff * (1.0f / dist) : Vector2(1, 0);
    }
    return m;
}

static CollisionManifold rectVsRect(RigidBody& a, RigidBody& b) {
    CollisionManifold m;
    auto* rA = static_cast<RectangleShape*>(a.shape.get());
    auto* rB = static_cast<RectangleShape*>(b.shape.get());

    float dx = b.position.x - a.position.x;
    float px = (rA->width/2 + rB->width/2) - std::fabs(dx);
    if (px <= 0) return m;

    float dy = b.position.y - a.position.y;
    float py = (rA->height/2 + rB->height/2) - std::fabs(dy);
    if (py <= 0) return m;

    m.colliding = true;
    if (px < py) {
        m.normal = Vector2(dx < 0 ? -1 : 1, 0);
        m.penetration = px;
    } else {
        m.normal = Vector2(0, dy < 0 ? -1 : 1);
        m.penetration = py;
    }
    return m;
}

CollisionManifold checkCollision(RigidBody& a, RigidBody& b) {
    if (!a.shape || !b.shape) return {};
    if (a.shape->type == ShapeType::Circle && b.shape->type == ShapeType::Circle)
        return circleVsCircle(a, b);
    if (a.shape->type == ShapeType::Rectangle && b.shape->type == ShapeType::Rectangle)
        return rectVsRect(a, b);

    // For now, cross-type collisions (circle vs rect) are not implemented.
    // They could be added here later (circle-rect SAT or clamping approach).
    return {};
}

void resolveCollision(RigidBody& a, RigidBody& b, const CollisionManifold& m) {
    if (!m.colliding) return;

    // Positional correction
    if (!a.isStatic && !b.isStatic) {
        float totalMass = a.mass + b.mass;
        a.position -= m.normal * (m.penetration * (b.mass / totalMass));
        b.position += m.normal * (m.penetration * (a.mass / totalMass));
    } else if (!a.isStatic) {
        a.position -= m.normal * m.penetration;
    } else if (!b.isStatic) {
        b.position += m.normal * m.penetration;
    }

    // Relative velocity
    Vector2 relativeVel = b.velocity - a.velocity;
    float velAlongNormal = relativeVel.dot(m.normal);
    if (velAlongNormal > 0) return;

    float e = Config::RESTITUTION; // use configured restitution
    float j = -(1 + e) * velAlongNormal;

    float invMassA = a.isStatic ? 0.0f : 1.0f / a.mass;
    float invMassB = b.isStatic ? 0.0f : 1.0f / b.mass;
    float denom = invMassA + invMassB;
    if (denom == 0.0f) return; // both static (shouldn't happen)
    j /= denom;

    Vector2 impulse = m.normal * j;
    if (!a.isStatic) a.applyImpulse(-impulse);
    if (!b.isStatic) b.applyImpulse(impulse);
}
