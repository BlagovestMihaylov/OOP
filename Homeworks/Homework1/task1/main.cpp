#include <iostream>
#include "Crypto.h"

int main()
{
    
    Crypto c1;
    c1.setName("FMI_coin");
    c1.setLastPrice(69);
    c1.setCurrentPrice(420);
    c1.priceDifference();
    c1.print();
}