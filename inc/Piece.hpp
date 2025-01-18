#pragma once

#include "Vec.hpp"

class Piece
{
private:
    uint player_id;
    Vec2 position;
    char symbol;

public:
    Vec2 GetPosition();
    void SetPosition(Vec2 new_position);
    uint GetPlayerId();
    void SetPlayerId(uint new_id);
    char GetSymbol();
    void SetSymbol(char new_symbol);

    Piece();
    Piece(Vec2 _position, uint _player_id = 0, char _symbol = '\0');
};