#include "TestHeader.hpp"

#include "Game_Velha.hpp"

TEST_CASE("Puzzle Game")
{
    Game_Velha* obj = new Game_Velha();
    REQUIRE(obj != nullptr);

    obj->Play_Infinity();

    delete obj;
}