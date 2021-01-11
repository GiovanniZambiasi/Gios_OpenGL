﻿#include "Singleton.h"

#include "../Debug.h"

template <class T>
Gio::Utilities::Singleton<T>::Singleton()
{
    if(instance != nullptr)
    {
        Debug::LogError("New instance of Singleton has been created");
    }
    else
        instance = this;    
}

template <class T>
Gio::Utilities::Singleton<T>::~Singleton()
{
    if(instance == this)
    {
        instance = nullptr;
    }
}