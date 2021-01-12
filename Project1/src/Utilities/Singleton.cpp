#include "Singleton.h"

#include "../Debug.h"

template <class T>
Gio::Utilities::Singleton<T>::Singleton<T>()
{
    if(instance != nullptr)
    {
        Debug::LogError("New instance of Singleton has been created");
    }
    else
        instance = (T*)this;    
}

template <class T>
Gio::Utilities::Singleton<T>::~Singleton<T>()
{
    if(instance == (T*)this)
    {
        instance = nullptr;
    }
}