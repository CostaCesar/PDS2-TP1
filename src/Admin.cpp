#include "Admin.hpp"
#include "Register.hpp"
#include "Random.hpp"
#include "Game_Reversi.hpp"
#include "Game_Liga4.hpp"
#include "Game_Velha.hpp"
#include "Game_Puzzle.hpp"
#include "Game_Velha_Infinity.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>

using std::cout;
using std::string; 
using std::map;
using std::vector;

map<string, int> INDEX= {
    {"REVERSI", 1},
    {"LIGA4",2},
    {"VELHA",3},
    {"PUZZLE",4},
    {"INFINITY",5},
};

void printMenu() {
    cout << "digite uma das opçoes abaixo:" << std::endl;
    cout << std::endl << "Cadastrar jogador: CJ <Apelido> <Nome>" << std::endl;
    cout << "Remover jogador: RJ <Apelido>" << std::endl;
    cout << "Listar jogadores: LJ [A|N]" << std::endl;
    
    cout << "Executar partida: ";
    cout << "EP <Jogo: (R|L|V|P|I)> <Apelido Jogador 1> <Apelido Jogador 2>" << std::endl;
    
    cout << "Finalizar sistema: FS" << std::endl << std::endl;
}

void checkWinner (string j1, string j2, int vencedor, int jogo) {
    switch(vencedor) {
        case 0:
            cout << std::endl << " EMPATE!" << std::endl <<  std::endl;
            break;
        case 1:
            updateScore(j1, j2, jogo, NOME_ARQ);
            cout << std::endl << j1 << " GANHOU!" << std::endl <<  std::endl;
            break;
        case 2:
            updateScore(j2, j1, jogo, NOME_ARQ);
            cout << std::endl << j2 << " GANHOU!" << std::endl <<  std::endl;
            break;
    }
}

void checkWinner (string j1,  int vencedor, int jogo) {
    string admin = "admin";

    switch(vencedor) {
        case 0:
            updateScore(admin, j1, jogo, NOME_ARQ);
            cout << std::endl << "MAIS SORTE NA PRÓXIMA!" << std::endl <<  std::endl;
            break;
        case 1:
            updateScore(j1,admin, jogo, NOME_ARQ);
            cout << std::endl << j1 << " GANHOU!" << std::endl <<  std::endl;
            break;
    }
}

int validGame (char game) {
    vector<char> games = {'R','L','V','P','I'};

    auto it = std::find(games.begin(), games.end(), game);

    if (it == games.end()) {
        return 0;
    }

    return 1;
}

int validPlayers (string j1, string j2, string arquivo) {
    
    // se os dois jogadores existem, retorna 1
    if (playerExists(j1, arquivo) && playerExists(j2, arquivo)) {
        return 1;
    }
    
    return 0;
}

void playReversi (string j1, string j2) {
   int vencedor;
    
    Board* obj = new Game_Reversi();
    vencedor = obj->Play(j1, j2);

    checkWinner(j1, j2, vencedor, INDEX["REVERSI"]);
}


void playLiga4 (string j1, string j2) {
    int vencedor;
    
    Board* obj = new Game_Liga4(8,8);
    vencedor = obj->Play(j1, j2);

    checkWinner(j1, j2, vencedor, INDEX["LIGA4"]);
}

void playVelha (string j1, string j2) {
    int vencedor;
    
    Board* obj = new Game_Velha();
    vencedor = obj->Play(j1, j2);

    checkWinner(j1, j2, vencedor, INDEX["VELHA"]);
}

void playPuzzle (string j1) {
    int vencedor;

    Board* obj = new Game_Puzzle(500);
    vencedor = obj->Play(j1);

    checkWinner(j1, vencedor, INDEX["PUZZLE"]);
}

void playInfinity (string j1, string j2) {
    int vencedor;
    
    Board* obj = new Game_Velha_Infinity();
    vencedor = obj->Play(j1, j2);

    checkWinner(j1, j2, vencedor, INDEX["INFINITY"]);
}