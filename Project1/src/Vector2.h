#pragma once
#include <string>

namespace Gio
{
    struct Vector2
    {
    public:
        float x = 0.0f;
        float y = 0.0f;
        
        Vector2(float x, float y);
        
        Vector2();

        ~Vector2();

        void Rotate(float degrees);
        
        virtual float GetMagnitude();

        Vector2 GetNormalized();

        virtual std::string to_string();
        
        Vector2& operator+(const Vector2& vector2)
        {
            x += vector2.x;
            y += vector2.y;
            return *this;
        }

        static Vector2 Up() { return Vector2(0.0f, 1.0f); }
        
        static Vector2 Down() { return Vector2(0.0f, -1.0f); }

        static Vector2 Right() { return Vector2(1.0f, 0.0f); }
        
        static Vector2 Left() { return Vector2(-1.0f, 0.0f); }
    };
}
