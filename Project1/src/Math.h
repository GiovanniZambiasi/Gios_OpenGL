#pragma once
#include <valarray>

#include "Debug.h"

namespace Gio
{
    class Math
    {
    private:
        Math();

        ~Math();
    public:
        inline static const float pi = 3.14159265359f;
            
        static float DegreesToRadians(float degrees) { return (degrees / 180.0f) * pi; }

        static float RadiansToDegrees(float radians) { return (radians/pi) * 180.0f; }

        static float Cos(float degrees)
        {
            return std::cos(DegreesToRadians(degrees));
        }

        static float Sin(float degrees)
        {
            return std::sin(DegreesToRadians(degrees));
        }

        static float Abs(float x)
        {
            return x < 0 ? -x : x;
        }

        static float Sqrt(float x)
        {
            return std::sqrt(x);
        }

        static float Pow(float x, float pw)
        {
            return std::pow(x, pw);
        }

        static float Clamp(float v, float min, float max)
        {
            if(min > max)
            {
                Gio::Debug::LogError("Trying to clamp " + std::to_string(v) + " between " + std::to_string(min) + " and " + std::to_string(max) + ", but min is higher than max");
                return v;
            }

            if(v < min)
                return min;
            else if(v > max)
                return max;
            else
                return v;
        }
    };
}
