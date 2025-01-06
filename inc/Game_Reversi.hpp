#pragma once

#include "Board.hpp"
#include <unordered_set>
using std::unordered_set;

// Here because there's a unordered set of Vec2
struct Vec2Hash
{
    size_t operator()(const Vec2& vec) const
    {
    size_t xHash = std::hash<int>()(vec.x);
    size_t yHash = std::hash<int>()(vec.y) << 1;
    return xHash ^ yHash;
    }
};

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
    unordered_set<Vec2, Vec2Hash> border_tiles;

    bool AddPiece(Piece* new_piece);
    void Draw();
    uint GetWinner() override;
    bool IsDraw() override;

    bool March(Vec2 &start_pos, uint direction);
    void CalculateBorders(Vec2 position);
    void CascadeMove(Piece* start_piece);
    void MarkAsPlayable();

public:
    uint Play();

    Game_Reversi(uint _num_plays = 30);
    ~Game_Reversi();

};