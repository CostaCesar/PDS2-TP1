#include "Liga4.hpp"
#include <iostream>

Liga4::Liga4(uint rows, uint cols) : Board(Vec2{rows, cols}) {
    current_player = 1;
    game_over = false;
}

Liga4::~Liga4() {
}

void Liga4::SwitchPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
}

uint Liga4::Play() {
    uint column;

    while (!game_over) {
        Draw();

        std::cout << "Jogador " << current_player << ", escolha uma coluna: ";
        std::cin >> column;

        if (!AddPiece(new Piece(Vec2{0, column}, current_player))) {
            std::cout << "Coluna inválida ou cheia. Tente novamente." << std::endl;
            continue;
        }

        if (CheckWin(current_player)) {
            game_over = true;
            std::cout << "Jogador " << current_player << " venceu!" << std::endl;
        }

        else if (IsDraw()) {
            game_over = true;
            std::cout << "O jogo terminou em empate!" << std::endl;
        }

        if (!game_over) {
            SwitchPlayer();
        }
    }

    return GetWinner();
}

bool Liga4::CheckWin(uint player) {

    for (uint y = 0; y < GetSize().y; ++y) {
        for (uint x = 0; x < GetSize().x - 3; ++x) {
            if (GetPiece(Vec2{x, y}) != nullptr && GetPiece(Vec2{x, y})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 1, y}) != nullptr && GetPiece(Vec2{x + 1, y})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 2, y}) != nullptr && GetPiece(Vec2{x + 2, y})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 3, y}) != nullptr && GetPiece(Vec2{x + 3, y})->GetPlayerId() == player) {
                return true;
            }
        }
    }

    for (uint x = 0; x < GetSize().x; ++x) {
        for (uint y = 0; y < GetSize().y - 3; ++y) {
            if (GetPiece(Vec2{x, y}) != nullptr && GetPiece(Vec2{x, y})->GetPlayerId() == player &&
                GetPiece(Vec2{x, y + 1}) != nullptr && GetPiece(Vec2{x, y + 1})->GetPlayerId() == player &&
                GetPiece(Vec2{x, y + 2}) != nullptr && GetPiece(Vec2{x, y + 2})->GetPlayerId() == player &&
                GetPiece(Vec2{x, y + 3}) != nullptr && GetPiece(Vec2{x, y + 3})->GetPlayerId() == player) {
                return true;
            }
        }
    }

    for (uint x = 0; x < GetSize().x - 3; ++x) {
        for (uint y = 0; y < GetSize().y - 3; ++y) {
            if (GetPiece(Vec2{x, y}) != nullptr && GetPiece(Vec2{x, y})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 1, y + 1}) != nullptr && GetPiece(Vec2{x + 1, y + 1})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 2, y + 2}) != nullptr && GetPiece(Vec2{x + 2, y + 2})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 3, y + 3}) != nullptr && GetPiece(Vec2{x + 3, y + 3})->GetPlayerId() == player) {
                return true;
            }
        }
    }

    for (uint x = 0; x < GetSize().x - 3; ++x) {
        for (uint y = 3; y < GetSize().y; ++y) {
            if (GetPiece(Vec2{x, y}) != nullptr && GetPiece(Vec2{x, y})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 1, y - 1}) != nullptr && GetPiece(Vec2{x + 1, y - 1})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 2, y - 2}) != nullptr && GetPiece(Vec2{x + 2, y - 2})->GetPlayerId() == player &&
                GetPiece(Vec2{x + 3, y - 3}) != nullptr && GetPiece(Vec2{x + 3, y - 3})->GetPlayerId() == player) {
                return true;
            }
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