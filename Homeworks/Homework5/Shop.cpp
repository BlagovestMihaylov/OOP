#include "Shop.hpp"

Shop::Shop()
{
    itemList;
}

void Shop::addProduct(Product _product)
{
    itemList.push(_product);
}

void Shop::removeProduct(int _index)
{
    itemList.remove(_index);
}

void Shop::printShop() const
{
    for(int i =0; i<itemList.size(); ++i)
    {
        std::cout<<i<<".  Product name: "<<itemList[i].getProductName()<<",  Product prize: "<<itemList[i].getProductPrize()<<std::endl;
    }
}
