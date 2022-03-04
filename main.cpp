#include <iostream>

#include "cxxopts.hpp"

#include "xp58.h"


int main(int argc, char **argv)
{
    cxxopts::Options options("xp58tool", "A tool to control Xp-58 printer.");
    options.allow_unrecognised_options();
    options.add_options()
            ("d,device", "Xp-58 device path", cxxopts::value<std::string>()->default_value("/dev/usb/lp0"))
            ("t,text", "Text", cxxopts::value<std::string>())
            ("h,help", "Xp-58 Tool Help");

    auto result = options.parse(argc, argv);

    if (result.count("help") || result.count("text") == 0)
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    std::cout << "Start printing..." << std::endl;

    Xp58 printer(result["device"].as<std::string>().c_str());
    printer.PrintLine(result["text"].as<std::string>());
    printer.FeedNLines(2);

    std::cout << "Finish." << std::endl;

    return 0;
}
