#pragma once
#include "RigidBody.h"

struct CollisionManifold {
    bool colliding{false};
    Vector2 normal{0.f, 0.f};
    float penetration{0.f};
};

CollisionManifold checkCollision(RigidBody& a, RigidBody& b);
void resolveCollision(RigidBody& a, RigidBody& b, const CollisionManifold& m);
