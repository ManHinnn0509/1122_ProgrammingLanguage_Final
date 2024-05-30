#ifndef BANK_H
#define BANK_H

#include <iostream>

class Bank {
    public:
        Bank(std::string name) {
            this->name = name;
        }

        std::string getName();

    private:
        std::string name;
};

class Bank69 : public Bank {
    public:
        Bank69() : Bank("Bank69") {

        }

    private:

};

class Bank420 : public Bank {
    public:
        Bank420() : Bank("Bank420") {

        }

    private:

};

#endif