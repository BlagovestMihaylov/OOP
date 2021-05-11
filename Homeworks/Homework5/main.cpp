#include <iostream>
#include "Coin.hpp"

int main()
{
    BulgarianCoin bgc;
    bgc.changeValue(217);
    bgc.print();
    GermanCoin dec;
    dec.changeValue(100);
    dec.changeValue(dec.GermanToBulgarianCoin());
    dec.print();
}