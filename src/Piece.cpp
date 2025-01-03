#include "Piece.hpp"

Vec2 Piece::GetPosition()
{
    return this->position;
}
void Piece::SetPosition(Vec2 new_position)
{
    this->position = new_position;
}
uint Piece::GetPlayerId()
{
    return this->player_id;
}
Piece::Piece()
{
    this->position = Vec2{0, 0};
    this->player_id = 0;
}
Piece::Piece(Vec2 _position, uint _player_id)
{
    this->position = _position;
    this->player_id = _player_id;
}