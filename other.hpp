#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

#ifdef _WIN32
#include "windows.h"
#else
#include <unistd.h>
#endif

extern std::vector<std::string> affirmative;
extern std::vector<std::string> negative;

void mSleep(unsigned seconds);

bool Contains(const std::vector<std::string> &list, std::string x);