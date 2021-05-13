#include "Wallet.hpp"

Wallet::Wallet()
{
    moneyType = "UNKNOWN";
}

Wallet::Wallet(String _moneyType)
{
    moneyType = _moneyType;
}

void Wallet::preAddCoin(Coin _coin)
{
    money.push(_coin);
}

String Wallet::getMoneyType()
{
    return moneyType;
}

void Wallet::changerMoneyType(String _moneyType)
{
    if (helper::checkForMoneyType(moneyType))
        moneyType = _moneyType;
    else
        helper::notEmptyWalletChangeTypeError();
}

void Wallet::addCoin(Coin _coin)
{
    if (helper::checkForMoneyType)
    {
        changerMoneyType(_coin.checkNationality());
        preAddCoin(_coin);
    }
    else
    {
        if (moneyType == _coin.checkNationality())
        {
            preAddCoin(_coin);
            helper::normalisingValues(money);
        }
        else
        {
            helper::addingMoneyWithDifferentType(moneyType, _coin);
        }
    }
}

void Wallet::removeCoin()
{
    money.remove(money.size());
}

size_t Wallet::getSize()
{
    return money.size();
}