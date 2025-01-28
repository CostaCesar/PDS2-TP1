#pragma once


#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;
using std::vector;

const string NOME_ARQ = "cadastro.csv";

struct Jogador {
    string nickname;
    string name;
    int vitoriasReversi;
    int derrotasReversi;
    int vitoriasLiga4;
    int derrotasLiga4;
    int vitoriasVelha;
    int derrotasVelha;
    int vitoriasPuzzle;
    int derrotasPuzzle;
    int vitoriasInfinity;
    int derrotasInfinity;
};


int playerExists (string nickname, string arquivo);

int registerPlayer (string nickname, string name, string arquivo);

int deletePlayer (string nickname, string arquivo);

void listPlayers (char sel, string arquivo);

void updateScore(string winnerNickname, string looserNickname, int jogo, string arquivo);