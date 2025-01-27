#pragma once

#include "Defs.hpp"

class Random
{
private:
    static uint next_number;
public:
    // stdc implementaiton of rand() 
    static uint GetRandomNum();
    static void SetRandomSeed(uint seed);

    Random() = delete;
};
