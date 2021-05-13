#include "AmericanCoin.hpp"


AmericanCoin::AmericanCoin()
{
    nationality = "US";
    value = 0;
}

bool AmericanCoin::flip()
{
    return helper::Chance9010();
}

double AmericanCoin::AmericanToBulgarianCoin()
{
    return helper::UStoBG(this->value, 1);
}

double AmericanCoin::AmericanToBulgarianCoin(size_t coins)
{
    return helper::UStoBG(this->value, coins);
}

double AmericanCoin::AmericanToGermanCoin()
{
    return helper::UStoDe(this->value, 1);
}

double AmericanCoin::AmericanToGermanCoin(size_t coins)
{
    return helper::UStoDe(this->value, coins);
}


void AmericanCoin::print() const
{
    std::cout << "Coin nationality: " << nationality << std::endl;
    std::cout << "Coin value: " << value << std::endl;
    if (helper::Chance5050())
        std::cout << "Coin face is Heads\n";
    else
        std::cout << "Coin face is Tails\n";
}