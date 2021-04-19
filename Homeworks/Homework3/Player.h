#include "Deck.h"
#include "MyString.h"
#include <fstream>

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
    Player(MyString, size_t, size_t);
    void setPrimaryDeck(Deck<T>);
    size_t playerWins() const;
    size_t playerLosses() const;
  //  T drawCard();
    void showPrimeryDeck() const;
    T drawFromPrimaryDeck();
    V drawFromSecondaryDeck();
    void savePlayer(const MyString);
    void loadPlayer(MyString);
    void fullStats() const;
};
template <typename T, typename V>
void Player<T, V>::showPrimeryDeck() const
{
    primaryDeck.ShowDeck();
}

template <typename T, typename V>
void Player<T, V>::setPrimaryDeck(Deck<T> _primaryDeck)
{
    for (int i = 0; i < _primaryDeck.getSize(); i++)
    {
        primaryDeck[i] = _primaryDeck[i];
    }
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

// template <typename T, typename V>
// T Player<T, V>::drawCard()
// {
//     int i = rand() % 2 + 1;
//     if (i == 1)
//        return primaryDeck.drawCard();
//     else
//     {
//        return secondaryDeck.drawCard();
//     }
// }

template <typename T, typename V>
void Player<T, V>::fullStats() const
{
    playerName.printString();
    std::cout << " wins: " << wins << " losses:" << losses << std::endl;
}

template <typename T, typename V>

Player<T, V>::Player(MyString _name, size_t _wins, size_t _losses)
{
    playerName = _name;
    wins = _wins;
    losses = _losses;
}

template <typename T, typename V>

Player<T, V>::Player()
{
    playerName = "Unknown Player";
    wins = 0;
    losses = 0;
}

// template <typename T, typename V>

// void Player<T,V>::loadPlayer(MyString file)
// {
//     std::ifstream in;
//     char temp;
//     in.open(file.c_str(), std::ios::in);
//     if (in.is_open())
//     {
//         while (temp != ' ')
//         {
//             in >> temp;
//             playerName.push_back(temp);
//         }
//     }
//     in.close();emplate <typename T>
// void Player<T,V>::loadPlayer(MyString file)
// {
//     std::ifstream in;
//     char temp;
//     in.open(file.c_str(), std::ios::in);
//     if (in.is_open())
//     {
//         while (temp != ' ')
//         {
//             in >> temp;
//             playerName.push_back(temp);
//         }
//     }
//     in.close();
// }
// }

template <typename T, typename V>

size_t Player<T, V>::playerWins() const
{
    return wins;
}
template <typename T, typename V>

size_t Player<T, V>::playerLosses() const
{
    return losses;
}