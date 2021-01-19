#pragma once

#include <vector>
#include "IInputDevice.h"
#include "IInputDeviceFactory.h"
#include "InputAction.h"
#include "InputActionBinding.h"
#include "InputAxis.h"
#include "InputAxisBindings.h"
#include "../Utilities/Singleton.h"

namespace Gio::Input
{
    class Input : public Utilities::Singleton<Input>
    {
    private:
        std::vector<IInputDevice*> _devices;
        std::vector<InputAction*> _actions;
        std::vector<InputAxis*> _axes;
    
    public:
        Input(IInputDeviceFactory& deviceFactory);

        ~Input();

        void Update();

        void GetDevices(std::vector<IInputDevice*>& collection);

        IInputDevice* GetDevice(const std::string& name);
        
        void RegisterInputAction(InputActionBinding binding);

        void GetActions(std::vector<InputAction*>& collection);

        InputAction* GetAction(const std::string name);

        void RegisterInputAxis(InputAxisBindings binding);

        void GetAxes(std::vector<InputAxis*>& collection);

        InputAxis* GetAxis(const std::string name);

        template <typename TDevice>
        TDevice* GetDevice();
    
    private:
        void GetDeviceElements(std::vector<DeviceElementPair> pairs, std::vector<IInputElement*>& collection);    
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
