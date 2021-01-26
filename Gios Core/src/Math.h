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

        static float Round(float v)
        {
            int valueWithNoDecimal = (int)v;
            
            float decimal = v - valueWithNoDecimal;

            if(decimal < .5f)
                return valueWithNoDecimal;
            else
                return valueWithNoDecimal + 1;
        }

        static int Sign(float v)
        {
            return v < 0 ? -1 : 1;
        }

        static int Sign(int v)
        {
            return v < 0 ? -1 : 1;
        }
        
        static int RoundToInt(float v)
        {
            return Round(v);
        }

        static float Floor(float v)
        {
            return (int)v;
        }

        static int FloorToInt(float v)
        {
            return Floor(v);
        }

        static float Ceil(float v)
        {
            int valueWithNoDecimal = (int)v;
            float decimal = v - valueWithNoDecimal;

            if(decimal == 0.0f)
                return v;
            else
                return v + 1;
        }

        static int CeilToInt(float v)
        {
            return Ceil(v);
        }

        static float Lerp(float x, float y, float t)
        {
            return LerpUnclamped(x, y, Clamp(t, 0.0f, 1.0f));
        }

        static float LerpUnclamped(float x, float y, float t)
        {
            return x * (1 - t) + y * t;
        }

        static float ApplyDrag(float x, float drag)
        {
            int sign = Sign(x);
            float absX = Abs(x);
            float absDrag = Abs(drag);

            absX = Clamp((absX - absDrag), 0.0f, absX);

            return absX * sign;
        }
    };
}
