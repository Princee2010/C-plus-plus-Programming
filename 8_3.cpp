#include <iostream>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

void processTransactions(const vector<int>& transactions) {
    set<int> uniqueTransactions(transactions.begin(), transactions.end()); // Automatically filters duplicates

    // Display unique transaction IDs
    cout << "Unique Transaction IDs (Sorted):\n";
    for (const int id : uniqueTransactions) {
        cout << id << " ";
    }
    cout << endl;
}

int main() {
    vector<int> transactionIDs;
    int n, id;

    // User input
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    cout << "Enter transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> id;
        transactionIDs.push_back(id);
    }

    processTransactions(transactionIDs);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}