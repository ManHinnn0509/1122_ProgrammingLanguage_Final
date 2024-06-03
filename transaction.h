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

class BasicTransaction {
    public:
        BasicTransaction(Account user, double amount);
        Account getUser() ;
        double getAmount();
        TransactionType getTransactionType();

        bool execute() const {}

    protected:
        TransactionType transactionType = TransactionType::DEFAULT;
        Account user;
        double amount;

};

class DepositTransaction : public BasicTransaction {
    public:
        DepositTransaction(Account user, double amount);
        bool execute() const;
};

class WithdrawTransaction : public BasicTransaction {
    public:
        WithdrawTransaction(Account user, double amount);
        bool execute() const;
};

/* ---------------------------------------------------------------------------------------------------- */

class TransferTransaction : public BasicTransaction {
    public:
        TransferTransaction(Account src, Account dest, double amount);
        Account getSrc();
        Account getDest();
        bool execute() const;

    private:
        TransactionType transactionType = TransactionType::DEFAULT;
        Account dest;
        double amount;
};

#endif
