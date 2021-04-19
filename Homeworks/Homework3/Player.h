#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

template <typename T, typename V>
class Player
{
private:
    MyString playerName;
    size_t wins;
    size_t losses;
    Deck<T> primaryDeck;
    Deck<V> secondaryDeck;

public:
    Player();
    // Player(Mystring, size_t, size_t);
    T drawFromPrimaryDeck();
    V drawFromSecondaryDeck();
    void changePlayerName(MyString);
    void changeWins(size_t);
    void changeLosses(size_t);
    void savePlayer();
    void addPrimaryDeck(Deck<T>);
    void addSecondaryDeck(Deck<V>);
    void FullStats() const;
    Player<T, V> loadPlayer();
};

template <typename T, typename V>
void Player<T, V>::FullStats() const
{
    std::cout << playerName.c_str() << std::endl;
    std::cout << "Wins: " << wins << " Losses: " << losses << std::endl;
    std::cout << "Primary Deck:" << std::endl;
    primaryDeck.ShowDeck();
    std::cout << "Secondary Deck:" << std::endl;
    secondaryDeck.ShowDeck();
}

template <typename T, typename V>
void Player<T, V>::addPrimaryDeck(Deck<T> _primaryDeck)
{
    primaryDeck = _primaryDeck;
}

template <typename T, typename V>
void Player<T, V>::addSecondaryDeck(Deck<V> _secondaryDeck)
{
    secondaryDeck = _secondaryDeck;
}

template <typename T, typename V>
Player<T, V>::Player()
{
    playerName = "Unknown player";
    wins = 0;
    losses = 0;
}

// template <typename T, typename V>
// Player<T, V>::Player(MyString _name, size_t _wins, size_t _losses)
// {
//     playerName = _name;
//     wins = _wins;
//     losses = _losses;
//     primaryDeck();
//     secondaryDeck();
// }

template <typename T, typename V>
void Player<T, V>::changePlayerName(MyString _name)
{
    playerName = _name;
}

template <typename T, typename V>
void Player<T, V>::changeWins(size_t _wins)
{
    wins = _wins;
}

template <typename T, typename V>
void Player<T, V>::changeLosses(size_t _losses)
{
    losses = _losses;
}

template <typename T, typename V>
T Player<T, V>::drawFromPrimaryDeck()
{
    primaryDeck.drawCard();
}

template <typename T, typename V>
V Player<T, V>::drawFromSecondaryDeck()
{
    secondaryDeck.drawCard();
}

#endif