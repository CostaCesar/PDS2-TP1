#include "TestHeader.hpp"

#include "Game_Reversi.hpp"

// "./bin/Reversi_Test < ./test/reversi_input.txt"
TEST_CASE("Reversi Creation")
{
    Board* object = new Game_Reversi();
    REQUIRE(object != nullptr);

    uint winner = object->Play();
    CHECK(winner == 2);

    // switch (object->Play())
    // {
    // case 1:
    //     std::cout << "# PLAYER 1 WINS #" << std::endl;
    //     break;
    // case 2:
    //     std::cout << "# PLAYER 2 WINS #" << std::endl;
    //     break;
    // case 0:
    //     std::cout << "# DRAW #" << std::endl;
    //     break;
    // }
    
    delete object;
}