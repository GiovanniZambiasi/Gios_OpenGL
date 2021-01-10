#pragma once

namespace Gio
{
    class Math
    {
    private:
        Math();

        ~Math();
    public:
        inline static const float pi = 3.14159265f;
            
        static float RadiansToDegrees(float radians)
        {
            return radians * pi / 180.0f;
        }
    };
}