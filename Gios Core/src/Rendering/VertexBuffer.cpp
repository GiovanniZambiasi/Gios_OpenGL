#include "VertexBuffer.h"
#include "OpenGLUtilities.h"

namespace Gio::Rendering 
{
    VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    {
        GLCall(glGenBuffers(1, &_rendererID));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererID));
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    VertexBuffer::~VertexBuffer()
    {
        GLCall(glDeleteBuffers(1, &_rendererID));
    }

    void VertexBuffer::Bind() const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererID));
    }

    void VertexBuffer::UnBind() const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }
}