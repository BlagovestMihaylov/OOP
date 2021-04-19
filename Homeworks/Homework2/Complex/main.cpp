#include "Complex.h"

int main()
{
    Complex a;
    Complex b;
    a.setRealPart(1);
    a.setImaginaryPart(2);
    b.setRealPart(2);
    b.setImaginaryPart(3);
    Complex t;
    t.print();
    t = a + b;
    t.print();
    t = a - b;
    t.print();
    t = a * b;
    t.print();
    t = a / b;
    t.print();
    // for (int i = 1; i < 10; i++)
    // {
    //     a += b;
    //     a.print();
    // }
    for (int i = 1; i < 10; i++)
    {
        a *= b;
        a.print();
    }

}