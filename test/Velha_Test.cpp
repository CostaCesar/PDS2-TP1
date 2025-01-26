#include "TestHeader.hpp"

#include "Game_Velha.hpp"

TEST_CASE("Jogo da velha")
{
    Board* obj = new Game_Velha();
    REQUIRE(obj != nullptr);

    obj->Play();

    delete obj;
}
