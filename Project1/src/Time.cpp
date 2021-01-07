#include <chrono>
#include "Time.h"
#include "Debug.h"

double GetCurrentTimeMs()
{
    using namespace std::chrono;

    auto ms =duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    
    return ms.count();
}

double Gio::Time::_startTimeMs = GetCurrentTimeMs(); 
double Gio::Time::_lastFrameTimeMs = _startTimeMs; 
double Gio::Time::_currentFrameTimeMs = _startTimeMs; 

Gio::Time::Time()
{
    Debug::Log("Time class created");
}

Gio::Time::~Time()
{
    Debug::Log("Time class destroyed");
}

double Gio::Time::GetTimeSinceStartSeconds()
{
   return (GetCurrentTimeMs() - _startTimeMs) / 1000;
}

float Gio::Time::GetDeltaTimeSeconds()
{
    return (_currentFrameTimeMs - _lastFrameTimeMs) / 1000;
}

void Gio::Time::RecordFrameTime()
{
    _lastFrameTimeMs = _currentFrameTimeMs;

    _currentFrameTimeMs = GetCurrentTimeMs();
}

int Gio::Time::GetFPSApprox()
{
    return 1/GetDeltaTimeSeconds();
}
