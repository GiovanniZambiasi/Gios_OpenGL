#include "Renderer.h"
#include "Camera.h"
#include "Rendering/Mesh.h"
#include "Rendering/OpenGLUtilities.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderManager.h"

using namespace Gio::Rendering;

namespace Gio
{
    Renderer::Renderer(Camera* camera)
        : _camera(camera), projectionMatrix(), viewProjectionMatrix()
          , _drawCalls(0), _triangleCount(0), _previousRenderedMesh(nullptr)
          , _previousRenderedShader(nullptr)
    {
        ShaderManager::LoadShaders();
    }

    Renderer::~Renderer()
    {
    }

    void Renderer::SetupProjectionMatrix(WindowSize windowSize)
    {
        _windowSize = windowSize;
        projectionMatrix = glm::ortho(.0f,  float(_windowSize.width), .0f, float(_windowSize.height), -100.0f, 100.0f);
        Debug::Log("Setting projection matrix for " + windowSize.ToString());
    }

    void Renderer::DrawRay(Vector3 origin, Vector3 direction, Color color)
    {
        DrawLine(origin, origin + direction, color);
    }

    void Renderer::DrawLine(Vector3 start, Vector3 end, Color color)
    {
        glBegin(GL_LINE);
        
        glColor3f(color.r, color.g, color.b);

        glVertex3f(start.x, start.y, start.z);
        
        glVertex3f(end.x, end.y, end.z);
        
        glEnd();
    }

    void Renderer::BeforeDraw()
    {
        _drawCalls = 0;
        _triangleCount = 0;
        
        CalculateViewProjectionMatrix();
    }

    void Renderer::Draw(Transform& transform, Rendering::Mesh& mesh, Rendering::Material& material)
    {
        Shader& shader = material.GetShader();
        
        if(_previousRenderedShader == nullptr || _previousRenderedShader != &shader)
        {
            shader.Bind();            
            _previousRenderedShader = &shader;
        }
        
        material.ApplyProperties();

        const auto modelMatrix = CalculateModelMatrix(transform);
        
        shader.SetUniformByLocation(shader.GetViewProjectionMatrixLocation(), viewProjectionMatrix);
        shader.SetUniformByLocation(shader.GetModelMatrixLocation(), modelMatrix);

        if(_previousRenderedMesh == nullptr || _previousRenderedMesh != &mesh)
        {
            mesh.Bind();
            _previousRenderedMesh = &mesh;
        }

        _drawCalls++;
        _triangleCount += mesh.GetTriangleCount();
        
        GLCall(glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::CalculateViewProjectionMatrix()
    {
        Transform& cameraTransform = _camera->GetTransform();
        
        auto cameraPosition = cameraTransform.GetPosition();
        cameraPosition.x = cameraPosition.x - (_windowSize.width/2);
        cameraPosition.y = cameraPosition.y - (_windowSize.height/2);
        
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-cameraPosition.x, -cameraPosition.y, cameraPosition.z));

        viewProjectionMatrix = projectionMatrix * view;
    }

    glm::mat4 Renderer::CalculateModelMatrix(Transform& transform)
    {
        auto model = glm::mat4(1.0f);

        auto position = transform.GetPosition();
        glm::mat4 translate = glm::translate(model, glm::vec3(position.x, position.y, position.z));
        
        auto scale = transform.GetScale();
        glm::mat4 scaleMatrix = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));

        auto rotationRadians = transform.GetRotationRadians();
        glm::mat4 rotationMatrix = glm::rotate(model, rotationRadians.z, glm::vec3(0, 0, 1));
        
        return translate * scaleMatrix * rotationMatrix;
    }

    void Renderer::Clear()
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }
}