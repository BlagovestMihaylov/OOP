#include "Deck.h"

template <typename T>
class Player
{
private:
    MyString playerName;
    size_t wins;
    size_t losses;
    Deck<T> primaryDeck;
    Deck<T> secondaryDeck;

public:
    Player();
    T drawCard();
    void savePlayer();
    Player<T> loadPlayer();
};