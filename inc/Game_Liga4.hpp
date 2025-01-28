#pragma once

#include "Board.hpp"

/*! @file Game_Liga4.hpp 
    @brief Estrutura do Jogo Liga4 (Connect 4)
*/

/**
 * @class Game_Liga4
 * @brief Classe que representa o jogo "Conecta 4" (Liga 4), que herda de `Board`.
 */
class Game_Liga4 : public Board {
private:
    /**
     * @fn EmptyRow(uint column)
     * @brief Retorna a linha vazia mais próxima para uma coluna, 'gravidade'.
     * 
     * @param column Coluna onde a peça será colocada.
     * @return uint Primeira linha desocupada da coluna respectiva.
     */
    uint EmptyRow(uint column);

    /**
     * @fn ReadMove()
     * @brief Le a jogada.
     * 
     * @details A jogada é feita atravez da coluan em que a peça deve ser posicionada, com a linha sendo determinada via gravidade. 
     * 
     * @return Coordenada da jogada.
     */
    Vec2 ReadMove() override;

public:
    /**
     * @fn Game_Liga4(uint rows, uint cols)
     * @brief Construtor da classe `Game_Liga4`.
     * 
     * @param rows Número de linhas do tabuleiro.
     * @param cols Número de colunas do tabuleiro.
     */
    Game_Liga4(uint rows, uint cols);

    /**
     * @fn ~Game_Liga4()
     * @brief Destrutor da classe `Game_Liga4`.
     */
    ~Game_Liga4();

    /**
     * @fn GetWinner()
     * @brief Retorna o vencedor do jogo ou 0 em caso de empate.
     * 
     * @return uint Identificador do vencedor (1 ou 2) ou 0 em caso de empate.
     */
    uint GetWinner() override;

    /**
     * @fn IsDraw()
     * @brief Verifica se o jogo terminou em empate. Método trivial.
     * 
     * @details Ocorre um empate quando o tabuleiro foi totalmente preenchido sem nenhum vencedor
     * 
     * @return bool Retorna `true` se o jogo foi um empate, caso contrário `false`.
     */
    bool IsDraw() override;

    /**
     * @fn CheckWin(uint player_ID, const Vec2& last_move)
     * @brief Verifica se o jogador venceu o jogo.
     * 
     * @details O jogo é vencido quando um dos jogadores faz uma linha de 4 peças em qualquer direção
     * 
     * @param player_ID Identificador do jogador (1 ou 2).
     * @param last_move Última jogada realizada.
     * @return bool Retorna `true` se o jogador venceu ou`false` se ele perdeu.
     */
    bool CheckWin(uint player_ID, const Vec2& last_move);

    /**
     * @fn Play()
     * @brief Inicia o jogo e alterna entre os jogadores alguém venca seja ou termine em empate.
     * 
     * @param player1 [Jogador 1] Apelido do primeiro jogador
     * @param player2 [Jogador 2] Apelido do segundo jogador
     * 
     * @details Imprime o board e os nomes do jogadores com sua respectiva cor, caso a entrada seja por cin ele limpa a tela toda rodada.
     * Quando um jogador vence, o método imprime a mensagem de vitória e o jogo termina. Se o jogo terminar sem vencedor, imprime Empate
     * 
     * @return uint O identificador do vencedor (1 ou 2) ou 0 em caso de empate.
     */
    uint Play(std::string player1, std::string player2) override;
};
