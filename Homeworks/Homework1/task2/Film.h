#include <iostream>
#include <cstring>

class Film
{
private:
    char *name;
    char *directorName;
    int awards;

    void copy(const Film &otherFilm);
    void erase();

public:
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