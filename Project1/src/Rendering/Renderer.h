#pragma once
#include "../Debug.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace Gio::Rendering
{
    class Renderer
    {
    private:
        Renderer();
        
        ~Renderer();
    public:
        static void Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader);

        static void Clear();
    };
}