﻿#pragma once
#include "Scene.h"
#include "Window.h"
#include "Input/IInputDevice.h"
#include "Input/Input.h"

namespace Gio
{
    class GUI
    {
    private:
        Window& _window;
        Scene& _game;
        Input::Input& _input;
        std::vector<Input::IInputDevice*> _devices;
        std::vector<Input::IInputElement*> _inputElements;
        char _log[24];
        bool _shouldShowDebugInfo = false;
        bool _shouldShowEntities = false;
        bool _shouldShowInputDevices = false;
        bool _shouldShowInputActions = false;
        bool _shouldShowInputAxes = false;
        int _windowHeight = 0;
        int _windowWidth = 0;
        
    public:
        GUI(Scene& game, Window& window, Input::Input& input);

        ~GUI();

        void Clear();

        void Draw();

        void DrawSettingsWindow();

        void DrawInputDevices();
        
        void DrawInputActions();
        
        void DrawInputAxes();
    };
}
