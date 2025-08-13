#include "World.h"
#include "Collision.h"
#include "Config.h"
#include <algorithm>

void World::addBody(RigidBody* body) {
    bodies.push_back(body);
}

void World::step(float dt) {
    // 1) Apply global forces (gravity) and integrate velocities -> positions
    for (auto& body : bodies) {
        if (!body->isStatic) {
            // gravity on y-axis
            body->velocity.y += Config::GRAVITY_Y * dt;
            body->position += body->velocity * dt;
        }
    }

    // 2) Boundary constraints (screen bounds) using per-shape extents
    for (auto& body : bodies) {
        if (!body->shape) continue;

        // Window bounds
        float left = 0.0f;
        float right = static_cast<float>(Config::WINDOW_WIDTH);
        float top = 0.0f;
        float bottom = static_cast<float>(Config::WINDOW_HEIGHT);

        if (body->shape->type == ShapeType::Circle) {
            float r = body->shape->getBoundingRadius();
            // Left
            if (body->position.x - r < left) {
                body->position.x = left + r;
                body->velocity.x = -body->velocity.x * Config::RESTITUTION;
            }
            // Right
            if (body->position.x + r > right) {
                body->position.x = right - r;
                body->velocity.x = -body->velocity.x * Config::RESTITUTION;
            }
            // Top
            if (body->position.y - r < top) {
                body->position.y = top + r;
                body->velocity.y = -body->velocity.y * Config::RESTITUTION;
            }
            // Bottom
            if (body->position.y + r > bottom) {
                body->position.y = bottom - r;
                body->velocity.y = -body->velocity.y * Config::RESTITUTION;
            }
        } else if (body->shape->type == ShapeType::Rectangle) {
            auto half = body->shape->getHalfExtents();
            // Left
            if (body->position.x - half.x < left) {
                body->position.x = left + half.x;
                body->velocity.x = -body->velocity.x * Config::RESTITUTION;
            }
            // Right
            if (body->position.x + half.x > right) {
                body->position.x = right - half.x;
                body->velocity.x = -body->velocity.x * Config::RESTITUTION;
            }
            // Top
            if (body->position.y - half.y < top) {
                body->position.y = top + half.y;
                body->velocity.y = -body->velocity.y * Config::RESTITUTION;
            }
            // Bottom
            if (body->position.y + half.y > bottom) {
                body->position.y = bottom - half.y;
                body->velocity.y = -body->velocity.y * Config::RESTITUTION;
            }
        }
    }

    // 3) Collision detection & resolution (pairwise)
    for (size_t i = 0; i < bodies.size(); i++) {
        for (size_t j = i + 1; j < bodies.size(); j++) {
            auto m = checkCollision(*bodies[i], *bodies[j]);
            if (m.colliding) {
                resolveCollision(*bodies[i], *bodies[j], m);
            }
        }
    }
}
