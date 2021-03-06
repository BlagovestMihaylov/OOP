#include "Film.h"
#include "FilmRanking.h"

void FilmRanking::copy(const FilmRanking &otherFilmRanking)
{
    this->filmCount = otherFilmRanking.filmCount;
    int size = otherFilmRanking.filmCount;
    this->filmArray = new Film[size];
}

void FilmRanking::erase()
{
    delete[] this->filmArray;
}

void FilmRanking::sort(Film *filmArray, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            if (filmArray[j].getAwards() < filmArray[j - 1].getAwards())
            {
                Film a = filmArray[j];
                filmArray[j] = filmArray[j - 1];
                filmArray[j - 1] = a;
            }
        }
    }
}
//
FilmRanking::FilmRanking()
{
    this->filmArray = new Film[filmCount];
    this->filmCount = 0;
}

FilmRanking &FilmRanking::operator=(const FilmRanking &otherFilmRanking)
{
    if (this != &otherFilmRanking)
    {
        this->erase();
        this->copy(otherFilmRanking);
    }
    return *this;
}

FilmRanking::FilmRanking(const FilmRanking &other)
{
    this->copy(other);
}

FilmRanking::~FilmRanking()
{
    this->erase();
}

void FilmRanking::setFilmArray(const Film *_filmArray)
{

    delete[] this->filmArray;
    this->filmArray = new Film[filmCount];
    sort(this->filmArray, this->filmCount);
}

const Film *FilmRanking::getFilmArray() const
{
    return this->filmArray;
}

int FilmRanking::getFilmCount() const
{
    return this->filmCount;
}

void FilmRanking::topFilms(int size) const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << this->filmArray[i].getName() << " " << this->filmArray[i].getDirectorName() << " " << this->filmArray[i].getAwards() << std::endl;
    }
}