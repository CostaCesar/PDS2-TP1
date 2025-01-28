#pragma once

#include "Register.hpp"
#include <string>

using std::string;


void checkWinner (string j1, string j2, int vencedor, int jogo);
void checkWinner (string j1, int vencedor, int jogo);

int validGame (char game);
int validPlayers (string j1, string j2, string arquivo);


/**
 * @fn playReversi (string j1, string j2)
 * @brief Inicia uma partida de Reversi.
 * 
 * @param j1 ID do jogador 1.
 * @param j2 ID do jogador 2.
 */
void playReversi (string j1, string j2);

/**
 * @fn playLiga4 (string j1, string j2)
 * @brief Inicia uma partida de Reversi.
 * 
 * @param j1 ID do jogador 1.
 * @param j2 ID do jogador 2.
 */
void playLiga4 (string j1, string j2);
void playVelha (string j1, string j2);
void playPuzzle (string j1);
void playInfinity (string j1, string j2);
