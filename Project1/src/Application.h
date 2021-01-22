#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Window.h"
#include "Input.h"
#include "GUI.h"
#include "SceneManager.h"

namespace Gio
{
    enum ApplicationResultTypes : unsigned char
    {
        Good,
        Bad,
    };
    
    class Application final : public Utilities::Observer<WindowSize>
    {
    private:
        Window* _window;
        Renderer* _renderer;
        SceneManager* _sceneManager;
        Camera* _camera;
        Input* _input;
        GUI* _gui;

    public:
        Application(std::string name, unsigned int windowWidth, unsigned int windowHeight);

        ~Application();

        ApplicationResultTypes Run();

        void Observe(WindowSize windowSize) override;
    
    private:
        void Update();

        void Prepare();

    };

    class BadWindowException : std::exception
    {
    public:
        char const* what() const override;
    };
}
