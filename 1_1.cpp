// practical :: 1.1
// Program of simple class Bank Account to represent a bank account

#include <iostream>
using namespace std;

// Creating a Class named Bank Account

class BankAccount
{
    // Declaring private data member +
private:
    string Account_Holder_Name;
    int Account_Number;
    int Balance;

public:
    // Declaring and defining public method and constructor
    void SetData()
    {
        cout << endl
             << "Enter Your Bank Detials::::::::::::";
        cout << endl
             << "Enter The Account Holder Name::";
        cin >> Account_Holder_Name;
        cout << endl
             << "Enter The Account Number::";
        cin >> Account_Number;
        cout << endl
             << "Enter The Account Balance::";
        cin >> Balance;
    }

    // Method to add money to the account

    void Deposite(int Money)
    {
        Balance = Balance + Money;
    }

    // Method to withdraw money from the account

    void Withdraw(int Amount)
    {
        if (Amount > Balance) /// Checking for sufficient balance exist or not
        {
            cout << "Error! there is no sufficient money!!";
        }
        else
        {
            Balance = Balance - Amount;
        }
    }

    // method to show the current balance

    void Display_Balance()
    {
        cout << "Current Balance:" << Balance << endl;
    }
};

int main()
{
    BankAccount A1;
    int Money, Amount;

    A1.SetData();
    cout << endl
         << "Enter the Amount which is to be Deposited :";
    cin >> Money;

    A1.Deposite(Money);
    A1.Display_Balance();

    cout << endl
         << "Enter the Amount you want to Withdraw : :";
    cin >> Amount;

    A1.Withdraw(Amount);
    A1.Display_Balance();

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}
