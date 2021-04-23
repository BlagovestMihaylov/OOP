#ifndef WINDCARD_H
#define WINDCARD_H
#include "String.h"

class WindCard
{
private:
    String cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    WindCard();
    WindCard(String);
    WindCard(String, size_t);
    WindCard(String, size_t, size_t);

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

    WindCard& operator=(const WindCard&);
    void FullStats() const;
};

#endif