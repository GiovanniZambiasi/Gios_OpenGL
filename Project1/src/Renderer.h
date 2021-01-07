#pragma once
#include "Rendering/VertexArray.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"

namespace Gio
{
    class Renderer
    {
    private:
        Renderer();
        
        ~Renderer();
    public:
        static void Draw(Rendering::VertexArray& vertexArray, Rendering::IndexBuffer& indexBuffer, Rendering::Shader& shader);

        static void Clear();
    };
}