#ifndef UTILS_INPUT_H
#define UTILS_INPUT_H

#include <iostream>
#include <time.h>

std::string getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buffer[80];
    tstruct = *localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &tstruct);
    return buffer;
}

#endif