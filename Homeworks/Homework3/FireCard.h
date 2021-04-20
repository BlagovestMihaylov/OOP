#ifndef FIRECARD_H
#define FIRECARD_H
#include "String.h"

class FireCard
{
private:
    String cardName;
    size_t baseDemage;
    size_t bonusDemage;
    size_t cardType;
    size_t overallDemage;

public:
    FireCard();
    FireCard(String);
    FireCard(String, size_t);
    FireCard(String, size_t, size_t);

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

    void nameReaderHelper(std::ifstream &, String);
    void loadCard(std::ifstream &);
    void saveCard(std::ofstream &);
};

#endif