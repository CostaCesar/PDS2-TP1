#include "TestHeader.hpp"

#include "Velha.hpp"

TEST_CASE("Puzzle Game")
{
    Board* obj = new JogoDaVelha();
    REQUIRE(obj != nullptr);

    obj->Play();

    delete obj;
}