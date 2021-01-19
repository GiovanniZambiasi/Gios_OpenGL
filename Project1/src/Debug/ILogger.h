#pragma once
#include <string>

namespace Gio::Debugging
{
    class ILogger
    {
    public:
        virtual ~ILogger() = default;
        
        virtual void LogWarning(std::string message) = 0;
        virtual void Log(std::string message) = 0;
        virtual void LogError(std::string message) = 0;
    };
}