#pragma once

#include <iostream>
#include "Product.hpp"
#include "Vector.hpp"

class Shop
{
private:
    Vector<Product> itemList;

public:
    Shop();
    size_t getShopSize();
    void addProduct(Product);
    void removeProduct(int);
    void printShop() const;
};