#include<iostream>
using namespace std;

//Deafult BankAccount class
class BankAccount
{
    public:
    string nameOfAccHolder ;
    string accountNum ;
    double Balance ;
    //Default constructor to initialize Balance to 0
    BankAccount()
    {
        Balance = 0;
    }
    //Parameterized constructor to initialized object with given data
    BankAccount(string name , string AccNum , double AccBalance) 
    {
        nameOfAccHolder = name;
        accountNum = AccNum;
        Balance = AccBalance;
    }

    //Function to deposite money into account 
    void Deposite (double Amounnt)
    {
        Balance += Amounnt;
        cout<<"Transaction is successfully done!!"<<endl;
    }

    //Function to Withdraw money from accounnt with Balance check
    void Withdraw (double Amount)
    {
        if (Amount <= Balance)
        {
            Balance -= Amount;
            cout<<"There are not sufficient amount in your bank account !!"<<endl;
        }
        else
        {
            cout<<"There are not sufficient amount in your bank account !! "<<endl;
        }
    }
    //Function to display account detials
    void SeeDetials()
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"Account Holder Name :"<<nameOfAccHolder<<endl;
        cout<<"Account Number :"<<accountNum<<endl;
        cout<<"Balance :"<<Balance<<endl;
        cout<<"---------------------------------------"<<endl;
    }
    void CurrentBalance()
    {
        cout<<"Balance :"<<Balance<<endl;
    }
};  
int main()
{
    string name; //Character array to store account holder name 
    double AccBalance; //Variable to holder balance
    string accNo; //Variable to hold account number
    double Amount;
    //Create an object acc1 using default constructor
    BankAccount acc1;
    acc1.nameOfAccHolder = "Princee Bhingradiya"; // Set details manualy
    acc1.accountNum = "259874631";
    acc1.Balance = 25000;
    acc1.SeeDetials(); // Show account details
    cout<<"How much money you want deposite :";
    cin>>Amount;
    acc1.Deposite(Amount); //Deposite money
    acc1.CurrentBalance();
    cout<<"How much money you want Withdraw :";
    cin>>Amount;
    acc1.Withdraw(Amount);
    acc1.CurrentBalance(); // Withdraw money 
    cout<<endl;

    //Take user input for a second account 
    cout<<endl
        <<"-------------Second Account Holder ------------ "
    <<endl;
    cout<<"Enter Account Holder's Name :";
    cin>>name;
    cout<<endl;
    cout<<"Enter Account Number :";
    cin>>accNo;
    cout<<endl;
    cout<<"Enter Balance :";
    cin>>AccBalance;
    cout<<endl;

    //Create an object acc2 using parameterized constructor 
    BankAccount acc2(name , accNo , AccBalance);
    acc2.SeeDetials(); // Show account details
    cout<<"How much money you want deposite :";
    cin>>Amount;
    acc2.Deposite(Amount); //Deposite money
    acc2.CurrentBalance();
    cout<<"How much money you want Withdraw :";
    cin>>Amount;
    acc2.Withdraw(Amount); // Withdraw money
    acc2.CurrentBalance();

    cout<<endl;
    cout<<" 24DIT006  Princee_Bhingradiya"<<endl;

    return 0;
}