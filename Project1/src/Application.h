#pragma once
#include "Game.h"
#include "GUI.h"
#include "Renderer.h"
#include "Window.h"
#include "Input/Input.h"

namespace Gio
{
    class Application
    {
    private:
        Window* _window;
        Renderer* _renderer;
        Game* _game;
        GUI* _gui;
        Camera* _camera;
        Input::Input* _input;

        void HandleWindowSizeChanged(unsigned int width, unsigned int height);
    
    public:
        Application();

        ~Application();

        bool Run(std::string name, unsigned int windowWidth, unsigned int windowHeight);
    };
}
