﻿#pragma once
#include "Random.h"

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
        static Color White() { return Color(1.0f, 1.0f, 1.0f, 1.0f); }
        static Color Black() { return Color(.0f, .0f, .0f, 1.0f); }
        static Color Random(){return Gio::Color(Random::Scalar(), Random::Scalar(), Random::Scalar(), 1.0f);}
    };
}
