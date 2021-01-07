#include "IndexBuffer.h"
#include "Renderer.h"
#include "OpenGLUtilities.h"

namespace Gio::Rendering
{
    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
        : _count(count) // Initializer list. Initializes parameters before calling the constructor method
    {
        Debug::Log("Index buffer created with id " + std::to_string(count) + " current: " + std::to_string(_count));
        ASSERT(sizeof(unsigned int) == sizeof(GLuint));

        GLCall(glGenBuffers(1, &_rendererID));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    }

    IndexBuffer::~IndexBuffer()
    {
        GLCall(glDeleteBuffers(1, &_rendererID));
    }

    void IndexBuffer::Bind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));
    }

    void IndexBuffer::UnBind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
}
