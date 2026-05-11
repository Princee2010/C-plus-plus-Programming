/*#include <iostream>
#include <vector>

using namespace std;

vector<Undo>v;

class BankAccount
{
private:
    string Acc_No;
    
    double Balance;
    

public:
    BankAccount(string AN, double Bal)
    {
        Acc_No = AN;
        Balance = Bal;
    }

    void Withdraw(int Amount)
    {
        if (Balance > Amount)
        {
            Balance -= Amount;
            v.push_back(Withdraw,Amount);
        }
        else
        {
            cout << "Enter a valid Number.." << endl;
        }
    }

    void deposite(int Amount)
    {
        Balance += Amount;
        v.push_back(deposite,Amount);
    }

    void Display_Balance()
    {
        cout << "Current Balance:" << Balance << endl;
    }
};

class Undo 
{
    string Type , v;
    double Amount;
    

};
int main()
{

    vector<Undo>v;


    return 0;
}*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Account Class
class Account {
protected:
    int accountNumber;
    double balance;
    vector<string> transactions;

public:
    Account(int accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual ~Account() {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back("Deposit: " + to_string(amount));
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back("Withdraw: " + to_string(amount));
        } else {
            cout << "Not enough balance!" << endl;
        }
    }

    void printBalance() {
        cout << "Account No: " << accountNumber << ", Balance: " << balance << endl;
    }

    void showHistory() {
        cout << "Transactions for Account No: " << accountNumber << endl;
        for (const auto& t : transactions) {
            cout << t << endl;
        }
    }
};

// Savings Account
class Savings : public Account {
    double interestRate;

public:
    Savings(int accNum, double initialBalance, double rate)
        : Account(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        transactions.push_back("Interest Applied: " + to_string(interest));
    }
};

// Current Account
class Current : public Account {
    double overdraftLimit;

public:
    Current(int accNum, double initialBalance, double limit)
        : Account(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            transactions.push_back("Withdraw: " + to_string(amount));
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

// Main Function
int main() {
    Savings sAcc(101, 5000, 5); // Account No: 101, Initial Balance: 5000, Interest: 5%
    sAcc.deposit(1000);
    sAcc.withdraw(2000);
    sAcc.applyInterest();
    sAcc.printBalance();
    sAcc.showHistory();

    cout << endl;

    Current cAcc(102, 3000, 1000); // Account No: 102, Initial Balance: 3000, Overdraft: 1000
    cAcc.deposit(500);
    cAcc.withdraw(3500);
    cAcc.withdraw(5000); // Exceeds overdraft
    cAcc.printBalance();
    cAcc.showHistory();
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}