#ifndef WATERCARD_H
#define WATERCARD_H
#include "MyString.h"

class WaterCard
{
private:
    MyString cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    WaterCard();
    WaterCard(MyString);
    WaterCard(MyString, size_t);
    WaterCard(MyString, size_t, size_t);

    void changeCardName(MyString);
    void changeBaseDemage(size_t);
    void changeBonusDemage(size_t);
    void addPower(int);

    MyString seeCardName() const;
    size_t BaseDemage() const;
    size_t BonusDemage() const;
    size_t CardType() const;
    MyString seeCardType() const;
    size_t OverallDemage() const;

    void FullStats() const;
};

#endif