#include <iostream>
#include "MyString.h"
#include "EarthCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "WaterCard.h"
#include "Deck.h"
#include "Player.h"

//  fire > wind; water > fire ; earth > water; wind > earth

//fire interactions
void counter(FireCard f, WindCard wd)
{
    wd.changeBonusDemage(-50); //counter wind
}
void counter(FireCard f, WaterCard wd)
{
    wd.changeBonusDemage(50); //counter fire
}
void counter(FireCard f, EarthCard wd)
{
    wd.changeBonusDemage(-10);
}

//  fire > wind; water > fire ; earth > water; wind > earth

//water interactions
void counter(WaterCard f, WindCard wd)
{
    wd.changeBonusDemage(10);
}
void counter(WaterCard f, EarthCard wd)
{
    wd.changeBonusDemage(50); //counter earth
}
void counter(WaterCard f, FireCard wd)
{
    wd.changeBonusDemage(-50); //counter water
}

//  fire > wind; water > fire ; earth > water; wind > earth

//earth interactions

void counter(EarthCard f, WindCard wd)
{
    wd.changeBonusDemage(50); //counter wind
}
void counter(EarthCard f, WaterCard wd)
{
    wd.changeBonusDemage(-50); //counter earth
}
void counter(EarthCard f, FireCard wd)
{
    wd.changeBonusDemage(-5);
}

//  fire > wind; water > fire ; earth > water; wind > earth

//wind interactions
void counter(WindCard f, EarthCard wd)
{
    wd.changeBonusDemage(-50); //counter wind
}
void counter(WindCard f, FireCard wd)
{
    wd.changeBonusDemage(50); //counter fire
}
void counter(WindCard f, WaterCard wd)
{
    wd.changeBonusDemage(5);
}

//special interactions
void counter(WindCard f, WindCard wd)
{
    wd.changeBonusDemage(wd.BonusDemage());
    f.changeBonusDemage(f.BonusDemage());
}
void counter(WaterCard f, WaterCard wd)
{
    wd.changeBonusDemage(wd.BonusDemage());
    f.changeBonusDemage(f.BonusDemage());
}
void counter(EarthCard f, EarthCard wd)
{
    wd.changeBonusDemage(wd.BonusDemage());
    f.changeBonusDemage(f.BonusDemage());
}
void counter(FireCard f, FireCard wd)
{
    wd.changeBonusDemage(wd.BonusDemage());
    f.changeBonusDemage(f.BonusDemage());
}




int main()
{
    
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
    EarthCard Earth("Darius", 10, 69);
    Earth.addPower(21);
    Earth.changeCardName("Malphite");
    EarthCard Earth1("Darius1", 10, 69);
    EarthCard Earth2("Darius2", 10, 69);
    EarthCard Earth3("Darius3", 10, 69);
    EarthCard Earth4("Darius1", 10, 69);
    Deck<EarthCard> earthDeck;
    earthDeck.addCard(Earth);
    earthDeck.addCard(Earth1);
    earthDeck.addCard(Earth2);
    earthDeck.addCard(Earth3);
    earthDeck.addCard(Earth4);
    //earthDeck.ShowDeck();
    EarthCard e = earthDeck.drawCard();

    //  std::cout << "Old deck" << std::endl;
    //earthDeck.ShowDeck();

    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "New deck" << std::endl;
    earthDeck.shuffle();
    //earthDeck.ShowDeck();

    ///////////////////////////////////
    WaterCard Water("Riven", 10, 69);
    Water.addPower(21);
    Water.changeCardName("Nami");
    WaterCard Water1("Riven1", 10, 69);
    WaterCard Water2("Riven2", 10, 69);
    WaterCard Water3("Riven3", 10, 69);
    WaterCard Water4("Riven1", 10, 69);
    Deck<WaterCard> waterDeck;
    waterDeck.addCard(Water);
    waterDeck.addCard(Water1);
    waterDeck.addCard(Water2);
    waterDeck.addCard(Water3);
    waterDeck.addCard(Water4);
    //waterDeck.ShowDeck();
    WaterCard w = waterDeck.drawCard();

    Player<WaterCard, EarthCard> player1;
    player1.changePlayerName("Blagovest");
    player1.changeLosses(4);
    player1.changeWins(4);
    player1.addPrimaryDeck(waterDeck);
    player1.addSecondaryDeck(earthDeck);
    player1.FullStats();
    w.FullStats();
    
}