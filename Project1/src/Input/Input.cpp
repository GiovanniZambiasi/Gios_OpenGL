#include "Input.h"

#include <fstream>


#include "IInputDeviceFactory.h"
#include "../Debug.h"

Gio::Input::Input::Input(IInputDeviceFactory& deviceFactory)
{
    deviceFactory.CreateDevices(_devices);

    LoadBindings();
}

Gio::Input::Input::~Input()
{
}

void Gio::Input::Input::Update()
{
    for (auto i = 0; i < _devices.size(); i++)
    {
        IInputDevice* device = _devices[i];
        device->Update();
    }

    for (auto i = 0; i < _actions.size(); i++)
    {
        auto action = _actions[i];
        action->Update();
    }

    for (auto i = 0; i < _axes.size(); i++)
    {
        auto axis = _axes[i];
        axis->Update();
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

    GetDeviceElements(binding.elements, elements);
    
    if (elements.size() == 0)
    {
        Debug::LogWarning("Input Action '" + binding.actionName + "' registered with no elements");
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

Gio::Input::InputAction* Gio::Input::Input::GetAction(const std::string name)
{
    for (auto i = 0; i < _actions.size(); i++)
    {
        auto action = _actions[i];
        if (action->GetName() == name)
            return action;
    }

    return nullptr;
}

void Gio::Input::Input::RegisterInputAxis(InputAxisBindings binding)
{
    std::vector<IInputElement*> positiveContributors;
    GetDeviceElements(binding.positiveContributors, positiveContributors);
    
    std::vector<IInputElement*> negativeContributors;
    GetDeviceElements(binding.negativeContributors, negativeContributors);
    
    if (positiveContributors.size() == 0 && negativeContributors.size() == 0)
    {
        Debug::LogWarning("Input Axis '" + binding.axisName + "' registered with no elements");
    }

    auto action = new InputAxis(binding.axisName, positiveContributors, negativeContributors);
    _axes.push_back(action);
}

void Gio::Input::Input::GetAxes(std::vector<InputAxis*>& collection)
{
    for (auto i = 0; i < _axes.size(); i++)
    {
        auto axis = _axes[i];
        collection.push_back(axis);
    }
}

Gio::Input::InputAxis* Gio::Input::Input::GetAxis(const std::string name)
{
    for (auto i = 0; i < _axes.size(); i++)
    {
        auto axis = _axes[i];
        
        if(axis->GetName() == name)
            return axis;
    }

    return nullptr;
}

Gio::Input::IInputDevice* Gio::Input::Input::GetDevice(const std::string& name)
{
    for (auto i = 0; i < _devices.size(); i++)
    {
        auto device = _devices[i];
        if (device->GetName() == name)
            return device;
    }
    return nullptr;
}

void Gio::Input::Input::GetDeviceElements(std::vector<DeviceElementPair> pairs, std::vector<IInputElement*>& collection)
{
    for (auto i = 0; i < pairs.size(); i++)
    {
        auto pair = pairs[i];

        auto device = GetDevice(pair.device);
        if (device == nullptr)
        {
            Debug::LogError("Couldn't find device '" + pair.device + "'");
            continue;
        }

        auto element = device->GetElement(pair.element);
        if (element == nullptr)
        {
            Debug::LogError("Couldn't find element '" + pair.element + "' in device '" + pair.device + "'");
            continue;
        }

        collection.push_back(element);
    }
}

void Gio::Input::Input::SaveBindings()
{
    nlohmann::json j;
    
    auto action  = InputActionBinding(
        "ColorChange",
        {
            DeviceElementPair("Keyboard", "Spacebar"),
        });
    
    auto bindings = InputAxisBindings();
    bindings.axisName ="MoveHorizontal";
    bindings.positiveContributors = {
        DeviceElementPair("Keyboard", "D"),
        DeviceElementPair("Keyboard", "Arrow Right"),
    };
    bindings.negativeContributors = {
        DeviceElementPair("Keyboard", "A"),
        DeviceElementPair("Keyboard", "Arrow Left"),
    };

    j["Actions"] = std::vector<InputActionBinding>{
        action
    };

    j["Axes"] = std::vector<InputAxisBindings>{
        bindings
    };
    
    std::fstream file = std::fstream("res/Input/Bindings.json");
    auto dump = j.dump();
    file.write(dump.c_str(), dump.length());
    file.close();
}

void Gio::Input::Input::LoadBindings()
{
    try
    {
        nlohmann::json j;
    
        std::fstream bindingsFile = std::fstream("res/Input/Bindings.json");
        bindingsFile >> j;

        auto actions = j["Actions"];
    
        std::vector<InputActionBinding> actionBindings;
        actionBindings = actions.get<std::vector<InputActionBinding>>();

        for (auto i = 0; i < actionBindings.size(); i++)
        {
            auto binding = actionBindings[i];
            RegisterInputAction(binding);
        }
    
        auto axes = j["Axes"];
        std::vector<InputAxisBindings> axisBindings;
        axisBindings = axes.get<std::vector<InputAxisBindings>>();

        for (auto i = 0; i < axisBindings.size(); i++)
        {
            auto binding = axisBindings[i];
            RegisterInputAxis(binding);
        }
    }
    catch(std::exception e)
    {
        Debug::LogError("An exception was caught while loading input bindings: '" + std::string(e.what()) + "'");
    }
}
