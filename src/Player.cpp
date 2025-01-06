#include "Register.hpp"

map<string, uint> Player::GetWins(string game)
{
    return this->wins[game];
}
void AddWins(string game)
{
    this->wins[game] += 1;
}

map<string, uint> Player::GetLosses(string game)
{
    return this->losses[game];
}
void AddLosses(string game)
{
    this->losses[game] += 1;
}

string Player::GetName()
{
    return this->name;
}

string Player::GetNickname()
{
    return this->nickname
}

Player::Player(string _name, string _nickname)
{
    this->name = _name;
    this->nickname = _nickname;
}
