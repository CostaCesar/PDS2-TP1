#include "Admin.hpp"
#include "Register.hpp"
#include "Game_Reversi.hpp"
#include "Game_Liga4.hpp"
#include "Game_Velha.hpp"
#include "Game_Puzzle.hpp"

#include <iostream>
#include <string>
#include <vector>

using 
    std::cout;
    std::endl;
    std::string,
    std::vector;


void checkWinner (string j1, string j2, int vencedor, int jogo) {
    switch(vencedor) {
        case 0:
            cout <<  endl << " EMPATE!" << endl <<  endl;
            break;
        case 1:
            updateScore(j1, j2, jogo);
            cout <<  endl << j1 << " GANHOU!" << endl <<  endl;
            break;
        case 2:
            updateScore(j2, j1, jogo);
            cout <<  endl << j2 << " GANHOU!" << endl <<  endl;
            break;
    }
}

void checkWinner (string j1,  int vencedor, int jogo) {
    switch(vencedor) {
        case 0:
            cout <<  endl << "MAIS SORTE NA PRÓXIMA!" << endl <<  endl;
            break;
        case 1:
            updateScore(j1, j2, jogo);
            cout <<  endl << j1 << "GANHOU!" << endl <<  endl;
            break;
}

int validGame (char game) {
    char g;
    
    vector<char> games = {'R','L','V','P','I'}

    for (g : games) {
        if (g == game) {
            return 0;
        }
    }

    return 1;
}

int validPlayers (string j1, string j2) {
    
    // se os dois jogadores existem, retorna 0
    if (!playerExists(j1) && !playerExists(j2)) {
        return 1;
    }
    
    return 0;
}

void playReversi (string j1, string j2) {
   int vencedor;
    
    Board* obj = new Game_Reversi();
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, INDEX["REVERSI"]);
}


void playLiga4 (string j1, string j2) {
    int vencedor;
    
    Board* obj = new Game_Liga4(8,8);
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, INDEX["LIGA4"]);
}

void playVelha (string j1, string j2) {
    int vencedor;
    
    Board* obj = new Game_Velha();
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, INDEX["VELHA"]);
}

void playPuzzle (string j1) {
    int vencedor;

    Board* obj = new Game_Puzzle();
    vencedor = obj->Play();

    checkWinner(j1, vencedor,, INDEX["PUZZLE"])
}

void playInfinity (string j1, string j2) {
    int vencedor;
    
    Board* obj = new Game_Velha_Infinity();
    vencedor = obj->Play();

    checkWinner(j1, j2, vencedor, INDEX["INFINITY"]);
}