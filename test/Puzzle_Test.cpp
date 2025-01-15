#include "TestHeader.hpp"

#include "Game_Puzzle.hpp"

TEST_CASE("Puzzle Game")
{
    Board* obj = new Game_Puzzle(500);
    REQUIRE(obj != nullptr);

    obj->Play();

    delete obj;
}