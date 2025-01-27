#include "Register.hpp"
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


int playerExists (string nickname) {
    ifstream csv;

    csv.open(NOME_ARQ, std::fstream::in);

    string linha;
    
    // itera ao longo de todas as linhas do csv
    while (std::getline(csv, linha)) {
        stringstream ss(linha);
        string valor;
        
        // itera ao logo de todos os campos do csv
        // se o nickname foi encontrado, retorna 0
        while (std::getline(ss, valor, ',')) {
            if (valor == nickname) {
                csv.close();
                return 0;
            }
        }
    }
    
    csv.close();
    return 1;
}

int registerPlayer(string nickname, string name) { 
    ofstream csv;

    csv.open(NOME_ARQ, std::fstream::app);

    if (playerExists (nickname)) {
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
    
    // itera ao longo de cada linha buscando pelo nickname.
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

    // se não encontrar o nickname, retorna o código de erro 1.
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

void listPlayers(char sel) {
    ifstream csv;
    string linha;
    vector<Jogador> jogadores;

    csv.open(NOME_ARQ, std::fstream::in);

    while (std::getline(csv, linha)) {
        stringstream ss(linha);
        Jogador jogador;

        if (
            std::getline(ss, jogador.nickname, ',') &&
            std::getline(ss, jogador.name, ',') &&
            ss >> jogador.vitoriasReversi && ss.ignore(1) &&
            ss >> jogador.derrotasReversi && ss.ignore(1) &&
            ss >> jogador.vitoriasLiga4 && ss.ignore(1) &&
            ss >> jogador.derrotasLiga4 && ss.ignore(1) &&
            ss >> jogador.vitoriasVelha && ss.ignore(1) &&
            ss >> jogador.derrotasVelha) 
        {
            jogadores.push_back(jogador);
        }
    }

    if (sel == 'A') {
        std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b) {
            return a.nickname < b.nickname;
        });
    } else if (sel == 'N') {
        std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b) {
            return a.name < b.name;
        });
    }

    for (const auto& jogador : jogadores) {
        std::cout << std::endl
            << "<" << jogador.nickname << "> " << "<" << jogador.name << ">" << std::endl
            << "REVERSI - V: " << "<" << jogador.vitoriasReversi << "> D: " << "<" << jogador.derrotasReversi << ">" << std::endl
            << "LIG4 - V: " << "<" << jogador.vitoriasLiga4 << "> D: " << "<" << jogador.derrotasLiga4 << ">" << std::endl
            << "VELHA - V: " << "<" << jogador.vitoriasVelha << "> D: " << "<" << jogador.derrotasVelha << ">" << std::endl
            << std::endl;
    }

    csv.close();
}

void updateScore(string winnerNickname, string looserNickname, int jogo) {
    ifstream csv;
    vector<string> linhas;
    string linha;

    csv.open(NOME_ARQ, std::fstream::in);

    // Ler o arquivo linha por linha
    while (std::getline(csv, linha)) {
        std::stringstream ss(linha);
        std::string nickname, name;
        int reversiV, reversiD, liga4V, liga4D, velhaV, velhaD;
        
        // Ler os campos da linha
        if (std::getline(ss, nickname, ',') &&
            std::getline(ss, name, ',') &&
            ss >> reversiV && ss.ignore(1) &&
            ss >> reversiD && ss.ignore(1) &&
            ss >> liga4V && ss.ignore(1) &&
            ss >> liga4D && ss.ignore(1) &&
            ss >> velhaV && ss.ignore(1) &&
            ss >> velhaD) {

            // Se o nickname corresponde, incrementar o campo correspondente
            if (nickname == winnerNickname) {
                switch (jogo) {
                    case 1: reversiV++; break;
                    case 2: liga4V++; break;
                    case 3: velhaV++; break;
                    }
            } else if (nickname == looserNickname) {
                switch (jogo) {
                    case 1: reversiD++; break;
                    case 2: liga4D++; break;
                    case 3: velhaD++; break;
                }
            }

            // Reescrever a linha com os dados atualizados
            std::ostringstream newLinha;
            newLinha
                << nickname << ","
                << name << ","
                << reversiV << ","
                << reversiD << ","
                << liga4V << "," 
                << liga4D << ","
                << velhaV << ","
                << velhaD;
                
            linhas.push_back(newLinha.str());

        } else {
            // Se houver erro ao processar a linha, mantê-la como está
            linhas.push_back(linha);
        }
    }

    csv.close();

    // Reescrever o arquivo com os dados atualizados
    ofstream updated_csv;
    updated_csv.open(NOME_ARQ, std::fstream::trunc);

    for (string linha : linhas) {
        updated_csv << linha << "\n";
    }

    updated_csv.close();
}

void updateScore(string nickname, int jogo) {
    ifstream csv;
    vector<string> linhas;
    string linha;

    csv.open(NOME_ARQ, std::fstream::in);

    // Ler o arquivo linha por linha
    while (std::getline(csv, linha)) {
        std::stringstream ss(linha);
        std::string nickname, name;
        int 
            reversiV, reversiD,
            liga4V, liga4D,
            velhaV, velhaD
            puzzleV, puzzleD,
            infinityV, infinityD;
        
        // Ler os campos da linha
        if (std::getline(ss, nickname, ',') &&
            std::getline(ss, name, ',') &&
            ss >> reversiV && ss.ignore(1) &&
            ss >> reversiD && ss.ignore(1) &&
            ss >> liga4V && ss.ignore(1) &&
            ss >> liga4D && ss.ignore(1) &&
            ss >> velhaV && ss.ignore(1) &&
            ss >> velhaD) {

            // Se o nickname corresponde, incrementar o campo correspondente
            if (nickname == winnerNickname) {
                switch (jogo) {
                    case 1: reversiV++; break;
                    case 2: liga4V++; break;
                    case 3: velhaV++; break;
                    }
            } else if (nickname == looserNickname) {
                switch (jogo) {
                    case 1: reversiD++; break;
                    case 2: liga4D++; break;
                    case 3: velhaD++; break;
                }
            }

            // Reescrever a linha com os dados atualizados
            std::ostringstream newLinha;
            newLinha
                << nickname << ","
                << name << ","
                << reversiV << ","
                << reversiD << ","
                << liga4V << "," 
                << liga4D << ","
                << velhaV << ","
                << velhaD;
                
            linhas.push_back(newLinha.str());

        } else {
            // Se houver erro ao processar a linha, mantê-la como está
            linhas.push_back(linha);
        }
    }

    csv.close();

    // Reescrever o arquivo com os dados atualizados
    ofstream updated_csv;
    updated_csv.open(NOME_ARQ, std::fstream::trunc);

    for (string linha : linhas) {
        updated_csv << linha << "\n";
    }

    updated_csv.close();
}