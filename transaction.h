#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <optional>

#include "account.h"

enum TransactionType {
    DEFAULT = 0,
    WITHDRAW = 1,
    DEPOSIT = 2,
    TRANSFER = 3
};

class Transaction {
    public:
        Transaction(Account source, Account dest, double amount);
        Transaction(Account user, double amount);

        TransactionType getType();
        std::optional<Account> getSource();
        std::optional<Account> getDest();
        double getAmount();
    
    protected:
        TransactionType type = TransactionType::DEFAULT;
        std::optional<Account> source;
        std::optional<Account> dest;
        double amount;
};

class TransferTransation : public Transaction {
    public:
        TransferTransation(Account source, Account dest, double amount) : Transaction(source, dest, amount) {
            Transaction(source, dest, amount);
            this->type = TransactionType::TRANSFER;
        }
};

class WithdrawTransaction : public Transaction {
    public:
        WithdrawTransaction(Account source, double amount) : Transaction(source, amount) {
            Transaction(source, amount);
            this->type = TransactionType::WITHDRAW;
        }
};

class DepositTransaction : public Transaction {
    public:
        DepositTransaction(Account source, double amount) : Transaction(source, amount) {
            Transaction(source, amount);
            this->type = TransactionType::DEPOSIT;
        }
};

#endif
