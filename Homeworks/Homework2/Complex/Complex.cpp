#include "Complex.h"

Complex::Complex()
{
    this->realPart = 0.0;
    this->imaginaryPart = 0.0;
}

Complex::Complex(double _real, double _imag)
{
    realPart = _real;
    imaginaryPart = _imag;
}

// Complex &Complex::operator=(const Complex &other)
// {
//     if (this != &other)
//     {
//         //return other;
//     }
//     return *this;
// }

void Complex::setRealPart(double _real)
{
    realPart = _real;
}

void Complex::setImaginaryPart(double _imag)
{
    imaginaryPart = _imag;
}

double Complex::getRealPart() const
{
    return realPart;
}

double Complex::getImaginaryPart() const
{
    return imaginaryPart;
}

void Complex::print() const
{
    if (imaginaryPart < 0)
    {
        std::cout << realPart << " - " << imaginaryPart * -1 << "i" << std::endl;
    }
    else if (imaginaryPart > 0)
    {
        std::cout << realPart << " + " << imaginaryPart << "i" << std::endl;
    }
    else
    {
        std::cout << realPart << std::endl;
    }
}
