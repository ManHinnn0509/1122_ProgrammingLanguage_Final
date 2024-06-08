#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

#include "json.hpp"

class Account {
    public:
        // Need a fromUUID(string uuid) constructor
        Account(std::string name, std::string passwd);
        Account(std::string name, std::string passwd, nlohmann::json data);
        Account(std::string uuid);

        std::string getHash();
        std::string getName();
        double getBalance();
        vector<string> getTransactionHistory();

        void setBalance(int newBalance);
        void setTransactionHistory(vector<string> history);
        void addTransactionHistory(string hist);

        nlohmann::json getData();

        //bool alreadyExists();
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