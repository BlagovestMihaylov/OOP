#include <iostream>
#include "MyString.h"
#include "EarthCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "WaterCard.h"
#include "Deck.h"
#include "Player.h"

//  fire > Wind; water > fire ; earth > water; Wind > earth

//fire interactions
void counter(FireCard &f, WindCard &s)
{
    s.addPower(-50); //counter Wind
}
void counter(FireCard &f, WaterCard &s)
{
    s.addPower(50); //counter fire
}
void counter(FireCard &f, EarthCard &s)
{
    s.addPower(-10);
}

//  fire > Wind; water > fire ; earth > water; Wind > earth

//water interactions
void counter(WaterCard &f, WindCard &s)
{
    s.addPower(10);
}
void counter(WaterCard &f, EarthCard &s)
{
    s.addPower(50); //counter earth
}
void counter(WaterCard &f, FireCard &s)
{
    s.addPower(-50); //counter water
}

//  fire > Wind; water > fire ; earth > water; Wind > earth

//earth interactions

void counter(EarthCard &f, WindCard &s)
{
    s.addPower(50); //counter Wind
}
void counter(EarthCard &f, WaterCard &s)
{
    s.addPower(-50); //counter earth
}
void counter(EarthCard &f, FireCard &s)
{
    s.addPower(-5);
}

//  fire > Wind; water > fire ; earth > water; Wind > earth

//Wind interactions
void counter(WindCard &f, EarthCard &s)
{
    s.addPower(-50); //counter Wind
}
void counter(WindCard &f, FireCard &s)
{
    s.addPower(50); //counter fire
}
void counter(WindCard &f, WaterCard &s)
{
    s.addPower(5);
}

//special interactions
void counter(WindCard &f, WindCard &s)
{
    s.addPower(s.BonusDemage());
    f.addPower(f.BonusDemage());
}
void counter(WaterCard &f, WaterCard &s)
{
    s.addPower(s.BonusDemage());
    f.addPower(f.BonusDemage());
}
void counter(EarthCard &f, EarthCard &s)
{
    s.addPower(s.BonusDemage());
    f.addPower(f.BonusDemage());
}
void counter(FireCard &f, FireCard &s)
{
    s.addPower(s.BonusDemage());
    f.addPower(f.BonusDemage());
}

int fight(Player<WaterCard, EarthCard> player1, Player<FireCard, WindCard> player2)
{
    int p1 = 0;
    int p2 = 0;
    WaterCard water;
    EarthCard earth;
    FireCard fire;
    WindCard wind;
    bool ff = false, fe = false, fwt = false, fwn = false;
    for (;;)
    {
        int i = rand() 15 + 1;
        int k = rand() 15 + 1;
        if (i % 2 == 0)
        {
            water = player1.drawFromPrimaryDeck();
            if (k % 2 == 0)
            {
                wind = player2.addPrimaryDeck();
            }
            else
            {
                fire = player2.drawFromPrimaryDeck();
            }
        }
        else
        {
            earth = player1.drawFromSecondaryDeck();
        }
    }
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
    EarthCard Earth1("Maplhite1", 10, 69);
    EarthCard Earth2("Maplhite2", 10, 69);
    EarthCard Earth3("Maplhite3", 10, 69);
    EarthCard Earth4("Maplhite1", 10, 69);
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
    WaterCard Water1("Nami1", 10, 69);
    WaterCard Water2("Nami2", 10, 69);
    WaterCard Water3("Nami3", 10, 69);
    WaterCard Water4("Nami1", 10, 69);
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
    // player1.FullStats();
    // w.FullStats();
    // e.FullStats();
    // counter(e, w);
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // w.FullStats();
    // e.FullStats();

    ///////////////////////////////////
    WindCard Wind("Riven", 10, 69);
    Wind.addPower(21);
    Wind.changeCardName("Yasuo");
    WindCard Wind1("Yasuo1", 10, 69);
    WindCard Wind2("Yasuo2", 10, 69);
    WindCard Wind3("Yasuo3", 10, 69);
    WindCard Wind4("Yasuo1", 10, 69);
    Deck<WindCard> windDeck;
    windDeck.addCard(Wind);
    windDeck.addCard(Wind1);
    windDeck.addCard(Wind2);
    windDeck.addCard(Wind3);
    windDeck.addCard(Wind4);
    //WindDeck.ShowDeck();
    WindCard wn = WindDeck.drawCard();

    ///////////////////////////////////
    FireCard Fire("Riven", 10, 69);
    Fire.addPower(21);
    Fire.changeCardName("Brand");
    FireCard Fire1("Brand1", 10, 69);
    FireCard Fire2("Brand2", 10, 69);
    FireCard Fire3("Brand3", 10, 69);
    FireCard Fire4("Brand1", 10, 69);
    Deck<FireCard> fireDeck;
    fireDeck.addCard(Fire);
    fireDeck.addCard(Fire1);
    fireDeck.addCard(Fire2);
    fireDeck.addCard(Fire3);
    fireDeck.addCard(Fire4);
    //FireDeck.ShowDeck();
    FireCard f = FireDeck.drawCard();
    Player<FireCard, WindCard> player2;
    player2.changeLosses(2);
    player2.changeWins(3);
    player2.changePlayerName("Faker");
    player2.addPrimaryDeck(fireDeck);
    player2.addSecondaryDeck(windDeck);
}