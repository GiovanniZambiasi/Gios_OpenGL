#pragma once

#include <vector>
#include "IInputDevice.h"
#include "IInputDeviceFactory.h"
#include "InputAction.h"
#include "InputActionBinding.h"
#include "../Utilities/Singleton.h"

namespace Gio::Input
{
    class Input : public Utilities::Singleton<Input>
    {
    private:
        std::vector<IInputDevice*> _devices;
        std::vector<InputAction*> _actions;
    
    public:
        Input(IInputDeviceFactory& deviceFactory);

        ~Input();

        void Update();

        void GetDevices(std::vector<IInputDevice*>& collection);

        void RegisterInputAction(InputActionBinding binding);

        void GetActions(std::vector<InputAction*>& collection);
        
        IInputDevice* GetDevice(const std::string& name);
        
        template <typename TDevice>
        TDevice* GetDevice();
    };

    template <typename TDevice>
    TDevice* Input::GetDevice()
    {
        for (int i = 0; i < _devices.size(); i++)
        {
            IInputDevice* device = _devices[i];

            TDevice* ptr = dynamic_cast<TDevice*>(device);

            if (ptr != nullptr)
                return ptr;
        }

        return nullptr;
    }
}
