#include "Game_Liga4.hpp"
#include <iostream>

Game_Liga4::Game_Liga4(uint rows, uint cols) 
    : Board(Vec2{rows, cols})
{
    this->num_plays = GetSize().x * GetSize().y;
    this->current_player = 1;
}

Game_Liga4::~Game_Liga4() {}

const std::string color_player1 = "\033[91m"; // Vermelho 1
const std::string color_player2 = "\033[93m"; // Amarelo 2
const std::string reset_color = "\033[0m";    // Resetando a cor

uint Game_Liga4::Play() {
    Vec2 last_move;
    uint invalid_move_count = 0;

    while (this->num_plays > 0) {
        std::cout << (current_player == 1 ? color_player1 : color_player2) 
                  << "\nJogador " << current_player << reset_color << "\n" << std::endl;

        Draw();

        bool valid_move = false;
        while (!valid_move) {
            try {
                last_move = ReadMove();
                valid_move = true;
            } catch (const std::exception& e) {
                std::cout << "ERRO: " << e.what() << std::endl;
                invalid_move_count++;

                if (invalid_move_count >= 15) {
                    std::cerr << color_player1 << "\nERRO: Entrada incorreta muitas vezes ou numero insuficiente de jogadas\n" << reset_color << std::endl;
                    return 0;
                }
            }
        }

        char symbol = (current_player == 1) ? 'X' : 'O';
        Piece* piece = new Piece(current_player, symbol);

        if (!AddPiece(last_move, piece)) {
            delete piece;
            continue;
        }

        if (IsReadingFromCin()){
            #if defined(_WIN32) || defined(_WIN64)
                system("cls");
            #else
                system("clear");
            #endif 
        }

        if (CheckWin(current_player, last_move)) {
            std::cout << (current_player == 1 ? color_player1 : color_player2) 
                      << "Jogador " << current_player << " venceu!" << reset_color << "\n" << std::endl;
            break;
        }

        num_plays--;
        NextPlayer();
    }

    return GetWinner();
}

uint Game_Liga4::EmptyRow(uint column) {
    for (uint row = GetSize().y; row > 0; --row) {
        if (GetPiece(Vec2{column, row - 1}) == nullptr)
            return row - 1;
    }
    return GetSize().y;
}

Vec2 Game_Liga4::ReadMove() {
    Vec2 output;

    try {
        output.x = GetUintFromInput();
        AssertEmptyInput();
    }
    catch (const std::exception& e) {
        FlushInput();
        throw std::invalid_argument("Entrada invalida!");
    }

    if (output.x < 0 || output.x >= GetSize().x)
        throw std::out_of_range("Jogada invalida!");

    output.y = EmptyRow(output.x);
    if (output.y == GetSize().y) 
        throw std::out_of_range("Jogada invalida!");

    return output;
}

uint Game_Liga4::GetWinner() {
    if (IsDraw())
        std::cout << "Empate!\n" << std::endl;
    Draw();
    return IsDraw() ? 0 : current_player;
}

bool Game_Liga4::CheckWin(uint player, const Vec2 &last_move) {
    for (uint i = 0; i < 8; i++) {
        if (MatchUntilStep(last_move, (Direction)i, 3) == MatchReturn::Matched)
            return true;
    }
    return false;
}

bool Game_Liga4::IsDraw() {
    return num_plays == 0;
}
