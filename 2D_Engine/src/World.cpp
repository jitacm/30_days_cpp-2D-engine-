#include "World.h"

void World::addRigidBody(RigidBody* body)
{
    bodies.push_back(body);
}

void World::update(float dt)
{
    for (auto& body : bodies)
    {
        body->update(dt);
    }
}
