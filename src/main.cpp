#include "Register.hpp"
#include "Admin.hpp"
#include <iostream>
#include <string>

using
    std::cin,
    std:: string;

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
                std::cout << "Jogador " << nickname << " cadastrado com sucesso" << std::endl;
            } else {
                std::cout << "ERRO: jogador repetido" << std::endl;
            }

        } else if (comando == "RJ") {
            cin >> nickname;

            if (!deletePlayer(nickname)) {
                std::cout << "Jogador " << nickname << " removido com sucesso" << std::endl;
            } else {
                std::cout << "ERRO: jogador inexistente" << std::endl;
            }

        } else if (comando == "LJ") {
            char sel;
            cin >> sel;
            listPlayers(sel);
        
        } else if (comando == "EP") {
            char sel;
            string j1, j2;

            cin >> sel >> j1 >> j2;

            if (!validPlayers(j1, j2)) {
                std::cout << "ERRO: jogador inexistente." << std::endl;
            } else if (sel != 'R' || sel != 'J' || sel != 'V') {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }

            if (sel == 'R') {
                jogoReversi(j1,j2);
            } else if (sel == 'L') {
                jogoLig4(j1,j2);
            } else if (sel == 'V') {
                jogoVelha(j1,j2);
            }


        } else if (comando == "FS") {
            return 0;
        }
    }

    return 1;
}