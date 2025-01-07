#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using
    std::ofstream,
    std::ifstream,
    std::string,
    std::stringstream,
    std::vector;


const string NOME_ARQ = "./src/cadastro.csv";

int playerExists (string NOME_ARQ, string nickname) {
    ifstream csv(NOME_ARQ);
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

int registerPlayer(string nickname, string name) {
    ofstream csv;

    csv.open(NOME_ARQ, std::fstream::app);

    if (!playerExists (NOME_ARQ, nickname)) {
        csv << name << "," << nickname << "," << "0" << "," << "0" << "," << "0" << "," << "0" << "0" << "," << "0" << std::endl;
    } else {
        return 1;
    }

    csv.close();

    return 0;
}

int deletePlayer(string nickname) {
    ifstream csv;

    csv.open(NOME_ARQ, std::fstream::in);
    
    vector<string> linhas;
    string linha;

    bool valorEncontrado = false;

    while (std::getline(csv, linha)) {
        stringstream ss(linha);
        string valor;
        bool linhaContemValor = false;

        while(std::getline(ss, valor, ',')) {
            if (valor == nickname) {
                linhaContemValor = true;
                valorEncontrado = true;
                break;
            }
        }

        if (!linhaContemValor) {
            linhas.push_back(linha);
        }
    }

    csv.close();

    if (!valorEncontrado) {
        return 1;
    }

    ofstream updated_csv;
    updated_csv.open(NOME_ARQ, std::fstream::trunc);
    
    for (auto updated_linha : linhas) {
        updated_csv << updated_linha << std::endl;
    }

    updated_csv.close();
    
    return 0;
}