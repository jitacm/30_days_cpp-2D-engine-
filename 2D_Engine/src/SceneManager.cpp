#include "SceneManager.h"

void SceneManager::addScene(std::unique_ptr<Scene> scene) {
    scenes.push_back(std::move(scene));
    if (activeIndex == static_cast<size_t>(-1)) activeIndex = 0;
}

void SceneManager::setActive(size_t index) {
    if (index < scenes.size()) activeIndex = index;
}

Scene* SceneManager::getActive() {
    if (activeIndex < scenes.size()) return scenes[activeIndex].get();
    return nullptr;
}
