#include "Renderer.h"
#include "Rendering/OpenGLUtilities.h"
#include "Rendering/Mesh.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"
#include "Rendering/VertexArray.h"
#include "Camera.h"

using namespace Gio::Rendering;

namespace Gio
{
    Renderer::Renderer(Camera* camera)
        : _camera(camera), projectionMatrix(), viewProjectionMatrix()
    {
    }

    Renderer::~Renderer()
    {
    }

    void Renderer::SetupProjectionMatrix(unsigned int screenWidth, unsigned int screenHeight)
    {
        projectionMatrix = glm::ortho(.0f,  float(screenWidth), .0f, float(screenHeight), -1.0f, 1.0f);
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
        CalculateViewProjectionMatrix();
    }

    void Renderer::Draw(Transform& transform, VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader)
    {
        shader.Bind();

        auto modelViewProjectionMatrix = viewProjectionMatrix * CalculateModelMatrix(transform);
        
        shader.SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
        
        vertexArray.Bind();
        indexBuffer.Bind();
        
        GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::Draw(Transform& transform, Rendering::Mesh& mesh, Rendering::Material& material)
    {
        material.Bind();

        auto modelViewProjectionMatrix = viewProjectionMatrix * CalculateModelMatrix(transform);

        Shader& shader = material.GetShader();
        shader.SetUniform("u_MVP", modelViewProjectionMatrix);
        
        mesh.Bind();
        
        GLCall(glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::CalculateViewProjectionMatrix()
    {
        Transform& cameraTransform = _camera->GetTransform();
        
        auto cameraPosition = cameraTransform.position;
        
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z));

        viewProjectionMatrix = projectionMatrix * view;
    }

    glm::mat4 Renderer::CalculateModelMatrix(Transform& transform)
    {
        auto model = glm::mat4(1.0f);
        
        glm::mat4 translate = glm::translate(model, glm::vec3(transform.position.x, transform.position.y, transform.position.z));
        
        auto scale = transform.GetScale();
        glm::mat4 scaleMatrix = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));

        auto rotationRadians = transform.GetRotationRadians();
        //glm::mat4 rotationMatrix = glm::radians(glm::);
        glm::mat4 rotationMatrix = glm::rotate(model, rotationRadians.z, glm::vec3(0, 0, 1));
        rotationMatrix *= glm::rotate(model, rotationRadians.x, glm::vec3(1, 0, 0));
        rotationMatrix *= glm::rotate(model, rotationRadians.y, glm::vec3(0, 1, 0));

        return translate * scaleMatrix * rotationMatrix;
    }

    void Renderer::Clear()
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }
}