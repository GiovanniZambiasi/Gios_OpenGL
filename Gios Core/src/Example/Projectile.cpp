#include "Projectile.h"

#include "../ECS/Components/ObjectRenderer.h"
#include "../ECS/Components/Physics.h"
#include "../Rendering/ShaderManager.h"
#include "../Rendering/Primitives/Square.h"

Gio::Example::Projectile::Projectile(Vector3 position, Vector3 rotation, Vector3 initialVelocity)
    : Entity("Projectile")
    , _lifespan(3.0f)
{
    Transform& transform = GetTransform();
    transform.SetPosition(position);
    transform.SetRotation(rotation);
    transform.SetScale(Vector3::One() * 2.0f);
    
    auto mesh = Rendering::Primitives::Square::GetOneByOne();

    auto material = new Rendering::Material(*Rendering::ShaderManager::GetShader("Basic"));

    material->SetColor("u_Color", Color::White());

    auto renderer = new ECS::Components::ObjectRenderer(*this, *mesh, *material);

    AddComponent(renderer);

    auto physics = new ECS::Components::Physics(*this, 1.0f, 0.0f, 0.0f);

    physics->SetVelocity(initialVelocity);
    physics->AddForce(transform.GetUp() * 900);
    
    AddComponent(physics);
}

Gio::Example::Projectile::~Projectile()
{
}

void Gio::Example::Projectile::OnUpdate(float deltaTime)
{
    _lifespan -= deltaTime;

    if(_lifespan <= 0)
        Delete();
}