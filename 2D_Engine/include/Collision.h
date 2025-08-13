#pragma once
#include "RigidBody.h"

struct CollisionManifold {
    bool colliding;
    Vector2 normal;
    float penetration;
};

CollisionManifold checkCollision(RigidBody& a, RigidBody& b);
void resolveCollision(RigidBody& a, RigidBody& b, const CollisionManifold& m);
