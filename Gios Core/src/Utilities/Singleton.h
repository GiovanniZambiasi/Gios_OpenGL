#pragma once

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
                delete this;
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
