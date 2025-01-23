#include "Game_Velha.hpp"

#include <iostream>
#include <vector>



uint Game_Velha::GetWinnerPos(Vec2 pos){
    for (int i=0; i<8; i++){
        if (this->MatchUntilStep(pos, (Direction) i , 2) == MatchReturn::Matched){
            return this->GetPiece(pos)->GetPlayerId();
        }
    }
    return 0;
};

uint Game_Velha::GetWinner(){
    return 0;
};

bool Game_Velha::IsDraw(){
    return 0;
};

uint Game_Velha::Play(){

    using namespace std;
    uint id1 = 1;
    uint id2 = 2;
    Vec2 jogada;
    uint vencedor = 0;
    for (int i=0;i<4;i++){

        while(1){
            cout << "Jogada do jogador" << id1 << ":" << endl;
            try{
                jogada = ReadMove();
            }
            catch(const std::exception& e)
            {
                cout << "Entrada invalida" << endl;
                continue;
            }
            Piece* peca = this->GetPiece(jogada);
            peca = new Piece(jogada, id1 , 'X');
            if (AddPiece(peca)) {
                break;
                }
            
            else{
                delete peca;
                cout << "Jogada invalida" << endl;
            } 
        }

        this->Draw();

        if(i>=1) vencedor = GetWinnerPos(jogada);
        if(i>3 || vencedor != 0) break;

        while(1){
            cout << "Jogada do jogador" << id2 << ":" << endl;
            try{
                jogada = ReadMove();
            }
            catch(const std::exception& e)
            {
                cout << "Entrada invalida" << endl;
                continue;
            }
            Piece* peca = this->GetPiece(jogada);
            peca = new Piece(jogada, id2 , 'O');
            if (AddPiece(peca)) {
                break;
                }
            
            else{
                delete peca ;
                cout << "Jogada invalida" << endl;
            } 
        }

        this->Draw();
        
        if(i>=1) vencedor = GetWinnerPos(jogada);
        if(vencedor != 0) break;

    }
    return vencedor;
};