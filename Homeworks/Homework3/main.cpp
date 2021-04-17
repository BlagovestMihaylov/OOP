#include <iostream>
#include "MyString.h"
#include "EarthCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "WaterCard.h"
#include "Deck.h"
#include "Player.h"

int main()
{
    EarthCard Earth("Darius", 10, 69);
    Earth.addPower(21);
    Earth.changeCardName("Malphite");
    // Earth.FullStats();
    // std::cout << std::endl;
    // FireCard Fire("Brand", 15, 75);
    // Fire.addPower(420);
    // Fire.FullStats();
    // std::cout << std::endl;
    // WindCard Wind("Yasuo", 1337, 55);
    // Wind.FullStats();
    // std::cout << std::endl;
    // WaterCard Water("Nami", 0, 1234);
    // Water.FullStats();

    EarthCard Earth1("Darius1", 10, 69);
    EarthCard Earth2("Darius2", 10, 69);
    EarthCard Earth3("Darius3", 10, 69);
    EarthCard Earth4("Darius1", 10, 69);
    Deck<EarthCard> earhtDeck;
    earhtDeck.addCard(Earth);
    earhtDeck.addCard(Earth1);
    earhtDeck.addCard(Earth2);
    earhtDeck.addCard(Earth3);
    earhtDeck.ShowDeck();
    //EarthCard e = earhtDeck.drawCard();
    earhtDeck.addCard(Earth4);
    // std::cout << "Old deck" << std::endl;
    // earhtDeck.ShowDeck();

    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "New deck" << std::endl;
    // earhtDeck.shuffle();
    earhtDeck.ShowDeck();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Player<EarthCard, WaterCard> earthPlayer("Blagovest", 3, 2);
    earthPlayer.setPrimaryDeck(earhtDeck);
    EarthCard t;
    t = earthPlayer.drawCard();
    earthPlayer.showPrimeryDeck();
}