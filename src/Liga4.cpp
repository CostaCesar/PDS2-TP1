#include "Liga4.hpp"
#include <iostream>

Liga4::Liga4(uint rows, uint cols) : Board(Vec2{rows, cols}) {
    current_player = 1;
}

Liga4::~Liga4() {}

uint Liga4::Play() {
    uint column;
    Vec2 last_move;

    uint num_plays = GetSize().x * GetSize().y;

    while (num_plays > 0)
    {
        Draw();

        std::cin >> column;
        uint row = EmptyRow(column);

        last_move = Vec2{column, row};
        Piece* piece = new Piece(last_move, current_player);

        if (!AddPiece(piece)) {
            std::cout << "ERRO: jogada inválida" << std::endl;
            delete piece;
            continue;
        }

        if (CheckWin(current_player, last_move))
            break;

        NextPlayer();
    }

    Draw();
    return GetWinner();
}

uint Liga4::EmptyRow(uint column) {
    for (uint row = GetSize().y ; row > 0; --row) {
        if (GetPiece(Vec2{column, row-1}) == nullptr) {
            return row-1;
        }
    }

    return GetSize().y;
}

uint Liga4::GetWinner()
{
    if(IsDraw())
        return 0;
    else return current_player;
}

bool Liga4::CheckWin(uint player, const Vec2& last_move) {
    for (uint i = 0; i < 8; i++)
    {
        if(MatchUntilStep(last_move, (Direction) i, 3) == MatchReturn::Matched)
            return true;
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