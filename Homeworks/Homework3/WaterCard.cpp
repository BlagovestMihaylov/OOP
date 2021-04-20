#include "WaterCard.h"

WaterCard::WaterCard()
{
    cardName = "Unknown card";
    cardType = 1;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

WaterCard::WaterCard(String _carName)
{
    cardName = _carName;
    cardType = 1;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

WaterCard::WaterCard(String _carName, size_t _base)
{
    cardName = _carName;
    cardType = 1;
    baseDemage = _base;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}
WaterCard::WaterCard(String _carName, size_t _base, size_t _bonus)
{
    cardName = _carName;
    cardType = 1;
    baseDemage = _base;
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void WaterCard::changeCardName(String _cardName)
{
    cardName = _cardName;
}

void WaterCard::changeBaseDemage(size_t _base)
{
    baseDemage = _base;
    overallDemage = bonusDemage + baseDemage;
}

void WaterCard::changeBonusDemage(size_t _bonus)
{
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void WaterCard::addPower(int _moreDMG)
{
    bonusDemage += _moreDMG;
    overallDemage = bonusDemage + baseDemage;
}

String WaterCard::seeCardName() const
{
    return cardName;
}

String WaterCard::seeCardType() const
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
    std::cout << "Name of the Card: " << cardName << std::endl;
    std::cout << "Power of the card: " << overallDemage << " ( " << baseDemage << " Base Power + " << bonusDemage << " Bonus Power )" << std::endl;
    std::cout << "Type of the card: Water" << std::endl;
}