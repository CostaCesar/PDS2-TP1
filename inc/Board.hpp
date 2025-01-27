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

    (0, 0) -> x++ -> (x-1, 0)
    
    V y++ 
    
    (0, y-1)
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
    /*! @var uint current_player
    @brief ID do jogador atual
    */
    uint current_player;

    /*! @var uint num_plays
    @brief Número de jogadas realizadas no tabuleiro
    */
    uint num_plays;

    /*! @fn GetOpponentId()
        @return ID do jogador oponente
    */
    uint GetOpponentId();

    /*! @fn NextPlayer()
        @brief Troca de jogador
        @details Avança <current_player> para o próximo jogador
    */
    virtual void NextPlayer();

    /*! @fn Vec2ToIndex(Vec2 position)
        @brief Converte a posição Vec2 para o indice no tabuleiro
        @param position Posição no tabuleiro
        @return Indice da posição no tabuleiro

        @warning Essa função não garante que a posição/indice seja válido (esteja dentro do tabuleiro)
    */
    uint Vec2ToIndex(Vec2 position);

    /*! @fn IndexToVec2(uint index)
        @brief Converte o indice no tabuleiro para uma posição Vec2
        @param index Indice no tabuleiro
        @return Vec2: Posição no tabuleiro

        @warning Essa função não garante que a posição/indice seja válido (esteja dentro do tabuleiro)
    */
    Vec2 IndexToVec2(uint index);


    /*! @fn PosFromDirec(Vec2 pos, Direction direc)
        @brief Retorna a posição ao seguir uma direção a partir da posição passada
        @param pos Posição base
        @param direc Direção a seguir
        
        @return Vec2: Proxima posição na direção seguida

        @warning Essa função não garante que a posição/indice seja válido (esteja dentro do tabuleiro)
    */
    Vec2 PosFromDirec(Vec2 pos, Direction direc);

    /*! @fn IsInsideBoard(Vec2 position)
        @brief Checa se a posição passada está dentro dos limites
        @param position Posição a ser checada
        @return true se a posição está dentro, caso contrário, false
    */
    bool IsInsideBoard(Vec2 position);

    /*! @fn GetPiece(Vec2 position);
        @brief Acessa a peça na dada posição
        @param position Posição a ser acessada
        @return Piece*: Peça na posição, se existir. Caso contrário, nullptr é retornado
    */
    Piece* GetPiece(Vec2 position);

    /*! @fn MatchUntilStep(Vec2 position, Direction direction, uint steps)
        @brief Faz a checagem de peças em uma direção a partir de uma posição
        @param position Posição base da operação
        @param direction Direção a ser seguida
        @param steps Número de passos a serem executados
        @return veja MatchReturn
    */
    MatchReturn MatchUntilStep(Vec2 position, Direction direction, uint steps);
    
    /*! @fn HandleOverlap_Move(Vec2 position, Vec2 new_position)
        @brief Tratador do caso em que uma peça se sobrepõe a outra numa moviemntação
        @param position Posição da peça que esta sendo movimentada
        @param new_position Posição da peça que está na posição do movimento
        
        @return true se o movimento foi completo, falso caso contrário

        @details Essa função deve ser sobrescrita pelos hedeiros que tem regras próprias para essa ocasião
    */
    virtual bool HandleOverlap_Move(Vec2 position, Vec2 new_position);
    
    /*! @fn HandleOverlap_Add(Vec2 position, Piece* new_piece)
        @brief Tratador do caso em que uma peça se sobrepõe a outra na adição de uma peça ao tabuleiro
        @param position Posição da peça que esta sendo adicionada
        @param new_piece Peça que está sendo adicionada
        
        @return true se a adição foi completa, falso caso contrário

        @details Essa função deve ser sobrescrita pelos hedeiros que tem regras próprias para essa ocasião
    */
    virtual bool HandleOverlap_Add(Vec2 position, Piece* new_piece);
    
    /*! @fn GetCharFromInput()
        @brief Faz a leitura de uma letra do input
        @return Número que a letra representa, sendo A = 0
    */
    uint GetCharFromInput();

    /*! @fn GetUintFromInput()
        @brief Faz a leitura de um numero inteiro positivo do input
        @return Número lido 

        @exception invalid_argument, Caso o valor lido seja inválido
    */
    uint GetUintFromInput();

    /*! @fn ReadMove()
        @brief Faz a leitura de um movimento do jogador atual
        @return Vec2: Posição escolhida

        @exception invalid_argument, Caso o valor lido seja inválido

        @details Essa função lê 2 números inteiros positivos por padrão, X Y (veja GetUintFromInput()).
        Outros jogos podem sobreescreve-la para a leitura no formato apropriado
    */
    virtual Vec2 ReadMove();

    /*! @fn IsReadingFromCin()
        @brief Checa a origem do input
        @return true se o input é &std::cin, falso em caso contrário

        @details Essa função permite as classes herdeiras saberem se estão rodando em um ambiente de arquivos (testes)
        ou no programa do usuário (lendo entradas de std::cin)
    */
    bool IsReadingFromCin();

