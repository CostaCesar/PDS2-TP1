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

bool Game_Velha::CheckForWin(Vec2 pos)
{
    Vec2 verification_origin = pos;

    if(verification_origin.x == verification_origin.y or verification_origin == Vec2{0, GetSize().y - 1} or verification_origin == Vec2{GetSize().x - 1, 0}){
        // Diagonal check
        if(MatchUntilStep(Vec2{0, 0}, Direction::SouthEast, GetSize().x - 1) == MatchReturn::Matched)
            return true;
        else if(MatchUntilStep(Vec2{0, GetSize().y - 1}, Direction::NorthEast, GetSize().x - 1) == MatchReturn::Matched)
            return true;
    }

    verification_origin.y = 0;
    // Vertical check
    if(MatchUntilStep(verification_origin, Direction::South, GetSize().y - 1) == MatchReturn::Matched)
        return true;
    verification_origin = pos;

    verification_origin.x = 0;
    // Horizontal check
    if(MatchUntilStep(verification_origin, Direction::East, GetSize().x - 1) == MatchReturn::Matched)
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

uint Game_Velha::Play(std::string player1, std::string player2)
{
    using std::cout;
    using std::endl;

    this->num_plays = 0;

    Vec2 move;

    while (!IsDraw())
    {
        cout << endl;
        Draw();
        cout << "\nTurno de " << (current_player == 1 ? player1 : player2) << " <X Y>: ";
        
        while(1)
        {
            try { move = ReadMove(); }
            catch(const std::exception& e)
            {
                cout << endl << "Entrada invalida" << endl;
                continue;
            }

            Piece* peca = new Piece(this->current_player);
            if (AddPiece(move, peca) == true) break;
            else
            {
                delete peca;
                cout << endl << "Jogada invalida" << endl;
            }
        }

        cout << endl;
        ResetScreen();

        if(CheckForWin(move)) break;
        
        this->num_plays++;
        NextPlayer();
    }

    cout << endl;
    Draw();
    return GetWinner();
}

Game_Velha::Game_Velha()
    : Board(Vec2{3, 3})
{

}