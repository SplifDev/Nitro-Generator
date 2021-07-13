#include <iostream>
#include "other.hpp"
#include "bot.hpp"

int main() {
    bool startArg = start();
    //bool startArg = false;
    if (startArg) {
        createdOnDiscord(startArg);
        std::string BOTName = createNew(startArg);
        std::string BOTToken = getTOKEN(startArg);
        std::string Config = generateCONFIG(BOTName, BOTToken);
        std::cout << Config << std::endl;
    }
    if (!startArg) {
        tmp();
    }
    return 0;
}