// File: encapsulation.cpp

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    // Constructor
    BankAccount(string accOwner, double initialBalance) {
        owner = accOwner;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Initial balance can't be negative. Set to 0." << endl;
        }
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Getter for owner
    string getOwner() {
        return owner;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs. " << amount << " successfully." << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs. " << amount << " successfully." << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance!" << endl;
        }
    }
};

int main() {
    BankAccount rajeevAccount("Rajeev", 10000);

    cout << "Account Owner: " << rajeevAccount.getOwner() << endl;
    cout << "Initial Balance: Rs. " << rajeevAccount.getBalance() << endl;

    rajeevAccount.deposit(5000);
    cout << "Current Balance: Rs. " << rajeevAccount.getBalance() << endl;

    rajeevAccount.withdraw(3000);
    cout << "Remaining Balance: Rs. " << rajeevAccount.getBalance() << endl;

    // Try accessing private fields directly (uncomment to see error)
    // cout << rajeevAccount.balance << endl; // ❌ This will throw a compile error

    return 0;
}
