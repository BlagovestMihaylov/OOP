#include <iostream>
#include "Wallet.hpp"
#include "AmericanCoin.hpp"
#include "BulgarianCoin.hpp"
#include "GermanCoin.hpp"
#include "Product.hpp"
#include "Buyer.hpp"
#include "Shop.hpp"

int main()
{
    BulgarianCoin b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
    GermanCoin g1, g2, g3, g4, g5, g6, g7, g8, g9, g10;
    AmericanCoin a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    Wallet usWallet, bgWallet, deWallet;
    usWallet.changerMoneyType("US");
    bgWallet.changerMoneyType("BG");
    deWallet.changerMoneyType("DE");
    bgWallet.addCoin(b1);
    bgWallet.addCoin(b2);
    bgWallet.addCoin(b3);
    bgWallet.addCoin(b4);
    bgWallet.addCoin(b5);
    bgWallet.addCoin(b6);
    bgWallet.addCoin(b7);
    bgWallet.addCoin(b8);
    bgWallet.addCoin(b9);
    bgWallet.addCoin(b10);
    usWallet.addCoin(a1);
    usWallet.addCoin(a2);
    usWallet.addCoin(a3);
    usWallet.addCoin(a4);
    usWallet.addCoin(a5);
    usWallet.addCoin(a6);
    usWallet.addCoin(a7);
    usWallet.addCoin(a8);
    usWallet.addCoin(a9);
    usWallet.addCoin(a10);
    deWallet.addCoin(g1);
    deWallet.addCoin(g2);
    deWallet.addCoin(g3);
    deWallet.addCoin(g4);
    deWallet.addCoin(g5);
    deWallet.addCoin(g6);
    deWallet.addCoin(g7);
    deWallet.addCoin(g8);
    deWallet.addCoin(g9);
    deWallet.addCoin(g10);
    Product p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    Shop candyShop;
    p2.changeProductName("Konstantin");
    p2.changeProductPrize(420);
    candyShop.addProduct(p1);
    candyShop.addProduct(p2);
    candyShop.addProduct(p3);
    candyShop.addProduct(p4);
    candyShop.addProduct(p5);
    candyShop.addProduct(p6);
    candyShop.addProduct(p7);
    candyShop.addProduct(p8);
    candyShop.addProduct(p9);
    candyShop.addProduct(p10);
    Buyer Blago;
    Blago.addBGWallet(bgWallet);
    Blago.addDEWallet(deWallet);
    Blago.addUSWallet(usWallet);
    Blago.enterShop(candyShop);
    Blago.printItems();
}