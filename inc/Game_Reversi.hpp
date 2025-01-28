#pragma once

#include "Board.hpp"
#include <unordered_set>
#include <iostream>

using std::unordered_set;

/*! @file Game_Reversi.hpp 
    @brief Estrutura do Reversi (Othello)
*/

/**
* @class Vec2Hash
* @brief Classe que implementa um hash para o Vec2
*
* @details Esse hash é necessário para que o unordered_set de Vec2 seja possível
*/
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

    /** @var uint white_count
     *  @brief Contagem das peças no tabuleiro do jogador 1
     *
    */  
    uint white_count;

    /** @var uint black_count
     *  @brief Contagem das peças no tabuleiro do jogador 2
     *
    */  
    uint black_count;

    /** @var uint black_count
     *  @brief Guarda as posições da borda em relação às peças colocadas no tabuleiro
     *  @details As bordas são as posições vazias adjacentes a pelo menos 1 peça de qualquer jogador.
     *  Elas são geradas para facilitar o calculo das posições em que cada jogador pode jogar
     *  Para evitar a repetição de posições, o unordered_set é utilizado, através de Vec2Hash
    */
    unordered_set<Vec2, Vec2Hash> border_tiles;

    /**
     * @fn AddPiece(Vec2 position, Piece* new_piece)
     * @brief Adiciona uma piece em um dado endereço de memoria do board.
     * 
     * @param position posição relativa no tabuleiro onde a peça sera adicionada.
     * @param new_piece Ponteiro da peça a ser adicionada.
     * @return bool True caso a operação serja efetivada, False caso contrario.
     */
    bool AddPiece(Vec2 position, Piece* new_piece);

    /**
     * @fn Draw()
     * @brief Desenha o Tabuleiro na saida.
     * 
     * @details Também imprime a quantidade de peças no tabuleiro de cada jogador
     */
    void Draw();

    /**
     * @fn GetWinner()
     * @brief Verifica qual jogador está vencendo.
     * 
     * @details Essa função só é relevante quando o tabuleiro está totalmente preenchido
     * Caso contrário, 0 sempre será retornado, pois o jogo está em andamento
     * 
     * @return uint ID do jogador que está vencendo. 0 indica que não há vencendor
     */
    uint GetWinner() override;

    /**
     * @fn IsDraw()
     * @brief Verifica se houve um empate.
     * 
     * @details O empate ocorre quando o tabuleiro está totalmente preenchido, mas a quantidade de peças do jogadores é igual
     * 
     * @return bool True caso seja um empate, caso contrario False.
     */
    bool IsDraw() override;

    /**
     * @fn CalculateBorders(Vec2 position)
     * @brief Calcula as bordas em relação às peças colocadas e salva na variavel da classe.
     * 
     * @details Quando uma jogada é realizada, essa função atualiza as bordas, deletando a posição agora ocupada e
     * procurando por posiç~eos vazias adjacentes a ela
     * 
     * @param position Posição relativa no tabuleiro onde a borda será calculada.
     */
    void CalculateBorders(Vec2 position);

    /**
     * @fn CascadeMove(Vec2 position, Piece* start_piece)
     * @brief Calcula o resultado de uma jogada.
     * 
     * @details Realiza uma sequencia de movimentos "convertendo" as peça do oponente até alcançar outra peças do jogador que fez a jogada
     * O resutlado é um efeito de raio nas 8 direções (veja Direction)
     * 
     * @param position posição de origem do movimento.
     * @param start_piece peça inicial de onde começa o movimento.
     */
    void CascadeMove(Vec2 position, Piece* start_piece);

    /**
     * @fn MarkAsPlayable()
     * @brief Calcula quantos movimentos são possiveis em uma determinada jogada.
     * 
     * @details Um movimento é possivel quando existe uma direção a partir daquela posição em que existe outra peça desse jogador.
     * Quando o movimento for realizado (veja CascadeMove()), as peças do oponente na direção serão convertidas
     * 
     * @return uint número de movimentos possiveis.
     */
    uint MarkAsPlayable();

public:

    /**
     * @fn lay()
     * 
     * @brief Inicia a partida de Reversi
     * 
     * @details Loop onde é solicitado um input para a jogada de cada jogar respectivamente e imprime o tabuleriro a cada jogada.
     * Se não houverem jogadas disponíveis para o jogador atual (MarkAsPlayable() retornando 0), o outro jogador ganha a vez para progredir o jogo
     * O jogo acaba quando o tabuleiro é completamente preenchido, então contando as quantidades de peças
     * 
     * @return ID do jogador que venceu, ou 0 em caso de empate 
     */
    uint Play();

    /**
     * @fn  Game_Reversi(uint _start_player = 1)
     * @brief Construtor da classe Game_Reversi.
     * 
     * @param _start_player [1] Declara qual o jogador inicial.
     */
    Game_Reversi(uint _start_player = 1);

    /**
     * @fn ~Game_Reversi()
     * @brief Destrutor da classe Game_Reversi.
     */
    ~Game_Reversi();
};