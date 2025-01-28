#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;
using std::vector;

/*! @file Register.hpp
    @brief Módulo para gerência de dados de jogadores.
*/

const string NOME_ARQ = "cadastro.csv";

/*! @struct Jogador
    Estrutura auxiliar utilizada para facilitar a listagem de jogadores.
    @warning Ao implementar novos jogos, atente-se ao formato da struct Jogador.
 */

struct Jogador {
    string nickname;
    string name;
    int vitoriasReversi;
    int derrotasReversi;
    int vitoriasLiga4;
    int derrotasLiga4;
    int vitoriasVelha;
    int derrotasVelha;
    int vitoriasPuzzle;
    int derrotasPuzzle;
    int vitoriasInfinity;
    int derrotasInfinity;
};

/*! @fn playerExists(string nickname, string arquivo)
    @brief Busca em um arquivo .csv se existe um jogador com o apelido apresentado.
    @param nickname Apelido do jogador a ser buscado.
    @param arquivo Arquivo .csv com dados dos jogadores.
    @return Caso o jogador seja encontrado, retorna 1. Se não, retorna 0.
 */
int playerExists(string nickname, string arquivo);

/*! @fn registerPlayer(string nickname, string name, string arquivo)
    @brief Caso o apelido passado não seja admin e o jogador não exista no arquivo .csv passado, adiciona uma linha no arquivo no mesmo formato que a struct Jogador.
    @param nickname Apelido do jogador a ser registrado.
    @param arquivo Arquivo .csv com dados dos jogadores.
    @return Caso as condições para registro do jogador sejam cumpridas, retorna 1. Se não, retorna 0;

    @warning Ao implementar novos jogos, atente-se ao formato dos dados adicionados por essa função.
*/
int registerPlayer(string nickname, string name, string arquivo);

/*! @fn deletePlayer(string nickname, string arquivo)
    @brief Caso o apelido passado exista no arquivo .csv passado, remove os dados do jogador do arquivo.
    @param nickname Apelido do jogador a ser removido.
    @param arquivo Arquivo .csv com dados dos jogadores.
    @return Caso as condições para remoção do jogador sejam cumpridas, retorna 0. Se não, retorna 1;
*/
int deletePlayer(string nickname, string arquivo);

/*! @fn listPlayers(char sel, string arquivo)
    @brief Lista os jogadores no arquivo .csv passado por ordem alfabetica de apelido ou nome.
    @param sel Pode ser A ou N. Caso seja A, lista os jogadores por apelido. Caso seja N, lista os jogadores por nome.
    @param arquivo Arquivo .csv com dados dos jogadores.
*/
void listPlayers(char sel, string arquivo);

/*! @fn updateScore(string winnerNickname, string looserNickname, int jogo, string arquivo)
    @brief Atualiza a pontuação dos jogadores participantes de uma partida.
    @param winnerNickname Apelido do jogador vencedor.
    @param looserNickname Apelido do jogador perdedor.
    @param jogo Indice de 1 a 5 com o jogo cujo dado deve ser atualizado.
    -# Reversi
    -# Liga4
    -# Jogo da Velha
    -# Puzzle
    -# Jogo da Velha Infinito
    @param arquivo Arquivo .csv com dados dos jogadores.
    
    @warning Ao implementar novos jogos, atente-se ao formato dos dados adicionados por essa função.
*/
void updateScore(string winnerNickname, string looserNickname, int jogo, string arquivo);