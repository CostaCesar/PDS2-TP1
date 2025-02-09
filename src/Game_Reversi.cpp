#include "Game_Reversi.hpp"
#include <iostream>

#include <sstream>

uint Game_Reversi::Play(std::string player1, std::string player2)
{
    while (GetWinner() == 0)
    {
        if(IsDraw()) break;

        NextPlayer();
        
        // No valid plays, skip to next player
        if(MarkAsPlayable() == 0)
            continue;

        Draw();
        Vec2 move;
        while (1)
        {
            std::cout << "Turno de " << (current_player == 1 ? player1 : player2) << " <X Y>: ";
            
            try { move = ReadMove(); }
            catch(const std::exception& e)
            {
                std::cout << std::endl << "Entrada invalida!" << std::endl;
                continue;
            }
            
            Piece* play = new Piece(this->current_player);
            if(AddPiece(move, play) == true)
            {
                break;
            }
            else
            {
                std::cout << std::endl << "Jogada invalida [" << move.x << "X " << move.y << "Y]"<< std::endl;
                delete play;
            }
        }

        std::cout << std::endl;
        this->num_plays--;

        ResetScreen();
    }
    
    Draw();
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

bool Game_Reversi::AddPiece(Vec2 position, Piece* new_piece)
{
    // Must be a player move. Call Board::AddPiece() if you otherwise
    if(new_piece->GetPlayerId() == 1)
        new_piece->SetSymbol(k_player1);
    else if(new_piece->GetPlayerId() == 2)
        new_piece->SetSymbol(k_player2);
    else return false;

    // Check if is a valid Reversi move
    Piece* at_board = this->GetPiece(position);
    if(at_board == nullptr)
        return false;
    else if (at_board->GetSymbol() != k_available)
        return false;

    DeletePiece(position);
    Board::AddPiece(position, new_piece);

    if(this->current_player == 1)
        this->white_count++;
    else if(this->current_player == 2)
        this->black_count++;

    CalculateBorders(position);
    CascadeMove(position, new_piece);
    return true;
}

void Game_Reversi::CascadeMove(Vec2 position, Piece *start_piece)
{
    // Checking lines from the current tile
    // 0 = North -> 7 = North-West, Clockwise
    for (uint i = 0; i < 8; i++)
    {
        Vec2 i_pos = PosFromDirec(position, (Direction) i);
        // Check if it's adjacent to an opponent piece
        if(GetPiece(i_pos) == nullptr)
            continue;
        if(GetPiece(i_pos)->GetPlayerId() != GetOpponentId())
            continue;

        if(MatchUntilStep(i_pos, (Direction )i, 7) == MatchReturn::Opponent)
        {
            // Go in direction and change pieces
            while (1)
            {
                if(GetPiece(i_pos) == nullptr)
                    break;
                if(GetPiece(i_pos)->GetPlayerId() == this->current_player)
                    break;

                GetPiece(i_pos)->SetSymbol(start_piece->GetSymbol());
                GetPiece(i_pos)->SetPlayerId(start_piece->GetPlayerId());

                if(this->current_player == 1)
                    this->white_count++, this->black_count--;
                else if(this->current_player == 2)
                    this->black_count++, this->white_count--;
                       
                i_pos = PosFromDirec(i_pos, (Direction) i);
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

uint Game_Reversi::MarkAsPlayable()
{
    uint valid_plays = 0;
    for (auto &&pos : this->border_tiles)
    {
        bool valid = false;

        // Checking lines from the current tile
        // 0 = North -> 7 = North-West, Clockwise
        for(uint i = 0; i < 8; i++)
        {            
            Vec2 i_pos = PosFromDirec(pos, (Direction) i);
            
            
            if(GetPiece(i_pos) == nullptr)
                continue;
            if(GetPiece(i_pos)->GetPlayerId() != GetOpponentId())
                continue;

            // Search for opponent of this piece, a.k.a current player
            if(MatchUntilStep(i_pos, (Direction) i, 7) == MatchReturn::Opponent)
            {
                valid = true;
                valid_plays++;

                Piece* at_board = GetPiece(pos);
                if(at_board == nullptr)
                    Board::AddPiece(pos, new Piece(0, k_available));
                else at_board->SetSymbol(k_available);
                break;
            }
        }

        // No valid orientation, reseting to empty
        if(!valid)
            DeletePiece(pos);
    }
    return valid_plays;
}

void Game_Reversi::Draw()
{
    Board::Draw();

    // Score
    std::cout << this->white_count << " " << this->k_player1;
    std::cout << " v.s "; 
    std::cout << this->black_count << " " << this->k_player2 << std::endl;
}

Game_Reversi::Game_Reversi(uint _start_player)
:   Board(Vec2{8, 8}, _start_player),
    border_tiles
    {   // Intial tiles for borders
        Vec2{2,2}, Vec2{2,3}, Vec2{2,4}, Vec2{2,5},
        Vec2{3,2},                       Vec2{4,2},
        Vec2{3,5},                       Vec2{4,5},
        Vec2{5,2}, Vec2{5,3}, Vec2{5,4}, Vec2{5,5}
    }
{
    // White Pieces
    Board::AddPiece(Vec2{3,3}, new Piece(1, k_player1));
    Board::AddPiece(Vec2{4,4}, new Piece(1, k_player1));

    // Black Pieces
    Board::AddPiece(Vec2{3,4}, new Piece(2, k_player2));
    Board::AddPiece(Vec2{4,3}, new Piece(2, k_player2));

    this->black_count = this->white_count = 2;
    this->num_plays = (GetSize().x * GetSize().y) - 4;
}
Game_Reversi::~Game_Reversi()
{

}