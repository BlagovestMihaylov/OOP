#include "WaterCard.h"

WaterCard::WaterCard()
{
    cardName = "Unknown card";
    cardType = 1;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

WaterCard::WaterCard(MyString _carName)
{
    cardName = _carName;
    cardType = 1;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

WaterCard::WaterCard(MyString _carName, size_t _base)
{
    cardName = _carName;
    cardType = 1;
    baseDemage = _base;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}
WaterCard::WaterCard(MyString _carName, size_t _base, size_t _bonus)
{
    cardName = _carName;
    cardType = 1;
    baseDemage = _base;
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void WaterCard::changeCardName(MyString _cardName)
{
    cardName = _cardName;
}

void WaterCard::changeBaseDemage(int _base)
{
    baseDemage += _base;
    overallDemage = bonusDemage + baseDemage;
}

void WaterCard::changeBonusDemage(int _bonus)
{
    bonusDemage += _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void WaterCard::addPower(size_t _moreDMG)
{
    bonusDemage += _moreDMG;
    overallDemage = bonusDemage + baseDemage;
}

MyString WaterCard::seeCardName() const
{
    return cardName;
}

MyString WaterCard::seeCardType() const
{
    return "Water";
}

size_t WaterCard::CardType() const
{
    return 1;
}

size_t WaterCard::BaseDemage() const
{
    return baseDemage;
}

size_t WaterCard::BonusDemage() const
{
    return bonusDemage;
}

size_t WaterCard::OverallDemage() const
{
    return overallDemage;
}

void WaterCard::FullStats() const
{
    std::cout << "Name of the Card: ";
    cardName.printString();
    std::cout << "Power of the card: " << overallDemage << " ( "<< baseDemage << " Base Power + " << bonusDemage << " Bonus Power )" << std::endl;
    std::cout << "Type of the card: Water" << std::endl;
}