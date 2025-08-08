#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "RigidBody.h"
#include "Vector2.h"

class World {
public:
    explicit World(sf::Vector2u size);
    void addBody(std::unique_ptr<RigidBody> body);
    bool canSpawnAt(const Vector2& pos, float radius) const;
    void update(float dt);
    void draw(sf::RenderWindow& window);
    void logState() const;

private:
    void resolveCollision(RigidBody* a, RigidBody* b, const Vector2& diff, float dist, float combinedRadius);
    void handleBoundaries();

public:
    std::vector<std::unique_ptr<RigidBody>> bodies;
    Vector2 gravity;
    sf::Vector2u windowSize;
};

#endif
