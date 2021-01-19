#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Window.h"
#include "Input.h"
#include "GUI.h"

namespace Gio
{
    class Application
    {
    private:
        Window* _window;
        Renderer* _renderer;
        Scene* _scene;
        GUI* _gui;
        Camera* _camera;
        Input* _input;

        void HandleWindowSizeChanged(unsigned int width, unsigned int height);
    
    public:
        Application(std::string name, unsigned int windowWidth, unsigned int windowHeight);

        ~Application();

        bool Run();

    private:
        void Update();
    };
}
