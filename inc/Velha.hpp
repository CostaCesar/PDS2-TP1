#pragma once

#include "Defs.hpp"
#include "Vec.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include <vector>

using std::vector;
class JogoDaVelha:public Board {
protected:

    bool IsInsideBoard(Vec2 position);
    Piece* GetPiece(Vec2 position);
    
    bool HandleOverlap_Move(Vec2 position, Vec2 new_position);
    bool HandleOverlap_Add(Vec2 position, Vec2 new_position);
    bool DeletePiece(Vec2 position);

public:

    bool AddPiece(Piece* piece_ptr);
    void Draw();

    uint GetWinner();
    bool IsDraw();

    JogoDaVelha():Board(Vec2{3,3}){};

    void JogarVelha(uint id1 , uint id2);
};

