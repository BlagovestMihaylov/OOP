#include "EarthCard.h"

EarthCard::EarthCard()
{
    cardName = "Unknown card";
    cardType = 3;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

EarthCard::EarthCard(String _carName)
{
    cardName = _carName;
    cardType = 3;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

EarthCard::EarthCard(String _carName, size_t _base)
{
    cardName = _carName;
    cardType = 3;
    baseDemage = _base;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}
EarthCard::EarthCard(String _carName, size_t _base, size_t _bonus)
{
    cardName = _carName;
    cardType = 3;
    baseDemage = _base;
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

// EarthCard::EarthCard(EarthCard &E)
// {
//     cardName = E.cardName;
//     cardType = 3;
//     baseDemage = E.baseDemage;
//     bonusDemage = E.bonusDemage;
//     overallDemage = baseDemage + overallDemage;
// }

void EarthCard::changeCardName(String _cardName)
{
    cardName = _cardName;
}

void EarthCard::changeBaseDemage(size_t _base)
{
    baseDemage = _base;
    overallDemage += bonusDemage + baseDemage;
}

void EarthCard::changeBonusDemage(size_t _bonus)
{
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void EarthCard::addPower(int _moreDMG)
{
    bonusDemage += _moreDMG;
    overallDemage = bonusDemage + baseDemage;
}

String EarthCard::seeCardName() const
{
    return cardName;
}

String EarthCard::seeCardType() const
{
    return "Earth";
}

size_t EarthCard::CardType() const
{
    return 3;
}

size_t EarthCard::BaseDemage() const
{
    return baseDemage;
}

size_t EarthCard::BonusDemage() const
{
    return bonusDemage;
}

size_t EarthCard::OverallDemage() const
{
    return overallDemage;
}

EarthCard &EarthCard::operator=(const EarthCard &_other)
{
    baseDemage = _other.baseDemage;
    bonusDemage = _other.bonusDemage;
    cardType = 3;
    overallDemage = _other.overallDemage;
    cardName = _other.cardName;
    return *this;
}

void EarthCard::FullStats() const
{
    std::cout << "Name of the Card: " << cardName << std::endl;
    std::cout << "Power of the card: " << overallDemage << " ( " << baseDemage << " Base Power + " << bonusDemage << " Bonus Power )" << std::endl;
    std::cout << "Type of the card: Earth" << std::endl;
}
