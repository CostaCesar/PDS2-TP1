#include "Board.hpp"
#include <iostream>

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
void Board::Draw()
{
    using std::cout;
    using std::endl;
    uint current_piece = 0;

    for (uint i = 0; i < this->board_size.y; i++)
    {
        for (uint j = 0; j < this->board_size.x; j++)
        {
            cout << " ";
            if(this->board[Vec2ToIndex(Vec2{j, i})] == nullptr)
                cout << " ";
            else cout << this->board[Vec2ToIndex(Vec2{j, i})]->GetPlayerId();
            cout << " ";

            if(j < this->board_size.x - 1)
                cout << '|';
        }
        cout << endl;

        if(i < this->board_size.y - 1)
        {
            for (uint j = 0; j < (this->board_size.x * 3) + (this->board_size.x - 1); j++)
                cout << "=";
            cout << endl;
        }
    }
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