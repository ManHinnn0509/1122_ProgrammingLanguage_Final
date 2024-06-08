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
    //cout << "Deposit - execute, amount: " << this->amount << endl;

    DepositTransaction* dis = const_cast<DepositTransaction*>(this);

    Account user = dis->getUser();
    user.setBalance(user.getBalance() + dis->getAmount());
    user.addTransactionHistory(dis->toString());
    return user.save();
}

WithdrawTransaction::WithdrawTransaction(Account user, double amount) : BasicTransaction(user, amount) {
    this->transactionType = "Withdraw";
}

bool WithdrawTransaction::execute() const {
    //cout << "Withdraw - execute, amount: " << this->amount << endl;

    WithdrawTransaction* dis = const_cast<WithdrawTransaction*>(this);

    Account user = dis->getUser();
    /*
    if (user.getBalance() < dis->getAmount()) {
        return false;
    }
    */
    user.setBalance(user.getBalance() - dis->getAmount());
    user.addTransactionHistory(dis->toString());
    return user.save();
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
    //cout << "From: " << dis->getSrc().getName() << ", To: " << dis->getDest().getName() << ", Amount: " << dis->getAmount() << endl;

    Account src = dis->getSrc();
    Account dest = dis->getDest();
    double amount = dis->getAmount();

    // Checked before executing
    /*
    if (src.getBalance() < amount) {
        return false;
    }
    */

    src.setBalance(src.getBalance() - amount);
    src.addTransactionHistory(dis->toString());
    bool b1 = src.save();

    dest.setBalance(dest.getBalance() + amount);
    dest.addTransactionHistory(dis->toString());
    bool b2 = dest.save();

    return (b1 && b2);
}

string TransferTransaction::toString() {
    return "[" + getDateTime() + "] "
             + "From: " + this->getSrc().getName()
             + ", To: " + this->getDest().getName()
             + ", Amount: " + to_string(this->getAmount());
}