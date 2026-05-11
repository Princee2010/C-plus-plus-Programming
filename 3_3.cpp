#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Account class
class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Static variable to track total accounts
    static int totalAccounts;

    // Constructor
    Account(int number, string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {
        totalAccounts++;
    }

    // Destructor
    ~Account() {} 

    // Get account details
    void displayDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Transfer money to another account
    bool transfer(Account &toAccount, double amount) {
        if (balance >= amount && amount > 0) {
            balance -= amount;
            toAccount.balance += amount;
            return true;
        }
        return false;
    }

    // Get balance
    double getBalance() const {
        return balance;
    }

    // Static function to get total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Initialize static variable
int Account::totalAccounts = 0;

int main() {
    // Vector to dynamically store accounts
    vector<Account> accounts;

    // Create accounts
    accounts.push_back(Account(1001, "Radhe", 15000.00));
    accounts.push_back(Account(1002, "Krishna", 13000.00));
    accounts.push_back(Account(1003, "Princee", 7000.00));

    // Display account details
    cout << "Account Details:\n";
    for (int i = 0; i< accounts.size();i++) {
        accounts[i].displayDetails();
        cout << "--------------------\n";
    }
    // Perform a money transfer
    cout << "\nTransferring money...\n";
    if (accounts[0].transfer(accounts[1], 3000.00)) {
        cout << "Transfer successful.\n";
    } else {
        cout << "Transfer failed due to insufficient balance.\n";
    }

    // Display updated balances
    cout << "\nUpdated Account Balances:\n";
    for (int i =0 ; i <accounts.size();i++) {
        accounts[i].displayDetails();
        cout << "--------------------\n";
    }

    // Total accounts
    cout << "\nTotal Accounts: " << Account::getTotalAccounts() << endl;

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}