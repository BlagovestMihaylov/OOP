#pragma once

#include "Helper.hpp"

class GermanCoin : public Coin
{

public:
    bool flip();
    GermanCoin();
    void print() const;
    double GermanToBulgarianCoin();
    double GermanToBulgarianCoin(size_t);
    double GermanToAmericanCoin();
    double GermanToAmericanCoin(size_t);
};