#pragma once

namespace Gio
{
    struct Color
    {
    public:
        Color(float r, float g, float b, float a);
        
        Color();
        
        ~Color();
        
        float r;    
        float g;    
        float b;
        float a;

        static Color Red() { return Color(1.0f, 0.0f, 0.0f, 1.0f); }
        static Color Green() { return Color(0.0f, 1.0f, 0.0f, 1.0f); }
        static Color Blue() { return Color(0.0f, 0.0f, 1.0f, 1.0f); }
    };
}