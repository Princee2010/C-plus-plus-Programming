#include <iostream>
#include <vector>

using namespace std;

class BankAccount
{
private:
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(double initialBalance) : balance(initialBalance)
    {
        transactionHistory.push_back("Account created with balance: " + to_string(balance));
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            transactionHistory.push_back("Deposited: " + to_string(amount));
            cout << "Deposit successful. Balance: " << balance << endl;
        }
        else
        {
            transactionHistory.push_back("Deposit failed: Invalid amount.");
            cout << "Error: Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: " + to_string(amount));
            cout << "Withdrawal successful. Balance: " << balance << endl;
        }
        else
        {
            transactionHistory.push_back("Withdrawal failed: Insufficient funds.");
            cout << "Error: Insufficient funds.\n";
        }
    }

    void displayTransactionLog() const
    {
        cout << "\nTransaction History:\n";
        for (const auto &record : transactionHistory)
        {
            cout << record << endl;
        }
    }
};

int main()
{
    BankAccount account(1000); // Initial balance
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(2000); // Should fail due to insufficient funds
    account.displayTransactionLog();

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}