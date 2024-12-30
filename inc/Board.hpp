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


protected:
    uint Vec2ToIndex(Vec2 position);
    Vec2 IndexToVec2(uint index);
    bool IsInsideBoard(Vec2 position);
    Piece* GetPiece(Vec2 position);
    
    virtual bool HandleOverlap_Move(Vec2 position, Vec2 new_position);
    virtual bool HandleOverlap_Add(Vec2 position, Vec2 new_position);
    virtual bool DeletePiece(Vec2 position);

public:
    Vec2 GetSize();

    virtual bool MovePiece(Vec2 position, Vec2 new_position);
    virtual bool AddPiece(Piece* piece_ptr);
    virtual void Draw();

    virtual uint GetWinner() = 0;
    virtual bool IsDraw() = 0;

    Board();
    Board(Vec2 _size);
    virtual ~Board();
};