#include "Register.cpp"
#include <iostream>

using std::cin;
using std::cout;

int main() {
    string comando;
    string name, nickname;

    while(cin >> comando) {
        if (comando == "CJ") {
            cin >> name >> nickname;
            registerPlayer(name, nickname);
        } else if (comando == "RJ") {
        } else if (comando == "LJ") {
        } else if (comando == "EP") {
        } else if (comando == "FS") {
        } else {
            cout << "Comando inexistente. Tente novamente.";
        }
    }
}