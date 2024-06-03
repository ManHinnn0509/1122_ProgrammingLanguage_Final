#include <iostream>
using namespace std;

#include "account.h"
#include "transaction.h"

#include "utils_input.h"

int main() {

    cout << "D0809371 - Bank System" << endl;
    cout << "" << endl;
    cout << "    1) Register" << endl;
    cout << "    2) Login" << endl;
    cout << "    3) Exit Program" << endl;
    cout << "" << endl;

    string option;
    while (true) {

        cout << "Option: ";
        cin >> option;

        // Register
        if (option == "1") {
            bool result = askRegister();
            if (result) {
                cout << "Success! Now please login with your credentials." << endl;
            }
            else {
                cout << "Failed! Something went wrong when attempting to register." << endl;
            }
        }

        // Login
        else if (option == "2") {
            Account a = askLogin();
            if (!a.success()) {
                cout << "Account not found / wrong credentials." << endl;
                continue;
            }
            accountOperations(a);
        }

        // Exit
        else if (option == "3") {
            break;
        }

        else {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

    }
    
    return 0;
}

void accountOperations(Account a) {
    cout << "Transactions" << endl;
    cout << endl;
    cout << "    1) Withdraw" << endl;
    cout << "    2) Deposit" << endl;
    cout << "    3) Transfer" << endl;
    cout << "    4) Logout" << endl;
    cout << endl;

    string option;
    while (true) {
        cout << "Transaction option: ";
        cin >> option;
        
        double amount = scanDouble("Amount: ");
        if (amount <= 0) {
            cout << "Invalid input." << endl;;
            continue;
        }

        if (option == "1") {
            WithdrawTransaction t(a, amount);
            t.execute();
        }
        else if (option == "2") {
            DepositTransaction t(a, amount);
            t.execute();
        }
        else if (option == "3") {
            string receiverID;
            cout << "Receiver's ID: ";
            cin >> receiverID;
        }
        else if (option == "4") {

        }
    }
}

bool askRegister() {
    string accName, passwd;
    // Ask for account name
    cout << "Account name: ";
    cin >> accName;

    // Ask for password but the input will be hidden
    cout << "Password: ";
    passwd = scanPassword();

    // Check if account already exists
    Account temp(accName, passwd);
    if (temp.success()) {
        return false;
    }

    // Something went wrong when registering
    temp = Account::create(accName, passwd);
    if (!temp.success()) {
        return false;
    }

    return true;
}

Account askLogin() {
    string accName, passwd;
    // Ask for account name
    cout << "Account name: ";
    cin >> accName;

    // Ask for password but the input will be hidden
    cout << "Password: ";
    passwd = scanPassword();

    Account a(accName, passwd);
    return a;
}