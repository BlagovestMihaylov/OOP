//#pragma once
#include <iostream>
#include <cstring>
#include "Film.h"

class FilmRanking
{
private:
    int filmCount;
    Film *filmArray;

    void copy(const FilmRanking &otherFilmRanking);
    void erase();
    void sort(Film *_filmArray, int size);

public:
    FilmRanking();
    FilmRanking &operator=(const FilmRanking &otherFilmRanking);
    FilmRanking(const FilmRanking &otherFilmRanking);
    ~FilmRanking();

    void setFilmCount(int _filmCount);
    void setFilmArray(const Film *_filmArray);

    int getFilmCount() const;
    const Film *getFilmArray() const;

    void topFilms(int size) const;
};