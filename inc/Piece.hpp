#pragma once

#include "Defs.hpp"

class Piece
{
private:
    uint player_id;
    char symbol;

public:
    uint GetPlayerId();
    void SetPlayerId(uint new_id);
    char GetSymbol();
    void SetSymbol(char new_symbol);

    Piece();
    Piece(uint _player_id = 0, char _symbol = '\0');
};