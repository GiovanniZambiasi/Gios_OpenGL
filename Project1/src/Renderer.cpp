#include "Rendering/OpenGLUtilities.h"
#include "Renderer.h"

using namespace Gio::Rendering;

namespace Gio
{
    Renderer::Renderer()
    {
    }

    Renderer::~Renderer()
    {
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

    void Renderer::Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader)
    {
        shader.Bind();
        vertexArray.Bind();
        indexBuffer.Bind();
        
        GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::Clear()
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }
}