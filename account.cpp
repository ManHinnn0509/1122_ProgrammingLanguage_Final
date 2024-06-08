#include <sys/stat.h>
#include <iostream>
using namespace std;

#include "account.h"

#include "md5.h"
#include "json.hpp"
using json = nlohmann::json;

#include "utils.h"

Account::Account(string name, string passwd) {
    this->hash = MD5(name + "_" + passwd).toStr();
    this->data = this->read();
}

Account::Account(string name, string passwd, json data) {
    this->hash = MD5(name + "_" + passwd).toStr();
    this->data = data;
}

Account::Account(string uuid) {
    this->hash = uuid;
    this->data = this->read();
}

/*
bool Account::alreadyExists() {
    string filePath = "./data/account/" + this->getHash() + ".json";
    struct stat buffer;
    return (stat (filePath.c_str(), &buffer) == 0);
}
*/

bool Account::success() {
    return this->data != NULL;
}

string Account::getHash() {
    return this->hash;
}

string Account::getName() {
    return this->data["name"];
}

double Account::getBalance() {
    return this->data["balance"];
}

vector<string> Account::getTransactionHistory() {
    return this->data["transaction_history"];
}

void Account::setBalance(int newBalance) {
    this->data["balance"] = newBalance;
}

void Account::setTransactionHistory(vector<string> history) {
    this->data["transaction_history"] = history;
}

void Account::addTransactionHistory(string hist) {
    vector<string> h = this->getTransactionHistory();
    h.push_back(hist);
    this->setTransactionHistory(h);
}

json Account::getData() {
    return this->data;
}

string Account::getJSON_FilePath() {
    return "./data/account/" + this->hash + ".json";
}

json Account::read() {
    return readJSON_File(this->getJSON_FilePath());
}

bool Account::save() {
    json data = this->data;
    bool b = writeJSON_File(this->getJSON_FilePath(), data);
    return b;
}

Account Account::create(string name, string passwd) {

    vector<string> v;
    
    json data = {
        {"name", name},
        {"balance", 0.0},
        {"transaction_history", v}
    };

    Account a(name, passwd, data);
    
    string p = a.getJSON_FilePath();
    bool ignored = writeJSON_File(p, data);

    return a;
}

