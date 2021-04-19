#ifndef WINDCARD_H
#define WINDCARD_H
#include "MyString.h"

class WindCard
{
private:
    MyString cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    WindCard();
    WindCard(MyString);
    WindCard(MyString, size_t);
    WindCard(MyString, size_t, size_t);

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