#ifndef DECK_H
#define DECK_H
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
    Deck();
    void shuffle();
    void addCard(T &);
    T drawCard();
    Deck operator+(const T &);
    Deck &operator+=(const T &);
    void ShowDeck() const;
    size_t getSize() const;
    T &operator[](size_t pos);
};

template <typename T>
size_t Deck<T>::getSize() const
{
    return size;
}

template <typename T>
Deck<T>::Deck()
{
    size = 0;
}

template <typename T>
T &Deck<T>::operator[](size_t pos)
{
    return container[pos];
}

template <typename T>
Deck<T> Deck<T>::operator+(const T &card)
{
    Deck<T> temp;
    for (int i = 0; i < size; i++)
    {
        temp[i] = container[i];
    }
    temp.addCard(card);
    return temp;
}
template <typename T>
Deck<T> &Deck<T>::operator+=(const T &card)
{
    container[size++] = card;
    return container;
}

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
#endif