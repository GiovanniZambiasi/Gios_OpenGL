#pragma once
#include "../Mesh.h"

namespace Gio::Rendering::Primitives
{
    class Square : public Mesh
    {
    private:
        inline static Square* squareOneByOne = nullptr;
    
    public:
        Square(float length, float height);

        ~Square();

        static Square* GetOneByOne();
    };
}
