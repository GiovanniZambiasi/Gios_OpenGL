#pragma once
#include "Vector2.h"

namespace Gio
{
    struct Vector3 : Vector2
    {
    public:
        float z = .0f;

        Vector3(float x, float y, float z);
        
        Vector3();

        ~Vector3();

        float GetMagnitude() override;

        std::string to_string() override;
        
        void Normalize() override;

        Vector3& operator+(const Vector3& other)
        {
            x+=other.x;
            y+=other.y;
            z+=other.z;

            return *this;
        }
        
        Vector3& operator*(const float& other)
        {
            x *= other;
            y *= other;
            z *= other;

            return *this;
        }

        static Vector3 Up() { return Vector3(.0f, 1.0f, .0f); }
        
        static Vector3 Down() { return Vector3(.0f, -1.0f, .0f); }
        
        static Vector3 Right() { return Vector3(1.0f, .0f, .0f); }
        
        static Vector3 Left() { return Vector3(-1.0f, .0f, .0f); }
        
        static Vector3 Forward() { return Vector3(.0f, .0f, 1.0f); }
        
        static Vector3 Back() { return Vector3(.0f, .0f, -1.0f); }
        
        static Vector3 Zero() { return Vector3(.0f, .0f, .0f); }
        
        static Vector3 One() { return Vector3(1.0f, 1.0f, 1.0f); }
    };
}
