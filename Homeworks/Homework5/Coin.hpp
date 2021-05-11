
#include <iostream>
#include "String.hpp"

class Coin
{
private:
enum face{HEADS, TAILS};
String nationality;
int value;

public:
bool flip();
void print() const;

public:
Coin();
Coin(String, int);

};
