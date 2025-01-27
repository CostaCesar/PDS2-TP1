#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using
    std::ofstream,
    std::ifstream,
    std::string,
    std::stringstream,
    std::vector;

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
};


int playerExists (string nickname);

int registerPlayer (string nickname, string name);

int deletePlayer (string nickname);

void listPlayers (char sel);

void updateScore(string winnerNickname, string looserNickname, int jogo);
void updateScore(string nickname, int jogo)