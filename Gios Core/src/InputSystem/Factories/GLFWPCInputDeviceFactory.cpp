#include "GLFWPCInputDeviceFactory.h"
#include "../Devices/Keyboard.h"
#include "../Devices/Mouse.h"

Gio::InputSystem::Factories::GLFWPCInputDeviceFactory::GLFWPCInputDeviceFactory(GLFWwindow* window)
    : _window(window)
{ }

Gio::InputSystem::Factories::GLFWPCInputDeviceFactory::~GLFWPCInputDeviceFactory()
{ }

void Gio::InputSystem::Factories::GLFWPCInputDeviceFactory::CreateDevices(std::vector<::Gio::InputSystem::IInputDevice*>& collection)
{
    collection.push_back(new Devices::Keyboard(_window));
    collection.push_back(new Devices::Mouse(_window));
}