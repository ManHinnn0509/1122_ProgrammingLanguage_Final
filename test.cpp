#include <iostream>
using namespace std;

#include "bank.h"

void testBankGetName() {
    Bank69 b69 = Bank69();
    Bank420 b420 = Bank420();

    cout << b69.getName() << endl;
    cout << b420.getName() << endl;
}

int main() {
    testBankGetName();
    return 0;
}
