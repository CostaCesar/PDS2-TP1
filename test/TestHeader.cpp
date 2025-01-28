#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "TestHeader.hpp"

void NextCase(std::istream& input)
{   
    std::string buffer = "";
    while (buffer != "#" && !input.eof())
    {
        input >> buffer;
    }
}