#include "Game_Velha.hpp"

#include <iostream>

bool Game_Velha::AddPiece(Vec2 position, Piece* new_piece)
{
    if(new_piece->GetPlayerId() == 1)
        new_piece->SetSymbol('X');
    else if(new_piece->GetPlayerId() == 2)
        new_piece->SetSymbol('O');

    return Board::AddPiece(position, new_piece);
}

bool Game_Velha::CheckForWin()
{
    for (uint i = 0; i < GetSize().x; i++)
    {
        // Vertical check
        if(MatchUntilStep(Vec2{i, 0}, Direction::South, GetSize().x - 1) == MatchReturn::Matched)
            return true;
        
        // Horizontal check
        if(MatchUntilStep(Vec2{0, i}, Direction::East, GetSize().x - 1) == MatchReturn::Matched)
            return true;
    }
    
    // Diagonal check
    if(MatchUntilStep(Vec2{0, 0}, Direction::SouthEast, GetSize().x - 1) == MatchReturn::Matched)
        return true;
    else if(MatchUntilStep(Vec2{0, GetSize().x - 1}, Direction::NorthEast, GetSize().x - 1) == MatchReturn::Matched)
        return true;

    return false;
}

uint Game_Velha::GetWinner()
{
    if(IsDraw() == true)
        return 0;
    else return current_player;
}

bool Game_Velha::IsDraw()
{
    return this->num_plays == GetSize().x * GetSize().y;
}

uint Game_Velha::Play()
{
    using std::cout;
    using std::endl;

    Vec2 move;

    while (!IsDraw())
    {
        Draw();
        cout << "Jogada do jogador" << this->current_player << " <X Y>:" << endl;
        
        while(1)
        {
            try { move = ReadMove(); }
            catch(const std::exception& e)
            {
                cout << "Entrada invalida" << endl;
                continue;
            }

            Piece* peca = new Piece(this->current_player);
            if (AddPiece(move, peca) == true) break;
            else
            {
                delete peca;
                cout << "Jogada invalida" << endl;
            }
        }

        if(CheckForWin()) break;

        NextPlayer();
    }

    Draw();
    return GetWinner();
}

Game_Velha::Game_Velha()
    : Board(Vec2{3, 3})
{

}