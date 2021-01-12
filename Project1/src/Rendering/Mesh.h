#pragma once
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Gio::Rendering
{
    class Mesh
    {
    private:
        VertexBuffer _vertexBuffer;
        VertexBufferLayout _bufferLayout;
        VertexArray _vertexArray;
        IndexBuffer _indexBuffer;
    public:
        Mesh(float vertices[], int vertexCount, unsigned int indices[], unsigned int indexCount);
        
        ~Mesh();
        
        void Bind();

        unsigned int GetIndexCount() { return _indexBuffer.GetCount(); }
    };
}
