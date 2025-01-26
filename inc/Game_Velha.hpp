#pragma once

#include "Board.hpp"

class Game_Velha : public Board
{
protected:
    uint GetWinner() override;
    bool IsDraw() override;
    bool AddPiece(Vec2 position, Piece* new_piece);
    
    bool CheckForWin(Vec2 pos);

public:
    virtual uint Play() override;
    Game_Velha();
};