public:
    /*! @fn GetSize()
        @return Vec2: A dimensão do tabuleiro
    */
    Vec2 GetSize();

    /*! @fn AssignInput(std::istream* new_input)
        @brief Atribui o input do Board para uma istream escolhida
        @param new_input Ponteiro para uma stream de entrada
        @details Permite o tabuleiro utilizar outras formas de input, como arquivos
    */
    void AssignInput(std::istream* new_input);

    /*! @fn FlushInput()
        @brief Limpa a stream de input
        @details Quando a leitura no ReadMove() ger uma exceção, é necessário limpar a stream par que
        a próxima jogada seja registrada corretamente
    */
    void FlushInput();

    /*! @fn Draw()
        @brief Imprime o tabuleiro e seus detalhes
        @details 

        @note Essa função pode ser sobreescrita

    */
    virtual void Draw();

    /*! @fn MovePiece(Vec2 position, Vec2 new_position)
        @brief Move a peça de uma posição a outra
        @param position Posição da peça a ser movida
        @param new_position Nova posição da peça
        @return true se o movimento ocorreu com sucesso, false em caso contrário
        @details O movimento da peça quando ela se sobrepõe a outra é controlado pelo HandleOverlap_Move()

        @note Essa função pode ser sobreescrita
    */
    virtual bool MovePiece(Vec2 position, Vec2 new_position);

    /*! @fn AddPiece(Vec2 position, Piece* piece_ptr)
        @brief Adiciona uma peça no tabuleiro em uma dada posição
        @param position Posição da peça a ser adicionada
        @param piece_ptr Ponteiro da peça a ser adicionada
        @return true se a peça foi adicionada com sucesso, false em caso contrário
        @details A adição da peça quando ela se sobrepõe a outra é controlado pelo HandleOverlap_Add()

        @note Essa função pode ser sobreescrita
    */
    virtual bool AddPiece(Vec2 position, Piece* piece_ptr);

    /*! @fn DeletePiece(Vec2 position)
        @brief Deleta uma peça na posição
        @param position Posição da peça a ser deletada
        @return true se a peça foi removida com sucesso, false em caso contrário
        @details Essa ação deleta a peça da memória, não só do tabuleiro.

        @note Essa função pode ser sobreescrita
    */
    virtual bool DeletePiece(Vec2 position);
    
    /*! @fn GetWinner()
        @brief Obtem o joagador que venceu
        @return 
            - 0: Nehum jogador - Jogo em andamento OU Empate (veja IsDraw())
            - X: ID do jogador que venceu 
        @details A função pode ser chamada após o jogo ter sido jogado.
        A função não é capaz de diferenciar entre jogo em andamento ou empate
        @warning Essa função deve ser sobreescrita para que a classe seja válida
    */
    virtual uint GetWinner() = 0;

    /*! @fn IsDraw()
        @brief Determina se o jogo empatou ou não
        @return true se ocorreu um empate, false em caso contrário
        @details A função pode ser chamada após o jogo ter sido jogado.
        @warning Essa função deve ser sobreescrita para que a classe seja válida
    */
    virtual bool IsDraw() = 0;

    /*! @fn Play()
        @brief Realiza a partida do jogo
        @return 0 em caso de empate. Senão, O ID do jogador que venceu é retornado
        @details Essa é a principal função da classe Board.

        @warning Essa função deve ser sobreescrita para que a classe seja válida
    */
    virtual uint Play() = 0;

    /*! @fn Board()
        @brief Construtor padrão do Board
        @return Board: board_size={0,0}, board=vector<Piece*>(0), current_player=1, input=std::cin
    */
    Board();

    /*! @fn Board(Vec2 _size, uint start_player = 1)
        @brief Construtor comum do Board
        @param _size Dimensões do tabuleiro
        @param start_player [1] Jogador incial na partida
        @return Board: board_size, board=board_size.x*board_size+y, current_player=1, input=std::cin
    */
    Board(Vec2 _size, uint start_player = 1);
    
    /*! @fn ~Board()
        @brief Destrutor do board
        @details Desaloca todas as peças associadas ao Board
    */
    virtual ~Board();
};