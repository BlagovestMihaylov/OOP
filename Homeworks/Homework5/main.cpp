#include <iostream>
#include "Coin.hpp"
#include "Wallet.hpp"

int main()
{
    BulgarianCoin bgc;
    bgc.changeValue(217);
    bgc.print();
    GermanCoin dec;
    dec.changeValue(100);
    dec.changeValue(dec.GermanToBulgarianCoin());
    dec.print();
    Wallet wallet1;
    wallet1.changerMoneyType("BG");
    wallet1.addCoin(bgc);
    wallet1.addCoin(dec);
}