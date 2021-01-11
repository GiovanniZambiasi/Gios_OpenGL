#include "Rendering/OpenGLUtilities.h"
#include "Renderer.h"
#include "Camera.h"
#include "Debug.h"

using namespace Gio::Rendering;

namespace Gio
{
    Renderer::Renderer()
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
        /*sceneGizmosShader->Bind();
        sceneGizmosShader->SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
        sceneGizmosShader->SetUniformMat4f("u_MVP", viewProjectionMatrix);*/

        glBegin(GL_LINE);
        
        glColor3f(color.r, color.g, color.b);

        glVertex3f(start.x, start.y, start.z);
        
        glVertex3f(end.x, end.y, end.z);
        
        glEnd();

        //sceneGizmosShader->UnBind();
    }

    void Renderer::BeforeDraw()
    {
        CalculateViewProjectionMatrix();
        DrawSceneGizmos();
    }

    void Renderer::Draw(Transform& transform, VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader)
    {
        shader.Bind();

        shader.SetUniformMat4f("u_MVP", viewProjectionMatrix * CalculateModelMatrix(transform));
        
        vertexArray.Bind();
        indexBuffer.Bind();
        
        GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::CalculateViewProjectionMatrix()
    {
        Transform& cameraTransform = Camera::GetTransform();
        
        auto cameraPosition = cameraTransform.position;
        
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z));

        viewProjectionMatrix = projectionMatrix * view;
    }

    void Renderer::DrawSceneGizmos()
    {
        Renderer::DrawLine(Vector3::Left() * 1000.0f, Vector3::Right() * 1000.0f, Color::Red());
        Renderer::DrawLine(Vector3::Up() * 1000.0f, Vector3::Down() * 1000.0f, Color::Green());
    }

    glm::mat4 Renderer::CalculateModelMatrix(Transform& transform)
    {
        auto model = glm::mat4(1.0f);
        
        glm::mat4 translate = glm::translate(model, glm::vec3(transform.position.x, transform.position.y, transform.position.z));
        
        auto scale = transform.GetScale();
        glm::mat4 scaleMatrix = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));

        auto rotationRadians = transform.GetRotationRadians();
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