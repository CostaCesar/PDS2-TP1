#pragma once

#include <algorithm>
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


const string NOME_ARQ = "cadastro.csv";

struct Jogador {
    string apelido;
    string nome;
    int vitoriasReversi;
    int vitoriasLIg4;
    int vitoriasVelha;
    int derrotasReversi;
    int derrotasLIg4;
    int derrotasVelha;
};

void listPlayers(char sel) {
    ifstream csv;
    string linha;
    vector<Jogador> jogadores;

    csv.open(NOME_ARQ, std::fstream::in);

    while (std::getline(csv, linha)) {
        stringstream ss(linha);
        string apelido, nome, vR, vL, vV, dR, dL, dV;

        std::getline(ss, apelido, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, vR, ',');
        std::getline(ss, vL, ',');
        std::getline(ss, vV, ',');
        std::getline(ss, dR, ',');
        std::getline(ss, dL, ',');
        std::getline(ss, dV, ',');

        Jogador jogador;
        jogador.apelido = apelido;
        jogador.nome = nome;
        jogador.vitoriasReversi = std::stoi(vR);
        jogador.vitoriasLIg4 = std::stoi(vL);
        jogador.vitoriasVelha = std::stoi(vV);
        jogador.vitoriasReversi = std::stoi(dR);
        jogador.vitoriasLIg4 = std::stoi(dL);
        jogador.vitoriasVelha = std::stoi(dV);

        jogadores.push_back(jogador);
    }

    if (sel == 'A') {
        std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b) {
            return a.apelido < b.apelido;
        });
    } else if (sel == 'N') {
        std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b) {
            return a.nome < b.nome;
        });
    }

    for (const auto& jogador : jogadores) {
        std::cout << std::endl
            << "<" << jogador.apelido << "> " << "<" << jogador.nome << ">" << std::endl
            << "REVERSI - V: " << "<" << jogador.vitoriasReversi << "> D: " << "<" << jogador.vitoriasReversi << ">" << std::endl
            << "LIG4 - V: " << "<" << jogador.vitoriasLIg4 << "> D: " << "<" << jogador.vitoriasLIg4 << ">" << std::endl
            << "VELHA - V: " << "<" << jogador.vitoriasVelha << "> D: " << "<" << jogador.vitoriasVelha << ">" << std::endl;
    }

    csv.close();
}

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
    string arquivo = "cadastro.csv"; 
    ofstream csv;

    csv.open(arquivo, std::fstream::app);

    if (!playerExists (arquivo, nickname)) {
        csv << nickname << "," << name << ","
        << "0" << "," << "0" << ","
        << "0" << "," << "0" << ","
        << "0" << "," << "0" << "," << std::endl;
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

    // itera ao longo do arquivo csv.
    while (std::getline(csv, linha)) {
        stringstream ss(linha);
        string valor;
        bool linhaContemValor = false;
    
    // itera ao longo de cada linha buscando pelo apelido.
        while(std::getline(ss, valor, ',')) {
            if (valor == nickname) {
                linhaContemValor = true;
                valorEncontrado = true;
                break;
            }
        }

    // adiciona a linha sem o valor encontrado a um vetor de linhas
        if (!linhaContemValor) {
            linhas.push_back(linha);
        }
    }

    csv.close();

    // se não encontrar o apelido, retorna o código de erro 1.
    if (!valorEncontrado) {
        return 1;
    }

    // reescreve o arquivo csv com as linhas do vetor de linhas.
    ofstream updated_csv;
    updated_csv.open(NOME_ARQ, std::fstream::trunc);
    
    for (auto updated_linha : linhas) {
        updated_csv << updated_linha << std::endl;
    }

    updated_csv.close();
    
    return 0;
}
