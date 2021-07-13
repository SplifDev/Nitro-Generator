#include "json.hpp"
#include <fstream>
#include <streambuf>

std::string json::buildJSON(std::string type, std::string name, std::string value) {
    if (type == "bool" || type == "number") {
        return "\"" + name + "\" : " + value + "";
    }
    if (type == "string") {
        return "\"" + name + "\" : \"" + value + "\"";
    }
    if (type == "list") {
        return name + " []";
    }
    if (type == "object") {
        return "\"" + name + "\" :" + " {}";
    }
    return "";
}

std::string json::insertInListOrOBJ(std::string type,  std::string loo, std::string data, bool end) {
    std::string toFind;
    if (type == "object") {
        toFind = "}";
    }
    if (type == "list") {
        toFind = "]";
    }
    
    int where = loo.find_last_of(toFind);
    data = data + ", ";
    loo.insert(where, data);
    if (end == true){
        loo.resize(loo.size() - 3);
        loo += "}";
    }
    return loo;
}

std::string json::finalTouch(std::string loo) {
    loo.insert(0, "{\n    ");
    loo.insert(loo.length(), "\n}");
    return loo;
}

std::string json::read(std::string fileName) {
    std::ifstream file(fileName.c_str());
    std::string str((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    std::cout << str << std::endl;
    std::string tmp = str.erase(str.length() - 4);
    int tmpInt = tmp.find_last_of("\"");
    std::string TOKEN = tmp.substr(tmpInt + 1, tmp.length());
    std::cout << "Token: " << TOKEN << std::endl;
    tmpInt = 0;
    tmpInt = tmp.find_last_of("\"");
    std::cout << tmp << std::endl << std::endl;
    int tmp2 = tmpInt;
    tmpInt =  tmp.length() - tmpInt;
    int tmp1 = tmp.length();
    
    tmp = tmp.erase(tmpInt, tmp.length());
    std::cout << tmp << tmpInt << std::endl << tmp1 << " " << tmp2 << std::endl;
    return "a";
}

void json::writeJSON(std::string loo, std::string file) {
    std::ofstream openedFile(file.c_str());
    openedFile.clear();
    openedFile << loo.c_str();
    openedFile.close();
}

bool json::fexists(const char *filename) {
  std::ifstream ifile(filename);
  return ifile.good();
}