#include <GL/glew.h>
#include <stdexcept>

#include "ObjectRenderer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "../Debug.h"

Gio::ECS::ObjectRenderer::ObjectRenderer(Entity* entity, float vertices[], float vertexBufferSize, unsigned int indices[],
    unsigned indexCount, Color color)
        : Component(entity)
        , _color(color)
{
    _vertexArray = new Rendering::VertexArray();

    _vertexBuffer = new Rendering::VertexBuffer(vertices,  vertexBufferSize);

    _bufferLayout = new Rendering::VertexBufferLayout();
    _bufferLayout->Push<float>(2);

    _vertexArray->AddBuffer(*_vertexBuffer, *_bufferLayout);
    
    _indexBuffer = new Rendering::IndexBuffer(indices, indexCount);
    
    _shader = new Rendering::Shader("res/Shaders/Basic.shader");

    _shader->Bind();
    _shader->SetUniform4f("u_Color", _color.r, _color.g, _color.b, _color.a);
    
    _vertexArray->UnBind();
    _vertexBuffer->UnBind();
    _indexBuffer->UnBind();
    _shader->UnBind();
}

Gio::ECS::ObjectRenderer::~ObjectRenderer()
{
    delete _vertexArray;
    delete _vertexBuffer;
    delete _bufferLayout;
    delete _indexBuffer;
    delete _shader;
}

void Gio::ECS::ObjectRenderer::Draw()
{    
    //glPushMatrix();

    auto transform = entity->GetTransform();

    Vector3 position = transform.position;

    glRotatef(transform.rotation.x, 1.0f, .0f, .0f);
    glRotatef(transform.rotation.y, .0f, 1.0f, .0f);
    glRotatef(transform.rotation.z, .0f, .0f, 1.0f);

    //glTranslatef(position.x, position.y, position.z);

    Renderer::Draw(transform, *_vertexArray, *_indexBuffer, *_shader);
    
    //glColor3f(_color.r, _color.g, _color.b);

    //glBegin(GL_TRIANGLES);
    
    /*for (int i = 0; i < _vertices.size(); i++)
    {
        Vector2 vertex = _vertices.at(i);

        glVertex2f(vertex.x, vertex.y);
    }
    
    glEnd();
    */

    //glPopMatrix();
}
