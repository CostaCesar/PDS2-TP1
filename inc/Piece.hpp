#pragma once

#include "Vec.hpp"

class Piece
{
private:
    uint player_id;
    Vec2 position;
public:
    Vec2 GetPosition();
    void SetPosition(Vec2 new_position);
    uint GetPlayerId();
    void ChangePlayerId(uint new_id);

    Piece();
    Piece(Vec2 _position, uint _player_id = 0);
};