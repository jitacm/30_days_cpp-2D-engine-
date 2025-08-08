#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

enum class BodyType { Dynamic, Static };

class RigidBody {
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float radius;
    float mass;
    float inverseMass;
    BodyType type;
    sf::CircleShape shape;

    RigidBody(float x, float y, float r, float m, BodyType t = BodyType::Dynamic);

    void applyForce(const Vector2& force);
    void update(float dt);
};

#endif
