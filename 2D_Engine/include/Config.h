#pragma once
#include "Vector2.h"

namespace Config {
    // pixels per second squared
    static inline Vector2 gravity = {0.f, 500.f};

    // global restitution if needed as fallback
    static constexpr float DEFAULT_RESTITUTION = 0.2f;
}
