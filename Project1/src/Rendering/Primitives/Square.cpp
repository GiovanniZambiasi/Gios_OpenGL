#include "Square.h"
#include "../../Debug.h"

Gio::Rendering::Primitives::Square::Square(float length, float height)
    : Mesh(
        new float[]
        {
            -length, -height, 0.0f,
            -length, height, 0.0f,
            length, height, 0.0f,
            length, -height, 0.0f
        }
        , 4
        , new unsigned int[]
        {
            0, 1, 2,
            2, 3, 0
        }
        , 6)
{
}

Gio::Rendering::Primitives::Square::~Square()
{
    Debug::Log("Destroying square");
}
