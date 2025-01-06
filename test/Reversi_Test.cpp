#include "TestHeader.hpp"

#include "Game_Reversi.hpp"

TEST_CASE("Reversi Creation")
{
    Board* object = new Game_Reversi();

    switch (object->Play())
    {
    case 1:
        std::cout << "# PLAYER 1 WINS #" << std::endl;
        break;
    case 2:
        std::cout << "# PLAYER 2 WINS #" << std::endl;
        break;
    case 0:
        std::cout << "# DRAW #" << std::endl;
        break;
    }
    
    delete object;
}