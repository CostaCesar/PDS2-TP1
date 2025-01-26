#include "TestHeader.hpp"
#include <fstream>

#include "Game_Reversi.hpp"

TEST_CASE("Reversi")
{
    std::ifstream input;
    std::string path = INPUT_DIR;

    Board* object = new Game_Reversi();
    REQUIRE(object != nullptr);


    SUBCASE("Game 0: White Win")
    {
        path += "./reversi_white.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 1);
    }
    SUBCASE("Game 1: Black Win")
    {
        path += "./reversi_black.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 2);
    }
    SUBCASE("Game 2: Perfetct Game [Draw]")
    {
        path += "./reversi_draw.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);

        uint winner = object->Play();
        CHECK(winner == 0);
    }


    delete object;
    input.close();
}