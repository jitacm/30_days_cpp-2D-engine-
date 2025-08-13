#pragma once
#include <vector>
#include "RigidBody.h"
#include "Collision.h"

class World
{
public:
    void addRigidBody(RigidBody* body);
    void update(float dt);

    const std::vector<RigidBody*>& getBodies() const { return bodies; }

private:
    std::vector<RigidBody*> bodies;
};
