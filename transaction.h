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
        std::string getDateTime();
        std::string toString();

        virtual bool execute() const = 0;

    protected:
        std::string transactionType = "Default";
        Account user;
        double amount;
        std::string dateTime;

};

class DepositTransaction : public BasicTransaction {
    public:
        DepositTransaction(Account user, double amount);
        bool execute() const override;
};

class WithdrawTransaction : public BasicTransaction {
    public:
        WithdrawTransaction(Account user, double amount);
        bool execute() const override;
};

/* ---------------------------------------------------------------------------------------------------- */

class TransferTransaction : public BasicTransaction {
    public:
        TransferTransaction(Account src, Account dest, double amount);

        Account getSrc();
        Account getDest();

        bool execute() const override;

        std::string toString();

    private:
        Account dest;
};

#endif
