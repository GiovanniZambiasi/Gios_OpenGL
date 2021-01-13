#pragma once

#include <vector>
#include "IInputDevice.h"
#include "IInputDeviceFactory.h"

namespace Gio::Input
{
    class Input /*: public Utilities::Singleton<Input>*/
    {
    private:
        std::vector<IInputDevice*> _devices;
    
    public:
        Input(IInputDeviceFactory& deviceFactory);
        
        ~Input();

        void Update();
        
        void GetDevices(std::vector<IInputDevice*>& collection);
    };
}
