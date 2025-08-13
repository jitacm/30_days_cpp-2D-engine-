#include "Scene.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "RigidBody.h"
#include "Utils.h"

Scene::Scene(const std::string& name_) : name(name_) {}

Scene::~Scene() {
    // delete owned bodies
    for (auto* b : ownedBodies) delete b;
    ownedBodies.clear();
}

void Scene::init() {
    // default: create simple demo layout if nothing else
    // clear previous
    clear();

    // ground-ish rectangle (static)
    auto floorShape = std::make_shared<RectangleShape>(800.f, 50.f, Vector2{400.f, 575.f}, sf::Color(100,100,100));
    RigidBody* floor = new RigidBody(floorShape, 0.f, 0.f, true);
    floor->isStatic = true;
    ownedBodies.push_back(floor);
    world.addRigidBody(floor);

    // sample circle
    auto circleShape = std::make_shared<CircleShape>(20.f, Vector2{200.f, 100.f}, sf::Color::Green);
    RigidBody* circle = new RigidBody(circleShape, 5.f, 0.3f, false);
    ownedBodies.push_back(circle);
    world.addRigidBody(circle);

    // sample rectangle
    auto rectShape = std::make_shared<RectangleShape>(80.f, 30.f, Vector2{400.f, 50.f}, sf::Color::Blue);
    RigidBody* rect = new RigidBody(rectShape, 10.f, 0.2f, false);
    ownedBodies.push_back(rect);
    world.addRigidBody(rect);

    // another circle
    auto c2 = std::make_shared<CircleShape>(30.f, Vector2{600.f, 120.f}, sf::Color::Green);
    RigidBody* circle2 = new RigidBody(c2, 8.f, 0.4f, false);
    ownedBodies.push_back(circle2);
    world.addRigidBody(circle2);
}

void Scene::update(float dt) {
    world.update(dt);
}

void Scene::clear() {
    // delete existing bodies in world and ownedBodies
    // Note: World class does not own the pointers; Scene owns them here.
    // To remove them from world, simplest is to rebuild the world. For simplicity in this small engine:
    // We'll not remove bodies from world vector here; instead Scene destructor handles deleting.
    // To support multiple scenes, we will create fresh scenes (with their own worlds) in SceneManager.
    // So clear is minimal.
}
