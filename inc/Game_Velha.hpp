#pragma once

#include "Board.hpp"

class Game_Velha : public Board
{
private:
    uint GetWinner() override;
    bool IsDraw() override;
    bool AddPiece(Piece* new_piece);
    
    bool CheckForWin();

public:
    uint Play() override;
    Game_Velha();
};

