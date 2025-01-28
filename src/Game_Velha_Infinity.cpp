#include "Game_Velha_Infinity.hpp"

#include <iostream>
#include <list>

uint Game_Velha_Infinity::Play(std::string player1, std::string player2)
{
    using std::cout;
    using std::endl;

    this->num_plays = 0;

    Vec2 move;
    std::list<Vec2> last_moves[2];

    while (!IsDraw())
    {
        Draw();
        cout << "\nTurno de " << (current_player == 1 ? player1 : player2) << " <X Y>:" << endl;
        
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

        last_moves[this->current_player-1].push_back(move);
        if(last_moves[this->current_player-1].size()>3){
            DeletePiece(last_moves[this->current_player-1].front());
            last_moves[this->current_player-1].pop_front();
        }

        ResetScreen();

        if(CheckForWin(move)) break;
        this->num_plays+=1;
        NextPlayer();
    }

    Draw();
    return GetWinner();
}

Game_Velha_Infinity::Game_Velha_Infinity()
    : Game_Velha()
{

}