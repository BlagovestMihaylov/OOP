#include "Crypto.h"
#include <cstring>

Crypto::Crypto()
{
    this->name = new char[6];
    strcpy(this->name, "Empty");
    this->currentPrice = 0;
    this->lastPrice = 0;
}

void Crypto::setName(const char *_name)
{
    delete[] this->name;
    this->name = new char[31];
    strcpy(this->name, _name);
}

const char *Crypto::getName() const
{
    return this->name;
}

void Crypto::setLastPrice(double _lastPrice)
{
    this->lastPrice = _lastPrice;
}

double Crypto::getLastPrice() const
{
    return this->lastPrice;
}

void Crypto::setCurrentPrice(double _currentPrice)
{
    this->currentPrice = _currentPrice;
}

double Crypto::getCurrentPrice() const
{
    return this->currentPrice;
}

void Crypto::print() const
{
    std::cout << this->name << std::endl;
    std::cout << this->lastPrice << std::endl;
    std::cout << this->currentPrice << std::endl;
}

void Crypto::priceDifference() const
{
    double percentage = (this->currentPrice / this->lastPrice) * 100 - 100;

    if (percentage > 0)
        std::cout << "Стойността на " << this->name << " се е повишила от " << this->lastPrice << " до " << this->currentPrice << ", което е растеж от " << percentage << "%" << std::endl;
    if (percentage < 0)
        std::cout << "Стойността на " << this->name << " е намаляла от " << this->lastPrice << " до " << this->currentPrice << ", което е спад от " << percentage << "%" << std::endl;
    if (percentage == 0)
        std::cout << "Стойността на " << this->name << "не се е променила" << std::endl;
}