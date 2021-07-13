#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>
#include <fstream>
#include "other.hpp"

bool start();

bool createdOnDiscord(bool confirm);

void tmp();

std::string createNew(bool confirm);
std::string getTOKEN(bool confirm);
std::string generateCONFIG(std::string name, std::string token);
void stringErrHandler(std::string output, std::string reason);