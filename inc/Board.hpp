#pragma once

#include "Defs.hpp"
#include "Vec.hpp"
#include "Piece.hpp"
#include "Direction.hpp"

#include <vector>

using std::vector;
class Board
{
private:
    Vec2 board_size;
    vector<Piece*> board;

    uint Vec2ToIndex(Vec2 position);
    Vec2 IndexToVec2(uint index);

protected:
    Vec2 PosFromDirec(Vec2 pos, Direction direc);
    bool IsInsideBoard(Vec2 position);
    Piece* GetPiece(Vec2 position);
    uint MatchUntilStep(Vec2 position, Direction direction, uint steps);
    
    virtual bool HandleOverlap_Move(Vec2 position, Vec2 new_position);
    virtual bool HandleOverlap_Add(Vec2 position, Piece* new_piece);

public:
    Vec2 GetSize();

    virtual void Draw();
    virtual bool MovePiece(Vec2 position, Vec2 new_position);
    virtual bool AddPiece(Piece* piece_ptr);
    virtual bool DeletePiece(Vec2 position);
    
    virtual uint GetWinner() = 0;
    virtual bool IsDraw() = 0;
    virtual uint Play() = 0;

    Board();
    Board(Vec2 _size);
    virtual ~Board();
};