#include "ActionManager.h"

#include "../Debug.h"

Gio::InputSystem::ActionManager::ActionManager(DeviceManager* deviceManager)
    : _deviceManager(deviceManager)
{
    LoadBindings();
}

Gio::InputSystem::ActionManager::~ActionManager()
{
}

void Gio::InputSystem::ActionManager::Update()
{
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

void Gio::InputSystem::ActionManager::RegisterInputAction(Actions::InputActionBinding binding)
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

void Gio::InputSystem::ActionManager::GetActions(std::vector<InputAction*>& collection)
{
    for (int i = 0; i < _actions.size(); i++)
    {
        auto action = _actions[i];
        collection.push_back(action);
    }
}

Gio::InputSystem::InputAction* Gio::InputSystem::ActionManager::GetAction(const std::string name)
{
    for (auto i = 0; i < _actions.size(); i++)
    {
        auto action = _actions[i];
        if (action->GetName() == name)
            return action;
    }

    return nullptr;
}

void Gio::InputSystem::ActionManager::RegisterInputAxis(Actions::InputAxisBindings binding)
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

void Gio::InputSystem::ActionManager::GetAxes(std::vector<InputAxis*>& collection)
{
    for (auto i = 0; i < _axes.size(); i++)
    {
        auto axis = _axes[i];
        collection.push_back(axis);
    }
}

Gio::InputSystem::InputAxis* Gio::InputSystem::ActionManager::GetAxis(const std::string name)
{
    for (auto i = 0; i < _axes.size(); i++)
    {
        auto axis = _axes[i];
        
        if(axis->GetName() == name)
            return axis;
    }

    return nullptr;
}

void Gio::InputSystem::ActionManager::SaveBindings()
{
    nlohmann::json j;
    j["Actions"] = _actionBindings;
    j["Axes"] = _axisBindings;

    std::fstream file = std::fstream("res/Input/Bindings.json");
    auto dump = j.dump();
    file.write(dump.c_str(), dump.length());
    file.close();
}

void Gio::InputSystem::ActionManager::LoadBindings()
{
    try
    {
        nlohmann::json j;
    
        std::fstream bindingsFile = std::fstream("res/Input/Bindings.json");
        bindingsFile >> j;

        auto actions = j["Actions"];
    
        _actionBindings = actions.get<std::vector<Actions::InputActionBinding>>();

        for (auto i = 0; i < _actionBindings.size(); i++)
        {
            auto binding = _actionBindings[i];
            RegisterInputAction(binding);
        }
    
        auto axes = j["Axes"];
        _axisBindings = axes.get<std::vector<Actions::InputAxisBindings>>();

        for (auto i = 0; i < _axisBindings.size(); i++)
        {
            auto binding = _axisBindings[i];
            RegisterInputAxis(binding);
        }
    }
    catch(std::exception e)
    {
        Debug::LogError("An exception was caught while loading input bindings: '" + std::string(e.what()) + "'");
    }
}

Gio::InputSystem::IInputElement* Gio::InputSystem::ActionManager::GetDeviceElement(Gio::InputSystem::DeviceElementPair pair)
{
    auto device = _deviceManager->GetDevice(pair.device);
    if (device == nullptr)
    {
        Debug::LogError("Couldn't find device '" + pair.device + "'");
        return nullptr;
    }

    auto element = device->GetElement(pair.element);
    if (element == nullptr)
    {
        Debug::LogError("Couldn't find element '" + pair.element + "' in device '" + pair.device + "'");
        return nullptr;
    }
    
    return element;
}

void Gio::InputSystem::ActionManager::GetDeviceElements(std::vector<DeviceElementPair> pairs, std::vector<IInputElement*>& collection)
{
    for (auto i = 0; i < pairs.size(); i++)
    {
        auto pair = pairs[i];

        IInputElement* element = GetDeviceElement(pair);
        
        if (element == nullptr) continue;

        collection.push_back(element);
    }
}
