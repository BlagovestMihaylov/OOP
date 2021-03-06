#pragma once

#include "Coin.hpp"
#include "Helper.hpp"

class BulgarianCoin : public Coin
{

private:
    String nationality = "BG";

public:
    bool flip();
    BulgarianCoin();
    void print() const;
    double BulgarianToGermanCoin();
    double BulgarianToGermanCoin(size_t);
    double BulgarianToAmericanCoin();
    double BulgarianToAmericanCoin(size_t);
};
