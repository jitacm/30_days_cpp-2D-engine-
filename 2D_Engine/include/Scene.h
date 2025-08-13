#pragma once
#include <string>
#include <vector>
#include "World.h"

class Scene {
public:
    Scene(const std::string& name);
    ~Scene();

    void init();              // create bodies etc.
    void update(float dt);
    void clear();             // remove bodies (but not delete pointers)
    World& getWorld() { return world; }
    const std::string& getName() const { return name; }

private:
    std::string name;
    World world;
    std::vector<RigidBody*> ownedBodies; // memory owned by scene; deleted in dtor
};
