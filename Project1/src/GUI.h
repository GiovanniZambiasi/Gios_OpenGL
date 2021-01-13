#pragma once
#include "Game.h"
#include "Window.h"
#include "Input/IInputDevice.h"
#include "Input/Input.h"

namespace Gio
{
    class GUI
    {
    private:
        Window& _window;
        Game& _game;
        Input::Input& _input;
        std::vector<Input::IInputDevice*> _devices;
        std::vector<Input::IInputElement*> _inputElements;
        bool _shouldShowDebugInfo = false;
        bool _shouldShowEntities = false;
        bool _shouldShowInput = false;
        int _windowHeight = 0;
        int _windowWidth = 0;
        
    public:
        GUI(Game& game, Window& window, Input::Input& input);

        ~GUI();

        void Clear();
        
        void Draw();

        void DrawSettingsWindow();

        void DrawInputDevices();
    };
}
