#include "ConsoleAndFileLogger.h"

#include <fstream>
#include<iostream>
#include <string>
#include <Windows.h>

Gio::Debugging::Loggers::ConsoleAndFileLogger::ConsoleAndFileLogger()
{
    ClearFile();
}

Gio::Debugging::Loggers::ConsoleAndFileLogger::~ConsoleAndFileLogger()
{
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::ClearFile()
{
    _logFile.open("log.txt");

    if(_logFile.fail())
    {
        Print("Couldn't open log file");
        return;
    }
    
    _logFile.close();
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::PrintAndWrite(std::string message)
{
    Print(message);
    
    WriteToFile(message);
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::Print(std::string message)
{
    std::cout << message << std::endl;
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::WriteToFile(std::string message)
{
    _logFile.open("log.txt", std::ios_base::app);

    if(_logFile.fail())
    {
        Print("Couldn't open log file");
        return;
    }

    message = message + "\n";
    
    _logFile.write(message.c_str(), message.length());

    _logFile.close();
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::LogWarning(std::string message)
{
    HANDLE __handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(__handle, 14);

    PrintAndWrite("[Warning]: " + message);   
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::Log(std::string message)
{
    HANDLE __handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(__handle, 15);
    
    PrintAndWrite("[Log]: " + message);
}

void Gio::Debugging::Loggers::ConsoleAndFileLogger::LogError(std::string message)
{
    HANDLE __handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(__handle, 12);
    
    PrintAndWrite("[Error]: " + message);
}