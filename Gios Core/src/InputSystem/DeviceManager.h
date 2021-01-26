#pragma once
#include <vector>

#include "IInputDevice.h"
#include "IInputDeviceFactory.h"

namespace Gio::InputSystem
{
    class DeviceManager
    {
    private:
        std::vector<IInputDevice*> _devices;
    
    public:
        DeviceManager(IInputDeviceFactory& deviceFactory);

        ~DeviceManager();

        void Update();

        void GetDevices(std::vector<IInputDevice*>& collection);

        IInputDevice* GetDevice(const std::string& name);
        
        template <typename TDevice>
        TDevice* GetDevice();
    };

    template <typename TDevice>
    TDevice* DeviceManager::GetDevice()
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
