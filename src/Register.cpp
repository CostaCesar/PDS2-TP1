#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::ofstream, std::ifstream, std::string, std::stringstream;

int playerExists (string& nome_arquivo, string& nickname) {
    ifstream csv(nome_arquivo);
    string linha;
    
    while (std::getline(csv, linha)) {
        stringstream ss(linha);
        string valor;

        while (std::getline(ss, valor, ',')) {
            if (valor == nickname) {
                csv.close();
                return 1;
            }
        }
    }
    return 0;
}

void registerPlayer(string nome, string nickname) {
    string arquivo = "cadastro.csv"; 
    ofstream csv;

    csv.open(arquivo, std::fstream::app);
    if (!playerExists (arquivo, nickname)) {
        csv << nome << "," << nickname << "," << "0" << "," << "0" << std::endl;
    }
}