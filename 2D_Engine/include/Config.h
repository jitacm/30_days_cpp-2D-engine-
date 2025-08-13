#pragma once
#include "Vector2.h"

namespace Config
{
    // Global gravity vector applied to all rigid bodies
    // Default: downward force similar to Earth's gravity
    static inline Vector2 gravity = { 0.f, 500.f }; // px/s²
}
