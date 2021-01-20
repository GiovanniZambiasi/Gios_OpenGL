#pragma once
#include "Camera.h"
#include "Transform.h"
#include "Vector3.h"
#include "Rendering/Material.h"
#include "Rendering/Mesh.h"
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

namespace Gio
{
    class Renderer
    {
    private:
        Camera* _camera;
        glm::mat4 projectionMatrix;
        glm::mat4 viewProjectionMatrix;
        unsigned int _screenWidth;
        unsigned int _screenHeight;

        Rendering::Mesh* _previousRenderedMesh;
        Rendering::Shader* _previousRenderedShader;
        
        glm::mat4 CalculateModelMatrix(Transform& transform);
        
        void CalculateViewProjectionMatrix();

    public:
        Renderer(Camera* camera);
        
        ~Renderer();
        
        void Draw(Transform& transform, Rendering::Mesh& mesh, Rendering::Material& material);

        void DrawRay(Vector3 origin, Vector3 direction, Color color);

        void DrawLine(Vector3 start, Vector3 end, Color color);
        
        void Clear();

        void SetupProjectionMatrix(unsigned int screenWidth, unsigned int screenHeight);
        
        void BeforeDraw();
    };
}