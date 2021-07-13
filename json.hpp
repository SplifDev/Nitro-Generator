#pragma once

#include "other.hpp"
#include <filesystem>

class json {
private:
    /* data */
public:
    json() {}
    ~json() {}
    std::string buildJSON(std::string type, std::string name, std::string value);
    std::string insertInListOrOBJ(std::string type,  std::string loo, std::string data, bool end);
    std::string finalTouch(std::string loo);
    std::string read(std::string fileName, std::string what);
    
    bool fexists(const char *filename);

    void writeJSON(std::string loo, std::string file);
};
