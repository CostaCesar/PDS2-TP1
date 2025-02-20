#include "TestHeader.hpp"
#include "Game_Puzzle.hpp"

TEST_CASE("Puzzle Game")
{
    Board* obj;
    
    std::string path = INPUT_DIR;
    path += "puzzle_moves.txt";
    std::ifstream input(path);
    REQUIRE(input.is_open() == true);

    SUBCASE("Game 1")
    {
        obj = new Game_Puzzle(500, 100);
        obj->AssignInput(&input);
        CHECK(obj->Play() == 1);
    }
    NextCase(input);
    SUBCASE("Game 2")
    {
        obj = new Game_Puzzle(500, 420);
        obj->AssignInput(&input);
        CHECK(obj->Play() == 1);
    }
    NextCase(input);
    SUBCASE("Game 3")
    {
        obj = new Game_Puzzle(400, 101);
        obj->AssignInput(&input);
        CHECK(obj->Play() == 1);
    }

    delete obj;
    input.close();
}