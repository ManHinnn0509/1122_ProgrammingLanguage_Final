#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <optional>

#include "account.h"


class BasicTransaction {
    public:
        BasicTransaction(Account user, double amount);
        Account getUser() ;
        double getAmount();
        std::string getTransactionType();

        bool execute() const {}

    protected:
        std::string transactionType = "Default";
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
        Account dest;
};

#endif
