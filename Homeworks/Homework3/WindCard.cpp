#include "WindCard.h"

WindCard::WindCard()
{
    cardName = "Unknown card";
    cardType = 4;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

WindCard::WindCard(String _carName)
{
    cardName = _carName;
    cardType = 4;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

WindCard::WindCard(String _carName, size_t _base)
{
    cardName = _carName;
    cardType = 4;
    baseDemage = _base;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}
WindCard::WindCard(String _carName, size_t _base, size_t _bonus)
{
    cardName = _carName;
    cardType = 4;
    baseDemage = _base;
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void WindCard::changeCardName(String _cardName)
{
    cardName = _cardName;
}

void WindCard::changeBaseDemage(size_t _base)
{
    baseDemage = _base;
    overallDemage = bonusDemage + baseDemage;
}

void WindCard::changeBonusDemage(size_t _bonus)
{
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void WindCard::addPower(int _moreDMG)
{
    bonusDemage += _moreDMG;
    overallDemage = bonusDemage + baseDemage;
}

String WindCard::seeCardName() const
{
    return cardName;
}

String WindCard::seeCardType() const
{
    return "Wind";
}

size_t WindCard::CardType() const
{
    return 4;
}

size_t WindCard::BaseDemage() const
{
    return baseDemage;
}

size_t WindCard::BonusDemage() const
{
    return bonusDemage;
}

size_t WindCard::OverallDemage() const
{
    return overallDemage;
}

WindCard &WindCard::operator=(const WindCard &_other)
{
    baseDemage = _other.baseDemage;
    bonusDemage = _other.bonusDemage;
    cardType = 4;
    overallDemage = _other.overallDemage;
    cardName = _other.cardName;
    return *this;
}

void WindCard::FullStats() const
{
    std::cout << "Name of the Card: " << cardName << std::endl;
    std::cout << "Power of the card: " << overallDemage << " ( " << baseDemage << " Base Power + " << bonusDemage << " Bonus Power )" << std::endl;
    std::cout << "Type of the card: Wind" << std::endl;
}