#pragma once

#include "Wallet.hpp"
#include "Product.hpp"
#include "Shop.hpp"
#include "String.hpp"

class Buyer
{
private:
    String buyerName;
    Wallet BGwallet;
    Wallet USwallet;
    Wallet DEwallet;
    Shop boughtItems;
    void preBuy(Product, Wallet);

public:
    void changeName(String);
    void addBGWallet(Wallet);
    void addUSWallet(Wallet);
    void addDEWallet(Wallet);
    void addBoughtItem(Product);

    String getName();
    void printItems() const;

    void buy(Shop, int);
    void enterShop(Shop);

    Buyer();
    Buyer(String);

    
};