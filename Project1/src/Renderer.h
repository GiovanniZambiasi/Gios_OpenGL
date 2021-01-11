#pragma once
#include "Color.h"
#include "Vector3.h"
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

        static void DrawRay(Vector3 origin, Vector3 direction, Color color);
        
        static void DrawRay(Vector2 origin, Vector2 direction, Color color);
    };
}