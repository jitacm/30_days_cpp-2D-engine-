#pragma once
#include <vector>
#include "RigidBody.h"

class World {
public:
    std::vector<RigidBody*> bodies;

    void addBody(RigidBody* body);
    void step(float dt);
};
