#include "Random.h"

#include <ctime>
#include <stdlib.h>

#include "Math.h"

unsigned int Gio::Random::_seed = 0;
bool Gio::Random::_initialized = false;

float Gio::Random::Scalar()
{
    if(!_initialized)
    {
        _initialized = true;
        SetSeed(time(NULL));
    }
    
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

float Gio::Random::Between(float min, float max)
{
    return Math::Lerp(min, max, Scalar());
}

int Gio::Random::Between(int min, int max)
{
    return Math::RoundToInt(Math::Lerp(min, max, Scalar()));
}

void Gio::Random::SetSeed(unsigned int seed)
{
    _seed = seed;
    srand(_seed);
}

Gio::Color Gio::Random::Color()
{
    return Gio::Color(Scalar(), Scalar(), Scalar(), 1.0f);
}
