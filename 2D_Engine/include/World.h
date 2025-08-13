#pragma once
#include <vector>
#include "RigidBody.h"

class World
{
public:
    void addRigidBody(RigidBody* body);
    void update(float dt);

private:
    std::vector<RigidBody*> bodies;
};
