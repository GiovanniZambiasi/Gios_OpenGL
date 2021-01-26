#include "Input.h"

#include <fstream>

Gio::Input::Input(InputSystem::IInputDeviceFactory& deviceFactory)
{
    _deviceManager = new InputSystem::DeviceManager(deviceFactory);

    _actionManager = new InputSystem::ActionManager(_deviceManager);
}

Gio::Input::~Input()
{
    delete _deviceManager;
    
    delete _actionManager;
}

void Gio::Input::Update()
{
    _deviceManager->Update();
    
    _actionManager->Update();
}