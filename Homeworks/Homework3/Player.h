#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "String.h"
#include <fstream>

template <typename T, typename V>
class Player
{
private:
    String playerName;
    size_t wins;
    size_t losses;
    Deck<T> primaryDeck;
    Deck<V> secondaryDeck;

public:
    Player();
    // Player(String, size_t, size_t);
    T drawFromPrimaryDeck();
    V drawFromSecondaryDeck();
    void changePlayerName(String);
    void changeWins(size_t);
    void changeLosses(size_t);
    void changeWins();
    void changeLosses();
    void savePlayer(std::ofstream &) const;
    void nameReaderHelper(std::ifstream &, String);
    void loadPlayer(std::ifstream &);
    void addPrimaryDeck(Deck<T>);
    void addSecondaryDeck(Deck<V>);
    void FullStats() const;
    void printName() const;
};

template <typename T, typename V>
void Player<T, V>::printName() const
{
    std::cout << playerName << std::endl;
}

template <typename T, typename V>
void Player<T, V>::savePlayer(std::ofstream &out) const
{
    out << playerName << std::endl;
    out << wins << std::endl;
    out << losses << std::endl;
}

// template <typename T, typename V>
// void Player<T, V>::nameReaderHelper(std::ifstream &in, String _name)
// {
//     char ch = ' ';
//     while (ch != '\n')
//     {
//         ch = in.get();
//         if (ch != '\n')
//         {
//             _name + ch;
//         }
//     }
//}

template <typename T, typename V>
void Player<T, V>::loadPlayer(std::ifstream &in)
{
    in >> playerName;
    in >> wins;
    in >> losses;
}

template <typename T, typename V>
void Player<T, V>::FullStats() const
{
    std::cout << playerName << std::endl;
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
    playerName = "unknow";
    wins = 0;
    losses = 0;
}

// template <typename T, typename V>
// Player<T, V>::Player(String _name, size_t _wins, size_t _losses)
// {
//     playerName = _name;
//     wins = _wins;
//     losses = _losses;
//     primaryDeck();
//     secondaryDeck();
// }

template <typename T, typename V>
void Player<T, V>::changePlayerName(String _name)
{
    playerName = _name;
}

template <typename T, typename V>
void Player<T, V>::changeWins(size_t _wins)
{
    wins = _wins;
}

template <typename T, typename V>
void Player<T, V>::changeWins()
{
    wins++;
}

template <typename T, typename V>
void Player<T, V>::changeLosses(size_t _losses)
{
    losses = _losses;
}

template <typename T, typename V>
void Player<T, V>::changeLosses()
{
    losses++;
}

template <typename T, typename V>
T Player<T, V>::drawFromPrimaryDeck()
{
    return primaryDeck.drawCard();
}

template <typename T, typename V>
V Player<T, V>::drawFromSecondaryDeck()
{
    return secondaryDeck.drawCard();
}

#endif
