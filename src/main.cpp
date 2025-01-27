#include "Register.hpp"
#include "Admin.hpp"
#include <iostream>
#include <string>

using
    std::cin,
    std::string;

int main() {
    string name, nickname, comando;
    
    std::cout << "digite uma das opções abaixo:" << std::endl;
    std::cout << std::endl << "Cadastrar jogador: CJ <Apelido> <Nome>" << std::endl;
    std::cout << "Remover jogador: RJ <Apelido>" << std::endl;
    std::cout << "Listar jogadores: LJ [A|N]" << std::endl;
    
    std::cout << "Executar partida: ";
    std::cout << "EP <Jogo: (R|L|V)> <Apelido Jogador 1> <Apelido Jogador 2>" << std::endl;
    
    std::cout << "Finalizar sistema: FS" << std::endl << std::endl;
    

    while(cin >> comando) {
        if (comando == "CJ") {
            cin >> nickname >> name;
            if (!registerPlayer(nickname, name)) {
                std::cout << "Jogador " << nickname << " cadastrado com sucesso" << std::endl << std::endl;
            } else {
                std::cout << "ERRO: jogador repetido" << std::endl << std::endl;
            }

        } else if (comando == "RJ") {
            cin >> nickname;

            if (!deletePlayer(nickname)) {
                std::cout << "Jogador " << nickname << " removido com sucesso" << std::endl << std::endl;
            } else {
                std::cout << "ERRO: jogador inexistente" << std::endl << std::endl;
            }

        } else if (comando == "LJ") {
            char sel;
            cin >> sel;
            listPlayers(sel);
        
        } else if (comando == "EP") {
            char sel;
            string j1, j2;

            cin >> sel >> j1 >> j2;

            if ((!validPlayers(j1, j2)) &&
                !validGame(sel)) {
                std::cout << "ERRO: Jogo e jogador inexistentes." << std::endl << std::endl;
            
            } else if (!validPlayers(j1, j2)) {
                std::cout << "ERRO: Jogador inexistente." << std::endl << std::endl;

            } else if (!validGame(sel)) {
                std::cout << "ERRO: Jogo inexistente." << std::endl << std::endl;

            } else {
                switch(sel) {
                    case 'R':
                        playReversi(j1,j2);
                        break;
                    case 'L':
                        playLiga4(j1,j2);
                        break;
                    case 'V':
                        playVelha(j1,j2);
                        break;
                    case 'P':
                        playPuzzle(j1);
                        break;
                    case 'I':
                        playInfinity(j1,j2);
                        break;
                }
            }

        } else if (comando == "FS") {
            return 0;
        }
    }

    return 1;
}