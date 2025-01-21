#pragma once

#include "Register.cpp"
#include "Game_Reversi.hpp"
#include "Liga4.hpp"
#include "Velha.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


int validPlayers(string j1, string j2) {
    if (!playerExists(NOME_ARQ, j1) || !playerExists(NOME_ARQ, j2)) {
        return 1;
    }
    
    return 0;
}

void jogoReversi(string j1, string j2) {
    std::cout << "que deus me acuda" << std::endl;
}

void jogoLig4(string j1, string j2) {
    std::cout << "que deus me acuda" << std::endl;
}

void jogoVelha(string j1, string j2) {
    JogoDaVelha::Play();
}