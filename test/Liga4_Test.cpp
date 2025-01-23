#include "TestHeader.hpp"

#include "Game_Liga4.hpp"

TEST_CASE("Liga 4")
{
    Board* a = new Game_Liga4(8, 8);

    a->Play();

    delete a;
}