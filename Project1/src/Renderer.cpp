#include "Rendering/OpenGLUtilities.h"
#include "Renderer.h"
#include "Camera.h"

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
        projectionMatrix = glm::ortho(.0f,  float(screenWidth), .0f, float(screenHeight), -1.0f, 1.0f);;
    }

    void Renderer::DrawRay(Vector3 origin, Vector3 direction, Color color)
    {
        glColor3f(color.r, color.g, color.b);

        glBegin(GL_LINES);

        glVertex3f(origin.x, origin.y, origin.z);
        
        Vector3 end = origin + direction;
        
        glVertex3f(end.x, end.y, end.z);
        
        glEnd();
    }

    void Renderer::DrawRay(Vector2 origin, Vector2 direction, Color color)
    {
        glColor3f(color.r, color.g, color.b);

        glBegin(GL_LINES);

        glVertex2f(origin.x, origin.y);
        glVertex2f(origin.x + direction.x, origin.y + direction.y);
        
        glEnd();
    }

    void Renderer::BeforeDraw()
    {
        CalculateViewProjectionMatrix();
    }

    void Renderer::Draw(Transform& transform, VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader)
    {
        shader.Bind();

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(transform.position.x, transform.position.y, transform.position.z));
        
        shader.SetUniformMat4f("u_MVP", viewProjectionMatrix * model);
        
        vertexArray.Bind();
        indexBuffer.Bind();
        
        GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::CalculateViewProjectionMatrix()
    {
        auto cameraTransform = Camera::GetTransform();
        
        auto cameraPosition = cameraTransform.position;
        
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z));

        viewProjectionMatrix = projectionMatrix * view;
    }

    void Renderer::Clear()
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }
}