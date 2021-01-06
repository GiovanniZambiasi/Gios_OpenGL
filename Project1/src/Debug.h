#pragma once
#include<iostream>
#include <string>
#include <Windows.h>

namespace Gio
{
    class Debug
    {
    public:
        static void LogWarning(std::string message);
        
        static void Log(std::string message);
        
        static void LogError(std::string message);
    };
}