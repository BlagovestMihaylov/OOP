#include <iostream>
#include "String.h"
#include "EarthCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "WaterCard.h"
#include "Deck.h"
#include "Player.h"




//продължавам да получавам някакъв еррор "segmentation fault (core dumped)"
//и не знам защо, пробвах с дебъгера, откри ми грешка в копи конструктора на 
//първия ми стринг, след това си дръпнах друг (векторен от гитхъб), с него отново
//имаше проблеми, но с итератори стана. След това си направих нов стринг
//с него същата грешка "segmentation fault (core dumped)" или 
//"free() invalid next size (normal) (core dumped)" 
//при първия опит работеше, после имах малък мемори лийк като се опитах да чета тестета от 
//файлове, и после малък проблем с едно мърджване на чекаути и от тогава не бачка

//като цяло не знам къде е проблема, пробвах с чар масив (както на практикума)
//не стана, пробвах същото със стринга ми и не стана
//пробвах със предевиниране на >> и пак не стана








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

int whichCounter(bool water, bool earth, bool fire, bool wind)
{
    if (water && fire)
        return 1;
    if (water && wind)
        return 2;
    if (earth && fire)
        return 3;
    if (earth && wind)
        return 4;
    else
        return 0;
}

void endGame(int winner, Player<WaterCard, EarthCard> Player1, Player<FireCard, WindCard> Player2)
{
    if (winner == 1)
    {
        Player1.printName();
        std::cout << " has defeated  " << std::endl;
        Player2.printName();
        Player1.changeWins();
        Player2.changeLosses();
    }
    else
    {
        Player2.printName();
        std::cout << " has defeated  " << std::endl;
        Player1.printName();
        Player2.changeWins();
        Player1.changeLosses();
    }
}

void fight(Player<WaterCard, EarthCard> player1, Player<FireCard, WindCard> player2)
{
    int flag = 0;
    int p1 = 0;
    int p2 = 0;
    WaterCard water;
    EarthCard earth;
    FireCard fire;
    WindCard wind;
    bool ff = false, fe = false, fwt = false, fwn = false;
    for (;;)
    {
        int i = rand() % 15 + 1;
        int k = rand() % 15 + 1;
        if (i % 2 == 0)
        {
            fwt = true;
            fe = false;
            water = player1.drawFromPrimaryDeck();
            if (k % 2 == 0)
            {
                ff = false;
                fwn = true;
                wind = player2.drawFromSecondaryDeck();
            }
            else
            {
                ff = true;
                fwn = false;
                fire = player2.drawFromPrimaryDeck();
            }
        }
        else
        {
            fwt = false;
            fe = true;
            earth = player1.drawFromSecondaryDeck();
        }

        //bool water, bool earth, bool fire, bool wind
        flag = whichCounter(fwt, fe, ff, fwn);

        switch (flag)
        {
        case 1:
            counter(water, fire);
            if (water.OverallDemage() > fire.OverallDemage())
            {
                p1++;
            }
            else if (fire.OverallDemage() > water.OverallDemage())
            {
                p2++;
            }
            if (fire.OverallDemage() == water.OverallDemage())
            {
                continue;
            }
            break;
        case 2:
            counter(water, wind);
            if (water.OverallDemage() > wind.OverallDemage())
            {
                p1++;
            }
            else if (fire.OverallDemage() > water.OverallDemage())
            {
                p2++;
            }
            if (wind.OverallDemage() == water.OverallDemage())
            {
                continue;
            }
            break;
        case 3:
            counter(earth, fire);
            if (earth.OverallDemage() > fire.OverallDemage())
            {
                p1++;
            }
            else if (fire.OverallDemage() > earth.OverallDemage())
            {
                p2++;
            }
            if (fire.OverallDemage() == earth.OverallDemage())
            {
                continue;
            }
            break;
        case 4:
            counter(earth, wind);
            if (earth.OverallDemage() > wind.OverallDemage())
            {
                p1++;
            }
            else if (wind.OverallDemage() > earth.OverallDemage())
            {
                p2++;
            }
            if (wind.OverallDemage() == earth.OverallDemage())
            {
                continue;
            }
            break;
        default:
            break;
        }
        if (p1 == 5)
            endGame(1, player1, player2);
        if (p2 == 5)
            endGame(2, player1, player2);
        break;
    }
}

int main()
{

    Player<WaterCard, EarthCard> player1;
    player1.changePlayerName("Blagovest");
    player1.changeLosses(4);
    player1.changeWins(2);
    Player<FireCard, WindCard> player2;
    player2.changePlayerName("maria");
    player2.changeLosses(3);
    player2.changeWins(3);

    Deck<WaterCard> waterDeck;

    WaterCard Water("Riven", 36, 213);
    Water.addPower(21);
    Water.changeCardName("Nami");
    WaterCard Water1("Nami1", 36, 43);
    WaterCard Water2("Nami2", 39, 431);
    WaterCard Water3("Nami3", 39, 41);
    WaterCard Water4("Nami1", 39, 413);

    waterDeck.addCard(Water);
    waterDeck.addCard(Water1);
    waterDeck.addCard(Water2);
    waterDeck.addCard(Water3);
    waterDeck.addCard(Water4);

    Deck<EarthCard> earthDeck;

    EarthCard Earth("Darius", 40, 51);
    Earth.addPower(21);
    Earth.changeCardName("Malphite");
    EarthCard Earth1("Maplhite1", 43, 55);
    EarthCard Earth2("Maplhite2", 42, 42);
    EarthCard Earth3("Maplhite3", 42, 54);
    EarthCard Earth4("Maplhite1", 47, 542);

    earthDeck.addCard(Earth);
    earthDeck.addCard(Earth1);
    earthDeck.addCard(Earth2);
    earthDeck.addCard(Earth3);
    earthDeck.addCard(Earth4);

    Deck<FireCard> fireDeck;

    FireCard Fire("Riven", 70, 542);
    Fire.addPower(21);
    Fire.changeCardName("Brand");
    FireCard Fire1("Brand1", 72, 51);
    FireCard Fire2("Brand2", 71, 98);
    FireCard Fire3("Brand3", 79, 94);
    FireCard Fire4("Brand1", 78, 93);

    fireDeck.addCard(Fire);
    fireDeck.addCard(Fire1);
    fireDeck.addCard(Fire2);
    fireDeck.addCard(Fire3);
    fireDeck.addCard(Fire4);

    Deck<WindCard> windDeck;

    WindCard Wind("Riven", 60, 87);
    Wind.addPower(21);
    Wind.changeCardName("Yasuo");
    WindCard Wind1("Yasuo1", 61, 84);
    WindCard Wind2("Yasuo2", 6152, 87);
    WindCard Wind3("Yasuo3", 68, 81);
    WindCard Wind4("Yasuo1", 682, 36);
    windDeck.addCard(Wind);
    windDeck.addCard(Wind1);
    windDeck.addCard(Wind2);
    windDeck.addCard(Wind3);
    windDeck.addCard(Wind4);

    player1.addPrimaryDeck(waterDeck);
    player1.addSecondaryDeck(earthDeck);
    player2.addPrimaryDeck(fireDeck);
    player2.addSecondaryDeck(windDeck);
    std::ifstream in1("player1.txt");
    std::ifstream in2("player2.txt");
     player1.loadPlayer(in1);
    // player2.loadPlayer(in2);
     std::ofstream out("dataLog.txt");
     player1.savePlayer(out);
    // player2.savePlayer(out);

    player1.FullStats();
    // player2.FullStats();
   // fight(player1, player2);
    //fight(player1, player2);
}
