#include "World.h"
#include "Config.h"
#include <iostream>

World::World(sf::Vector2u size) : windowSize(size), gravity(0.0f, Config::GRAVITY_Y) {}

void World::addBody(std::unique_ptr<RigidBody> body) {
    bodies.push_back(std::move(body));
}

bool World::canSpawnAt(const Vector2& pos, float radius) const {
    for (const auto& body : bodies) {
        float dist = (body->position - pos).length();
        if (dist < (body->radius + radius + 5.0f)) { // 5px buffer
            return false;
        }
    }
    return true;
}

void World::update(float dt) {
    for (auto& body : bodies) {
        body->applyForce(gravity);
    }

    for (auto& body : bodies) {
        body->update(dt);
    }

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            RigidBody* a = bodies[i].get();
            RigidBody* b = bodies[j].get();

            Vector2 diff = a->position - b->position;
            float dist = diff.length();
            float combinedRadius = a->radius + b->radius;

            if (dist < combinedRadius) {
                resolveCollision(a, b, diff, dist, combinedRadius);
            }
        }
    }

    handleBoundaries();
}

void World::draw(sf::RenderWindow& window) {
    for (const auto& body : bodies) {
        window.draw(body->shape);
    }
}

void World::logState() const {
    std::cout << "World State: " << bodies.size() << " bodies\n";
    for (size_t i = 0; i < bodies.size(); ++i) {
        std::cout << "Body " << i << ": Pos(" << bodies[i]->position.x << "," << bodies[i]->position.y
                  << ") Vel(" << bodies[i]->velocity.x << "," << bodies[i]->velocity.y << ")\n";
    }
}

void World::resolveCollision(RigidBody* a, RigidBody* b, const Vector2& diff, float dist, float combinedRadius) {
    float penetration = combinedRadius - dist;
    Vector2 normal = diff.normalized();
    Vector2 separation = normal * (penetration / 2.0f);
    a->position = a->position + separation;
    b->position = b->position - separation;

    Vector2 relativeVelocity = a->velocity - b->velocity;
    float velocityAlongNormal = Vector2::dot(relativeVelocity, normal);

    if (velocityAlongNormal > 0) return;

    float impulseScalar = -(1 + Config::RESTITUTION) * velocityAlongNormal;
    impulseScalar /= a->inverseMass + b->inverseMass;

    Vector2 impulse = normal * impulseScalar;
    a->velocity = a->velocity + impulse * a->inverseMass;
    b->velocity = b->velocity - impulse * b->inverseMass;
}

void World::handleBoundaries() {
    for (auto& body : bodies) {
        if (body->position.x - body->radius < 0) {
            body->position.x = body->radius;
            body->velocity.x *= -Config::RESTITUTION;
        }
        if (body->position.x + body->radius > windowSize.x) {
            body->position.x = windowSize.x - body->radius;
            body->velocity.x *= -Config::RESTITUTION;
        }
        if (body->position.y - body->radius < 0) {
            body->position.y = body->radius;
            body->velocity.y *= -Config::RESTITUTION;
        }
        if (body->position.y + body->radius > windowSize.y) {
            body->position.y = windowSize.y - body->radius;
            body->velocity.y *= -Config::RESTITUTION;
        }
    }
}
