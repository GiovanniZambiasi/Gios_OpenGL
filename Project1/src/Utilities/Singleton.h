#pragma once

namespace Gio::Utilities
{
    template <class T> class Singleton
    {
    public:
        Singleton();

        ~Singleton();
    
        inline static T* instance = nullptr;
    };
}