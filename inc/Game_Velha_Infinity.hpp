#pragma once

#include "Game_Velha.hpp"

class Game_Velha_Infinity : public Game_Velha
{
private:
    uint GetWinner();
    bool IsDraw();
    bool AddPiece(Vec2 position, Piece* new_piece);

    bool CheckForWin();

public:
    uint Play() override;
    Game_Velha_Infinity();
};

