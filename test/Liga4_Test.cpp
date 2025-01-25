#include "TestHeader.hpp"

#include "Liga4.hpp"

TEST_CASE("Liga 4")
{
    Board* a = new Liga4(7, 6);

    a->Play();

    delete a;
}