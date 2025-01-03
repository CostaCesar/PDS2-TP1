#include "Game_Reversi.hpp"
#include <iostream>

Vec2 PosFromDirec(Vec2 pos, uint direction)
{
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

uint Game_Reversi::Play()
{
    Draw();
    this->current_player = (this->current_player % 2) + 1;
    std::cout << "\n";
    Draw();
    return 0;
}
bool Game_Reversi::IsDraw()
{
    return (this->num_plays == 0 && this->white_count == this->black_count);
}
uint Game_Reversi::GetWinner()
{
    if(this->num_plays > 0 || IsDraw())
        return 0;
    else return (this->white_count > this->black_count ? 1 : 2);
}
bool Game_Reversi::AddPiece(Piece* new_piece)
{
    if(new_piece->GetPlayerId() == 1)
        new_piece->SetSymbol(k_player1);
    else if(new_piece->GetPlayerId() == 2)
        new_piece->SetSymbol(k_player2);
    else return false;

    Piece* at_board = this->GetPiece(new_piece->GetPosition());
    if(at_board == nullptr)
        return false;
    else if (at_board->GetSymbol() != k_available)
        return false;

    DeletePiece(new_piece->GetPosition());
    return Board::AddPiece(new_piece);
}
void Game_Reversi::CalculateBorders()
{
    auto border_end = this->border_tiles.end();

    for (auto &&pos : this->border_tiles)
    {
        // Filter empty tiles
        if(GetPiece(pos) == nullptr) continue;
        if(GetPiece(pos)->GetPlayerId() == 0) continue;

        // Checking adjacent tiles to the current tile
        // 0 = North -> 7 = North-West, Clockwise
        for(uint i = 0; i < 8; i++)
        {
            Vec2 i_pos = PosFromDirec(pos, i);

            if(GetPiece(i_pos) == nullptr)
                border_tiles.push_back(i_pos);
        }
    }

    for(auto i = this->border_tiles.begin(); i != border_end; i++)
    {
        if((GetPiece(*i) != nullptr) && GetPiece(*i)->GetPlayerId() != 0)
            i = border_tiles.erase(i);
    }
}
void Game_Reversi::MarkAsPlayable()
{
    for (auto &&pos : this->border_tiles)
    {
        bool valid;
        // Checking lines from the current tile
        // 0 = North -> 7 = North-West, Clockwise
        for(uint i = 0; i < 8; i++)
        {
            bool found_same = false;
            bool found_opponent = false;

            valid = false;
            Vec2 i_pos = pos;
            while (IsInsideBoard(i_pos))
            {
                i_pos = PosFromDirec(i_pos, i);

                // Checking for empty, end search if true
                if(GetPiece(i_pos) == nullptr)
                    break;
                if(GetPiece(i_pos)->GetPlayerId() == 0)
                    break;

                if(GetPiece(i_pos)->GetPlayerId() == (this->current_player % 2) + 1)
                { // Oposing piece, continue searching
                    found_opponent = true;
                    continue;
                }
                else
                { // Same piece, end search
                    found_same = true;
                    break;
                }
            }
            if(found_opponent == true && found_same == true)
            {
                valid = true;
                Piece* at_board = GetPiece(pos);
                if(at_board == nullptr)
                    Board::AddPiece(new Piece(pos, 0, k_available));
                else at_board->SetSymbol(k_available);
                break;
            }
        }

        // No valid orientation, reseting to empty
        if(!valid)
            DeletePiece(pos);
    }
}

void Game_Reversi::Draw()
{
    CalculateBorders();
    MarkAsPlayable();
    Board::Draw();
}

Game_Reversi::Game_Reversi(uint _num_plays)
: Board(Vec2{8, 8})
{
    // White Pieces
    Board::AddPiece(new Piece(Vec2{3,3}, 1, k_player1));
    Board::AddPiece(new Piece(Vec2{4,4}, 1, k_player1));

    // Black Pieces
    Board::AddPiece(new Piece(Vec2{3,4}, 2, k_player2));
    Board::AddPiece(new Piece(Vec2{4,3}, 2, k_player2));

    // Borders
    for(uint i = 2; i <= 5; i++)
    {
        for(uint j = 2; j <= 5; j++)
        {
            if(i == 2 || j == 2 || i == 5 || j == 5)
                this->border_tiles.push_back(Vec2{j, i});
        }
    }

    this->black_count = this->white_count = 2;
    this->num_plays = num_plays;
    this->current_player = 1;
}
Game_Reversi::~Game_Reversi()
{

}