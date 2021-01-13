#include "GLFWPCInputDeviceFactory.h"
#include "../Devices/Keyboard.h"

Gio::Input::Factories::GLFWPCInputDeviceFactory::GLFWPCInputDeviceFactory(GLFWwindow* window)
    : _window(window)
{ }

Gio::Input::Factories::GLFWPCInputDeviceFactory::~GLFWPCInputDeviceFactory()
{ }

void Gio::Input::Factories::GLFWPCInputDeviceFactory::CreateDevices(std::vector<::Gio::Input::IInputDevice*>& collection)
{
    collection.push_back(new Devices::Keyboard(_window));
}