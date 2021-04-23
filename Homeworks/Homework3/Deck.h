#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "EarthCard.h"
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"
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
    size_t getSize();
    void shuffle();
    void addCard(T &);
    T drawCard();
    Deck operator=(const T &);
    Deck operator+(const T &);
    Deck &operator+=(const T &);
    void loadDeck(std::ifstream &, int);
    String nameReaderHelper(std::ifstream &);
    void ShowDeck() const;
    size_t getSize() const;
    T &operator[](size_t pos);
};

template <typename T>
void Deck<T>::loadDeck(std::ifstream &in, int count)
{

    for (int i = 0; i < count; i++)
    {
        T temp;
        temp.loadCard(in);
        addCard(temp);
    }
}

template <typename T>
size_t Deck<T>::getSize()
{
    return size;
}

template <typename T>
Deck<T> Deck<T>::operator=(const T &_other)
{
    if (*this != &_other)
    {
        for (size_t i = 0; i < _other.getSize(); i++)
        {
            container[i] = _other[i];
        }
    }
    return *this;
}

template <typename T>
Deck<T>::Deck()
{
    size = 0;
}

template <typename T>
T &Deck<T>::operator[](size_t pos)
{
    if (pos < size)
        return container[pos];
    else
        std::cout << "There less than " << pos << " card in the deck" << std::endl;
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
void Deck<T>::addCard(T &card)
{
    if (size <= 30 && duplicates(card))
        container[size++] = card;
}

template <typename T>
Deck<T> &Deck<T>::operator+=(const T &card)
{
    addCard(card);
    return *this;
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
        std::cout << "Card: " << i + 1 << std::endl;
        container[i].FullStats();
    }
    std::cout << std::endl;
}

#endif