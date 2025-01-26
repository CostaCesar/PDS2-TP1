#include "TestHeader.hpp"
#include <fstream>

#include "Game_Velha.hpp"

TEST_CASE("Jogo da velha")
{
    std::ifstream input;
    std::string path = INPUT_DIR;

    Board* object = new Game_Velha();
    REQUIRE(object != nullptr);


    SUBCASE("Game 0: X Win")
    {
        path += "./velha_x.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 1);
    }
    SUBCASE("Game 1: O Win")
    {
        path += "./velha_o.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 2);
    }
    SUBCASE("Game 2: Perfetct Game [Draw]")
    {
        path += "./velha_draw.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);

        uint winner = object->Play();
        CHECK(winner == 0);
    }

    delete object;
    input.close();
}
