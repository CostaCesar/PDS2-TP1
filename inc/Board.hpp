#pragma once

#include "Defs.hpp"
#include "Vec.hpp"
#include "Piece.hpp"
#include <vector>

using std::vector;

class Board
{
private:
    Vec2 board_size;
    vector<Piece*> board;

    uint Vec2ToIndex(Vec2 position);
    bool CheckPosition(Vec2 position);
    virtual bool HandleOverlap(Vec2 position, Vec2 new_position);
public:
    bool MovePiece(Vec2 position, Vec2 new_position);
    bool AddPiece(Piece* piece_ptr);

    virtual void Draw();

    Board();
    Board(Vec2 _size);
    ~Board();
};