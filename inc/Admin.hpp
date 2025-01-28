#pragma once

#include "Register.hpp"
#include <string>

using std::string;

/**
 * @fn validPlayers (string j1, string j2)
 * @brief Verifica se os jogadores (j1, j2) são jogadores validos.
 * 
 * @param j1 ID do jogador 1.
 * @param j2 ID do jogador 2.
 * @return int caso sejam validos 0, caso contrario 1.
 */
int validPlayers (string j1, string j2);


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

/**
 * @fn playVelha (string j1, string j2)
 * @brief Inicia uma partida de Reversi.
 * 
 * @param j1 ID do jogador 1.
 * @param j2 ID do jogador 2.
 */
void playVelha (string j1, string j2);