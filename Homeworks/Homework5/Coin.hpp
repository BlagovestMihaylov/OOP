
#ifndef COIN_HPP
#define COIN_HPP

#include <iostream>
#include "String.hpp"

class Coin
{
protected:
    enum face
    {
        HEADS,
        TAILS
    };
    String nationality;
    double value;

public:
    virtual bool flip();
    void print() const;

public:
    Coin();
    Coin(String, int);
    void changeValue(double);
    double checkValue() const;
    String checkNationality() const;
};

#endif

#ifndef BGCOIN
#define BGCOIN

class BulgarianCoin : public Coin
{
private:
    const String nationality = "BG";

public:
    bool flip();
    void print() const;
};

#endif

#ifndef USCOIN
#define USCOIN

class AmericanCoin : public Coin
{
private:
    const String nationality = "US";

public:
    bool flip();
    void print() const;
};

#endif

#ifndef DECOIN
#define DECOIN

class GermanCoin : public Coin
{
private:
    const String nationality = "DE";

public:
    bool flip();
    void print() const;
};

#endif