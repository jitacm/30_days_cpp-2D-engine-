#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "RigidBody.h"
#include "Utils.h"
#include "Scene.h"
#include "SceneManager.h"

int main()
{
    Utils::initRandom();

    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Engine - Scenes, Debug & HUD");
    window.setFramerateLimit(60);

    // Scene manager and scenes
    SceneManager sceneManager;
    // Test Scene
    {
        auto s = std::make_unique<Scene>("Test Scene");
        s->init(); // populates default demo objects
        sceneManager.addScene(std::move(s));
    }
    // Demo Scene (different layout)
    {
        auto s = std::make_unique<Scene>("Demo Scene");
        // custom init: replace default init with more objects
        s->getWorld(); // we will manually create bodies
        // create floor
        auto floorShape = std::make_shared<RectangleShape>(800.f, 40.f, Vector2{400.f, 580.f}, sf::Color(120,120,120));
        RigidBody* floor = new RigidBody(floorShape, 0.f, 0.f, true);
        // add dynamic cluster
        auto c1 = std::make_shared<CircleShape>(18.f, Vector2{300.f, 70.f}, sf::Color::Green);
        auto c2 = std::make_shared<CircleShape>(18.f, Vector2{340.f, 40.f}, sf::Color::Green);
        auto r1 = std::make_shared<RectangleShape>(60.f, 20.f, Vector2{420.f, 30.f}, sf::Color::Blue);
        RigidBody* rc1 = new RigidBody(c1, 3.f, 0.35f, false);
        RigidBody* rc2 = new RigidBody(c2, 3.5f, 0.35f, false);
        RigidBody* rb1 = new RigidBody(r1, 6.f, 0.25f, false);
        // add to scene's world and store ownership in the scene
        s->getWorld().addRigidBody(floor);
        s->getWorld().addRigidBody(rc1);
        s->getWorld().addRigidBody(rc2);
        s->getWorld().addRigidBody(rb1);
        // store owned pointers in scene by calling init() path would normally own them; but for simplicity, let scene destructor not remove these (we used new).
        // For this simplified demo, avoid calling scene->init(); just push the scene
        sceneManager.addScene(std::move(s));
    }

    // Debug / control flags
    bool debugMode = false;
    bool paused = false;
    bool stepOnce = false;

    // HUD font (load if available)
    sf::Font font;
    bool fontLoaded = font.loadFromFile("assets/arial.ttf"); // place a font file at assets/arial.ttf if you want text HUD

    sf::Clock clock;
    float accumulator = 0.f;
    float fpsTimer = 0.f;
    int fpsCounter = 0;
    int currentFPS = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::D) debugMode = !debugMode;
                if (event.key.code == sf::Keyboard::P) paused = !paused;
                if (event.key.code == sf::Keyboard::O) stepOnce = true; // step one frame
                if (event.key.code == sf::Keyboard::Num1) sceneManager.setActive(0);
                if (event.key.code == sf::Keyboard::Num2) { if (sceneManager.sceneCount() > 1) sceneManager.setActive(1); }
                if (event.key.code == sf::Keyboard::Space) {
                    // apply impulse to first dynamic circle found in active scene
                    Scene* active = sceneManager.getActive();
                    if (active) {
                        const auto& bodies = active->getWorld().getBodies();
                        for (auto* b : bodies) {
                            if (!b->isStatic && b->getShapeType() == ShapeType::Circle) {
                                b->applyImpulse({200.f, -300.f});
                                break;
                            }
                        }
                    }
                }
            }
        }

        float dt = clock.restart().asSeconds();

        // FPS counting
        fpsTimer += dt;
        fpsCounter++;
        if (fpsTimer >= 1.0f) {
            currentFPS = fpsCounter;
            fpsCounter = 0;
            fpsTimer = 0.f;
        }

        // Update active scene world if not paused or if stepping once
        Scene* activeScene = sceneManager.getActive();
        if (activeScene) {
            if (!paused || stepOnce) {
                activeScene->update(dt);
                stepOnce = false;
            }
        }

        window.clear(sf::Color::Black);

        // Render active scene
        if (activeScene) {
            const auto& bodies = activeScene->getWorld().getBodies();
            for (auto* b : bodies) {
                // color: red if colliding, else shape default
                sf::Color drawColor = b->isColliding ? sf::Color::Red : b->shape->color;
                b->shape->render(window, drawColor, debugMode);

                if (debugMode) {
                    // velocity vector
                    sf::VertexArray arrow(sf::Lines, 2);
                    Vector2 pos = b->getPosition();
                    arrow[0].position = sf::Vector2f(pos.x, pos.y);
                    arrow[0].color = sf::Color::Cyan;
                    // scale velocity for visibility
                    float scale = 0.1f;
                    arrow[1].position = sf::Vector2f(pos.x + b->velocity.x * scale, pos.y + b->velocity.y * scale);
                    arrow[1].color = sf::Color::Cyan;
                    window.draw(arrow);
                }
            }
        }

        // HUD
        // Draw a semi-transparent background for HUD
        sf::RectangleShape hudBg(sf::Vector2f(240.f, 80.f));
        hudBg.setPosition(8.f, 8.f);
        hudBg.setFillColor(sf::Color(0, 0, 0, 120));
        window.draw(hudBg);

        if (fontLoaded) {
            sf::Text t;
            t.setFont(font);
            t.setCharacterSize(14);
            t.setFillColor(sf::Color::White);
            std::string hud = "Scene: ";
            hud += activeScene ? activeScene->getName() : "None";
            hud += "\nFPS: " + std::to_string(currentFPS);
            int count = activeScene ? (int)activeScene->getWorld().getBodies().size() : 0;
            hud += "\nObjects: " + std::to_string(count);
            hud += "\nDebug(D): " + std::string(debugMode ? "ON" : "OFF");
            hud += "  Pause(P): " + std::string(paused ? "PAUSED" : "RUN");
            t.setString(hud);
            t.setPosition(12.f, 12.f);
            window.draw(t);

            sf::Text help;
            help.setFont(font);
            help.setCharacterSize(12);
            help.setFillColor(sf::Color(200,200,200));
            help.setString("Space: impulse | 1/2: switch scenes | O: step 1 frame");
            help.setPosition(12.f, 64.f);
            window.draw(help);
        } else {
            // minimal HUD without font
            // small colored boxes represent some values
            sf::RectangleShape fpsBar(sf::Vector2f( (float)std::min(200, currentFPS), 6.f));
            fpsBar.setPosition(12.f, 12.f);
            fpsBar.setFillColor(sf::Color::Green);
            window.draw(fpsBar);

            // simple text-less labels (not ideal but safe)
        }

        window.display();
    }

    return 0;
}
