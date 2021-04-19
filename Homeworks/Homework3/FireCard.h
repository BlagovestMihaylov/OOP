#ifndef FIRECARD_H
#define FIRECARD_H
#include "MyString.h"

class FireCard
{
private:
    MyString cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    FireCard();
    FireCard(MyString);
    FireCard(MyString, size_t);
    FireCard(MyString, size_t, size_t);

    void changeCardName(MyString);
    void changeBaseDemage(int);
    void changeBonusDemage(int);
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