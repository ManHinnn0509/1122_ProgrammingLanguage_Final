#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <time.h>
#include <fstream>

#include "json.hpp"

nlohmann::json readJSON_File(std::string path) {
    try {
        std::ifstream f(path);
        nlohmann::json data = nlohmann::json::parse(f);
        return data;    
    }
    catch (std::exception& e) {
        return NULL;
    }
}

bool writeJSON_File(std::string path, nlohmann::json data) {
    try {
        std::ofstream f(path);
        f << std::setw(4) << data << std::endl;
        return true;
    }
    catch (std::exception& e) {
        std::cout << "gg" << std::endl;
        return false;        
    }
}

std::string getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buffer[80];
    tstruct = *localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &tstruct);
    return buffer;
}

#endif