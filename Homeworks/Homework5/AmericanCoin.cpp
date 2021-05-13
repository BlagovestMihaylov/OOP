#include "AmericanCoin.hpp"


AmericanCoin::AmericanCoin()
{
    nationality = "US";
    value = 0;
}

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


void AmericanCoin::print() const
{
    std::cout << "Coin nationality: " << nationality << std::endl;
    std::cout << "Coin value: " << value << std::endl;
    if (Chance5050())
        std::cout << "Coin face is Heads\n";
    else
        std::cout << "Coin face is Tails\n";
}