#include "Liga4.hpp"
#include <iostream>

Liga4::Liga4(uint rows, uint cols) : Board(Vec2{rows, cols}) {
    current_player = 1;
    game_over = false;
}

Liga4::~Liga4() {}

void Liga4::SwitchPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
}

uint Liga4::Play() {
    uint column;
    Vec2 last_move;

    while (!game_over) {
        Draw();

        std::cin >> column;
        uint row = EmptyRow(column);

        if (!AddPiece(new Piece(Vec2{0, column}, current_player))) {
            std::cout << "ERRO: jogada inválida" << std::endl;
            continue;
        }

        last_move = Vec2{row, column};

        if (CheckWin(current_player, last_move)) {
            game_over = true;
        } else if (IsDraw()) {
            game_over = true;
        }

        if (!game_over) {
            SwitchPlayer();
        }
    }

    return GetWinner();
}

uint Liga4::EmptyRow(uint column) {
    for (uint row = GetSize().y ; row > 0; --row) {
        if (GetPiece(Vec2{row-1, column}) == nullptr) {
            return row;
        }
    }

    return GetSize().y;
}

bool Liga4::CheckWin(uint player, const Vec2& last_move) {
    uint x = last_move.x;
    uint y = last_move.y;

    for (int dx = -3; dx <= 3; ++dx) {
        if (GetPiece(Vec2{x + dx, y}) != nullptr && GetPiece(Vec2{x + dx, y})->GetPlayerId() == player) {
            if (CheckDirection(x, y, dx, 0, player)) return true;
        }
    }

    for (int dy = -3; dy <= 3; ++dy) {
        if (GetPiece(Vec2{x, y + dy}) != nullptr && GetPiece(Vec2{x, y + dy})->GetPlayerId() == player) {
            if (CheckDirection(x, y, 0, dy, player)) return true;
        }
    }

    if (CheckDirection(x, y, 1, 1, player)) return true;
    if (CheckDirection(x, y, -1, 1, player)) return true;

    return false;
}

bool Liga4::CheckDirection(uint x, uint y, int dx, int dy, uint player) {
    for (int i = 1; i < 4; ++i) {
        if (GetPiece(Vec2{x + i * dx, y + i * dy}) == nullptr ||
            GetPiece(Vec2{x + i * dx, y + i * dy})->GetPlayerId() != player) {
            return false;
        }
    }
    return true;
}

bool Liga4::IsDraw() {
    for (uint x = 0; x < GetSize().x; ++x) {
        if (GetPiece(Vec2{x, GetSize().y - 1}) == nullptr) {
            return false;
        }
    }
    return true;
}