#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

#include "json.hpp"

class Account {
    public:
        Account(std::string name, std::string passwd);
        Account(std::string name, std::string passwd, nlohmann::json data);

        std::string getHash();
        std::string getName();
        double getBalance();

        nlohmann::json getData();

        bool success();

        nlohmann::json read();
        bool save();

        static Account create(std::string name, std::string passwd);
    
    private:
        std::string hash;
        nlohmann::json data;

        std::string getJSON_FilePath();
};

#endif