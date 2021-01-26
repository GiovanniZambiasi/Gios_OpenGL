#pragma once
#include <string>

namespace Gio
{
    struct Vector2
    {
    public:
        Vector2(float x, float y);
        
        Vector2();

        ~Vector2();
        
        float x = 0.0f;
        float y = 0.0f;
        
        virtual void Rotate(float degrees);
        
        virtual float GetMagnitude();

        virtual void Normalize();

        virtual std::string to_string();
        
        Vector2 operator+(const Vector2& other) const
        {
            return Vector2(x + other.x, y + other.y);
        }

        static Vector2 Up() { return Vector2(.0f, 1.0f); }
        
        static Vector2 Down() { return Vector2(.0f, -1.0f); }

        static Vector2 Right() { return Vector2(1.0f, .0f); }
        
        static Vector2 Left() { return Vector2(-1.0f, .0f); }
        
        static Vector2 Zero() { return Vector2(.0f, .0f); }
        
        static Vector2 One() { return Vector2(1.0f, 1.0f); }
    };
    
}
