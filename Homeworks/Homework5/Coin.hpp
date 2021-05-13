#pragma once


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
    void print() const;
    virtual bool flip();
    Coin();
    Coin(String, int);
    void changeValue(double);
    double checkValue() const;
    String checkNationality() const;
};

