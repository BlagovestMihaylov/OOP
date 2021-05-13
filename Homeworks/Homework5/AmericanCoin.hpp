#pragma once


#include "Helper.h"

class AmericanCoin : public Coin
{


public:
    bool flip();
    AmericanCoin();
    void print() const;
    double AmericanToGermanCoin();
    double AmericanToGermanCoin(size_t);
    double AmericanToBulgarianCoin();
    double AmericanToBulgarianCoin(size_t);
};
