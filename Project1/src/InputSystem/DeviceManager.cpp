#include "DeviceManager.h"

Gio::InputSystem::DeviceManager::DeviceManager(IInputDeviceFactory& deviceFactory)
{
    deviceFactory.CreateDevices(_devices);
}

Gio::InputSystem::DeviceManager::~DeviceManager()
{
    for (auto i = 0; i < _devices.size(); i++)
    {
        auto device = _devices[i];
        delete device;
    }
}

void Gio::InputSystem::DeviceManager::Update()
{
    for (auto i = 0; i < _devices.size(); i++)
    {
        IInputDevice* device = _devices[i];
        device->Update();
    }
}

void Gio::InputSystem::DeviceManager::GetDevices(std::vector<IInputDevice*>& collection)
{
    for (int i = 0; i < _devices.size(); i++)
    {
        IInputDevice* device = _devices[i];

        collection.push_back(device);
    }
}

Gio::InputSystem::IInputDevice* Gio::InputSystem::DeviceManager::GetDevice(const std::string& name)
{
    for (auto i = 0; i < _devices.size(); i++)
    {
        auto device = _devices[i];
        if (device->GetName() == name)
            return device;
    }
    return nullptr;
}