
#include "GermanCoin.hpp"

GermanCoin::GermanCoin()
{
    nationality = "DE";
    value = 0;
}

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


void GermanCoin::print() const
{
    std::cout << "Coin nationality: " << nationality << std::endl;
    std::cout << "Coin value: " << value << std::endl;
    if (Chance5050())
        std::cout << "Coin face is Heads\n";
    else
        std::cout << "Coin face is Tails\n";
}