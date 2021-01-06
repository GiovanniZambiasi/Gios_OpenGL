#include "Debug.h"
#include<iostream>
#include <string>
#include <Windows.h>

namespace Gio
{
	void Debug::LogWarning(std::string message)
    {
        HANDLE __handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(__handle, 14);
        std::cout << "[Warning]: " << message << std::endl;
    }

    void Debug::Log(std::string message)
    {
        HANDLE __handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(__handle, 15);
        std::cout << "[Log]: " << message << std::endl;
    }

    void Debug::LogError(std::string message)
    {
        HANDLE __handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(__handle, 12);
        std::cout << "[Error]: " << message << std::endl;
    }
}