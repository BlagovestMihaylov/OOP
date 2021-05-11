#include "Coin.hpp"
#include <stdlib.h>
#include "Helper.h"

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

////////////////////////////////////////////////////////////////////////////////////
////BGCOIN

bool BulgarianCoin::flip()
{
    return Chance3070();
}

double BulgarianCoin::BulgarianToAmericanCoin()
{
    return BGtoUS(this->value, 1);
}

double BulgarianCoin::BulgarianToAmericanCoin(size_t coins)
{
    return BGtoUS(this->value, coins);
}

double BulgarianCoin::BulgarianToGermanCoin()
{
    return BGtoDE(this->value, 1);
}

double BulgarianCoin::BulgarianToGermanCoin(size_t coins)
{
    return BGtoDE(this->value, coins);
}

///////////////////////////////////////////////////////////
/////USCOIN

bool AmericanCoin::flip()
{
    return Chance9010();
}

double AmericanCoin::AmericanToBulgarianCoin()
{
    return UStoBG(this->value, 1);
}

double AmericanCoin::AmericanToBulgarianCoin(size_t coins)
{
    return UStoBG(this->value, coins);
}

double AmericanCoin::AmericanToGermanCoin()
{
    return UStoDe(this->value, 1);
}

double AmericanCoin::AmericanToGermanCoin(size_t coins)
{
    return UStoDe(this->value, coins);
}
/////////////////////////////////////////////////////////////////
////DECOIN
bool GermanCoin::flip()
{
    return Chance5050();
}

double GermanCoin::GermanToAmericanCoin()
{
    return DEtoUS(this->value, 1);
}

double GermanCoin::GermanToAmericanCoin(size_t coins)
{
    return DEtoUS(this->value, coins);
}

double GermanCoin::GermanToBulgarianCoin()
{
    return DEtoBG(this->value, 1);
}

double GermanCoin::GermanToBulgarianCoin(size_t coins)
{
    return DEtoBG(this->value, coins);
}