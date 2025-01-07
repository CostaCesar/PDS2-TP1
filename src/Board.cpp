#include "Board.hpp"
#include "Direction.hpp"

#include <iostream>

Vec2 Board::PosFromDirec(Vec2 pos, Direction direc)
{
    uint direction = static_cast<uint>(direc);

    if(direction <= 1 || direction == 7) // North
        pos.y -= 1;
    else if(direction >= 3 && direction <= 5) // South
        pos.y += 1;

    if(direction >= 1 && direction <= 3) // East
        pos.x += 1;
    else if(direction >= 5 && direction <= 7) // West
        pos.x -= 1;

    return pos;
}
uint Board::Vec2ToIndex(Vec2 position)
{
    return (position.y * this->board_size.x) + position.x;
}
Vec2 Board::IndexToVec2(uint index)
{
    return Vec2{
        index % this->board_size.x, 
        index / this->board_size.x
    };
}
bool Board::IsInsideBoard(Vec2 position)
{
    return (position.x < this->board_size.x) && (position.y < this->board_size.y);
}
Piece* Board::GetPiece(Vec2 position)
{
    if(IsInsideBoard(position) == false)
        return nullptr;

    return this->board[Vec2ToIndex(position)];
}
bool Board::HandleOverlap_Move(Vec2 position, Vec2 new_position)
{
    return false;
}
bool Board::HandleOverlap_Add(Vec2 position, Piece* new_piece)
{
    return false;
}
bool Board::MovePiece(Vec2 position, Vec2 new_position)
{
    if(IsInsideBoard(position) == false)
        return false;
    if(IsInsideBoard(new_position) == false)
        return false;

    if(this->board[Vec2ToIndex(position)] == NULL)
        return false;
    if(this->board[Vec2ToIndex(new_position)] != NULL)
    {
        return HandleOverlap_Move(position, new_position);
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
    if(IsInsideBoard(piece_position) == false)
        return false;
    
    if(this->board[Vec2ToIndex(piece_position)] != NULL)
        return HandleOverlap_Add(piece_position, piece_ptr);

    this->board[Vec2ToIndex(piece_position)] = piece_ptr;
    return true;
}
bool Board::DeletePiece(Vec2 position)
{
    if(IsInsideBoard(position) == false)
        return false;

    if(this->board[Vec2ToIndex(position)] == nullptr)
        return false;

    delete this->board[Vec2ToIndex(position)];
    this->board[Vec2ToIndex(position)] = nullptr;

    return true;
}
void Board::Draw()
{
    using std::cout;
    using std::endl;

    for (uint i = 0; i < this->board_size.y; i++)
    {
        for (uint j = 0; j < this->board_size.x; j++)
        {
            cout << " ";
            if(this->board[Vec2ToIndex(Vec2{j, i})] == nullptr)
                cout << " ";
            else cout << this->board[Vec2ToIndex(Vec2{j, i})]->GetSymbol();
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

// @return
// 0 - Reached Board Limit
// 1 - Reached Empty Position
// 2 - Reached Another Player Piece
// 3 - All Pieces Match
uint Board::MatchUntilStep(Vec2 position, Direction direction, uint steps)
{
    if(GetPiece(position) == nullptr)
        return 1;
    uint base_id = GetPiece(position)->GetPlayerId();

    for(uint i = 0; i < steps; i ++)
    {
        position = PosFromDirec(position, direction);
        if (!IsInsideBoard(position))
            return 0;

        // Checking for empty, end search if true
        if (GetPiece(position) == nullptr)
            return 1;

         // Oposing piece, end search
        if (GetPiece(position)->GetPlayerId() != base_id)
            return 2;
    }
    // Same piece, end search
    return 3;
}
Vec2 Board::GetSize()
{
    return this->board_size;
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
        if(this->board[i] != nullptr)
            delete this->board[i];
    }
    this->board.clear();
}