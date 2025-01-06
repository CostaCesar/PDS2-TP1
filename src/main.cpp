#include "Register.cpp"
#include <iostream>
#include <string>

using std::cin, std:: string;

int main() {
    string name, nickname, comando;
    
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
                continue;
            } else {
                std::cout << "ERRO: jogador inexistente" << std::endl;
            }

        } else if (comando == "FS") {
            return 0;
        }
    }

    return 1;
}