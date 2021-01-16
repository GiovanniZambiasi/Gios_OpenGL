#pragma once
#include "../Debug.h"

namespace Gio::Utilities
{
    template <class T>
    class Singleton
    {
    public:
        Singleton<T>()
        {
            if (instance != nullptr)
            {
                Debug::LogError("New instance of Singleton has been created");
            }
            else
                instance = (T*)this;
        }

        ~Singleton<T>()
        {
            if (instance == (T*)this)
            {
                instance = nullptr;
            }
        }

        inline static T* instance;
    };
}
