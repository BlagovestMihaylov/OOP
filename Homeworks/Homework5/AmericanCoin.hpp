#pragma once

#include "Coin.hpp"
#include "Helper.hpp"

class AmericanCoin : public Coin
{
private:
    String nationality = "US";

public:
    bool flip();
    AmericanCoin();
    void print() const;
    double AmericanToGermanCoin();
    double AmericanToGermanCoin(size_t);
    double AmericanToBulgarianCoin();
    double AmericanToBulgarianCoin(size_t);
};
