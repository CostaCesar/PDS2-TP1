#include "Register.hpp"
#include "Admin.hpp"

#include <iostream>
#include <string>

using std::cin;
using std::string;

int main() {
    string name, nickname, comando;

    printMenu();
    
    while(cin >> comando) {
        if (comando == "CJ") {
            cin >> nickname >> name;
            if (registerPlayer(nickname, name, NOME_ARQ)) {
                std::cout << "Jogador " << nickname << " cadastrado com sucesso" << std::endl << std::endl;
            } else {
                std::cout << "ERRO: jogador repetido" << std::endl << std::endl;
            }

        } else if (comando == "RJ") {
            cin >> nickname;

            if (!deletePlayer(nickname, NOME_ARQ)) {
                std::cout << "Jogador " << nickname << " removido com sucesso" << std::endl << std::endl;
            } else {
                std::cout << "ERRO: jogador inexistente" << std::endl << std::endl;
            }

        } else if (comando == "LJ") {
            char sel;
            cin >> sel;
            listPlayers(sel, NOME_ARQ);
        
        } else if (comando == "EP P") {
            string j1;
            cin >> j1;

            if (!playerExists(j1, NOME_ARQ)) {
                std::cout << "ERRO: Jogador inexistente." << std::endl << std::endl;
            } else {
                playPuzzle(j1);
                break;
            }

        } else if (comando == "EP") {
            char sel;
            string j1, j2;

            cin >> sel;

            if (sel == 'P') {
                cin >> j1;
                if (!playerExists(j1, NOME_ARQ)) {
                    std::cout << "ERRO: Jogador inexistente." << std::endl << std::endl;
                    continue;
                } else {
                    playPuzzle(j1);
                }
            } else {
                cin >> j1 >> j2;
                if ((!validPlayers(j1, j2, NOME_ARQ)) &&
                    !validGame(sel)) {
                    std::cout << "ERRO: Jogo e jogador inexistentes." << std::endl << std::endl;
                
                } else if (!validPlayers(j1, j2, NOME_ARQ)) {
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
                        case 'I':
                            playInfinity(j1,j2);
                            break;
                    }
                }
            }
            printMenu();
            
        } else if (comando == "FS") {
            return 0;
        }
    }

    return 1;
}