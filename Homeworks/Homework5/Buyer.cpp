#include "Buyer.hpp"

Buyer::Buyer()
{
    buyerName = "UNKNOWN";
}

Buyer::Buyer(String _name)
{
    buyerName = _name;
}

void Buyer::changeName(String _name)
{
    buyerName = _name;
}

void Buyer::printItems() const
{
    boughtItems.printShop();
}

void Buyer::addBoughtItem(Product _product)
{
    boughtItems.addProduct(_product);
}

void Buyer::addBGWallet(Wallet _wallet)
{
    if (_wallet.getMoneyType() == "DE")
    {
        BGwallet = _wallet;
    }
    else
    {
        std::cout << "You are trying to add a non-de wallet to de wallet" << std::endl;
    }
}

void Buyer::addDEWallet(Wallet _wallet)
{
    if (_wallet.getMoneyType() == "BG")
    {
        BGwallet = _wallet;
    }
    else
    {
        std::cout << "You are trying to add a non-bg wallet to bg wallet" << std::endl;
    }
}

void Buyer::addUSWallet(Wallet _wallet)
{
    if (_wallet.getMoneyType() == "US")
    {
        BGwallet = _wallet;
    }
    else
    {
        std::cout << "You are trying to add a non-us wallet to us wallet" << std::endl;
    }
}

String Buyer::getName()
{
    return buyerName;
}

void Buyer::preBuy(Product _product, Wallet _wallet)
{
    //bool a = helper::emptyWalletCheck(_wallet);
    //if (!a)
    if (_wallet.getSize() != 0)
    {
        boughtItems.addProduct(_product);
        helper::boughtProduct(_product.getProductName(), _wallet[0]);
    }
}

void Buyer::buy(Shop _shop, int pos)
{
    if (helper::randomWallet() == 1)
    {
        preBuy(_shop[pos], BGwallet);
        //helper::removeCoinAlert(BGwallet);
        BGwallet.removeCoin();
    }
    else if (helper::randomWallet() == 2)
    {
        preBuy(_shop[pos], USwallet);
        //helper::removeCoinAlert(USwallet);
        USwallet.removeCoin();
    }
    else if (helper::randomWallet() == 3)
    {
        preBuy(_shop[pos], DEwallet);
        //helper::removeCoinAlert(DEwallet);
        DEwallet.removeCoin();
    }

    _shop.removeProduct(pos);
}

void Buyer::enterShop(Shop _shop)
{
    int a;
    while (true)
    {
        _shop.printShop();

        std::cout << "Enter the number of product you wanna buy.\n ";
        std::cout << "If you wanna leave type 13\n";
        do
        {
            std::cin >> a;

        } while (a < 0 && a > _shop.getShopSize());
        if (a == 13)
            break;
        buy(_shop, a);
        addBoughtItem(_shop[a]);
    }
}