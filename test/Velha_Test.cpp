#include "TestHeader.hpp"

#include "Game_Velha.hpp"

TEST_CASE("Jogo da velha")
{
    Game_Velha* obj = new Game_Velha();
    REQUIRE(obj != nullptr);

    obj->Play();

    delete obj;
}

TEST_CASE("Jogo da velha infinito")
{
    Game_Velha* obj = new Game_Velha();
    REQUIRE(obj != nullptr);

    obj->Play_Infinity();

    delete obj;
}