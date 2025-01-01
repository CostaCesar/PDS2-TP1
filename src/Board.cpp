#include "Board.hpp"
#include <iostream>

Piece* Board::GetPiece(Vec2 position)
{
    if(IsInsideBoard(position) == false)
        return nullptr;

    return this->board[position.x][position.y];
}
bool Board::HandleOverlap_Move(Vec2 position, Vec2 new_position)
{
    return false;
}
bool Board::HandleOverlap_Add(Vec2 position, Vec2 new_position)
{
    return false;
}
bool Board::MovePiece(Vec2 position, Vec2 new_position)
{
    if(IsInsideBoard(position) == false)
        return false;
    if(IsInsideBoard(new_position) == false)
        return false;

    if(this->board[position.x][position.y] == NULL)
        return false;
    if(this->board[position.x][position.y] != NULL)
    {
        return HandleOverlap_Move(position, new_position);
    }
    else
    {
        this->board[new_position.x][new_position.y] = this->board[position.x][position.y];
        this->board[new_position.x][new_position.y]->SetPosition(new_position);
        this->board[position.x][position.y] = NULL;
    }
    return true;
}
bool Board::AddPiece(Piece* piece_ptr)
{
    if(piece_ptr == NULL)
        return false;

    Vec2 piece_position = piece_ptr->GetPosition();
    if(IsInsideBoard(piece_position) == false)
        return false;
    
    if(this->board[piece_position.x][piece_position.y] != NULL)
        return false;

    this->board[piece_position.x][piece_position.y] = piece_ptr;
    return true;
}
bool Board::DeletePiece(Vec2 position)
{
    if(IsInsideBoard(position) == false)
        return false;

    if(this->board[position.x][position.y] == nullptr)
        return false;

    delete this->board[position.x][position.y];
    this->board[position.x][position.y] = nullptr;

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
            if(this->board[j][i] == nullptr)
                cout << " ";
            else cout << this->board[j][i]->GetPlayerId();
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
Vec2 Board::GetSize()
{
    return this->board_size;
}
Board::Board()
{
    this->board_size = Vec2{0, 0};
    this->board = vector<vector<Piece*>>();
}
Board::Board(Vec2 _size)
{
    this->board_size = _size;
    this->board = vector<vector<Piece*>>(_size.x, vector<Piece*>(_size.y, nullptr));
}
Board::~Board()
{
    for (uint i = 0; i < this->GetSize().x; i++){
        for (uint j = 0; j < this->GetSize().y; j++){
        
            if(this->board[i][j] != nullptr)
                delete this->board[i][j];
    }
    }
    this->board.clear();
}