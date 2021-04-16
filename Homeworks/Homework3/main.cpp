#include <iostream>
#include "MyString.h"
#include "EarthCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "WaterCard.h"

int main()
{
    EarthCard Earth("Darius", 10, 69);
    Earth.addPower(21);
    Earth.changeCardName("Malphite");
    Earth.FullStats();
    std::cout << std::endl;
    FireCard Fire("Brand", 15, 75);
    Fire.addPower(420);
    Fire.FullStats();
    std::cout << std::endl;
    WindCard Wind("Yasuo", 1337, 55);
    Wind.FullStats();
    std::cout << std::endl;
    WaterCard Water("Nami", 0, 1234);
    Water.FullStats();
}