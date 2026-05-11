#include <iostream>
#include <limits>

using namespace std;

void calculateLoanIncomeRatio() {
    double loanAmount, annualIncome;
    
    // Input loan amount
    while (true) {
        cout << "Enter the total loan amount: ";
        cin >> loanAmount;
        
        if (cin.fail() || loanAmount < 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a valid positive number.\n";
        } else {
            break;
        }
    }

    // Input annual income
    while (true) {
        cout << "Enter your annual income: ";
        cin >> annualIncome;
        
        if (cin.fail() || annualIncome <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            if (annualIncome == 0) {
                cout << "Error: Annual income cannot be zero! Please enter a valid positive number.\n";
            } else {
                cout << "Invalid input! Please enter a valid positive number.\n";
            }
        } else {
            break;
        }
    }

    // Calculate and display the loan-to-income ratio
    double ratio = loanAmount / annualIncome;
    cout << "Loan-to-Income Ratio: " << ratio << endl;
}

int main() {
    calculateLoanIncomeRatio();

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}