
#include "Helper.hpp"

namespace helper
{
    // int const MAX_ARRAY_SIZE = 502;  // max divisions(500) + symbols for opening, closing (2)
    // int const MAX_SLEEP_TIME = 2000; // in miliseconds
    // void sleeping(int seconds)
    // {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
    // }
    // void visualiseBar(char arr[], double progress = 0.25, char opening = '[', char closing = ']', bool showPercent = 1,
    //                   char filling = '*', char empty = '_', int divisions = 100)
    // {
    //     arr[divisions + 2];
    //     arr[0] = opening;         //sets the opening symbol of the bar
    //     arr[divisions] = closing; // sets the closing symbol of the bar
    //     arr[divisions + 1] = '\0';

    //     int reachedProgress = progress * 100.0;

    //     for (int i = 1; i < reachedProgress; i++)
    //     {
    //         arr[i] = filling;
    //     }
    //     if (showPercent && reachedProgress < 100)
    //     {
    //         for (int i = reachedProgress + 3; i < divisions; i++)
    //         { //sets percents at the center of the bar
    //             char firstPercent = (reachedProgress / 10 + '0');
    //             char scndPercent = (reachedProgress % 10 + '0');
    //             arr[(divisions + 1) / 2 - 1] = firstPercent;
    //             arr[(divisions + 1) / 2] = scndPercent;
    //             arr[(divisions + 1) / 2 + 1] = '%';
    //             arr[i] = empty;
    //         }
    //     }
    //     else
    //     {
    //         for (int i = reachedProgress; i < divisions; i++)
    //         {
    //             arr[i] = empty;
    //         }
    //     }

    //     for (int j = 0; j < divisions + 2; j++)
    //     {
    //         std::cout << arr[j];
    //     }
    //     std::cout << std::endl;
    // }

    int masiv5050[10] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    int masiv9010[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
    int masiv3070[10] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2};

    bool Chance5050()
    {
        srand(time(NULL));
        int a = rand() % 9;
        if (masiv5050[a] % 1 == 0)
            return true;
        else
            return false;
    }
    bool Chance3070()
    {
        srand(time(NULL));
        int a = rand() % 9;
        if (masiv3070[a] % 1 == 0)
            return true;
        else
            return false;
    }
    bool Chance9010()
    {
        srand(time(NULL));
        int a = rand() % 9;
        if (masiv9010[a] % 1 == 0)
            return true;
        else
            return false;
    }

    double BGtoUS(double a, int coins)
    {
        return a * coins * 3;
    }

    double UStoBG(double a, int coins)
    {
        return a * coins / 3;
    }

    double BGtoDE(double a, int coins)
    {
        return a * coins * 6;
    }

    double DEtoBG(double a, int coins)
    {
        return a * coins / 6;
    }

    double DEtoUS(double a, int coins)
    {
        return a * coins / 2.5;
    }

    double UStoDe(double a, int coins)
    {
        return a * coins * 2.5;
    }

    bool checkForMoneyType(String _string)
    {
        if (_string == "UNKNOWN")
            return true;
        else
            return false;
    }

    void normalisingValues(Vector<Coin> _vector)
    {
        for (int i = 1; i < _vector.size(); ++i)
        {
            _vector[i].changeValue(_vector[0].checkValue());
        }
    }
    void addingMoneyWithDifferentType(String _walletType, Coin _coin)
    {
        std::cout << "Error adding coin:\nexpected nationality " << _walletType << "\nrecived nationality " << _coin.checkNationality() << std::endl;
        //sleeping(2);
    }

    void notEmptyWalletChangeTypeError()
    {
        std::cout << "Unable to change wallet type, please make sure you are not changing type of not empty wallet" << std::endl;
        //sleeping(2);
    }

    bool isDiscountMatch(String _productSide, String _coinSide, double _discount)
    {
        if (_productSide == _coinSide)
        {
            std::cout << "Coins' sides match, you get a " << _discount << "% discount!\n";
            //sleeping(2);
            return true;
        }
        else
        {
            std::cout << "Coins' sides dont match, you dont get a discount :(\n";
            //sleeping(2);
            return false;
        }
    }

    void boughtWithBG(Coin _coin)
    {
        double a = _coin.checkValue();
        double b = BGtoDE(a, 1);
        double c = BGtoUS(a, 1);
        if (a < b && a < c)
        {
            std::cout << "It was cheapest to buy with BG coin, nice job!\n";
            //sleeping(2);
        }
        if (b < a && b < c)
        {
            std::cout << "It was cheapest to buy with DE coin, next time youll get more luck!\n";
            //sleeping(2);
        }
        if (c < a && c < b)
        {
            std::cout << "It was cheapest to buy with US coin, next time youll get more luck!\n";
            //sleeping(2);
        }
    }

    void boughtWithUS(Coin _coin)
    {
        double a = _coin.checkValue();
        double b = UStoBG(a, 1);
        double c = UStoDe(a, 1);
        if (a < b && a < c)
        {
            std::cout << "It was cheapest to buy with US coin, nice job!\n";
            //sleeping(2);
        }
        if (b < a && b < c)
        {
            std::cout << "It was cheapest to buy with BG coin, next time youll get more luck!\n";
            //sleeping(2);
        }
        if (c < a && c < b)
        {
            std::cout << "It was cheapest to buy with DE coin, next time youll get more luck!\n";
            //sleeping(2);
        }
    }

    void boughtWithDE(Coin _coin)
    {
        double a = _coin.checkValue();
        double b = DEtoBG(a, 1);
        double c = DEtoUS(a, 1);
        if (a < b && a < c)
        {
            std::cout << "It was cheapest to buy with DE coin, nice job!\n";
            //sleeping(2);
        }
        if (b < a && b < c)
        {
            std::cout << "It was cheapest to buy with BG coin, next time youll get more luck!\n";
            //sleeping(2);
        }
        if (c < a && c < b)
        {
            std::cout << "It was cheapest to buy with US coin, next time youll get more luck!\n";
            //sleeping(2);
        }
    }

    void boughtProduct(String _productName, Coin _coin)
    {
        std::cout << _productName << " was bought with " << _coin.checkNationality() << " coin with a stock value of " << _coin.checkValue() << std::endl;
        if (_coin.checkNationality() == "BG")
        {
            boughtWithBG(_coin);
            //sleeping(2);
        }
        if (_coin.checkNationality() == "DE")
        {
            boughtWithDE(_coin);
            //sleeping(2);
        }
        if (_coin.checkNationality() == "US")
        {
            boughtWithUS(_coin);
            //sleeping(2);
        }
    }

    // void addCoinAlert(Wallet _wallet)
    // {
    //     std::cout << "New coin added. Total coins are: " << _wallet.getSize();
    // }

    // void removeCoinAlert(Wallet _wallet)
    // {
    //     std::cout << "Coin removed. Total coins left: " << _wallet.getSize();
    // }

    int randomWallet()
    {
        int i = rand() % 3 + 1;
        return i;
    }

    // bool emptyWalletCheck(Wallet _wallet)
    // {
    //     if (_wallet.getSize() == 0)
    //     {
    //         std::cout << "You are trying to buy with empty wallet. Sir please get some money\n\n\nCredissimo is waiting!!\n";
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
}
