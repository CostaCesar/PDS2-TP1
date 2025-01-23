#include "Piece.hpp"

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
Piece::Piece() : Piece(0, ' ')
{

}
Piece::Piece(uint _player_id, char _symbol)
{
    if(_symbol != '\0')
        this->symbol = _symbol;
    else this->symbol = static_cast<char>((_player_id % 10) + '0');

    this->player_id = _player_id;
}
