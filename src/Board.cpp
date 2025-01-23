#include "Board.hpp"

#include <iostream>
#include <limits>

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
uint Board::GetCharFromInput()
{
    std::string buffer;

    *this->input >> buffer;
    
    char output = std::toupper(buffer[0]);
    output = std::max(output, 'A');
    output = std::min(output, 'Z');

    return output - 'A';    
}
uint Board::GetUintFromInput()
{
    std::string buffer;    
    uint output;

    try
    {
        (*this->input) >> buffer;
        output = std::stoi(buffer.c_str());
    }
    catch(const std::exception& e)
    { throw e; }

    return output;    
}
Vec2 Board::ReadMove()
{
    Vec2 output;

    try
    {
        output.x = GetUintFromInput();
        output.y = GetUintFromInput();
    }
    catch(const std::exception& e)
    {
        // Flush Bad Stream
        FlushInput();
        throw e;
    }

    return output;
}
void Board::FlushInput()
{
    this->input->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    if(!IsInsideBoard(position) || !IsInsideBoard(new_position))
        return false;
    else if(position == new_position)
        return true;
    if(GetPiece(position) == nullptr && GetPiece(new_position) == nullptr)
        return false;

    Piece* buffer = this->board[Vec2ToIndex(new_position)];
    if((buffer != nullptr) && HandleOverlap_Move(position, new_position) == false)
        return false;

    this->board[Vec2ToIndex(new_position)] = this->board[Vec2ToIndex(position)];
    this->board[Vec2ToIndex(position)] = buffer;

    return true;
}
bool Board::AddPiece(Vec2 position, Piece* piece_ptr)
{
    if(piece_ptr == nullptr)
        return false;

    if(IsInsideBoard(position) == false)
        return false;
    
    if(this->board[Vec2ToIndex(position)] != nullptr
    && HandleOverlap_Add(position, piece_ptr) == false)
    {
        return false;
    }

    this->board[Vec2ToIndex(position)] = piece_ptr;
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

    // X-axis positions
    cout << "   ";
    for (uint i = 0; i < this->board_size.x; i++)
    {
        cout << "| " << i << " ";
    }
    cout << "\n+++";
    for (uint i = 0; i < this->board_size.x; i++)
    {
        cout << "++++";
    }
    cout << endl;
    
    for (uint i = 0; i < this->board_size.y; i++)
    {
        // Y-axis positions
        cout << " " << i << " +";

        for (uint j = 0; j < this->board_size.x; j++)
        {
            // Actual Tiles
            cout << " ";
            if(this->board[Vec2ToIndex(Vec2{j, i})] == nullptr)
                cout << " ";
            else cout << this->board[Vec2ToIndex(Vec2{j, i})]->GetSymbol();
            cout << " ";

            // Vertical lines
            if(j < this->board_size.x - 1)
                cout << '|';
        }
        cout << endl;

        // Horizontal lines
        if(i < this->board_size.y - 1)
        {
            cout << "===+";
            for (uint j = 0; j < (this->board_size.x * 3) + (this->board_size.x - 1); j++)
                cout << "=";
            cout << endl;
        }
    }
}

// Returns:
// -2: Reached Board Limit
// -1: Reached Empty Position
//  0: Reached Non-Player Piece
//  1: Reached Opponent Piece
//  2: Matched all pieces
MatchReturn Board::MatchUntilStep(Vec2 position, Direction direction, uint steps)
{
    // Will not search if starting from empty pos
    if(GetPiece(position) == nullptr)
        return MatchReturn::Empty;

    uint base_id = GetPiece(position)->GetPlayerId();
    for(uint i = 0; i < steps; i ++)
    {
        position = PosFromDirec(position, direction);

        if (!IsInsideBoard(position))
            return MatchReturn::Limit;

        if (GetPiece(position) == nullptr)
            return MatchReturn::Empty;
            
        if (GetPiece(position)->GetPlayerId() == 0)
            return MatchReturn::Neutral;

        if (GetPiece(position)->GetPlayerId() != base_id)
            return MatchReturn::Opponent;
    }

    return MatchReturn::Matched;
}
Vec2 Board::GetSize()
{
    return this->board_size;
}
uint Board::GetOpponentId()
{
    return (this->current_player % 2) + 1;
}
void Board::NextPlayer()
{
    this->current_player = (this->current_player % 2) + 1;
}
void Board::AssignInput(std::istream* new_input)
{
    if(new_input != nullptr)
        this->input = new_input;
}
Board::Board() : Board(Vec2{0, 0})
{
    this->board = vector<Piece*>();
}
Board::Board(Vec2 _size, uint start_player)
{
    this->board_size = _size;
    this->board = vector<Piece*>(Vec2ToIndex(_size), nullptr);
    this->input = &std::cin;
    this->current_player = start_player;
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