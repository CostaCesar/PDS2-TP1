#include "Register.cpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;

void register() {
    string comando;
    string nome, nickname

    while(cin >> comando) {
        if (comando == "CJ") {
            cin >> name;
            cin >> nickname;
            register(name, nickname);
        } else if (comando == "RJ") {
        } else if (comando == "LJ") {
        } else if (comando == "EP") {
        } else if (comando == "FS") {
        } else {
            cout << "Comando inexistente. Tente novamente."
        }
    }
}