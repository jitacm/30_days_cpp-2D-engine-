#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

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
        return (l > 0) ? Vector2(x / l, y / l) : Vector2(0, 0);
    }

    static float dot(const Vector2& a, const Vector2& b) {
        return a.x * b.x + a.y * b.y;
    }
};

#endif
