//#pragma once
#include <iostream>
#include <cstring>
#include <string.h>
#include <strings.h>

class Crypto
{
private:
    char *name;
    double lastPrice;
    double currentPrice;

public:
    Crypto();

    void setName(const char *_name);
    void setLastPrice(double _lastPrice);
    void setCurrentPrice(double _currentPrice);

    const char *getName() const;
    double getLastPrice() const;
    double getCurrentPrice() const;

    void priceDifference() const;

    void print() const;
};