#pragma once

typedef unsigned int uint;

enum class Direction
{
    North = 0,
    NorthEast = 1,
    East = 2,
    SouthEast = 3,
    South = 4,
    SouthWest = 5,
    West = 6,
    NorthWest = 7
};
struct Vec2
{
    uint x;
    uint y;

    bool operator== (const Vec2 &a) const
    { return ((this->x == a.x) && (this->y == a.y)); }
    bool operator!= (const Vec2 &a) const
    { return ((this->x != a.x) || (this->y != a.y)); }
};
