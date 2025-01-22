#include "TestHeader.hpp"
#include <fstream>

#include "Game_Reversi.hpp"

// "./bin/Reversi_Test < ./test/reversi_input.txt"
TEST_CASE("Reversi")
{
    using std::ifstream;
    ifstream input;
    Board* object = new Game_Reversi();
    REQUIRE(object != nullptr);
    
    SUBCASE("Game 0: White Win")
    {
        input.open("./reversi_white.txt");
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 1);
    }
    SUBCASE("Game 1: Black Win")
    {
        input.open("./reversi_black.txt");
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 2);
    }
    SUBCASE("Game 2: Perfetct Game [Draw]")
    {
        input.open("reversi_draw.txt");
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);

        uint winner = object->Play();
        CHECK(winner == 0);
    }

    delete object;
    input.close();
}