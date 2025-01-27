#pragma once

#include "Board.hpp"

/**
 * @class Game_Puzzle
 * @brief Classe que representa o jogo extra puzzle, que herda de `Board`.
 */
class Game_Puzzle : public Board
{
private:

     /**
     * @brief Adiciona uma piece em um dado endereço de memoria do board.
     * 
     * @param position posição relativa no tabuleiro onde a peça sera adicionada.
     * @param new_piece Ponteiro da peça a ser adicionada.
     * @return bool Verdadeiro caso a operação serja efetivada, False caso contrario.
     */
    bool AddPiece(Vec2 position, Piece* new_piece);

    /**
     * @brief Move a peça na posição para uma direção vazia.
     * 
     * @param position posição relativa no tabuleiro onde a peça se encontra.
     * @return bool Verdadeiro caso a operação serja efetivada, False caso contrario.
     */
    bool MovePiece(Vec2 position);

    /**
     * @brief Verifica se houve um empate.
     * 
     * @return bool Verdadeiro caso seja um empate, caso contrario False.
     */
    bool IsDraw() override;

    /**
     * @brief Verifica se houve um vencedor.
     * 
     * @return bool Verdadeiro caso tenha uma vitória, caso contrario False.
     */
    uint GetWinner() override;

    /**
     * @brief Le um input para realização de um movimento.
     * 
     * @return Vec2 retorna a posição final do movimento dentro do board, caso chegue na borda, retorna a posição na borda.
     */
    Vec2 ReadMove() override;

    /**
     * @brief Sobreescreve uma função virtual pura ou seja, não faz nada.
     * 
     * @return bool Verdadeiro sempre.
     */
    bool HandleOverlap_Move(Vec2 position, Vec2 new_position) override;

public:
    uint Play() override;
    Game_Puzzle(uint complexity, uint seed = time(NULL), Vec2 _size = Vec2{3, 3});
    ~Game_Puzzle();
};