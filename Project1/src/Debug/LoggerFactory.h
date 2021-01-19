#pragma once
#include "ILogger.h"
#include "Loggers/ConsoleAndFileLogger.h"

namespace Gio::Debugging
{
    class LoggerFactory
    {
    private:
        LoggerFactory();

        ~LoggerFactory();
    public:
        static ILogger* CreateLogger()
        {
            return new Loggers::ConsoleAndFileLogger();
        }
    };
}