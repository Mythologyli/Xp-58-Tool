#include <iostream>

#include "xp58.h"


int main()
{
    std::cout << "Xp-58 tool starts..." << std::endl;

    Xp58 printer;
    printer.PrintLine("This is a text to test Xp-58 printer.");
    printer.FeedNLine(2);

    return 0;
}
