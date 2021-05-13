#include "BulgarianCoin.hpp"

BulgarianCoin::BulgarianCoin()
{
    nationality = "BG";
    value = 0;
}

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


void BulgarianCoin::print() const
{
    std::cout << "Coin nationality: " << nationality << std::endl;
    std::cout << "Coin value: " << value << std::endl;
    if (Chance5050())
        std::cout << "Coin face is Heads\n";
    else
        std::cout << "Coin face is Tails\n";
}