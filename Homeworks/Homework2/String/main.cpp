#include <iostream>
#include "String.h"

int main()
{
    String a = "Hello";
    String b = "World";
    a.Add('o');
    a.removeAt(2);
    b.trimEnd();
    b.trimStart(2);
    String c = a + b;
    a.printString();
    std::cout << std::endl;
    b.printString();
    std::cout << std::endl;
    c.printString();
    std::cout << std::endl;
}