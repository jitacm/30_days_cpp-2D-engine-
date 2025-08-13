#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

namespace Utils {
    inline void initRandom() { std::srand(static_cast<unsigned int>(std::time(nullptr))); }
    inline sf::Color randomColor() { return sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256); }
    inline float randomFloat(float min, float max) {
        return min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX) / (max - min));
    }
}

#endif
