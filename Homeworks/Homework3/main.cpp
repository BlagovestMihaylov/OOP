#include "String.h"

int main()
{
    String s1 = "Hello";
    s1.printString();
    String s2 = " world";
    //String s3 = s1 + s2;
    s1.add(s2);
    s1.printString();
   // s3.printString();

    return 0;
}