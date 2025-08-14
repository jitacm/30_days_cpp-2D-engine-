#pragma once
#include <cmath>

struct Vector2 {
    float x{0.f}, y{0.f};
    Vector2() = default;
    Vector2(float x_, float y_) : x(x_), y(y_) {}

    Vector2 operator+(const Vector2& v) const { return {x + v.x, y + v.y}; }
    Vector2 operator-(const Vector2& v) const { return {x - v.x, y - v.y}; }
    Vector2 operator*(float s) const { return {x * s, y * s}; }
    Vector2 operator/(float s) const { return {x / s, y / s}; }

    Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
    Vector2& operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }

    float length() const { return std::sqrt(x*x + y*y); }
    Vector2 normalized() const {
        float len = length();
        return len > 0.f ? Vector2(x/len, y/len) : Vector2(0.f,0.f);
    }
    float dot(const Vector2& v) const { return x * v.x + y * v.y; }
};
