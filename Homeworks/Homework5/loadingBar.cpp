#include <iostream>
#include <thread>

int const MAX_ARRAY_SIZE = 502;  // max divisions(500) + symbols for opening, closing (2)
int const MAX_SLEEP_TIME = 2000; // in miliseconds
void sleeping(int seconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
}
void visualiseBar(char arr[], double progress = 0.25, char opening = '[', char closing = ']', bool showPercent = 1,
                  char filling = '*', char empty = '_', int divisions = 100)
{
    arr[divisions + 2];
    arr[0] = opening;         //sets the opening symbol of the bar
    arr[divisions] = closing; // sets the closing symbol of the bar
    arr[divisions + 1] = '\0';

    int reachedProgress = progress * 100.0;

    for (int i = 1; i < reachedProgress; i++)
    {
        arr[i] = filling;
    }
    if (showPercent && reachedProgress < 100)
    {
        for (int i = reachedProgress + 3; i < divisions; i++)
        {   //sets percents at the center of the bar
            char firstPercent = (reachedProgress / 10 + '0');
            char scndPercent = (reachedProgress % 10 + '0');
            arr[(divisions + 1) / 2 - 1] = firstPercent;
            arr[(divisions + 1) / 2] = scndPercent;
            arr[(divisions + 1) / 2 + 1] = '%';
            arr[i] = empty;
        }
    }
    else
    {
        for (int i = reachedProgress; i < divisions; i++)
        {
            arr[i] = empty;
        }
    }

    for (int j = 0; j < divisions + 2; j++)
    {
        std::cout << arr[j];
    }
    std::cout << std::endl;
}

int main()
{
    //default values
    char openingSymbol = '[';
    char closingSymbol = ']';
    bool showPercent = 1;
    char fillingSymbol = '*';
    char emptySymbol = '_';
    int cntOfDivisionsOfTheBar = 100;
    char percent;
    char arrayOfSymbols[MAX_ARRAY_SIZE];
    int time; // in seconds

    std::cout << "Time: ";
    std::cin >> time;

    int sleepTime = time * 10;
    if (sleepTime <= MAX_SLEEP_TIME)
    {

        std::cout << "Enter an opening, filling, empty and closing symbol, whether or not to visualise percents and progress \n";
        std::cout << "Opening symbol: ";
        std::cin >> openingSymbol;
        std::cout << "Closing symbol: ";
        std::cin >> closingSymbol;
        std::cout << "Show percents? Type Y for yes or N for no: ";
        std::cin >> percent;
        std::cout << "Filling symbol: ";
        std::cin >> fillingSymbol;
        std::cout << "Empty symbol: ";
        std::cin >> emptySymbol;

        if (percent == 'N')
        {
            showPercent = 0;
        }

        int j;
        for (j = 0; j <= 100; j++)
        {
            system("clear");
            visualiseBar(arrayOfSymbols, (double)j / 100.0, openingSymbol, closingSymbol, showPercent, fillingSymbol, emptySymbol, cntOfDivisionsOfTheBar);
            sleeping(sleepTime);
        }
    }
    return 0;
}