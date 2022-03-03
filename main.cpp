#include <iostream>

#include "xp58.h"


int main()
{
    std::cout << "Xp-58 tool starts..." << std::endl;

    Xp58 printer;

    for (int i = 0; i < 5; i++)
    {
        printer.PrintLine("This is a text to test Xp-58 printer.");
    }

    printer.ReverseModeOn();

    for (int i = 0; i < 5; i++)
    {
        printer.PrintLine("This is a text to test Xp-58 printer.");
    }

    printer.FeedNLine(2);

    return 0;
}
