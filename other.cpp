#include "other.hpp"

bool Contains(const std::vector<std::string> &list, std::string x) {
	return std::find(list.begin(), list.end(), x) != list.end();
}

void mSleep(unsigned seconds) {
	#ifdef _WIN32
		Sleep(seconds*1000);
	#else
		usleep(seconds*1000000);
	#endif
}

std::vector<std::string> affirmative{"yes", "y", "1", "true",  "t"};
std::vector<std::string> negative   {"no",  "n", "0", "false", "f"};