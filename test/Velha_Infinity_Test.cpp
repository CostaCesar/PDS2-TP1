#include "TestHeader.hpp"
#include <fstream>

#include "Game_Velha_Infinity.hpp"

TEST_CASE("Jogo da velha infinito")
{
    std::ifstream input;
    std::string path = INPUT_DIR;

    Board* object = new Game_Velha_Infinity();
    REQUIRE(object != nullptr);


    SUBCASE("Game 0: X Win")
    {
        path += "./velha_infinity_x.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 1);
    }
    SUBCASE("Game 1: O Win")
    {
        path += "./velha_infinity_o.txt";
        input.open(path);
        REQUIRE(input.is_open() == true);
        object->AssignInput(&input);
        
        uint winner = object->Play();
        CHECK(winner == 2);
    }

    delete object;
    input.close();
}