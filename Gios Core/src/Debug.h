#pragma once
#include <string>
#include "Debug/ILogger.h"
#include "Debug/LoggerFactory.h"

namespace Gio
{
    class Debug
    {
    private:
        inline static Debugging::ILogger* _logger = nullptr;

    public:
        static void LogWarning(std::string message);
        
        static void Log(std::string message);
        
        static void LogError(std::string message);
    
    private:
        static void CreateLogger();
    };
}
