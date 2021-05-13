#include "Helper.hpp"


Coin::Coin()
{
    nationality = "UNKNOWN";
    value = 0;
}

Coin::Coin(String nat, int v)
{
    nationality = nat;
    value = v;
}

bool Coin::flip()
{
    return Chance5050();
}

void Coin::print() const
{
    std::cout << "Coin nationality: " << nationality << std::endl;
    std::cout << "Coin value: " << value << std::endl;
    if (Chance5050())
        std::cout << "Coin face is Heads\n";
    else
        std::cout << "Coin face is Tails\n";
}

void Coin::changeValue(double _newValue)
{
    value = _newValue;
}

String Coin::checkNationality() const
{
    return nationality;
}

double Coin::checkValue() const
{
    return value;
}