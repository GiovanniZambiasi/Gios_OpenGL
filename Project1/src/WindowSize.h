#pragma once
#include <string>

namespace Gio
{
    struct WindowSize
    {
    public:
        unsigned int width;
        unsigned int height;

        WindowSize(unsigned int width, unsigned int height)
            : width(width)
            , height(height)
        {        }

        WindowSize()
            :width(0)
            ,height(0)
        {        }

        std::string ToString() { return "W: " + std::to_string(width) + " H: " + std::to_string(height); }
    };
}