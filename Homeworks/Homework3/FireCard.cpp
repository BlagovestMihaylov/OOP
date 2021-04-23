#include "FireCard.h"

FireCard::FireCard()
{
    cardName = "Unknown card";
    cardType = 2;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

FireCard::FireCard(String _carName)
{
    cardName = _carName;
    cardType = 2;
    baseDemage = 0;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}

FireCard::FireCard(String _carName, size_t _base)
{
    cardName = _carName;
    cardType = 2;
    baseDemage = _base;
    bonusDemage = 0;
    overallDemage = bonusDemage + baseDemage;
}
FireCard::FireCard(String _carName, size_t _base, size_t _bonus)
{
    cardName = _carName;
    cardType = 2;
    baseDemage = _base;
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void FireCard::changeCardName(String _cardName)
{
    cardName = _cardName;
}

void FireCard::changeBaseDemage(size_t _base)
{
    baseDemage = _base;
    overallDemage = bonusDemage + baseDemage;
}

void FireCard::changeBonusDemage(size_t _bonus)
{
    bonusDemage = _bonus;
    overallDemage = bonusDemage + baseDemage;
}

void FireCard::addPower(int _moreDMG)
{
    bonusDemage += _moreDMG;
    overallDemage = bonusDemage + baseDemage;
}

String FireCard::seeCardName() const
{
    return cardName;
}

String FireCard::seeCardType() const
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

FireCard &FireCard::operator=(const FireCard &_other)
{
    baseDemage = _other.baseDemage;
    bonusDemage = _other.bonusDemage;
    cardType = 2;
    overallDemage = _other.overallDemage;
    cardName = _other.cardName;
    return *this;
}

void FireCard::FullStats() const
{
    std::cout << "Name of the Card: " << cardName << std::endl;
    std::cout << "Power of the card: " << overallDemage << " ( " << baseDemage << " Base Power + " << bonusDemage << " Bonus Power )" << std::endl;
    std::cout << "Type of the card: Fire" << std::endl;
}

// void FireCard::nameReaderHelper(std::ifstream &in, String _name)
// {
//     char ch = ' ';
//     while (ch != '\n')
//     {
//         ch = in.get();
//         if (ch != '\n')
//         {
//             _name.push_back(ch);
//         }
//     }
// }

// void FireCard::loadCard(std::ifstream &in)
// {
//     nameReaderHelper(in, cardName);
//     in >> baseDemage;
//     in >> bonusDemage;
//     cardType = 2;
// }
