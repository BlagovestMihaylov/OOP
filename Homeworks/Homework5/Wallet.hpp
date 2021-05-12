#ifndef WALLET_HPP
#define WALLET_HPP

#include "Vector.hpp"
#include "Coin.hpp"
#include "Helper.h"

class Wallet
{
private:
    Vector<Coin> money;
    String moneyType;
    void preAddCoin(Coin);

public:
    void addCoin(Coin);
    void removeCoin();
    Wallet();
    Wallet(String);
    String getMoneyType();
    void changerMoneyType(String);
    size_t getSize();
};

#endif