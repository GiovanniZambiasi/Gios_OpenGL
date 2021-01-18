#pragma once

namespace Gio
{
    class Random
    {
    private:
        Random();
        
        ~Random();

        static unsigned int _seed;
        static bool _initialized;
    
    public:
        static float Scalar();
        
        static float Between(float min, float max);
        
        static int Between(int min, int max);

        static void SetSeed(unsigned int seed);
    };
}
