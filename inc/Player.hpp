#pragma once

#include "Defs.hpp"
#include <string>
#include <map>

using std::string;
using std::map;

class Player 
{
private:
    map<string, uint> wins;
    map<string, uint> losses;

    string name;
    string nickname;
public:
    map<string, uint> GetWins(string game);
    void AddWins(string game);

    map<string, uint> GetLosses(string game);
    void AddLosses(string game);

    string GetName();
    string GetNickname();

    Player(string _name, string _nickname);
};