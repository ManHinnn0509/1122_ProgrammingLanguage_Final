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
    return writeJSON_File(this->getJSON_FilePath(), data);
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

