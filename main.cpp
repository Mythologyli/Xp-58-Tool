#include <iostream>

#include "xp58.h"


int main()
{
    std::cout << "Xp-58 tool starts..." << std::endl;

    Xp58 printer;

    printer.SetCharacterSize(2, 2);

    for (int i = 0; i < 1; i++)
    {
        printer.PrintLine("This is a text to test Xp-58 printer.");
    }

    printer.FeedNLines(2);

    return 0;
}
