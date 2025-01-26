#include "Game_Velha_Infinity.hpp"

#include <iostream>
#include <list>

uint Game_Velha::Play()
{
    using std::cout;
    using std::endl;

    Vec2 move;
    std::list<Vec2> last_moves[2];

    while (!IsDraw())
    {
        Draw();
        cout << "Jogada do jogador " << this->current_player << " <X Y>:" << endl;
        
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
        last_moves[this->current_player-1].push_back(move);
        if(last_moves[this->current_player-1].size()>3){
            DeletePiece(last_moves[this->current_player-1].front());
            last_moves[this->current_player-1].pop_front();
        }
        if(CheckForWin()) break;
        NextPlayer();
    }

    Draw();
    return GetWinner();
}

Game_Velha_Infinity::Game_Velha_Infinity()
    : Game_Velha_Infinity()
{

}