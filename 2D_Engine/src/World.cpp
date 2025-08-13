#include "World.h"
#include "Collision.h"

void World::addBody(RigidBody* body) {
    bodies.push_back(body);
}

void World::step(float dt) {
    for (auto& body : bodies) {
        if (!body->isStatic)
            body->position += body->velocity * dt;
    }

    for (size_t i = 0; i < bodies.size(); i++) {
        for (size_t j = i + 1; j < bodies.size(); j++) {
            auto m = checkCollision(*bodies[i], *bodies[j]);
            if (m.colliding) {
                resolveCollision(*bodies[i], *bodies[j], m);
            }
        }
    }
}
