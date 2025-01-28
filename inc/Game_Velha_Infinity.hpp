#pragma once

#include "Game_Velha.hpp"

/*! @file Game_Velha_Infinity.hpp 
    @brief Estrutura do Jogo da Velha Infinito
*/

/**
 * @class Game_Velha_Infinity
 * @brief Classe que representa o jogo "Jogo da velha infinito", que herda de `Game_Velha`.
 * 
 * @details É um jogo da velha que <FAVOR DESCREVA O QUE É>
 * 
 * @note Esse jogo é um extra adicionado no trabalho. Serve como exemplo de
 * como um jogo pode ser criado a partir de outro jogo completo
 */
class Game_Velha_Infinity : public Game_Velha
{
    
public:
     /**
     * @fn Play()
     * @brief Executa a partida de Jogo da Velha infinito
     * 
     * @details <FAVOR DESCREVA COMO SE JOGA>
     * Imprime um tabuleiro com as posições respectivas para cada jogada e admite uma entrada que representa a jogada de cada jogador alternando entre dois jogadores.
     * Quando o jogo acaba, seja pela vitoria de um jogador ou por empate, ele imprime a variavel que representa o resultado do jogo.
     * A diferença do jogo classico é que cada jogador pode ter até no maximo 3 peças no tabuleiro por vez, ou seja a cada 3 jogadas, a primeira peça é deletada.
     * 
     * @return uint 1 ou 2 para a vitoria do jogador respectivo e 0 para empate.
     */
    uint Play() override;

    /**
     * @fn Game_Velha_Infinity()
     * @brief Construtor da classe `Game_Velha_Infinity`.
     * @brief Construtor da classe `Game_Velha_Infinity`.
     * 
     */
    Game_Velha_Infinity();
};

