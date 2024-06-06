#ifndef UTILS_INPUT_H
#define UTILS_INPUT_H

#include <iostream>
#include <limits>

// From: https://stackoverflow.com/a/1455007
#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void SetStdinEcho(bool enable=true) {
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if(!enable)
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode);

#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if(!enable)
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

std::string scanPassword() {
    std::string passwd;
    SetStdinEcho(false);
    std::cin >> passwd;
    std::cout << "" << std::endl;
    SetStdinEcho(true);
    return passwd;
}

double scanDouble(const std::string& prompt) {
    double value;
    std::cout << prompt;
    std::cin >> value;

    // Check if the input was successful
    if (std::cin.fail()) {
        // Clear the error flag
        std::cin.clear();
        // Ignore invalid input
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        // Specific value that represents error
        return -0.069420;
        
    }
    else {
        // Ignore any remaining input
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), 
            '\n'
        );
        return value;
    }
}

#endif