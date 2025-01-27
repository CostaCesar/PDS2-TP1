#pragma once

#include "Board.hpp"

/**
 * @class Game_Liga4
 * @brief Classe que representa o jogo "Conecta 4" (Liga 4), que herda de `Board`.
 */
class Game_Liga4 : public Board {
private:
    /**
     * @brief Retorna a linha vazia mais próxima para uma coluna, 'gravidade'.
     * 
     * @param column Coluna onde a peça será colocada.
     * @return uint Primeira linha desocupada da coluna respectiva.
     */
    uint EmptyRow(uint column);

    /**
     * @brief Le a jogada.
     * 
     * @return Coordenada jogada.
     */
    Vec2 ReadMove() override;

public:
    /**
     * @brief Construtor da classe `Game_Liga4`.
     * 
     * @param rows Número de linhas do tabuleiro.
     * @param cols Número de colunas do tabuleiro.
     */
    Game_Liga4(uint rows, uint cols);

    /**
     * @brief Destrutor da classe `Game_Liga4`.
     */
    ~Game_Liga4();

    /**
     * @brief Retorna o vencedor do jogo ou 0 em caso de empate.
     * 
     * @return uint Identificador do vencedor (1 ou 2) ou 0 em caso de empate.
     */
    uint GetWinner() override;

    /**
     * @brief Verifica se o jogo terminou em empate.
     * método trivial.
     * @return bool Retorna `true` se o jogo foi um empate, caso contrário `false`.
     */
    bool IsDraw() override;

    /**
     * @brief Verifica se o jogador venceu o jogo.
     * 
     * @param player_ID Identificador do jogador (1 ou 2).
     * @param last_move Última jogada realizada.
     * @return bool Retorna `true` se o jogador venceu ou`false` se ele perdeu.
     */
    bool CheckWin(uint player_ID, const Vec2& last_move);

    /**
     * @brief Inicia o jogo e alterna entre os jogadores alguém venca seja ou termine em empate.
     * 
     * Imprime o board e os nomes do jogadores com sua respectiva cor, caso a entrada seja por cin ele limpa a tela toda rodada.
     * Quando um jogador vence, o método imprime a mensagem de vitória e o jogo termina. Se o jogo terminar sem vencedor, imprime Empate
     * 
     * @return uint O identificador do vencedor (1 ou 2) ou 0 em caso de empate.
     */
    uint Play() override;
};
