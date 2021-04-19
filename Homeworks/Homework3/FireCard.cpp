#include "FireCard.h"

FireCard::FireCard()
{
    cardName = "Unknown card";
    cardType = 2;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

FireCard::FireCard(MyString _carName)
{
    cardName = _carName;
    cardType = 2;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

FireCard::FireCard(MyString _carName, size_t _base)
{
    cardName = _carName;
    cardType = 2;
    baseDemage = _base;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}
FireCard::FireCard(MyString _carName, size_t _base, size_t _bonus)
{
    cardName = _carName;
    cardType = 2;
    baseDemage = _base;
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void FireCard::changeCardName(MyString _cardName)
{
    cardName = _cardName;
}

void FireCard::changeBaseDemage(int _base)
{
    baseDemage += _base;
    overallDemage = bonusDemage + baseDemage;
}

void FireCard::changeBonusDemage(int _bonus)
{
    bonusDemage += _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void FireCard::addPower(size_t _moreDMG)
{
    bonusDemage += _moreDMG;
    overallDemage = bonusDemage + baseDemage;
}

MyString FireCard::seeCardName() const
{
    return cardName;
}

MyString FireCard::seeCardType() const
{
    return "Fire";
}

size_t FireCard::CardType() const
{
    return 2;
}

size_t FireCard::BaseDemage() const
{
    return baseDemage;
}

size_t FireCard::BonusDemage() const
{
    return bonusDemage;
}

size_t FireCard::OverallDemage() const
{
    return overallDemage;
}

void FireCard::FullStats() const
{
    std::cout << "Name of the Card: ";
    cardName.printString();
    std::cout << "Power of the card: " << overallDemage << " ( "<< baseDemage << " Base Power + " << bonusDemage << " Bonus Power )" << std::endl;
    std::cout << "Type of the card: Fire" << std::endl;
}