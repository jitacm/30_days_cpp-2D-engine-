#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <memory>
#include <iostream>

// Simple 2D Vector class
struct Vector2 {
    float x = 0.0f, y = 0.0f;

    Vector2() = default;
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
    Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
    Vector2 operator*(float scalar) const { return Vector2(x * scalar, y * scalar); }
    float length() const { return std::sqrt(x * x + y * y); }
    Vector2 normalized() const {
        float l = length();
        if (l > 0) return Vector2(x / l, y / l);
        return Vector2(0, 0);
    }
    static float dot(const Vector2& a, const Vector2& b) {
        return a.x * b.x + a.y * b.y;
    }
};

// Represents a physical object in the world
class RigidBody {
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float radius;
    float mass;
    float inverseMass;
    sf::CircleShape shape;

    RigidBody(float x, float y, float r, float m)
        : position(x, y), radius(r), mass(m) {
        
        if (mass > 0.0f) {
            inverseMass = 1.0f / mass;
        } else {
            inverseMass = 0.0f; // Infinite mass for static objects
        }

        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setPosition(position.x, position.y);
        shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }

    void applyForce(const Vector2& force) {
        acceleration = acceleration + force * inverseMass;
    }

    void update(float dt) {
        // Simple Euler integration
        velocity = velocity + acceleration * dt;
        position = position + velocity * dt;
        
        // Reset acceleration after applying it
        acceleration = {0.0f, 0.0f};

        // Update visual shape
        shape.setPosition(position.x, position.y);
    }
};

// Manages the simulation world
class World {
public:
    std::vector<std::unique_ptr<RigidBody>> bodies;
    Vector2 gravity = {0.0f, 200.0f}; // Pixels per second^2
    sf::Vector2u windowSize;

    World(sf::Vector2u size) : windowSize(size) {}

    void addBody(std::unique_ptr<RigidBody> body) {
        bodies.push_back(std::move(body));
    }

    void update(float dt) {
        // Step 1: Apply forces
        for (auto& body : bodies) {
            body->applyForce(gravity);
        }

        // Step 2: Update positions
        for (auto& body : bodies) {
            body->update(dt);
        }

        // Step 3: Handle collisions
        for (size_t i = 0; i < bodies.size(); ++i) {
            for (size_t j = i + 1; j < bodies.size(); ++j) {
                RigidBody* a = bodies[i].get();
                RigidBody* b = bodies[j].get();

                Vector2 diff = a->position - b->position;
                float dist = diff.length();
                float combinedRadius = a->radius + b->radius;

                if (dist < combinedRadius) {
                    // Collision detected
                    resolveCollision(a, b, diff, dist, combinedRadius);
                }
            }
        }
        
        // Step 4: Handle screen boundary collisions
        handleBoundaries();
    }

private:
    void resolveCollision(RigidBody* a, RigidBody* b, const Vector2& diff, float dist, float combinedRadius) {
        // Separate the circles
        float penetration = combinedRadius - dist;
        Vector2 normal = diff.normalized();
        Vector2 separation = normal * (penetration / 2.0f);
        a->position = a->position + separation;
        b->position = b->position - separation;

        // Resolve velocities using impulse
        Vector2 relativeVelocity = a->velocity - b->velocity;
        float velocityAlongNormal = Vector2::dot(relativeVelocity, normal);

        if (velocityAlongNormal > 0) return; // They are already moving apart

        float restitution = 0.8f; // Bounciness
        float impulseScalar = -(1 + restitution) * velocityAlongNormal;
        impulseScalar /= a->inverseMass + b->inverseMass;

        Vector2 impulse = normal * impulseScalar;

        a->velocity = a->velocity + impulse * a->inverseMass;
        b->velocity = b->velocity - impulse * b->inverseMass;
    }

    void handleBoundaries() {
        for (auto& body : bodies) {
            if (body->position.x - body->radius < 0) {
                body->position.x = body->radius;
                body->velocity.x *= -0.8f; // Bounce off left wall
            }
            if (body->position.x + body->radius > windowSize.x) {
                body->position.x = windowSize.x - body->radius;
                body->velocity.x *= -0.8f; // Bounce off right wall
            }
            if (body->position.y - body->radius < 0) {
                body->position.y = body->radius;
                body->velocity.y *= -0.8f; // Bounce off top wall
            }
            if (body->position.y + body->radius > windowSize.y) {
                body->position.y = windowSize.y - body->radius;
                body->velocity.y *= -0.8f; // Bounce off bottom wall
            }
        }
    }
};

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "C++ 2D Physics Engine");
    window.setFramerateLimit(60);

    World world(window.getSize());

    // Add some bodies
    for (int i = 0; i < 15; ++i) {
        float r = (rand() % 20) + 10.0f;
        float x = (rand() % (WINDOW_WIDTH - (int)(2*r))) + r;
        float y = (rand() % (WINDOW_HEIGHT / 2)) + r;
        world.addBody(std::make_unique<RigidBody>(x, y, r, r * r * 0.1f));
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Add a new ball on mouse click
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    float r = (rand() % 20) + 10.0f;
                    world.addBody(std::make_unique<RigidBody>(mousePos.x, mousePos.y, r, r * r * 0.1f));
                }
            }
        }

        // Update physics
        float dt = clock.restart().asSeconds();
        world.update(dt);

        // Render
        window.clear(sf::Color(13, 17, 23)); // Dark background
        for (const auto& body : world.bodies) {
            window.draw(body->shape);
        }
        window.display();
    }

    return 0;
}
