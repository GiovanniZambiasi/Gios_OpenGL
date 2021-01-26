#pragma once
#include <vector>

#include "DeviceManager.h"
#include "InputAction.h"
#include "InputAxis.h"
#include "Actions/InputActionBinding.h"
#include "Actions/InputAxisBindings.h"

namespace Gio::InputSystem
{
    class ActionManager
    {
    private:
        std::vector<Actions::InputActionBinding> _actionBindings;
        std::vector<Actions::InputAxisBindings> _axisBindings;
        std::vector<InputAction*> _actions;
        std::vector<InputAxis*> _axes;

        DeviceManager* _deviceManager;
    
    public:
        ActionManager(DeviceManager* deviceManager);

        ~ActionManager();

        void Update();

        InputAction* GetAction(const std::string name);

        void GetActions(std::vector<InputAction*>& collection);
        
        void RegisterInputAction(Actions::InputActionBinding binding);

        InputAxis* GetAxis(const std::string name);

        void GetAxes(std::vector<InputAxis*>& collection);

        void RegisterInputAxis(Actions::InputAxisBindings binding);

        void SaveBindings();

        void LoadBindings();

    private:
        void GetDeviceElements(std::vector<DeviceElementPair> pairs, std::vector<IInputElement*>& collection);

        IInputElement* GetDeviceElement(Gio::InputSystem::DeviceElementPair pair);
    };
}
