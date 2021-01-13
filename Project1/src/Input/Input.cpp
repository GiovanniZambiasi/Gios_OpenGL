#include "Input.h"

#include "IInputDeviceFactory.h"

Gio::Input::Input::Input(IInputDeviceFactory& deviceFactory)
{
    deviceFactory.CreateDevices(_devices);
}

Gio::Input::Input::~Input()
{
}

void Gio::Input::Input::Update()
{
    for (int i = 0; i < _devices.size(); i++)
    {
        IInputDevice* device = _devices[i];
        device->Update();
    }
}

void Gio::Input::Input::GetDevices(std::vector<IInputDevice*>& collection)
{
    for (int i = 0; i < _devices.size(); i++)
    {
        IInputDevice* device = _devices[i];

        collection.push_back(device);
    }
}