#ifndef EARTHCARD_H
#define EARTHCARD_H
#include "MyString.h"

class EarthCard
{
private:
    MyString cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    EarthCard();
    EarthCard(MyString);
    EarthCard(MyString, size_t);
    EarthCard(MyString, size_t, size_t);
    //EarthCard(EarthCard&);

    void changeCardName(MyString);
    void changeBaseDemage(size_t);
    void changeBonusDemage(size_t);
    void addPower(size_t);

    MyString seeCardName() const;
    size_t BaseDemage() const;
    size_t BonusDemage() const;
    size_t CardType() const;
    MyString seeCardType() const;
    size_t OverallDemage() const;

    void FullStats() const;
};

#endif