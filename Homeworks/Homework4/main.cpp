#include <iostream>
#include "Vector.h"

// template <typename T>
// struct smartFunc
// {
//     T mapPtr =
// };

template <class T>
using mapApplier = T (*)(T);

template <class T>
void map(Vector<T> vec, mapApplier<T> applier)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = applier(vec[i]);
    }
}

template <class T>
T increment(T element)
{
    return element + 1;
}

void myF(Vector<int> vec, int a)
{
    printf("%d\n", vec[a]);
}

int main()
{

    Vector<int> vec;

    // void (*foo)(Vector<int>, int);
    // foo = &myF;
    // (*foo)(vec, 0);
    // printf("%d\n", vec.size());

    for (int i = 0; i < 15; i++)
    {
        vec.push(i);
        vec[i]++;
    }

    map<int>(vec, increment);

    vec.printVector();
    return 0;
}