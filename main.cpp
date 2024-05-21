#include <iostream>
using namespace std;

#include "account.h"

int main() {
    Account a = Account::create("hin", "123");
    
    // This line always became 0, idk why
    cout << a.getData() << endl;
    
    cout << "---" << endl;

    Account a2("hin", "123");
    cout << a2.getName() << endl;
    cout << a2.getData() << endl;
    cout << a2.success() << endl;

    cout << "-----" << endl;

    Account a3("hinnnnnn", "qiwdoqwoid");
    cout << a3.getData() << endl;
    cout << a3.success() << endl;
    
    return 0;
}