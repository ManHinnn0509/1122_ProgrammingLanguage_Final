

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
    Account a1 = Account::create("user001", "123");
    Account a2 = Account::create("user002", "123");
    
    //Account a1("user001", "123");
    //Account a2("user002", "123");

    //cout << a1.getName() << endl;

    WithdrawTransaction t1(a1, 100.69420);
    DepositTransaction t2(a1, 500);

    t1.execute();
    t2.execute();

    cout << t1.toString() << endl;
    cout << t2.toString() << endl;

    TransferTransaction t3(a1, a2, 69.420420);
    t3.execute();
    
    cout << t3.toString() << endl;
}

int main() {
    testTransactionType();
    return 0;
}
