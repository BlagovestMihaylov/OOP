#ifndef EARTHCARD_H
#define EARTHCARD_H
#include "String.h"

class EarthCard
{
private:
    String cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    EarthCard();
    EarthCard(String);
    EarthCard(String, size_t);
    EarthCard(String, size_t, size_t);
    //EarthCard(EarthCard&);

    void changeCardName(String);
    void changeBaseDemage(size_t);
    void changeBonusDemage(size_t);
    void addPower(int);

    String seeCardName() const;
    size_t BaseDemage() const;
    size_t BonusDemage() const;
    size_t CardType() const;
    String seeCardType() const;
    size_t OverallDemage() const;

    void FullStats() const;
};

#endif