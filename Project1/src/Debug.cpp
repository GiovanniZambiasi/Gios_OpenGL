#include "Debug.h"
#include<iostream>
#include <string>

#include "Debug/LoggerFactory.h"

namespace Gio
{
    void Debug::LogWarning(std::string message)
    {
        try
        {
            if(_logger == nullptr)
                CreateLogger();
            
            _logger->LogWarning(message);
        }
        catch (std::invalid_argument e)
        {
            std::cout << "Logger exception " << e.what() << std::endl;
        }
    }

    void Debug::Log(std::string message)
    {
        try
        {
            if(_logger == nullptr)
                CreateLogger();
            
            _logger->Log(message);
        }
        catch (std::invalid_argument e)
        {
            std::cout << "Logger exception " << e.what() << std::endl;
        }
    }

    void Debug::LogError(std::string message)
    {
        try
        {
            if(_logger == nullptr)
                CreateLogger();
            
            _logger->LogError(message);
        }
        catch (std::invalid_argument e)
        {
            std::cout << "Logger exception " << e.what() << std::endl;
        }
    }

    void Debug::CreateLogger()
    {
        _logger = Debugging::LoggerFactory::CreateLogger();
    }
}
