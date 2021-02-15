#include "SpaceScene.h"

#include "SpaceShip.h"
#include "Star.h"
#include "../Utilities/StdVectorUtilities.h"

Gio::Example::SpaceScene::SpaceScene()
    : Scene()
    , _starCount(100)
    , _starMargin(200)
{
    for (auto i = 0; i < _starCount; i++)
    {
        CreateStar(Vector3(Random::Between(-1000.0f, 1000.0f), Random::Between(-1000.0f, 1000.0f), 0.0f));    
    }

    new SpaceShip();

    auto spaceShip = GetEntity<SpaceShip>();
    
    if(spaceShip!=nullptr)
        Debug::Log("Found spaceship!");
}

Gio::Example::SpaceScene::~SpaceScene()
{
}

void Gio::Example::SpaceScene::OnUpdate(float deltaTime)
{
    DestroyStarsTooFarAway();

    CreateNewStars();
}

void Gio::Example::SpaceScene::CreateStar(Vector3 position)
{
    Star* star = new Star(Color::White(), position);

    _stars.push_back(star);
}

void Gio::Example::SpaceScene::DestroyStarsTooFarAway()
{
    auto camera = Camera::instance;
    Vector3 cameraPos = camera->GetTransform().GetPosition();

    float distanceTolerance = 1000 + _starMargin; // Todo - change to window W and H
    
    for (int i = _stars.size() - 1; i >= 0; i--)
    {
        auto star = _stars[i];

        auto starPosition = star->GetTransform().GetPosition();

        Vector3 starOffset = starPosition - cameraPos;
        
        if(Math::Abs(starOffset.x) >= distanceTolerance || Math::Abs(starOffset.y) >= distanceTolerance)
        {
            star->Delete();
            
            Utilities::RemoveAt(i, _stars);
        }
    }
}

void Gio::Example::SpaceScene::CreateNewStars()
{
    unsigned int starsToCreate = _starCount - _stars.size();

    if(starsToCreate == 0)
        return;
    
    auto camera = Camera::instance;
    Vector3 cameraPos = camera->GetTransform().GetPosition();
    
    for (auto i = 0; i < starsToCreate; i++)
    {
        Vector3 offset = Vector3(Random::Between(-1.0f, 1.0f), Random::Between(-1.0f, 1.0f), 0.0f);
        offset.Normalize();

        offset = offset * (Random::Between(0.0f, _starMargin) + 1000);

        Vector3 position = cameraPos + offset;
        
        CreateStar(position);
    }
}
