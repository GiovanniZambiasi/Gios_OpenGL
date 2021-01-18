#pragma once
#include "../IInputDevice.h"

namespace Gio::Input::Devices
{
    class Device : public IInputDevice
    {
    protected:
        std::vector<IInputElement*> elements;

    public:
        Device()
        {
        }

        virtual ~Device();

        std::string GetName() override = 0;
        
        void Update() override;
        
        void GetElements(std::vector<IInputElement*>& elements) override;
        
        IInputElement* GetElement(const std::string& name) override;
    };
}