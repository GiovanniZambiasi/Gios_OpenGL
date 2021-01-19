#pragma once
#include <vector>

#include "IInputElement.h"
#include "InputActionBinding.h"

namespace Gio::Input
{
    class InputAxis
    {
    private:
        std::string _name;
        std::vector<IInputElement*> _positiveContributors;
        std::vector<IInputElement*> _negativeContributors;
        float _value;
    
    public:
        InputAxis(const std::string& name, std::vector<IInputElement*> positiveContributors,
                  std::vector<IInputElement*> negativeContributors);

        ~InputAxis();

        std::string GetName() const { return _name; }

        float GetValue() const { return _value; }

        void Update();

        void GetPositiveContributors(std::vector<IInputElement*>& collection);
        
        void GetNegativeContributors(std::vector<IInputElement*>& collection);
    };
}
