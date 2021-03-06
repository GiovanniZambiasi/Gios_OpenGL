#pragma once
#include "Camera.h"
#include "Transform.h"
#include "Vector3.h"
#include "WindowSize.h"
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
        WindowSize _windowSize;
        unsigned int _drawCalls;
        unsigned int _triangleCount;

        Rendering::Mesh* _previousRenderedMesh;
        Rendering::Shader* _previousRenderedShader;
        
    public:
        Renderer(Camera* camera);
        
        ~Renderer();
        
        void Draw(Transform& transform, Rendering::Mesh& mesh, Rendering::Material& material);

        void DrawRay(Vector3 origin, Vector3 direction, Color color);

        void DrawLine(Vector3 start, Vector3 end, Color color);
        
        void Clear();

        void SetupProjectionMatrix(WindowSize windowSize);
        
        void BeforeDraw();
        
        unsigned int GetDrawCalls() const { return _drawCalls; }
        
        unsigned int GetTriangleCount() const {return _triangleCount;};

    private:
        glm::mat4 CalculateModelMatrix(Transform& transform);
        
        void CalculateViewProjectionMatrix();
    };
}