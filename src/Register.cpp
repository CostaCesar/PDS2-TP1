#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::ofstream, std::ifstream;

int check_player() {
    ifstream csv;
    std::string valor;
    while (getline())
}

void register(string nome, string nickname) {
    ofstream csv;
    csv.open("./data/cadastro.csv", std::fstream::in);
    csv << nome << "," << nickname << "," << "0" << "," << "0" << "/n";
}