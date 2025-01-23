#pragma once

#include "Board.hpp"

class Game_Puzzle : public Board
{
private:
    bool AddPiece(Vec2 position, Piece* new_piece);
    bool MovePiece(Vec2 position);

    bool IsDraw() override;
    uint GetWinner() override;
    Vec2 ReadMove() override;

public:
    uint Play() override;
    Game_Puzzle(uint complexity, Vec2 _size = Vec2{3, 3});
    ~Game_Puzzle();
};