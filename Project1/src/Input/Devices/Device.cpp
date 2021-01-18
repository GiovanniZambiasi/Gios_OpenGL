#include "Device.h"

Gio::Input::Devices::Device::~Device()
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        auto element = elements[i];
        
        delete element;
    }
}

void Gio::Input::Devices::Device::Update()
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        auto element = elements[i];
        element->Update();
    }
}

void Gio::Input::Devices::Device::GetElements(std::vector<IInputElement*>& elements)
{
    for (unsigned int i = 0; i < this->elements.size(); i++)
    {
        auto element = this->elements[i];
        elements.push_back(element);
    }
}

Gio::Input::IInputElement* Gio::Input::Devices::Device::GetElement(const std::string& name)
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        auto element = elements[i];
        
        if(element->GetName() == name)
            return element;
    }

    return nullptr;
}
