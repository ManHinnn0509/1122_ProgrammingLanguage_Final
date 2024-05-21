#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

#include "account.h"

class Transaction {
    public:
        Transaction(Account from, Account to, double amount);
    
    private:
        Account from;
        Account to;
        double amount;
};

#endif
