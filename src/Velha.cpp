#include "Vec.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include "Velha.hpp"
#include <iostream>
#include <vector>

uint JogoDaVelha::GetWinner(){
    for (uint i=0;i<3;i++){
        if (this->GetPiece(Vec2{0,i})==this->GetPiece(Vec2{1,i})&&this->GetPiece(Vec2{0,i})==this->GetPiece(Vec2{2,i}))
        {
            return this->GetPiece(Vec2{0,i})->GetPlayerId();
        }
        else if (this->GetPiece(Vec2{i,0})==this->GetPiece(Vec2{i,1})&&this->GetPiece(Vec2{i,0})==this->GetPiece(Vec2{i,2}))
        {
            return this->GetPiece(Vec2{i,0})->GetPlayerId();
        }
    };
    if (this->GetPiece(Vec2{0,0})==this->GetPiece(Vec2{1,1})&&this->GetPiece(Vec2{0,0})==this->GetPiece(Vec2{2,2})){
        return this->GetPiece(Vec2{0,0})->GetPlayerId();
    }
    else if(this->GetPiece(Vec2{0,2})==this->GetPiece(Vec2{1,1})&&this->GetPiece(Vec2{0,2})==this->GetPiece(Vec2{2,0})){
        return this->GetPiece(Vec2{0,2})->GetPlayerId();
    }
    else{
        return 0;
    }
}

void JogoDaVelha::JogarVelha(uint id1 , uint id2){

    using namespace std;

    Vec2 jogada;
    uint vencedor = 0;
    for (int i=0;i<4;i++){

        while(1){
            cout << "Jogada do jogador" << id1 << ":";
            cin >> jogada.x >> jogada.y;
            if (this->GetPiece(jogada)->GetPlayerId()!=0) {
                this->GetPiece(jogada)->ChangePlayerId(id1);
                break;
                }
            else cout << "Jogada invalida" << endl;
        }

        this->Draw();

        if(i>3) break;

        while(1){
            cout << "Jogada do jogador" << id2 << ":";
            cin >> jogada.x >> jogada.y;
            if (this->GetPiece(jogada)->GetPlayerId()!=0) {
                this->GetPiece(jogada)->ChangePlayerId(id2);
                break;
                }
            else cout << "Jogada invalida" << endl;
        }

        this->Draw();
        
    };
    if (vencedor != 0) cout << "O vencedor eh: " << vencedor << endl;
    else cout << "Foi um empate" << endl;
};