#pragma once

#include "Register.hpp"
#include <string>

using std::string;


void checkWinner (string j1, string j2, int vencedor, int jogo);
void checkWinner (string j1, int vencedor, int jogo);
int validGame (char game);
int validPlayers (string j1, string j2);

void playReversi (string j1, string j2);
void playLiga4 (string j1, string j2);
void playVelha (string j1, string j2);
void playPuzzle (string j1);
void playInfinity (string j1, string j2);