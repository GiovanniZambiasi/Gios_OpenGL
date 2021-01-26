#pragma once

#include "../Utilities/Singleton.h"
#include "InputSystem/ActionManager.h"
#include "InputSystem/DeviceManager.h"

namespace Gio
{
    class Input : Utilities::Singleton<Input>
    {
    private:
        InputSystem::DeviceManager* _deviceManager;
        InputSystem::ActionManager* _actionManager;
    
    public:
        Input(InputSystem::IInputDeviceFactory& deviceFactory);

        ~Input();

        void Update();

        static InputSystem::DeviceManager* GetDeviceManager() { return instance->_deviceManager; }

        static InputSystem::ActionManager* GetActionManager() { return instance->_actionManager; }
    };
}
