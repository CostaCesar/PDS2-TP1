#include "TestHeader.hpp"

#include "Game_Reversi.hpp"

TEST_CASE("Reversi Creation")
{
    Board* object = new Game_Reversi();

    object->Play();
    object->Play();
    object->Play();
    object->Play();
    object->Play();

    delete object;
}