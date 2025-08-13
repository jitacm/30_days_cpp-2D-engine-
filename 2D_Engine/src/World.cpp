#include "World.h"
#include "Collision.h"

void World::addRigidBody(RigidBody* body)
{
    bodies.push_back(body);
}

void World::update(float dt)
{
    // reset collision flags
    for (auto* b : bodies) b->isColliding = false;

    // update bodies
    for (auto* b : bodies) b->update(dt);

    // pairwise collision detection & resolve
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i+1; j < bodies.size(); ++j) {
            CollisionManifold m = checkCollision(*bodies[i], *bodies[j]);
            if (m.colliding) {
                bodies[i]->isColliding = true;
                bodies[j]->isColliding = true;
                resolveCollision(*bodies[i], *bodies[j], m);
            }
        }
    }

    // simple boundary screen clamp (optional)
    const float left = 0.f, top = 0.f, right = 800.f, bottom = 600.f;
    for (auto* b : bodies) {
        Vector2 pos = b->getPosition();
        if (pos.x < left) { pos.x = left; b->velocity.x *= -b->restitution; }
        if (pos.x > right) { pos.x = right; b->velocity.x *= -b->restitution; }
        if (pos.y < top) { pos.y = top; b->velocity.y *= -b->restitution; }
        if (pos.y > bottom) { pos.y = bottom; b->velocity.y *= -b->restitution; }
        b->setPosition(pos);
    }
}
