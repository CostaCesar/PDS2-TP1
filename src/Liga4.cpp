#include "Liga4.hpp"
#include <iostream>

Liga4::Liga4(uint rows, uint cols) : Board(Vec2{rows, cols}) {
    current_player = 1;
}

Liga4::~Liga4() {}

uint Liga4::Play() {
    Vec2 last_move;
    uint num_plays = GetSize().x * GetSize().y;

    while (num_plays > 0) {
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #else
            system("clear");
        #endif

        std::cout << "Player " << current_player << '\n' << std::endl;
        Draw();

        bool valid_move = false;
        while (!valid_move) {
            try {
                last_move = ReadMove();
                valid_move = true;
            } catch (const std::exception& e) {
                std::cout << "ERRO: " << e.what() << std::endl;
            }
        }

        char symbol = (current_player == 1) ? 'X' : 'O';
        Piece* piece = new Piece(last_move, current_player, symbol);

        if (!AddPiece(piece)) {
            delete piece;
            continue;
        }

        if (CheckWin(current_player, last_move)) {
            std::cout << "\n\nPlayer " << current_player << " venceu!" << std::endl;
            break;
        }

        num_plays--;
        if (IsDraw()) {
            std::cout << "\n\nEmpate" << std::endl;
            break;
        }

        NextPlayer();
    }

    Draw();
    return GetWinner();
}

uint Liga4::EmptyRow(uint column) {
    for (uint row = GetSize().y; row > 0; --row) {
        if (GetPiece(Vec2{column, row-1}) == nullptr) {
            return row-1;
        }
    }
    return GetSize().y;
}

Vec2 Liga4::ReadMove() {
    Vec2 output;
    std::string input_str;
    std::getline(std::cin, input_str);

    for (size_t i = 0; i < input_str.length(); i++) {
        if (!isdigit(input_str[i])) { // isdigit é o caminho
            throw std::invalid_argument("Entrada invalida!");
        }
    }

    output.x = std::atoi(input_str.c_str());
    if (output.x < 0 || output.x >= GetSize().x) {
        throw std::out_of_range("Jogada invalida!");
    }

    output.y = EmptyRow(output.x);
    if (output.y == GetSize().y) {
        throw std::out_of_range("Jogada invalida!");
    }

    return output;
}

uint Liga4::GetWinner() {
    return IsDraw() ? 0 : current_player;
}

bool Liga4::CheckWin(uint player, const Vec2& last_move) {
    for (uint i = 0; i < 8; i++) {
        if (MatchUntilStep(last_move, (Direction)i, 3) == MatchReturn::Matched) {
            return true;
        }
    }
    return false;
}

bool Liga4::IsDraw() {
    for (uint x = 0; x < GetSize().x; ++x) {
        if (GetPiece(Vec2{x, GetSize().y - 1}) == nullptr) {
            return false;
        }
    }
    return true;
}
