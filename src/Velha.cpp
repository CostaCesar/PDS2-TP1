#include "Vec.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include "Velha.hpp"
#include <iostream>
#include <vector>

uint JogoDaVelha::GetWinner(Vec2 pos){
    for (int i=0; i<8; i++){
        if (this->MatchUntilStep(pos, (Direction) i , 3) == (MatchReturn) 2){
            return this->GetPiece(pos)->GetPlayerId();
        }
    }
};

void JogoDaVelha::JogarVelha(uint id1 , uint id2){

    using namespace std;

    Vec2 jogada;
    uint vencedor = 0;
    for (int i=0;i<4;i++){

        while(1){
            cout << "Jogada do jogador" << id1 << ":";
            cin >> jogada.x >> jogada.y;
            if (this->GetPiece(jogada) == nullptr) {
                this->GetPiece(jogada)->SetPlayerId(id1);
                break;
                }
            else cout << "Jogada invalida" << endl;
        }

        this->Draw();

        if(i>1) vencedor = GetWinner(jogada);
        if(i>3 || vencedor != 0) break;

        while(1){
            cout << "Jogada do jogador" << id2 << ":";
            cin >> jogada.x >> jogada.y;
            if (this->GetPiece(jogada) == nullptr) {
                this->GetPiece(jogada)->SetPlayerId(id2);
                break;
                }
            else cout << "Jogada invalida" << endl;
        }

        this->Draw();
        
        if(i>1) vencedor = GetWinner(jogada);
        if(vencedor != 0) break;

    };
    if (vencedor != 0) cout << "O vencedor eh: " << vencedor << endl;
    else cout << "Foi um empate" << endl;
};