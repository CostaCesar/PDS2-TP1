#include "Game_Reversi.hpp"
#include <iostream>

bool Game_Reversi::March(Vec2 &position, uint direction)
{
    bool found_opponent = false;
    while (IsInsideBoard(position))
    {
        position = PosFromDirec(position, static_cast<Direction>(direction));

        // Checking for empty, end search if true
        if (GetPiece(position) == nullptr)
            break;
        if (GetPiece(position)->GetPlayerId() == 0)
            break;

        if (GetPiece(position)->GetPlayerId() == (this->current_player % 2) + 1)
        { // Oposing piece, continue searching
            found_opponent = true;
            continue;
        }
        // Same piece, end search
        else return (found_opponent == true);
    }
    return false;
}

uint Game_Reversi::Play()
{
    while (GetWinner() == 0)
    {
        if(IsDraw()) break;

        this->current_player = (this->current_player % 2) + 1;
        
        MarkAsPlayable();
        Draw();
        std::cout << "\n";

        Vec2 move;
        while (1)
        {
            std::cout << "Move for player " << this->current_player << " <X Y>: ";
            std::cout.flush();

            std::cin >> move.x >> move.y;
            Piece* play = new Piece(move, this->current_player);
            if(AddPiece(play) == true)
                break;
            else
            {
                std::cout << "Invalid Play! [" << move.x << "X " << move.y << "Y]"<< std::endl;
                delete play;
            }
        }
        this->num_plays--;
    }
    
    return GetWinner();
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
    // Must be a player move. Call Board::AddPiece() if you otherwise
    if(new_piece->GetPlayerId() == 1)
        new_piece->SetSymbol(k_player1);
    else if(new_piece->GetPlayerId() == 2)
        new_piece->SetSymbol(k_player2);
    else return false;

    // Check if is a valid Reversi move
    Piece* at_board = this->GetPiece(new_piece->GetPosition());
    if(at_board == nullptr)
        return false;
    else if (at_board->GetSymbol() != k_available)
        return false;

    DeletePiece(new_piece->GetPosition());
    Board::AddPiece(new_piece);

    if(this->current_player == 1)
        this->white_count++;
    else if(this->current_player == 2)
        this->black_count++;

    CalculateBorders(new_piece->GetPosition());
    CascadeMove(new_piece);
    return true;
}
void Game_Reversi::CascadeMove(Piece *start_piece)
{
    // Checking lines from the current tile
    // 0 = North -> 7 = North-West, Clockwise
    for (uint i = 0; i < 8; i++)
    {
        Vec2 i_pos = start_piece->GetPosition();
        if(March(i_pos, i) == true)
        {
            // Go in reverse direction and change pieces
            while (1)
            {
                i_pos = PosFromDirec(i_pos, static_cast<Direction>((i + 4) % 8));
                if(GetPiece(i_pos) == start_piece)
                    break;

                GetPiece(i_pos)->SetSymbol(start_piece->GetSymbol());
                GetPiece(i_pos)->SetPlayerId(start_piece->GetPlayerId());

                if(this->current_player == 1)
                    this->white_count++, this->black_count--;
                else if(this->current_player == 2)
                    this->black_count++, this->white_count--;   
            }
        }
    }
}

void Game_Reversi::CalculateBorders(Vec2 position)
{
    for(uint i = 0; i < 8; i++)
    {
        Vec2 i_pos = PosFromDirec(position, static_cast<Direction>(i));
        if(GetPiece(i_pos) == nullptr)
            border_tiles.insert(i_pos);
    }
    
    this->border_tiles.erase(position);
}

void Game_Reversi::MarkAsPlayable()
{
    for (auto &&pos : this->border_tiles)
    {
        bool valid = false;

        // Checking lines from the current tile
        // 0 = North -> 7 = North-West, Clockwise
        for(uint i = 0; i < 8; i++)
        {
            Vec2 i_pos = pos;
            if(March(i_pos, i) == true)
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
    Board::Draw();

    // Score
    std::cout << this->white_count << " " << this->k_player1;
    std::cout << " v.s "; 
    std::cout << this->black_count << " " << this->k_player2 << std::endl;
}

Game_Reversi::Game_Reversi(uint _num_plays)
:   Board(Vec2{8, 8}),
    border_tiles
    {   // Intial tiles for borders
        Vec2{2,2}, Vec2{2,3}, Vec2{2,4}, Vec2{2,5},
        Vec2{3,2}, Vec2{3,5}, Vec2{4,2}, Vec2{4,5},
        Vec2{5,2}, Vec2{5,3}, Vec2{5,4}, Vec2{5,5}
    }
{
    // White Pieces
    Board::AddPiece(new Piece(Vec2{3,3}, 1, k_player1));
    Board::AddPiece(new Piece(Vec2{4,4}, 1, k_player1));

    // Black Pieces
    Board::AddPiece(new Piece(Vec2{3,4}, 2, k_player2));
    Board::AddPiece(new Piece(Vec2{4,3}, 2, k_player2));

    this->black_count = this->white_count = 2;
    this->num_plays = _num_plays * 2;
    this->current_player = 1;
}
Game_Reversi::~Game_Reversi()
{

}