#include "TestHeader.hpp"
#include "Register.hpp"
#include <string>

TEST_CASE("Registro de Jogadores")
{
    std::string test_arq = "test.csv";
    SUBCASE("Jogador existe")
    {
        CHECK(playerExists("Doe", test_arq) == 1);
    }
    
    SUBCASE("Jogador não existe")
    {
        CHECK(playerExists("Fulano", test_arq) == 0);
    }
}