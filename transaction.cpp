#include <iostream>
#include <optional>

using namespace std;

#include "transaction.h"

Transaction::Transaction(Account source, Account dest, double amount)
    : source(source), dest(dest), amount(amount) {
    this->source = source;
    this->dest = dest;
    this->amount = amount;
}

Transaction::Transaction(Account source, double amount)
    : source(source), dest(nullopt), amount(amount) {
    this->source = source;
    this->amount = amount;
}

TransactionType Transaction::getType() {
    return this->type;
}

optional<Account> Transaction::getSource() {
    return this->source;
}

optional<Account> Transaction::getDest() {
    return this->dest;
}

double Transaction::getAmount() {
    return this->amount;
}
