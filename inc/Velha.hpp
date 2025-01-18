#pragma once

#include "Defs.hpp"
#include "Vec.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include <vector>

using std::vector;
class JogoDaVelha:public Board {
    
    public:

        uint GetWinner(Vec2 pos);
        bool IsDraw();

        JogoDaVelha():Board(Vec2{3,3}){};

        void JogarVelha(uint id1 , uint id2);
};

