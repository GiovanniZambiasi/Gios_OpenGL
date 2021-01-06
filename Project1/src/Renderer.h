#pragma once
#include <GL/glew.h>
#include "Debug.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) // "\" is used to allow macro to be written in multiple lines

class Renderer 
{
public:
    void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;

    void Clear() const;
};