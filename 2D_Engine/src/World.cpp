#include "World.h"

void World::addRigidBody(RigidBody* body)
{
    bodies.push_back(body);
}

void World::update(float dt)
{
    // Reset collision states
    for (auto& body : bodies)
        body->isColliding = false;

    // Physics update
    for (auto& body : bodies)
        body->update(dt);

    // Collision detection & resolution
    for (size_t i = 0; i < bodies.size(); ++i)
    {
        for (size_t j = i + 1; j < bodies.size(); ++j)
        {
            auto m = checkCollision(*bodies[i], *bodies[j]);
            if (m.colliding)
            {
                bodies[i]->isColliding = true;
                bodies[j]->isColliding = true;
                resolveCollision(*bodies[i], *bodies[j], m);
            }
        }
    }
}
