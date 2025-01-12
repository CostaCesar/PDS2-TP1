#pragma once

#include "Board.hpp"

class Liga4 : public Board {
private:

bool game_over;
uint current_player;
void SwitchPlayer();

public:

Liga4(uint rows, uint cols); 

    bool MakeMove(uint column);
    uint GetWinner() override;
    bool IsDraw() override;
    bool CheckWin(uint player_ID);
    uint Play() override;

};