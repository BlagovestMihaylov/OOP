#include "Product.hpp"

void Product::changeDiscount(double _dis)
{
    discount = _dis;
}

void Product::changeProductPrize(double _prize)
{
    productPrize = _prize;
}

void Product::changeProductName(String _name)
{
    productName = _name;
}

const String Product::getProductName() const
{
    return productName;
}

const double Product::getProductPrize() const
{
    return productPrize;
}

double Product::getDiscount()
{
    return discount;
}

Product::Product()
{
    productName = "UNKNOWN PRODUCT";
    discount = 0;
    productPrize = 0;
    _coinDiscount.changeValue(100);
}

Product::Product(String _name, double _prize, double _dis)
{
    productName = _name;
    productPrize = _prize;
    discount = _dis;
    _coinDiscount.changeValue(100);
}