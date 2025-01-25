#include "Admin.hpp"
#include "Register.hpp"
#include "Game_Reversi.hpp"
#include "Liga4.hpp"
#include "Velha.hpp"
#include <iostream>
#include <ostream>
#include <string>

/* 
=====

indice para seleção de jogos em funções correspondentes

1: Reversi
2: Liga4
3: Jogo da Velha

=====
*/

const int REVERSI_INDEX = 1;
const int LIGA4_INDEX = 2;
const int VELHA_INDEX = 3;


void checkWinner(std::string j1, std::string j2, int vencedor, int jogo) {
    switch(vencedor) {
        case 0:
            std::cout <<  std::endl << "EMPATE!" << std::endl << std:: endl;
            break;
        case 1:
            updateScore(j1, j2, jogo);
            std::cout <<  std::endl << j1 << "GANHOU!" << std::endl << std:: endl;
            break;
        case 2:
            updateScore(j2, j1, jogo);
            std::cout <<  std::endl << j2 << "GANHOU!" << std::endl << std:: endl;
            break;
    }
}

int validPlayers (std::string j1, std::string j2) {
    
    // se os dois jogadores existem, retorna 0
    if (!playerExists(j1) && !playerExists(j2)) {
        return 1;
    }
    
    return 0;
}

void playReversi (std::string j1, std::string j2) {
   int vencedor;
    
    Board* obj = new Game_Reversi();
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, REVERSI_INDEX);
}


void playLiga4 (std::string j1, std::string j2) {
    int vencedor;
    
    Board* obj = new Liga4(8,8);
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, LIGA4_INDEX);
}

void playVelha (string j1, string j2) {
    int vencedor;
    
    Board* obj = new JogoDaVelha();
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, VELHA_INDEX);
}