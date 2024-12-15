#pragma once

#include "Vec.hpp"

class Piece
{
private:
    uint player_id;
    Vec2 position;
public:
    Vec2 GetPosition();
    Vec2 SetPosition(Vec2 new_position);

    Piece();
    Piece(Vec2 _position, uint _player_id = 0);
};