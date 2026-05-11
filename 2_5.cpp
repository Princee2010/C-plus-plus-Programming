#include<iostream>
#include<cmath>
using namespace std;

// Define the loan class
class Loan {
private:
    int loanID;
    string applicant_name;
    float loan_amount;
    float interestRate;
    int loanTerm;

public:
    // Default constructor initializing members with default values
    Loan() : loanID(0), applicant_name("N/A"), loan_amount(0.0), interestRate(0.0), loanTerm(0) {}

    // Parameterized constructor to initialize loanID and input other details
    Loan(int id) {
        loanID = id;
        cout << "Enter Applicant's Name: ";
        cin.ignore(); // Ignore leftover newline character
        getline(cin, applicant_name);
        cout << "Enter loan amount: ";
        cin >> loan_amount;
        cout << "Enter Interest Rate (Annual %): ";
        cin >> interestRate;
        cout << "Enter loan tenure (in months): ";
        cin >> loanTerm;
    }
    
    // Function to calculate EMI using the corrected formula
    float calculateEMI() {
        float monthlyRate = interestRate / 100 / 12;
        float a = loan_amount * monthlyRate * pow(1 + monthlyRate, loanTerm);
        float b = pow(1 + monthlyRate, loanTerm) - 1;
        return a / b;
    }

    // Function to display loan details and EMI
    void displayLoanDetails() {
        cout << "-------------------------------------" << endl;
        cout << "Loan Details for Loan ID No. " << loanID << endl;
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicant_name << endl;
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Loan Term: " << loanTerm << " months" << endl;
        cout << "EMI per month: " << calculateEMI() << endl;
        cout << "--------------------------------------" << endl;
    }
};

int main() {
    Loan l1; // Create loan object using default constructor
    l1.displayLoanDetails(); // Display default loan details

    Loan l2(20); // Create loan object with ID = 20 using parameterized constructor
    l2.displayLoanDetails(); // Display entered loan details and EMI

    cout << endl << "24DIT006 PRINCEE_BHINGRADIYA" << endl;
    
    return 0;
}