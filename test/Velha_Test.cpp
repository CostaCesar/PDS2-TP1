#include "TestHeader.hpp"

#include "Game_Velha.hpp"

TEST_CASE("Puzzle Game")
{
    Board* obj = new Game_Velha();
    REQUIRE(obj != nullptr);

    obj->Play();

    delete obj;
}