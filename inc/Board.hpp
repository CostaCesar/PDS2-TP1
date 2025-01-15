#pragma once

#include "Defs.hpp"
#include "Vec.hpp"
#include "Piece.hpp"
#include "Direction.hpp"

#include <sstream>
#include <vector>

using std::vector;

enum class MatchReturn
{
    Limit = -2,
    Empty = -1,
    Neutral = 0,
    Opponent = 1,
    Matched = 2,
};
class Board
{
private:
    Vec2 board_size;
    vector<Piece*> board;

    uint Vec2ToIndex(Vec2 position);
    Vec2 IndexToVec2(uint index);

    std::istream* input;

protected:
    uint num_plays;
    uint current_player;

    uint GetOpponentId();
    virtual void NextPlayer();

    Vec2 PosFromDirec(Vec2 pos, Direction direc);
    bool IsInsideBoard(Vec2 position);
    Piece* GetPiece(Vec2 position);
    MatchReturn MatchUntilStep(Vec2 position, Direction direction, uint steps);
    
    virtual bool HandleOverlap_Move(Vec2 position, Vec2 new_position);
    virtual bool HandleOverlap_Add(Vec2 position, Piece* new_piece);
    
    uint GetCharFromInput();
    uint GetUintFromInput();
    virtual Vec2 ReadMove();
public:
    Vec2 GetSize();
    void AssignInput(std::istream* new_input);

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