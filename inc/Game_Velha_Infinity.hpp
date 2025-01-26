#pragma once

#include "Game_Velha.hpp"

class Game_Velha_Infinity : public Game_Velha
{
public:
    uint Play() override;
    Game_Velha_Infinity();
};

