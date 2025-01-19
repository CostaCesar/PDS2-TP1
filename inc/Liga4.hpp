#pragma once

#include "Board.hpp"

class Liga4 : public Board {
private:
    uint EmptyRow(uint colummn);
    Vec2 ReadMove() override;
public:
    Liga4(uint rows, uint cols);
    ~Liga4();

    uint GetWinner() override;
    bool IsDraw() override;
    bool CheckWin(uint player_ID, const Vec2& last_move);
    uint Play() override;
};
