#include <iostream>
#include "EarthCard.h"
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include <bits/stdc++.h>
#include <stdlib.h>

template <typename T>
class Deck
{
private:
    T container[30];
    size_t size;
    bool duplicates(T &card)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (container[i].seeCardName() == card.seeCardName())
            {
                return false;
                break;
            }
        }
        return true;
    }

public:
    void shuffle();
    void addCard(T &);
    T drawCard();
    Deck operator+(const T &);
    Deck operator+=(const T &);
    void ShowDeck() const;
};

template <typename T>
void Deck<T>::addCard(T &card)
{
    if (size <= 30 && duplicates(card))
        container[size++] = card;
}

template <typename T>
T Deck<T>::drawCard()
{
    T temp = container[0];
    for (size_t i = 0; i < size; i++)
    {
        container[i] = container[i + 1];
    }
    container[size - 1] = temp;
    return temp;
}

template <typename T>
void Deck<T>::shuffle()
{
    int i, j;
    i = rand() % size + 0;
    j = rand() % size + 0;
    for (size_t k = 0; k < i; k++)
    {
        T temp = container[j];
        container[j] = container[k];
        container[k] = temp;
    }
}

template <typename T>
void Deck<T>::ShowDeck() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << i << std::endl;
        container[i].FullStats();
        std::cout << std::endl;
    }
}