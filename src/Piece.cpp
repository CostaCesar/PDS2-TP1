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
void Piece::SetPlayerId(uint new_id)
{
    this->player_id = new_id;
}
char Piece::GetSymbol()
{
    return this->symbol;
}
void Piece::SetSymbol(char new_symbol)
{
    this->symbol = new_symbol;
}
Piece::Piece()
{
    this->position = Vec2{0, 0};
    this->player_id = 0;
}
Piece::Piece(Vec2 _position, uint _player_id, char _symbol)
{
    if(_symbol != '\0')
        this->symbol = _symbol;
    else this->symbol = static_cast<char>((_player_id % 10) + '0');

    this->position = _position;
    this->player_id = _player_id;
}