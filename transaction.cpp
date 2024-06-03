#include <iostream>
using namespace std;

#include "transaction.h"
#include "account.h"

// 1 user only

BasicTransaction::BasicTransaction(Account user, double amount) : user(user), amount(amount) {
    this->user = user;
    this->amount = amount;
}

Account BasicTransaction::getUser() {
    return this->user;
}

double BasicTransaction::getAmount() {
    return this->amount;
}

TransactionType BasicTransaction::getTransactionType() {
    return this->transactionType;
}

// Deposit & withdraw

DepositTransaction::DepositTransaction(Account user, double amount) : BasicTransaction(user, amount) {
    this->transactionType = TransactionType::DEPOSIT;
}

bool DepositTransaction::execute() const {
    cout << "Deposit - execute, amount: " << this->amount << endl;
}

WithdrawTransaction::WithdrawTransaction(Account user, double amount) : BasicTransaction(user, amount) {
    this->transactionType = TransactionType::WITHDRAW;
}

bool WithdrawTransaction::execute() const {
    cout << "Withdraw - execute, amount: " << this->amount << endl;
}

/* ---------------------------------------------------------------------------------------------------- */

// 2 users, transfer

TransferTransaction::TransferTransaction(Account src, Account dest, double amount) : BasicTransaction(src, amount), dest(dest) {
    this->dest = dest;
    this->transactionType = TransactionType::TRANSFER;
}

Account TransferTransaction::getSrc() {
    return this->user;
}

Account TransferTransaction::getDest() {
    return this->dest;
}

bool TransferTransaction::execute() const {
    
}
