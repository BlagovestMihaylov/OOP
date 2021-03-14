#include <iostream>
//#include "Film.h"
#include "FilmRanking.h"

int main()
{
    Film film1;
    film1.setAwards(7);
    film1.setDirectorName("Stefan Gergzhikov");
    film1.setName("Horror in FMI");
    film1.Print();
    Film film2;
    film2.setAwards(10);
    film2.setDirectorName("Stefan Gergzhikov");
    film2.setName("Horror in FMI");
    film2.Print();
    Film film3;
    film3.setAwards(15);
    film3.setDirectorName("Stefan Gergzhikov");
    film3.setName("Horror in FMI");
    film3.Print();
    Film film4;
    film4.setAwards(1);
    film4.setDirectorName("Stefan Gergzhikov");
    film4.setName("Horror in FMI");
    film4.Print();
    Film film5;
    film5.setAwards(2);
    film5.setDirectorName("Stefan Gergzhikov");
    film5.setName("Horror in FMI");
    film5.Print();

    FilmRanking topFilms;
    Film *films = new Film[10];
    films[0] = film1;
    films[1] = film2;
    films[2] = film3;
    films[3] = film4;
    films[4] = film5;
    
    topFilms.setFilmArray(films);
    int size = topFilms.getFilmCount();
    topFilms.topFilms(size);
}