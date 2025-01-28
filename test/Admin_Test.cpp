#include "TestHeader.hpp"
#include "Admin.hpp"
#include <string>

TEST_CASE("Administração dos Jogos")
{
    std::string test_arq = "test.csv";
    SUBCASE("Jogo Válido")
    {
        CHECK(validGame('R') == 1);
    }
    
    SUBCASE("Jogo Inválido")
    {
        CHECK(validGame('J') == 0);
    }
}