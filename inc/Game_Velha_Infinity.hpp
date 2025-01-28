#pragma once

#include "Game_Velha.hpp"

/**
 * @class Game_Liga4
 * @brief Classe que representa o jogo "Jogo da velha infinito", que herda de `Game_Velha`.
 */
class Game_Velha_Infinity : public Game_Velha
{
    
public:
     /**
     * @brief Executa a partida de Jogo da Velha infinito
     * 
     * Imprime um tabuleiro com as posições respectivas para cada jogada e admite uma entrada que representa a jogada de cada jogador alternando entre dois jogadores.
     * Quando o jogo acaba, seja pela vitoria de um jogador ou por empate, ele imprime a variavel que representa o resultado do jogo.
     * 
     * @return uint 1 ou 2 para a vitoria do jogador respectivo e 0 para empate.
     */
    uint Play() override;

    /**
     * @brief Construtor da classe `Game_Velha`.
     * 
     */
    Game_Velha_Infinity();
};

