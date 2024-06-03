#include <iostream>
using namespace std;

#include "account.h"
#include "bank.h"
#include "transaction.h"

void testBankGetName() {
    Bank69 b69 = Bank69();
    Bank420 b420 = Bank420();

    cout << b69.getName() << endl;
    cout << b420.getName() << endl;
}

void testTransactionType() {
    //Account a = Account::create("user001", "123");
    
    Account a("user001", "123");
    //cout << a.getName() << endl;

    WithdrawTransaction t1(a, 100);
    DepositTransaction t2(a, 500);

    t1.execute();
    t2.execute();
}

int main() {
    testTransactionType();
    return 0;
}
