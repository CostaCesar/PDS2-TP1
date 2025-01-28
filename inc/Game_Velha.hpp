#pragma once

#include "Board.hpp"

/*! @file Game_Velha.hpp 
    @brief Estrutura do Jogo da Velha (Tic Tac Toe)
*/

/**
 * @class Game_Velha
 * @brief Classe que representa o jogo da velha, que herda de `Board`.
 */
class Game_Velha : public Board
{
protected:
/**
     * @brief Retorna o vencedor da partida.
     * 
     * @return uint ID do jogador vencedor.
     */
    uint GetWinner() override;

    /**
     * @brief Retorna se houve um empate na partida.
     * 
     * @return bool True para empate, caso contrario Falso.
     */
    bool IsDraw() override;

    /**
     * @brief Adiciona uma peça ao endereço de memoria dentro do tabuleiro.
     * 
     * @param position Coluna onde a peça será colocada.
     * @param new_piece Obejto "piece" a ser introduzido no endereço.
     * @return bool True caso a ação tenha sido efetuada, caso contrario Falso.
     */
    bool AddPiece(Vec2 position, Piece* new_piece);
    
    /**
     * @brief Verifica se houve um vencedor apartir de uma dada posição do tabuleiro (observando coluna, linha  e diagonal relativa).
     * 
     * @param pos Posição de origem de verificação.
     * @return bool True caso houve uma vitoria, caso contrario Falso.
     */
    bool CheckForWin(Vec2 pos);

public:
    /**
     * @brief Executa a partida de Jogo da Velha
     * 
     * @details O jogo consiste em, existem dois tipos de peças representando cada jogador "X" e "O", cada jogador pode colocar uma peça por vez no tabuleiro (3x3), vence quem conseguir completar uma linha ou uma coluna ou uma diagonal completa (de tamnho 3) com suas respéctivas peças.
     * Imprime um tabuleiro com as posições respectivas para cada jogada e admite uma entrada que representa a jogada de cada jogador alternando entre dois jogadores.
     * Quando o jogo acaba, seja pela vitoria de um jogador ou por empate, ele imprime a variavel que representa o resultado do jogo.
     * 
     * @return uint 1 ou 2 para a vitoria do jogador respectivo e 0 para empate.
     */
    virtual uint Play() override;

     /**
     * @brief Construtor da classe `Game_Velha`.
     * 
     */
    Game_Velha();
};

