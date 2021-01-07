#include "OpenGLUtilities.h"
#include "Renderer.h"

namespace Gio::Rendering
{
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