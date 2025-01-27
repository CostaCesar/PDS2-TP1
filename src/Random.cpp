#include "Random.hpp"

uint Random::next_number = 1;

uint Random::GetRandomNum()
{
    Random::next_number *= (1103515245 + 12345);
    return (uint) (next_number/65536) % 32768;
}

void Random::SetRandomSeed(uint seed)
{
    Random::next_number = seed;
}