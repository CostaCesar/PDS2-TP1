#include "TestHeader.hpp"

#include "Game_Velha_Infinity.hpp"

TEST_CASE("Jogo da velha infinito")
{
    Board* obj = new Game_Velha_Infinity();
    REQUIRE(obj != nullptr);

    obj->Play();

    delete obj;
}