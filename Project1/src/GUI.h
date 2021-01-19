#pragma once
#include "Input.h"
#include "Scene.h"
#include "Window.h"
#include "InputSystem/IInputDevice.h"

namespace Gio
{
    class GUI
    {
    private:
        Window& _window;
        Scene& _game;
        Input& _input;
        std::vector<InputSystem::IInputDevice*> _devices;
        std::vector<InputSystem::IInputElement*> _inputElements;
        char _log[24];
        bool _shouldShowDebugInfo = false;
        bool _shouldShowEntities = false;
        bool _shouldShowInputDevices = false;
        bool _shouldShowInputActions = false;
        bool _shouldShowInputAxes = false;
        int _windowHeight = 0;
        int _windowWidth = 0;
        
    public:
        GUI(Scene& game, Window& window, Input& input);

        ~GUI();

        void Clear();

        void Draw();

        void DrawSettingsWindow();

        void DrawInputDevices();
        
        void DrawInputActions();
        
        void DrawInputAxes();
    };
}
