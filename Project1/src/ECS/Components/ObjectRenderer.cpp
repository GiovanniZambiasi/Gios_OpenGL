#include "ObjectRenderer.h"

#include "../../Input/Input.h"
#include "../../Input/Devices/Keyboard.h"


Gio::ECS::Components::ObjectRenderer::ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Color color)
        : Component(entity)
        , _mesh(mesh)
        , _shader(Rendering::Shader("res/Shaders/Basic.shader"))
{
    _material = new Rendering::Material(_shader);
    _material->SetColor("u_Color", color);
}

Gio::ECS::Components::ObjectRenderer::~ObjectRenderer()
{
}

void Gio::ECS::Components::ObjectRenderer::Draw(Renderer& renderer)
{
    Input::Devices::Keyboard* keyboard = Input::Input::instance->GetDevice<Input::Devices::Keyboard>();
    if(keyboard != nullptr)
    {
        if(keyboard->GetKey(Input::Devices::KeyboardKey::Space)->WasPressedThisFrame())
        {
            _material->SetColor("u_Color", Color::Red());
        }    
    }
    
    renderer.Draw(entity.GetTransform(), _mesh, *_material);
}