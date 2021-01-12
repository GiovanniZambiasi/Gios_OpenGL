#include "Mesh.h"

Gio::Rendering::Mesh::Mesh(float vertices[], int vertexCount, unsigned indices[], unsigned indexCount)
    : _vertexBuffer(Rendering::VertexBuffer(vertices,  vertexCount * 3 * sizeof(float)))
    , _bufferLayout (Rendering::VertexBufferLayout())
    , _vertexArray(Rendering::VertexArray())
    , _indexBuffer(Rendering::IndexBuffer(indices, indexCount))
{
    _bufferLayout.Push<float>(3);

    _vertexArray.AddBuffer(_vertexBuffer, _bufferLayout);
    
    _vertexArray.UnBind();
    _vertexBuffer.UnBind();
    _indexBuffer.UnBind();
}

Gio::Rendering::Mesh::~Mesh()
{
}

void Gio::Rendering::Mesh::Bind()
{
    _vertexArray.Bind();
    _indexBuffer.Bind();
}