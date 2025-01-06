#pragma once

#include "Defs.hpp"

struct Vec2
{
    uint x;
    uint y;

    bool operator== (const Vec2 &a) const
    { return ((this->x == a.x) && (this->y == a.y)); }
    bool operator!= (const Vec2 &a) const
    { return ((this->x != a.x) || (this->y != a.y)); }
};
