#include "InputAxis.h"

Gio::Input::InputAxis::InputAxis(const std::string& name,
    std::vector<IInputElement*> positiveContributors, std::vector<IInputElement*> negativeContributors)
    : _name(name)
    , _positiveContributors(std::vector<IInputElement*>(positiveContributors))
    , _negativeContributors(std::vector<IInputElement*>(negativeContributors))
    , _value(0.0f)
{
}

Gio::Input::InputAxis::~InputAxis()
{
}

void Gio::Input::InputAxis::Update()
{
    float value = 0.0f;

    for (int i = 0; i < _positiveContributors.size(); i++)
    {
        auto element = _positiveContributors[i];
        value += element->GetValue();
    }

    for (int i = 0; i < _negativeContributors.size(); i++)
    {
        auto element = _negativeContributors[i];
        value -= element->GetValue();
    }

    _value = value;
}

void Gio::Input::InputAxis::GetPositiveContributors(std::vector<IInputElement*>& collection)
{
    for (int i = 0; i < _positiveContributors.size(); i++)
    {
        auto element = _positiveContributors[i];
        collection.push_back(element);
    }
}

void Gio::Input::InputAxis::GetNegativeContributors(std::vector<IInputElement*>& collection)
{
    for (int i = 0; i < _negativeContributors.size(); i++)
    {
        auto element = _negativeContributors[i];
        collection.push_back(element);
    }
}
