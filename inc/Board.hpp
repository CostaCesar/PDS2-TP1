#pragma once

#include "Defs.hpp"
#include "Piece.hpp"

#include <sstream>
#include <vector>

using std::vector;

/*! @file Board.hpp 
    @brief Estrutura de um tabuleiro genérico
*/

/*!
    @enum MatchReturn
    @brief Valores de retorno possíveis para a função MatchUntilStep()
*/
enum class MatchReturn
{
    Limit = -2,  /*!< Limite do tabuleiro*/  
    Empty = -1,  /*!< Posição vazia, taubleiro[pos] == nullptr */  
    Neutral = 0, /*!< Peça neutra, player_id = 0*/    
    Opponent = 1,/*!< Peça do oponente, player_id diferente do começo*/   
    Matched = 2  /*!< Todas as peças combinam, player_id igual do começo*/  
};

/*! @class Board
    @brief Tabuleiro base

    @details Tabuleiro genérico, que serve de base para todos os outros tabuleiros.
    Possui diversas funções base compartilhadas entre diferentes jogos, além de
    funções comuns que permitem sobrecarga para a especialização nos jogos

    Todo tabuleiro que herda de Board deve implementar as seguintes funções abstratas:
    - GetWinner()
    - IsDraw()
    - Play()
*/
class Board
{
private:
    /*! @var Vec2 board_size
    @brief Dimensões do tabuleiro

    @details Esquema de posição do tabuleiro, sendo x,y as dimensões do tabuleiro:

     (0, 0)  | (1, 0) | ... | (x-1, 0)
    
     (0, 1)  | (1, 1) | ...

       ...

    (0, y-1) |     ...      | (x-1, y-1)
    */
    Vec2 board_size;

    /*! @var vector<Piece*> board
    @brief Vetor contendo todas as peças no tabuleiro

    @details Ao invés de uma matriz bidimensional, a linearização dessa estrutura facilita a alocação de memória.
    Como o acesso é intermediado por GetPiece(), consumidores dessa classe raramente devem lidar com a conversão
    Vec2 -> Indice e virse-versa.

    Contém ponteiros para as peças (que devem ser alocadas antes). Se o ponteiro em uma dada posição é nulo (nullptr),
    então a posição é considerada vazia.
    */
    vector<Piece*> board;

    /*! @var istream* input
    @brief Fonte da entrada de dados para o tabuleiro

    @details O valor comum é std::cin (terminal do usuário), mas alguns casos requerem ler as entradas de arquivos
    como nos testes das classes. Nesse caso, deve ser reatribuida através de AssignInput()
    */
    std::istream* input;

protected:
    uint current_player;
    uint num_plays;

    uint GetOpponentId();
    virtual void NextPlayer();

    uint Vec2ToIndex(Vec2 position);
    Vec2 IndexToVec2(uint index);
    Vec2 PosFromDirec(Vec2 pos, Direction direc);
    bool IsInsideBoard(Vec2 position);

    Piece* GetPiece(Vec2 position);
    MatchReturn MatchUntilStep(Vec2 position, Direction direction, uint steps);
    
    virtual bool HandleOverlap_Move(Vec2 position, Vec2 new_position);
    virtual bool HandleOverlap_Add(Vec2 position, Piece* new_piece);
    
    uint GetCharFromInput();
    uint GetUintFromInput();
    virtual Vec2 ReadMove();

public:
    Vec2 GetSize();
    void AssignInput(std::istream* new_input);
    void FlushInput();

    virtual void Draw();
    virtual bool MovePiece(Vec2 position, Vec2 new_position);
    virtual bool AddPiece(Vec2 position, Piece* piece_ptr);
    virtual bool DeletePiece(Vec2 position);
    
    virtual uint GetWinner() = 0;
    virtual bool IsDraw() = 0;
    virtual uint Play() = 0;

    Board();
    Board(Vec2 _size, uint start_player = 1);
    virtual ~Board();
};