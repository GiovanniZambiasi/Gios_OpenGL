#include "Renderer.h"
#include "Debug.h"

using namespace Gio;

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum __error = glGetError())  // Runs until '__error' is different from 0 (GL_NO_ERROR)
    {
        Debug::LogError("[OpenGL]: \"" + std::to_string(__error) + "\". " + function + " " + file + " @ line: " + std::to_string(line));
        return false;
    }
    return true;
}

void Renderer::Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const
{
    shader.Bind();
    vertexArray.Bind();
    indexBuffer.Bind();
    
    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}