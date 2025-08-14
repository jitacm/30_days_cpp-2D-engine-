#include "Collision.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include <algorithm>
#include <cmath>

// circle vs circle
static CollisionManifold circleVsCircle(RigidBody& a, RigidBody& b) {
    CollisionManifold m;
    auto* ca = static_cast<CircleShape*>(a.shape.get());
    auto* cb = static_cast<CircleShape*>(b.shape.get());

    Vector2 diff = b.getPosition() - a.getPosition();
    float dist = diff.length();
    float r = ca->getBoundingRadius() + cb->getBoundingRadius();

    if (dist < r) {
        m.colliding = true;
        m.penetration = r - dist;
        m.normal = dist > 0 ? diff / dist : Vector2(1.f, 0.f);
    }
    return m;
}

// rect vs rect (AABB)
static CollisionManifold rectVsRect(RigidBody& a, RigidBody& b) {
    CollisionManifold m;
    auto* ra = static_cast<RectangleShape*>(a.shape.get());
    auto* rb = static_cast<RectangleShape*>(b.shape.get());

    Vector2 apos = a.getPosition();
    Vector2 bpos = b.getPosition();

    sf::Vector2f halfA = ra->getHalfExtents();
    sf::Vector2f halfB = rb->getHalfExtents();

    float dx = bpos.x - apos.x;
    float px = (halfA.x + halfB.x) - std::fabs(dx);
    if (px <= 0.f) return m;

    float dy = bpos.y - apos.y;
    float py = (halfA.y + halfB.y) - std::fabs(dy);
    if (py <= 0.f) return m;

    m.colliding = true;
    if (px < py) {
        m.penetration = px;
        m.normal = Vector2(dx < 0 ? -1.f : 1.f, 0.f);
    } else {
        m.penetration = py;
        m.normal = Vector2(0.f, dy < 0 ? -1.f : 1.f);
    }
    return m;
}

// circle vs rect (A from circle, B from rect)
static CollisionManifold circleVsRect(RigidBody& a, RigidBody& b) {
    CollisionManifold m;
    auto* c = static_cast<CircleShape*>(a.shape.get());
    auto* r = static_cast<RectangleShape*>(b.shape.get());

    Vector2 circlePos = a.getPosition();
    Vector2 rectPos = b.getPosition();
    sf::Vector2f half = r->getHalfExtents();

    // Find closest point on AABB to circle center
    float closestX = std::clamp(circlePos.x, rectPos.x - half.x, rectPos.x + half.x);
    float closestY = std::clamp(circlePos.y, rectPos.y - half.y, rectPos.y + half.y);

    Vector2 diff = { circlePos.x - closestX, circlePos.y - closestY };
    float distSq = diff.x*diff.x + diff.y*diff.y;
    float radius = c->getBoundingRadius();

    if (distSq <= radius*radius) {
        float dist = std::sqrt(distSq);
        m.colliding = true;
        if (dist > 0.f) {
            m.normal = diff / dist; // from rect to circle
            m.penetration = radius - dist;
        } else {
            // center exactly on edge/inside; choose a normal based on direction
            Vector2 dir = (circlePos - rectPos).normalized();
            m.normal = dir.length() > 0 ? dir : Vector2(1.f, 0.f);
            // compute penetration along the minor overlap axis:
            float overlapX = radius + half.x - std::abs(circlePos.x - rectPos.x);
            float overlapY = radius + half.y - std::abs(circlePos.y - rectPos.y);
            m.penetration = std::min(overlapX, overlapY);
        }
    }
    return m;
}

CollisionManifold checkCollision(RigidBody& a, RigidBody& b) {
    if (!a.shape || !b.shape) return {};
    ShapeType A = a.getShapeType();
    ShapeType B = b.getShapeType();

    if (A == ShapeType::Circle && B == ShapeType::Circle) return circleVsCircle(a,b);
    if (A == ShapeType::Rectangle && B == ShapeType::Rectangle) return rectVsRect(a,b);
    if (A == ShapeType::Circle && B == ShapeType::Rectangle) return circleVsRect(a,b);

    // else rectangle vs circle -> flip
    if (A == ShapeType::Rectangle && B == ShapeType::Circle) {
        CollisionManifold m = circleVsRect(b, a);
        if (m.colliding) {
            // normal currently points from rect to circle (because we called circleVsRect with circle=b)
            // but we must invert normal to be from a -> b
            m.normal = m.normal * -1.f;
        }
        return m;
    }
    return {};
}

void resolveCollision(RigidBody& a, RigidBody& b, const CollisionManifold& m) {
    if (!m.colliding) return;

    // positional correction
    const float percent = 0.8f; // positional correction percentage
    const float slop = 0.01f;
    if (!a.isStatic && !b.isStatic) {
        float totalMass = a.mass + b.mass;
        float ratioA = b.mass / totalMass;
        float ratioB = a.mass / totalMass;
        a.setPosition(a.getPosition() - m.normal * (m.penetration * percent * ratioA));
        b.setPosition(b.getPosition() + m.normal * (m.penetration * percent * ratioB));
    } else if (!a.isStatic) {
        a.setPosition(a.getPosition() - m.normal * (m.penetration * percent));
    } else if (!b.isStatic) {
        b.setPosition(b.getPosition() + m.normal * (m.penetration * percent));
    }

    // relative velocity
    Vector2 rv = b.velocity - a.velocity;
    float velAlongNormal = rv.dot(m.normal);
    if (velAlongNormal > 0) return;

    float e = std::min(a.restitution, b.restitution);
    float j = -(1 + e) * velAlongNormal;
    float invMassA = a.isStatic ? 0.f : 1.f / a.mass;
    float invMassB = b.isStatic ? 0.f : 1.f / b.mass;
    float denom = invMassA + invMassB;
    if (denom == 0.f) return;
    j /= denom;

    Vector2 impulse = m.normal * j;
    if (!a.isStatic) a.applyImpulse(-impulse);
    if (!b.isStatic) b.applyImpulse(impulse);
}
