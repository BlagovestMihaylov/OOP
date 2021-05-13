#pragma once


#include "Vector.hpp"
#include "Helper.hpp"

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

