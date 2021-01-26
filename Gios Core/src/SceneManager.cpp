#include "SceneManager.h"

#include "SceneManagement/MissingSceneException.h"
#include "Utilities/MapUtilities.h"

void Gio::SceneManager::Update(float deltaTime)
{
    _masterScene->Update(deltaTime);
}

void Gio::SceneManager::Draw(Gio::Renderer& renderer)
{
    _masterScene->Draw(renderer);
}

void Gio::SceneManager::CreateMasterScene()
{
    try
    {
        _masterScene = CreateScene(0);            
    }
    catch(SceneManagement::MissingSceneException e)
    {
        Debug::LogError(e.what());

        _masterScene = new Scene();
    }
    catch(std::exception e)
    {
        Debug::LogError("Exception caught while creating master scene:\n" + std::string(e.what()));
        
        _masterScene = new Scene();
    }
}

Gio::Scene* Gio::SceneManager::CreateScene(int key)
{
    if(Utilities::ContainsKey(_sceneCreatorRegistry, key))
    {
        return _sceneCreatorRegistry[key]();
    }
    else
        throw SceneManagement::MissingSceneException(key);
}