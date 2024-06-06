#include <iostream>
#include <sstream>
using namespace std;

#include "transaction.h"
#include "account.h"

#include "utils_time.h"

// 1 user only

BasicTransaction::BasicTransaction(Account user, double amount) : user(user), amount(amount) {
    this->user = user;
    this->amount = amount;
    this->dateTime = getCurrentDateTime();
}

Account BasicTransaction::getUser() {
    return this->user;
}

double BasicTransaction::getAmount() {
    return this->amount;
}

string BasicTransaction::getTransactionType() {
    return this->transactionType;
}

string BasicTransaction::getDateTime() {
    return this->dateTime;
}

string BasicTransaction::toString() {
    return "[" + getDateTime() + "] " + this->getTransactionType() + ", " + to_string(this->getAmount());
}

// Deposit & withdraw

DepositTransaction::DepositTransaction(Account user, double amount) : BasicTransaction(user, amount) {
    this->transactionType = "Deposit";
}

bool DepositTransaction::execute() const {
    cout << "Deposit - execute, amount: " << this->amount << endl;
}

WithdrawTransaction::WithdrawTransaction(Account user, double amount) : BasicTransaction(user, amount) {
    this->transactionType = "Withdraw";
}

bool WithdrawTransaction::execute() const {
    cout << "Withdraw - execute, amount: " << this->amount << endl;
}



/* ---------------------------------------------------------------------------------------------------- */

// 2 users, transfer

TransferTransaction::TransferTransaction(Account src, Account dest, double amount) : BasicTransaction(src, amount), dest(dest) {
    this->dest = dest;
    this->transactionType = "Transfer";
}

Account TransferTransaction::getSrc() {
    return this->user;
}

Account TransferTransaction::getDest() {
    return this->dest;
}

bool TransferTransaction::execute() const {
    TransferTransaction* dis = const_cast<TransferTransaction*>(this);
    cout << "From: " << dis->getSrc().getName() << ", To: " << dis->getDest().getName() << ", Amount: " << dis->getAmount() << endl;
}

string TransferTransaction::toString() {
    return "[" + getDateTime() + "] "
             + "From: " + this->getSrc().getName()
             + ", To: " + this->getDest().getName()
             + ", Amount: " + to_string(this->getAmount());
}