#pragma once
#include <vector>

#include "Observer.h"

namespace Gio::Utilities
{
    template<typename T0>
    class Subject
    {
    private:
        std::vector<Observer<T0>*> _observers;
    public:
        void AddObserver(Observer<T0>* observer);

        void RemoveObserver(Observer<T0>* observer);

        void Invoke(T0 arg);
    };

    template <typename T0>
    void Subject<T0>::AddObserver(Observer<T0>* observer)
    {
        _observers.push_back(observer);
    }

    template <typename T0>
    void Subject<T0>::RemoveObserver(Observer<T0>* observer)
    {
        for (auto i = 0; i < _observers.size(); i++)
        {
            auto obs = observer[i];

            if (obs == observer)
            {
                _observers.erase(_observers.begin() + i);
                break;
            }
        }
    }

    template <typename T0>
    void Subject<T0>::Invoke(T0 arg)
    {
        for (int i = _observers.size() - 1; i >= 0; i--)
        {
            auto obs = _observers[i];

            if (obs == nullptr)
                _observers.erase(_observers.begin() + i);
            else
                obs->Observe(arg);
        }
    }
}
