#pragma once

#include "Board.hpp"
#include <unordered_set>
#include <iostream>

using std::unordered_set;

// Here because there's a unordered set of Vec2
struct Vec2Hash
{
    size_t operator()(const Vec2& vec) const
    {
    size_t xHash = std::hash<int>()(vec.x);
    size_t yHash = std::hash<int>()(vec.y) << 1;
    return xHash ^ yHash;
    }
};

/**
* @class Game_Reversi
* @brief Classe que representa o jogo Reversi, que herda de `Board`.
*/
class Game_Reversi : public Board
{
private:
    static const char k_player1 = '#'; /*!< Define um simbolo para o jogador 1*/  
    static const char k_player2 = 'O'; /*!< Define um simbolo para o jogador 2*/
    static const char k_available = '.'; /*!< Define um simbolo para espaço vazio no borad*/

    uint white_count;/*!< Conta as peças no tabuleiro do jogador 1*/  
    uint black_count;/*!< Conta as peças no tabuleiro do jogador 2*/ 
    unordered_set<Vec2, Vec2Hash> border_tiles;/*!< Guarda as posições da borda em relação às peças colocadas no tabuleiro*/

     /**
     * @brief Adiciona uma piece em um dado endereço de memoria do board.
     * 
     * @param position posição relativa no tabuleiro onde a peça sera adicionada.
     * @param new_piece Ponteiro da peça a ser adicionada.
     * @return bool Verdadeiro caso a operação serja efetivada, False caso contrario.
     */
    bool AddPiece(Vec2 position, Piece* new_piece);

    /**
     * @brief Desenha o Tabuleiro na saida.
     */
    void Draw();

    /**
     * @brief Verifica se houve um vencedor.
     * 
     * @return bool Verdadeiro caso tenha uma vitória, caso contrario False.
     */
    uint GetWinner() override;

    /**
     * @brief Verifica se houve um empate.
     * 
     * @return bool Verdadeiro caso seja um empate, caso contrario False.
     */
    bool IsDraw() override;

    /**
     * @brief Calcula as bordas em relação às peças colocadas e salva na variavel da classe.
     * 
     * @param position posição relativa no tabuleiro onde a borda será calculada.
     */
    void CalculateBorders(Vec2 position);

    /**
     * @brief Realiza uma sequencia de movimentos "comendo" a peça do oponente até que não seja mais possivel realizar na determinada jogada.
     * 
     * @param position posição de origem do movimento.
     * @param start_piece peça inicial de onde começa o movimento.
     */
    void CascadeMove(Vec2 position, Piece* start_piece);

    /**
     * @brief Calcula quantos movimentos são possiveis em uma determinada jogada.
     * 
     * @return uint número de movimentos possiveis.
     */
    uint MarkAsPlayable();

public:

    /**
     * @brief Inicia a partida de Reversi, criando um loop onde é solicitado um input para a jogada de cada jogar respectivamente e imprime o tabuleriro a cada jogada.
     */
    uint Play();

    /**
     * @brief Importa a função de Board sem modificações.
     */
    void AssignInput(std::istream* new_input);

    /**
     * @brief Construtor da classe Game_Reversi.
     * 
     * @param _start_player Declara qual o jogador inicial (default=1).
     */
    Game_Reversi(uint _start_player = 1);

    /**
     * @brief Destrutor da classe Game_Reversi.
     */
    ~Game_Reversi();

};