#pragma once

namespace Gio
{
    class Time
    {
    private:
        static double _startTimeMs;
        static double _lastFrameTimeMs;
        static double _currentFrameTimeMs;
        
        Time();

        ~Time();

    public:
        static double GetTimeSinceStartSeconds();

        static float GetDeltaTimeSeconds();

        static void RecordFrameTime();

        static int GetFPSApprox();
    };
}
