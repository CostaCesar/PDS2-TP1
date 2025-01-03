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
    uint GetWinner();
    bool IsDraw();
    void Draw();

    //bool IsValidForPlay(uint player_id, Vec2 position);
    void CalculateBorders();
public:
    uint Play();

    Game_Reversi(uint _num_plays = 30);
    ~Game_Reversi();

    void MarkAsPlayable();
};