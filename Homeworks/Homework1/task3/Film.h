//#pragma once
#include <iostream>
#include <cstring>

class Film
{
private:
    void copy(const Film &otherFilm);
    void erase();

public:
    char *name;
    char *directorName;
    int awards;
    Film();
    Film &operator=(const Film &otherFilm);
    Film(const Film &otherFilm);
    ~Film();

    void setName(const char *_name);
    void setDirectorName(const char *_directorName);
    void setAwards(int _awards);

    const char *getName() const;
    const char *getDirectorName() const;
    int getAwards() const;

    void Print() const;
};