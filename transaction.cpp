#include "transaction.h"

using namespace std;

Transaction::Transaction(Account from, Account to, double amount) : from(from), to(to), amount(amount) {
    this->from = from;
    this->to = to;
    this->amount = amount;
}