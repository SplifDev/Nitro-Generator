#include "bot.hpp"
#include "other.hpp"
#include "json.hpp"

bool start() {
    json JSON;
    if (!JSON.fexists("config.json")) {
        std::cout << "Hi there! Are you tierd of writing over, and over the same code for each Discord Bot?" <<std::endl\
                  << "Do you want a faster way to write them?" << std::endl\
                  << "Well, we have the solution! The ORCAFUL development team made this app for you, enjoy!" << std::endl << std::endl;
                  mSleep(10);
    }

    std::string response;
    std::cout << "Would you like to start a new bot?" << std::endl;
    std::cin >> response;
    std::string myinput;

    if (Contains(affirmative, response)) {
        return true;
    }
    else if (Contains(negative, response)) {
        return false;
    }
    return false;
}

bool createdOnDiscord(bool confirm) {
    if (confirm == true) {
        std::string response;
        std::cout << "Do you have a bot account for it? ";
        std::cin >> response;
        if (Contains(affirmative, response)) {
            return true;
        }
        if (Contains(negative, response)) {
            while (!Contains(affirmative, response)) {
                std::cout << "Then go ahead to https://discord.com/developers/applications and make an APP, and after that, make a BOT account!" << std::endl;
                std::cout << "Did you made it?" << std::endl;
                std::cin >> response;
            }
            return true;
        }
        else {
            std::cout << "I didn't understand that, Let's start again!" << std::endl << std::endl << std::endl;
            stringErrHandler("false", "");
        }
        
    }
    return false;
}

void stringErrHandler(std::string output, std::string reason) {
    if (output == "error") {
        std::cerr << "An error occured!" << std::endl;
        std::cerr << "error out: " << reason;
    }

    if (output == "restart") {
        createNew(true);
    }

    if (output == "TRestart") {
        getTOKEN(true);
    }

    if (output == "false") {
        createdOnDiscord(true);
    }
    
    

    else {
        std::cerr << "function status not recognized" << std::endl;
        std::cerr << "fatal error occured" << std::endl;
        exit(-1);
    }
    
    
}

std::string createNew(bool confirm) {
    if (confirm == false) {
        stringErrHandler("error", "confirm is false");
        return "error";
    }
    else if (confirm == true) {
        std::string out, name, TOKEN, userConfirm;
        std::cout << "What is it's a name: ";
        std::cin >> name;
        std::cout << "So it's name is: " << name << " , right? ";
        std::cin >> userConfirm;
        if (Contains(affirmative, userConfirm)) {
            out = name;
            userConfirm = "";
            return out;
        }
        else {
            std::cout << "So I miss understood, let's start again!" << std::endl << std::endl << std::endl;
            stringErrHandler("restart", "");
            return "restart";
        }
        
    }
    else {
        stringErrHandler("error", "confirm is invalid");
        return "error";
    }
    return "";
}

std::string getTOKEN(bool confirm) {
    std::string TOKEN, userConfirm, out;
    std::cout << "In order to create the configuration file I need the bot token, can you give it to me?" << std::endl;
    std::cout << "Don't worry this token will be just placed in a config.json file" << std::endl;
    std::cin >> TOKEN;
    std::cout << "So your token is: " << std::endl;
    std::cout << TOKEN << std::endl << "is that correct? ";
    std::cin >> userConfirm;
    if (Contains(affirmative, userConfirm)) {
            out = TOKEN;
            userConfirm = "";
            return out;
        }

    else {
            std::cout << "So I miss understood, let's start again! " << std::endl << std::endl << std::endl;
            stringErrHandler("TRestart", "");
            return "restart";
        }
    return "";
}

std::string generateCONFIG(std::string name, std::string token) {
    std::string jname, jtoken, jobject;
    json mJson;
    jname = mJson.buildJSON("string", "name", name);
    jtoken = mJson.buildJSON("string", "token", token);
    jobject = mJson.buildJSON("object", name, "");
    jobject = mJson.insertInListOrOBJ("object", jobject, jname, false);
    jobject = mJson.insertInListOrOBJ("object", jobject, jtoken, true);
    jobject = mJson.finalTouch(jobject);
    mJson.writeJSON(jobject, "config.json");
    
    return jobject;
}

void tmp() {
    json JSON;
    JSON.read("config.json");
}