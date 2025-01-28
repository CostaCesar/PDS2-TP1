#pragma once

#include "Defs.hpp"

/*! @file Piece.hpp 
    @brief Estrutura de uma peça de tabuleiro básica
*/

/*! @class Piece
    @brief Peça de tabuleiro

    @details Uma peça de tabuleiro base, contendo o ID do jogador dono da peça
    e o símbolo gráfico para desenha-la no tabuleiro.

    O ID do dono segue a seguinte convenção:
    - 0: Peça sem dono (neutra)
    - 1: Peça do jogador 1
    - 2: Peça do jogador 2
    - X: Peça do jogador X

*/
class Piece
{
private:
    /*! @var uint player_id
    @brief ID do jogador dono da peça
    */
    uint player_id;
    /*! @var char symbol
    @brief Caractere gráfico para representar a peça
    */
    char symbol;

public:
    /*! @fn GetPlayerId()
        @return ID do dono da peça
    */
    uint GetPlayerId();

    /*! @fn SetPlayerId(uint new_id)
        @param new_id Novo ID para a peça
    */
    void SetPlayerId(uint new_id);

    /*! @fn GetSymbol()
        @return Simbolo da peça
    */
    char GetSymbol();

    /*! @fn SetSymbol(char new_symbol)
        @param new_symbol Novo simbolo para a peça
    */
    void SetSymbol(char new_symbol);

    /*! @fn Piece (void)
        @brief Construtor padrão para peça
        @return Piece: player_id = 0, symbol = ' '
    */
    Piece();

    /*! @fn Piece (uint _player_id, char _symbol)
        @brief Construtor comum para Peça
        @param _player_id [0] ID do dono
        @param symbol     ['\\0'] Simbolo gráfico
        @return Piece: player_id, symbol
    */
    Piece(uint _player_id = 0, char _symbol = '\0');
};