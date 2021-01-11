#pragma once
#include "Color.h"
#include "Transform.h"
#include "Vector3.h"
#include "Rendering/VertexArray.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

namespace Gio
{
    class Renderer
    {
    private:
        Renderer();
        
        ~Renderer();

        inline static glm::mat4 projectionMatrix;
        inline static glm::mat4 viewProjectionMatrix;

        static void CalculateViewProjectionMatrix();
    
    public:
        static void SetupProjectionMatrix(unsigned int screenWidth, unsigned int screenHeight);
        
        static void Draw(Transform& transform, Rendering::VertexArray& vertexArray, Rendering::IndexBuffer& indexBuffer, Rendering::Shader& shader);

        static void Clear();

        static void DrawRay(Vector3 origin, Vector3 direction, Color color);

        static void DrawRay(Vector2 origin, Vector2 direction, Color color);
        
        static void BeforeDraw();
    };
}