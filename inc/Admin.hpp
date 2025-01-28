#pragma once

#include "Register.hpp"
#include <string>

using std::string;

/*! @file Admin.hpp
    @brief Módulo para gerência de dados de jogadores.
    - ID dos jogos
        -# Reversi
        -# Liga4
        -# Jogo da Velha
        -# Puzzle
        -# Jogo da Velha Infinito

    @warning Ao implementar novos jogos, atente-se ao ID do jogo.
*/

/*!
    @fn checkWinner (string j1, string j2, int vencedor, int jogo);
    @brief Verifica o vencedor de uma partida e chama a função updateScore().
    @param j1 Apelido do jogador 1.
    @param j2 Apelido do jogador 2.
    @param vencedor
    -# Jogador 1 venceu
    -# Jogador 2 venceu
    -# Empate
    \sa updateScore()
 */
void checkWinner (string j1, string j2, int vencedor, int jogo);

/*!
    @fn checkWinner (string j1, int vencedor, int jogo);
    @brief Em jogos para um jogador, verifica se o jogador venceu e chama a função updateScore().
    @param j1 Apelido do jogador 1.
    @param vencedor
    -# Jogador 1 venceu
    -# N/A
    -# Empate
    @param jogo ID do jogo.
    \sa updateScore()
 */
void checkWinner (string j1, int vencedor, int jogo);

/*!
    @fn validGame (char game)
    @brief Verifica se letra passada na entrada padrão representa algum dos jogos disponíveis.
    @param game Letra que representa o jogo a ser verificado.
    @return Caso o jogo seja encontrado, retorna 1. Se não, retorna 0.
 */
int validGame (char game);

/*!
    @fn validPlayers (string j1, string j2, string arquivo)
    @brief Verifica se o apelido dos jogadores passado na entrada padrão existe no arquivo passado.
    @param j1 Apelido do jogador 1.
    @param j2 Apelido do jogador 2.
    @param arquivo Arquivo .csv com os dados dos jogadores.
    @return Caso os dois jogadores sejam encontrados, retorna 1. Se não, retorna 0.
 */
int validPlayers (string j1, string j2, string arquivo);


/*!
    @fn playReversi (string j1, string j2)
    @brief Inicia uma partida de Reversi.

    @param j1 Apelido do jogador 1.
    @param j2 Apelido do jogador 2.
 */
void playReversi (string j1, string j2);

/*!
    @fn playLiga4 (string j1, string j2)
    @brief Inicia uma partida de Liga4.

    @param j1 Apelido do jogador 1.
    @param j2 Apelido do jogador 2.
 */
void playLiga4 (string j1, string j2);

/*!
    @fn playLiga4 (string j1, string j2)
    @brief Inicia uma partida de Jogo da Velha.

    @param j1 Apelido do jogador 1.
    @param j2 Apelido do jogador 2.
 */
void playVelha (string j1, string j2);

/*!
    @fn playLiga4 (string j1, string j2)
    @brief Inicia uma partida de Puzzle.

    @param j1 Apelido do jogador 1.
 */
void playPuzzle (string j1);

/*!
    @fn playLiga4 (string j1, string j2)
    @brief Inicia uma partida de Jogo da Velha Infinito.

    @param j1 Apelido do jogador 1.
    @param j2 Apelido do jogador 2.
 */
void playInfinity (string j1, string j2);
