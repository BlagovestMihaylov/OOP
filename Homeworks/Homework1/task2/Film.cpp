#include "Film.h"

void Film::copy(const Film &otherFilm)
{
    this->name = new char[strlen(otherFilm.name) + 1];
    strcpy(this->name, otherFilm.name);
    this->directorName = new char[strlen(otherFilm.directorName) + 1];
    strcpy(this->directorName, otherFilm.directorName);
    this->awards = otherFilm.awards;
}

void Film::erase()
{
    delete[] this->name;
    delete[] this->directorName;
}

Film::Film()
{
    this->name = new char[6];
    strcpy(this->name, "Empty");
    this->directorName = new char[6];
    strcpy(this->directorName, "Empty");
    this->awards = 0;
}

Film::Film(const Film &other)
{
    this->copy(other);
}

Film &Film::operator=(const Film &otherFilm)
{
    if (this != &otherFilm)
    {
        this->erase();
        this->copy(otherFilm);
    }
    return *this;
}

Film::~Film()
{
    this->erase();
}

void Film::setName(const char *_name)
{
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Film::setDirectorName(const char *_directorName)
{
    delete[] this->directorName;
    this->directorName = new char[strlen(_directorName) + 1];
    strcpy(this->directorName, _directorName);
}

void Film::setAwards(int _awards)
{
    this->awards = _awards;
}

const char *Film::getName() const
{
    return this->name;
}

const char *Film::getDirectorName() const
{
    return this->directorName;
}

int Film::getAwards() const
{
    return this->awards;
}

void Film::Print() const
{
    std::cout << this->name << std::endl;
    std::cout << this->directorName << std::endl;
    std::cout << this->awards << std::endl;
}