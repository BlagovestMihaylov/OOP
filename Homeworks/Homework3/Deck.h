#include <iostream>
#include "EarthCard.h"
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include <bits/stdc++.h>

template <typename T>
class Deck
{
private:
    T container[30];
    size_t size;

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
    if (size <= 30)
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
    unsigned seed = 0;

    shuffle(container, container + size, default_random_engine(seed));
}


template <typename T> 
void Deck<T>::ShowDeck() const
{
    for (size_t i = 0; i < size ; i++)
    {
        std::cout<<i<<std::endl;
        container[i].   
        
        std::cout<<std::endl;
    }
    
}