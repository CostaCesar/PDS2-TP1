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
    string apelido;
    string nome;
    int vitoriasReversi;
    int vitoriasLIg4;
    int vitoriasVelha;
    int derrotasReversi;
    int derrotasLIg4;
    int derrotasVelha;
};


int playerExists (string nickname);

int registerPlayer (string nickname, string name);

int deletePlayer (string nickname);

void listPlayers (char sel);