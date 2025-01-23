#include "Game_Liga4.hpp"

#include <iostream>

Game_Liga4::Game_Liga4(uint rows, uint cols) : Board(Vec2{rows, cols}) {
    current_player = 1;
}

Game_Liga4::~Game_Liga4() {}

uint Game_Liga4::Play() {
    Vec2 last_move;

    uint num_plays = GetSize().x * GetSize().y;

    while (num_plays > 0)
    {
        Draw();

        while (1)
        {
            try
            {
                last_move = ReadMove();
            }
            catch(const std::exception& e)
            {
                std::cout << "Entrada invalida!" << std::endl;
                continue;
            }
            break;
        }
        
        Piece* piece = new Piece(last_move, current_player);

        if (!AddPiece(piece)) {
            std::cout << "ERRO: jogada inválida" << std::endl;
            delete piece;
            continue;
        }

        if (CheckWin(current_player, last_move))
            break;

        num_plays--;
        NextPlayer();
    }

    Draw();
    return GetWinner();
}

uint Game_Liga4::EmptyRow(uint column) {
    for (uint row = GetSize().y ; row > 0; --row) {
        if (GetPiece(Vec2{column, row-1}) == nullptr) {
            return row-1;
        }
    }

    return GetSize().y;
}

Vec2 Game_Liga4::ReadMove()
{
    Vec2 output;

    try
    {
        output.x = GetUintFromInput();
    }
    catch(const std::exception& e)
    {
        // Flush Bad Stream
        FlushInput();
        throw e;
    }

    output.y = EmptyRow(output.x);
    return output;
}

uint Game_Liga4::GetWinner()
{
    if(IsDraw())
        return 0;
    else return current_player;
}

bool Game_Liga4::CheckWin(uint player, const Vec2& last_move) {
    for (uint i = 0; i < 8; i++)
    {
        if(MatchUntilStep(last_move, (Direction) i, 3) == MatchReturn::Matched)
            return true;
    }

    return false;
}

bool Game_Liga4::IsDraw() {
    for (uint x = 0; x < GetSize().x; ++x) {
        if (GetPiece(Vec2{x, GetSize().y - 1}) == nullptr) {
            return false;
        }
    }
    return true;
}