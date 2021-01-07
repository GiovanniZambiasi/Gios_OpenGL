#pragma once
#include <GL/glew.h>

namespace Gio::Rendering
{
    void GLClearError();

    bool GLLogCall(const char* function, const char* file, int line);

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) // "\" is used to allow macro to be written in multiple lines

}