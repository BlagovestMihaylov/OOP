#include <iostream>

class Complex
{
private:
    double realPart;
    double imaginaryPart;

public:
    Complex();
    Complex(double realPart, double imaginaryPart);

    void setRealPart(double _realPart);
    void setImaginaryPart(double _imaginaryPart);

    double getRealPart() const;
    double getImaginaryPart() const;

    void print() const;

    bool operator==(const Complex &other) const
    {
        return this->realPart == other.realPart && this->imaginaryPart == other.imaginaryPart;
    }

    bool operator!=(const Complex &other) const
    {
        return !(*this == other);
    }

    Complex operator+(const Complex &other) const
    {
        Complex temp;
        temp.realPart = realPart + other.realPart;
        temp.imaginaryPart = imaginaryPart + other.imaginaryPart;
        return temp;
    }

    Complex operator-(const Complex &other) const
    {
        Complex temp;
        temp.realPart = realPart - other.realPart;
        temp.imaginaryPart = imaginaryPart - other.imaginaryPart;
        return temp;
    }

    Complex operator*(const Complex &other) const
    {
        Complex temp;
        temp.realPart = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        temp.imaginaryPart = imaginaryPart * other.realPart + realPart * other.imaginaryPart;
        return temp;
    }

    Complex operator/(const Complex &other) const
    {
        Complex temp;
        double denom = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        temp.realPart = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denom;
        temp.imaginaryPart = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / denom;
        return temp;
    }

    Complex operator+=(const Complex &other)
    {
        realPart = realPart + other.realPart;
        imaginaryPart = imaginaryPart + other.imaginaryPart;
        return *this;
    }

    Complex operator-=(const Complex &other)
    {
        realPart = realPart - other.realPart;
        imaginaryPart = imaginaryPart - other.imaginaryPart;
        return *this;
    }

    Complex operator*=(const Complex &other)
    {
        double temp = realPart;
        realPart = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        imaginaryPart = imaginaryPart * other.realPart + temp * other.imaginaryPart;
        return *this;
    }

    Complex operator/=(const Complex &other)
    {
        double temp = realPart;
        double denom = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        realPart = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denom;
        imaginaryPart = (imaginaryPart * other.realPart - temp * other.imaginaryPart) / denom;
        return *this;
    }

    // Complex &operator=(const Complex &other);
};