#ifndef WATERCARD_H
#define WATERCARD_H
#include "String.h"

class WaterCard
{
private:
    String cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    WaterCard();
    WaterCard(String);
    WaterCard(String, size_t);
    WaterCard(String, size_t, size_t);

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
    WaterCard &operator=(const WaterCard& _other);
};

#endif