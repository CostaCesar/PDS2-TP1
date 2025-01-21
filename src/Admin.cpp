#include "Admin.hpp"
#include "Register.hpp"
#include "Game_Reversi.hpp"
#include "Liga4.hpp"
#include "Velha.hpp"
#include <iostream>
#include <ostream>



int validPlayers (string j1, string j2) {
    if (!playerExists(j1) || !playerExists(j2)) {
        return 1;
    }
    
    return 0;
}

void jogoReversi (string j1, string j2) {
    std::cout << "que deus me acuda" << std::endl;
}

void jogoLig4 (string j1, string j2) {
    std::cout << "que deus me acuda" << std::endl;
}

void jogoVelha (string j1, string j2) {
}