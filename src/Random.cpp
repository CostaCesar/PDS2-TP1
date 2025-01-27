#include "Random.hpp"

uint Random::next_number = 1;

uint Random::GetRandomNum()
{
    next_number ^= (next_number << 21);
    next_number ^= (next_number >> 30);
    next_number ^= (next_number << 4);
    return next_number;
}

void Random::SetRandomSeed(uint seed)
{
    Random::next_number = seed;
}