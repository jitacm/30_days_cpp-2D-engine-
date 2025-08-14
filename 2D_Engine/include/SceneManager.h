#pragma once
#include <vector>
#include <memory>
#include "Scene.h"

class SceneManager {
public:
    void addScene(std::unique_ptr<Scene> scene);
    void setActive(size_t index);
    Scene* getActive();
    size_t getActiveIndex() const { return activeIndex; }
    size_t sceneCount() const { return scenes.size(); }

private:
    std::vector<std::unique_ptr<Scene>> scenes;
    size_t activeIndex{static_cast<size_t>(-1)};
};
