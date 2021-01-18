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

    for (int i = 0; i < _actions.size(); i++)
    {
        auto action = _actions[i];
        action->Update();
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

void Gio::Input::Input::RegisterInputAction(InputActionBinding binding)
{
    std::vector<IInputElement*> elements;
    std::vector<DeviceElementPair> deviceElementPairs = binding.elements;
    
    for (int i = 0; i < deviceElementPairs.size(); i++)
    {
        auto pair = deviceElementPairs[i];
        
        auto device = GetDevice(pair.device);
        if(device == nullptr)
        {
            Debug::LogError("Couldn't find device '" + pair.device + "' for action '" + binding.actionName + "'");
            continue;
        }

        auto element = device->GetElement(pair.element);
        if(element == nullptr)
        {
            Debug::LogError("Couldn't find element '" + pair.element + "' in device '" + pair.device + "'");
            continue;
        }

        elements.push_back(element);
    }

    if(elements.size() == 0)
    {
        Debug::LogWarning("Input Action registered with no elements");
    }

    auto action = new InputAction(binding.actionName, elements);
    _actions.push_back(action);
}

void Gio::Input::Input::GetActions(std::vector<InputAction*>& collection)
{
    for (int i = 0; i < _actions.size(); i++)
    {
        auto action = _actions[i];
        collection.push_back(action);
    }
}

Gio::Input::IInputDevice* Gio::Input::Input::GetDevice(const std::string& name)
{
    for (int i = 0; i < _devices.size(); i++)
    {
        auto device = _devices[i];
        if(device->GetName() == name)
            return device;
    }
    return nullptr;
}
