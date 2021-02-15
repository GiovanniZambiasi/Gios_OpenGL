#pragma once
#include "Star.h"
#include "../Scene.h"

namespace Gio::Example
{
    class SpaceScene : public Scene
    {
    private:
        std::vector<Star*> _stars;
        unsigned int _starCount;
        unsigned int _starMargin;
        
    public:
        SpaceScene();

        ~SpaceScene();
    
    protected:
        
        void OnUpdate(float deltaTime) override;

    private:

        void CreateStar(Vector3 position);

        void DestroyStarsTooFarAway();

        void CreateNewStars();
    };
}
