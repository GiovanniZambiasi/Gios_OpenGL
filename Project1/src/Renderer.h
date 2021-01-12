#pragma once
#include "Color.h"
#include "Transform.h"
#include "Vector3.h"
#include "Rendering/Mesh.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"
#include "Rendering/VertexArray.h"
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

        inline static Rendering::Shader* sceneGizmosShader = nullptr;
        
        static glm::mat4 CalculateModelMatrix(Transform& transform);
        
        static void CalculateViewProjectionMatrix();

        static void DrawSceneGizmos();
    
    public:
        static void SetupProjectionMatrix(unsigned int screenWidth, unsigned int screenHeight);
        
        static void Draw(Transform& transform, Rendering::VertexArray& vertexArray, Rendering::IndexBuffer& indexBuffer, Rendering::Shader& shader);
        
        static void Draw(Transform& transform, Rendering::Mesh& mesh, Rendering::Shader& shader);

        static void Clear();

        static void DrawRay(Vector3 origin, Vector3 direction, Color color);
        
        static void DrawLine(Vector3 start, Vector3 end, Color color);

        static void BeforeDraw();
    };
}