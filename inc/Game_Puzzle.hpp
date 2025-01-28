#pragma once

#include "Board.hpp"

/*! @file Puzzle.hpp 
    @brief Estrutura do Jogo do 8
*/

/**
 * @class Game_Puzzle
 * @brief Classe que representa o jogo Puzzle, que herda de `Board`.
 * 
 * @note Esse jogo é um extra adicionado no trabalho. Serve como exemplo de
 * como um tabuleiro de jogador solo pode ser utilizado no sistema
 */
class Game_Puzzle : public Board
{
private:

    /**
     * @fn AddPiece(Vec2 position, Piece* new_piece)
     * @brief Adiciona uma piece em um dado endereço de memoria do board.
     * 
     * @param position posição relativa no tabuleiro onde a peça sera adicionada.
     * @param new_piece Ponteiro da peça a ser adicionada.
     * @return bool True caso a operação seja efetivada, False caso contrario.
     */
    bool AddPiece(Vec2 position, Piece* new_piece);

    /**
     * @fn MovePiece(Vec2 position)
     * @brief Move a peça na posição para uma direção vazia.
     * 
     * @param position posição relativa no tabuleiro onde a peça se encontra.
     * @return bool True caso a operação seja efetivada, False caso contrario.
     */
    bool MovePiece(Vec2 position);

    /**
     * @fn IsDraw()
     * @brief Verifica se o tabuleiro é jogável.
     * 
     * @details O puzzle têm solução quando a quantidade de trocas realizadas é par
     * Para mis detalhes, veja https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/
     * 
     * @return bool True caso seja possível jogar, caso contrario False.
     */
    bool IsDraw() override;

    /**
     * @fn GetWinner()
     * @brief Verifica se o tabuleiro está organizado na posição de vitória
     * 
     * @details A configuração de vitória é a sequência 1 -> 8 das peças, da esquerda a direita, do topo até embaixo,
     * com a utlima posição (2,2) estando vazia
     * 
     * @return bool True caso tenha uma vitória, caso contrario False.
     */
    uint GetWinner() override;

    /**
     * @fn ReadMove()
     * @brief Le um input para realização de um movimento.
     * 
     * @details A entrada lida é o número da peça no tabuleiro. O método converte-o para a posição ddessa peça
     * 
     * @return Vec2 retorna a posição final do movimento dentro do board, caso chegue na borda, retorna a posição na borda.
     */
    Vec2 ReadMove() override;

    /**
     * @fn HandleOverlap_Move(Vec2 position, Vec2 new_position)
     * @brief Sobreescreve uma função virtual pura ou seja, não faz nada.
     *
     * @return bool True sempre.
     */
    bool HandleOverlap_Move(Vec2 position, Vec2 new_position) override;

public:
    /**
     * @fn Play()
     * @brief Método principal da classe. Executa o jogo até a condição de vitória (veja GetWinner()) ou até a
     * desistência do jogador (entrada = 9) .
     * 
     * @param player1 [Jogador 1] Apelido do primeiro jogador
     * @param player2 [Jogador 2] Apelido do segundo jogador
     * 
     * @return uint 1 se o jogo foi completado com sucesso, 0 para qualquer outro caso.
     */
    uint Play(std::string player1, std::string player2) override;

    /**
     * @fn Game_Puzzle(uint complexity, uint seed = time(NULL), Vec2 _size = Vec2{3, 3})
     * @brief Construtor para o Puzzle
     * 
     * @param complexity Número aproximado de embaralhamentos que o tabuleiro sofrerá
     * @param seed [time(NULL)] A semente para determinar o tabuleiro final produzido
     * @param _size [Vec2{3,3}] Tamanho do tabuleiro a ser jogado.
     * 
     * @brief Serão geradas (size.x * size.y) - 1 peças no tabuleiro. Em seguida, serão embaralhadas
     * de acordo com a seed passada e a complexidade aplicada.
     */
    Game_Puzzle(uint complexity, uint seed = time(NULL), Vec2 _size = Vec2{3, 3});

    /**
     * @fn ~Game_Puzzle()
     * @brief Destrutor da classe
    */
    ~Game_Puzzle();
};