#include <iostream>
using namespace std;

#include "account.h"
#include "transaction.h"

#include "utils_input.h"

void accountOperations(string uuid);
bool askRegister();
Account askLogin();

int main() {

    while (true) {

        cout << "D0809371 - Bank System" << endl;
        cout << "" << endl;
        cout << "    1) Register" << endl;
        cout << "    2) Login" << endl;
        cout << "    3) Exit Program" << endl;
        cout << "" << endl;

        cout << "Option: ";
        string option;
        cin >> option;

        // Register
        if (option == "1") {
            bool result = askRegister();
            if (result) {
                cout << "Success! Now please login with your credentials." << endl;
            }
            else {
                cout << "Failed! Something went wrong when attempting to register." << endl;
                cout << "Maybe the account already exists" << endl;
            }
        }

        // Login
        else if (option == "2") {
            Account a = askLogin();
            if (!a.success()) {
                cout << "Account not found / wrong credentials." << endl;
                continue;
            }
            accountOperations(a.getHash());
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

void accountOperations(string uuid) {
    while (true) {
        cout << "Transactions" << endl;
        cout << endl;
        cout << "    1) Show balance" << endl;
        cout << "    2) Show transaction history" << endl;
        cout << "    3) Withdraw" << endl;
        cout << "    4) Deposit" << endl;
        cout << "    5) Transfer" << endl;
        cout << "    6) Logout" << endl;
        cout << endl;

        cout << "Transaction option: ";
        string option;
        cin >> option;

        // Logout, early return
        if (option == "6") {
            return;
        }

        Account a(uuid);

        // Show balance, continue
        if (option == "1") {
            cout << "Balance: $" << a.getBalance() << endl;
            continue;
        }
        if (option == "2") {
            vector<string> hist = a.getTransactionHistory();
            for (string h : hist) {
                cout << h << endl;
            }
            continue;
        }
        
        double amount = scanDouble("Amount: ");
        if (amount <= 0) {
            cout << "Invalid input." << endl;;
            continue;
        }

        // Only if the amount is valid
        else if (option == "3") {
            WithdrawTransaction t(a, amount);
            bool result = t.execute();
            if (result) {
                cout << "Withdrew $" << amount << endl;
            }
            else {
                cout << "Invalid amount (amount > balance)" << endl;
            }
        }
        else if (option == "4") {
            DepositTransaction t(a, amount);
            bool result = t.execute();
            if (result) {
                cout << "Deposited $" << amount << endl;
            }
            else {
                cout << "Unable to deposit" << endl;
            }
        }
        else if (option == "5") {
            string receiverID;
            cout << "Receiver's ID: ";
            cin >> receiverID;

            Account dest(receiverID);
            if (!dest.success()) {
                cout << "Invalid ID" << endl;
                continue;
            }

            TransferTransaction t(a, dest, amount);
            bool result = t.execute();
            if (result) {

            }
            else {

            }

        }
        else {
            cout << "Invalid option" << endl;
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