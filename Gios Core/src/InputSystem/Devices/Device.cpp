#include "Device.h"

Gio::InputSystem::Devices::Device::~Device()
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        auto element = elements[i];
        
        delete element;
    }
}

void Gio::InputSystem::Devices::Device::Update()
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        auto element = elements[i];
        element->Update();
    }
}

void Gio::InputSystem::Devices::Device::GetElements(std::vector<IInputElement*>& elements)
{
    for (unsigned int i = 0; i < this->elements.size(); i++)
    {
        auto element = this->elements[i];
        elements.push_back(element);
    }
}

Gio::InputSystem::IInputElement* Gio::InputSystem::Devices::Device::GetElement(const std::string& name)
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        auto element = elements[i];
        
        if(element->GetName() == name)
            return element;
    }

    return nullptr;
}
