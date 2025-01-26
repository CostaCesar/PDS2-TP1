#include "TestHeader.hpp"

#include "Game_Liga4.hpp"

TEST_CASE("Liga 4")
{  
    Board* obj;

    std::string path = INPUT_DIR;
    path += "liga4_moves.txt";
    std::ifstream input(path);
    REQUIRE(input.is_open() == true);

    SUBCASE("Game 1: Vertical Win")
    {
        obj = new Game_Liga4(9, 7);
        obj->AssignInput(&input);
        CHECK(obj->Play() == 1);
    }

    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    SUBCASE("Game 2: Horizontal Win")
    {
        obj = new Game_Liga4(9, 7);
        obj->AssignInput(&input);
        CHECK(obj->Play() == 1);
    }

    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    SUBCASE("Game 3: Diagonal Win")
    {
        obj = new Game_Liga4(9, 7);
        obj->AssignInput(&input);
        CHECK(obj->Play() == 2);
    }

    input.close();
    delete obj;
}