#pragma once

#include "Defs.hpp"
#include "Vec.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include <vector>

using std::vector;
class JogoDaVelha:public Board {

    public:

        uint GetWinner() override;
        bool IsDraw() override;

        JogoDaVelha():Board(Vec2{3,3}){};

        uint GetWinnerPos(Vec2 pos);
        uint Play() override;
};

