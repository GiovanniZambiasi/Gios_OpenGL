#pragma once
#include <fstream>

#include "../ILogger.h"

namespace Gio::Debugging::Loggers
{
    class ConsoleAndFileLogger : public ILogger
    {
    private:
        std::ofstream _logFile;
        
    public:
        ConsoleAndFileLogger();

        ~ConsoleAndFileLogger();
        
        void LogWarning(std::string message) override;
        void Log(std::string message) override;
        void LogError(std::string message) override;
    
    private:
        void PrintAndWrite(std::string message);

        void Print(std::string message);

        void WriteToFile(std::string message);

        void ClearFile();
    };
}