#pragma once


#include "Helper.h"


class BulgarianCoin : public Coin
{

public:
    bool flip();
    BulgarianCoin();
    void print() const;
    double BulgarianToGermanCoin();
    double BulgarianToGermanCoin(size_t);
    double BulgarianToAmericanCoin();
    double BulgarianToAmericanCoin(size_t);
};
