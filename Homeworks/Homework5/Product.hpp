#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "String.hpp"
#include <iostream>
#include "Helper.h"
#include "Coin.hpp"

class Product
{
private:
    String productName;
    double productPrize;
    double discount;
    Coin _coinDiscount;

public:
    Product();
    Product(String, double, double);
    void changeDiscount(double);
    void changeProductName(String);
    void changeProductPrize(double);
    const String getProductName() const;
    double getDiscount();
    const double getProductPrize() const;
};

#endif