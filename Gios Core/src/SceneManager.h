#pragma once
#include <map>

#include "Scene.h"

namespace Gio
{
    template<typename T>
    Scene * InstantiateScene() { return new T; }
    
    class SceneManager : Utilities::Singleton<SceneManager>
    {
    private:
        typedef std::map<int, Scene*(*)()> SceneCreationRegistry;

        Scene* _masterScene;
        SceneCreationRegistry _sceneCreatorRegistry;
    
    public:
        
        SceneManager()
            : Singleton<Gio::SceneManager>()
            , _masterScene(nullptr)
        {
        }

        ~SceneManager(){}

        void Update(float deltaTime);
        
        void Draw(Gio::Renderer& renderer);
        
        Scene* GetMasterScene() { return _masterScene; }

        template <typename T>
        static void RegisterMasterScene();

        void CreateMasterScene();

    private:
        
        Scene* CreateScene(int key);
        
        template <typename T>
        void RegisterScene(int key);
    };

    template <typename T>
    void SceneManager::RegisterMasterScene()
    {
        instance->RegisterScene<T>(0);
    }

    template <typename T>
    void SceneManager::RegisterScene(int key)
    {
        _sceneCreatorRegistry[key] = &InstantiateScene<T>;
    }
}
