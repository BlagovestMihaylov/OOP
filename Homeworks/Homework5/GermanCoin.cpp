
#include "GermanCoin.hpp"

GermanCoin::GermanCoin()
{
    nationality = "DE";
    value = 0;
}

bool GermanCoin::flip()
{
    return helper::Chance5050();
}

double GermanCoin::GermanToAmericanCoin()
{
    return helper::DEtoUS(this->value, 1);
}

double GermanCoin::GermanToAmericanCoin(size_t coins)
{
    return helper::DEtoUS(this->value, coins);
}

double GermanCoin::GermanToBulgarianCoin()
{
    return helper::DEtoBG(this->value, 1);
}

double GermanCoin::GermanToBulgarianCoin(size_t coins)
{
    return helper::DEtoBG(this->value, coins);
}


void GermanCoin::print() const
{
    std::cout << "Coin nationality: " << nationality << std::endl;
    std::cout << "Coin value: " << value << std::endl;
    if (helper::Chance5050())
        std::cout << "Coin face is Heads\n";
    else
        std::cout << "Coin face is Tails\n";
}