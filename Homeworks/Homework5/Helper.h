#include <stdlib.h>
#include <time.h>
#include "Coin.hpp"
#include "BulgarianCoin.hpp"
#include "AmericanCoin.hpp"
#include "GermanCoin.hpp"

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

double BGtoUS(double a)
{
    return a * 3;
}

double UStoBG(double a)
{
    return a / 3;
}

double BGtoDE(double a)
{
    return a * 6;
}

double DEtoBG(double a)
{
    return a / 6;
}

double DEtoUS(double a)
{
    return a / 2.5;
}

double UStoDe(double a)
{
    return a * 2.5;
}