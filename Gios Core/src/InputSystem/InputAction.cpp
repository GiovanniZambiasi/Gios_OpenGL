#include "InputAction.h"

const float InputValueTolerance = .1f;

Gio::InputSystem::InputAction::InputAction(const std::string& name, std::vector<IInputElement*> elements)
    : _name(name)
    , _elements(std::vector<IInputElement*>(elements))
    , _isPressed(false)
    , _wasPressedThisFrame(false)
    , _wasReleasedThisFrame(false)
{
}

Gio::InputSystem::InputAction::~InputAction()
{
}

bool Gio::InputSystem::InputAction::AreAnyElementsPressed()
{
    for (unsigned int i = 0; i < _elements.size(); i++)
    {
        auto element = _elements[i];

        if (element->GetValue() > InputValueTolerance)
        {
            return true;
        }
    }

    return false;
}

void Gio::InputSystem::InputAction::Update()
{
    bool wasPressed = _isPressed;
    
    _isPressed = AreAnyElementsPressed();

    _wasPressedThisFrame = _isPressed && !wasPressed;
    _wasReleasedThisFrame = wasPressed && !_isPressed;
}

void Gio::InputSystem::InputAction::GetElements(std::vector<IInputElement*>& collection)
{
    for (int i = 0; i < _elements.size(); i++)
    {
        auto element = _elements[i];
        collection.push_back(element);
    }
}