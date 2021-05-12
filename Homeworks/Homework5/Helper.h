#ifndef HELPER_H
#define HELPTER_H

#include <stdlib.h>
#include <time.h>
#include "Coin.hpp"
#include "Vector.hpp"
#include "Wallet.hpp"

int masiv5050[10] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int masiv9010[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
int masiv3070[10] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2};

bool Chance5050()
{
    srand(time(NULL));
    int a = rand() % 9;
    if (masiv5050[a] % 1 == 0)
        return true;
    else
        return false;
}
bool Chance3070()
{
    srand(time(NULL));
    int a = rand() % 9;
    if (masiv3070[a] % 1 == 0)
        return true;
    else
        return false;
}
bool Chance9010()
{
    srand(time(NULL));
    int a = rand() % 9;
    if (masiv9010[a] % 1 == 0)
        return true;
    else
        return false;
}

double BGtoUS(double a, int coins)
{
    return a * coins * 3;
}

double UStoBG(double a, int coins)
{
    return a * coins / 3;
}

double BGtoDE(double a, int coins)
{
    return a * coins * 6;
}

double DEtoBG(double a, int coins)
{
    return a * coins / 6;
}

double DEtoUS(double a, int coins)
{
    return a * coins / 2.5;
}

double UStoDe(double a, int coins)
{
    return a * coins * 2.5;
}

bool checkForMoneyType(String _string)
{
    if (_string == "UNKNOWN")
        return true;
    else
        return false;
}

void addingMoneyWithDifferentType(String _walletType, Coin _coin)
{
    std::cout << "Error adding coin:\nexpected nationality " << _walletType << "\nrecived nationality " << _coin.checkNationality() << std::endl;
}

void notEmptyWalletChangeTypeError()
{
    std::cout << "Unable to change wallet type, please make sure you are not changing type of not empty wallet" << std::endl;
}

#endif