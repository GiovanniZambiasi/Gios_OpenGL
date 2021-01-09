#include <GL/glew.h>
#include <stdexcept>
#include "ObjectRenderer.h"
#include "../Debug.h"

Gio::ECS::ObjectRenderer::ObjectRenderer(Transform* transform, std::vector<Vector2>* vertices, Color color)
    : Component(transform)
{
    _color = color;

    try
    {
        _vertices = vertices;
    }
    catch (std::out_of_range exception)
    {
        auto text = std::string(exception.what());
        Debug::LogError("Tried to access out of range index " + text);
    }
}

Gio::ECS::ObjectRenderer::~ObjectRenderer()
{
}

void Gio::ECS::ObjectRenderer::LateUpdate(float deltaTime)
{    
    glPushMatrix();

    Vector2 position = transform->position;
    
    glTranslatef(position.x, position.y, 0.0f);

    glColor3f(_color.r, _color.g, _color.b);

    glBegin(GL_TRIANGLES);
    
    for (int i = 0; i < _vertices->size(); i++)
    {
        Vector2 vertex = _vertices->at(i);

        glVertex2f(vertex.x, vertex.y);
    }
    
    glEnd();
    
    glPopMatrix();
}
