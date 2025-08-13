#pragma once
#include "RigidBody.h"

struct CollisionManifold {
    bool colliding{false};
    Vector2 normal;
    float penetration{0.0f};
};

CollisionManifold checkCollision(RigidBody& a, RigidBody& b);
void resolveCollision(RigidBody& a, RigidBody& b, const CollisionManifold& m);
