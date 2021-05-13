
#pragma once

#include <stdlib.h>
#include <time.h>
#include "Coin.hpp"
#include "Vector.hpp"
#include <thread>
#include "Wallet.hpp"

namespace helper
{

    //void sleeping(int seconds);
    //void visualiseBar(char arr[], double progress = 0.25, char opening = '[', char closing = ']', bool showPercent = 1, char filling = '*', char empty = '_', int divisions = 100);
    bool Chance5050();
    bool Chance3070();
    bool Chance9010();
    double BGtoUS(double a, int coins);
    double UStoBG(double a, int coins);
    double BGtoDE(double a, int coins);
    double DEtoBG(double a, int coins);
    double DEtoUS(double a, int coins);
    double UStoDe(double a, int coins);
    bool checkForMoneyType(String _string);
    void normalisingValues(Vector<Coin> _vector);
    void addingMoneyWithDifferentType(String _walletType, Coin _coin);
    void notEmptyWalletChangeTypeError();
    bool isDiscountMatch(String _productSide, String _coinSide, double _discount);
    void boughtWithBG(Coin _coin);
    void boughtWithUS(Coin _coin);
    void boughtWithDE(Coin _coin);
    void boughtProduct(String _productName, Coin _coin);
    //void addCoinAlert(Wallet __wallet);
    //void removeCoinAlert(Wallet _wallet);
    int randomWallet();
   // bool emptyWalletCheck(Wallet);
}