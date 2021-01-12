#pragma once
#include "../Mesh.h"

namespace Gio::Rendering::Primitives
{
    class Square : public Mesh
    {
    public:
        Square(float length, float height);
        
        ~Square();
    
    };
}
