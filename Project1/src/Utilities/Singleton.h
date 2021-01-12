#pragma once

namespace Gio::Utilities
{
    template <class T> class Singleton
    {
    public:
        Singleton<T>();

        ~Singleton<T>();
    
        inline static T* instance = nullptr;
    };
}