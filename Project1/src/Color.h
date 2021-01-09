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
    };
}