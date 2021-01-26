#include "SpaceScene.h"

#include "SpaceShip.h"
#include "Star.h"

Gio::Example::SpaceScene::SpaceScene()
    : Scene()
{
    for (auto i = 0; i < 1000; i++)
    {
        auto position = Vector3(Random::Between(-3000.0f, 3000.0f), Random::Between(-3000.0f, 3000.0f), 0.0f);
        new Star(Color::White(), position);    
    }

    new SpaceShip();

    auto spaceShip = GetEntity<SpaceShip>();
    
    if(spaceShip!=nullptr)
        Debug::Log("Found spaceship!");
}