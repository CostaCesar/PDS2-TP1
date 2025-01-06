#pragma once

#include "Board.hpp"

class Game_Reversi : public Board
{
private:
    static const char k_player1 = '#';
    static const char k_player2 = 'O';
    static const char k_available = '.';

    uint white_count;
    uint black_count;

    uint num_plays;
    uint current_player;
    vector<Vec2> border_tiles;

    bool AddPiece(Piece* new_piece);
    void Draw();
    uint GetWinner() override;
    bool IsDraw() override;

    bool March(Vec2 &start_pos, uint direction);
    void CalculateBorders();
    void CascadeMove(Piece* start_piece);
    void MarkAsPlayable();

public:
    uint Play();

    Game_Reversi(uint _num_plays = 30);
    ~Game_Reversi();

};