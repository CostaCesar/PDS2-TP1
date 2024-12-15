#include "Board.hpp"

uint Board::Vec2ToIndex(Vec2 position)
{
    return (position.y * this->board_size.x) + position.x;
}
bool Board::CheckPosition(Vec2 position)
{
    return (position.x < this->board_size.x) && (position.y < this->board_size.y);
}
bool Board::HandleOverlap(Vec2 position, Vec2 new_position)
{
    return false;
}
bool Board::MovePiece(Vec2 position, Vec2 new_position)
{
    if(CheckPosition(position) == false)
        return false;
    if(CheckPosition(new_position) == false)
        return false;

    if(this->board[Vec2ToIndex(position)] == NULL)
        return false;
    if(this->board[Vec2ToIndex(new_position)] != NULL)
    {
        return HandleOverlap(position, new_position);
    }
    else
    {
        this->board[Vec2ToIndex(new_position)] = this->board[Vec2ToIndex(position)];
        this->board[Vec2ToIndex(new_position)]->SetPosition(new_position);
        this->board[Vec2ToIndex(position)] = NULL;
    }
    return true;
}
bool Board::AddPiece(Piece* piece_ptr)
{
    if(piece_ptr == NULL)
        return false;

    Vec2 piece_position = piece_ptr->GetPosition();
    if(CheckPosition(piece_position) == false)
        return false;
    
    if(this->board[Vec2ToIndex(piece_position)] != NULL)
        return false;

    this->board[Vec2ToIndex(piece_position)] = piece_ptr;
    return true;
}
Board::Board()
{
    this->board_size = Vec2{0, 0};
    this->board = vector<Piece*>();
}
Board::Board(Vec2 _size)
{
    this->board_size = _size;
    this->board = vector<Piece*>(Vec2ToIndex(_size), nullptr);
}
Board::~Board()
{
    for (uint i = 0; i < this->board.size(); i++)
    {
        delete this->board[i];
    }
    this->board.clear();
}