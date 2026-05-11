#include <iostream>
#include <vector>
#include <algorithm>  // For reverse
#include <iterator>   // For iterators

using namespace std;

// Function to reverse using std::reverse()
void reverseWithSTL(vector<int>& nums) {
    reverse(nums.begin(), nums.end());
}

// Function to reverse manually using iterators
void reverseWithIterators(vector<int>& nums) {
    auto start = nums.begin();
    auto end = nums.end() - 1;
    while (start < end) {
        swap(*start, *end);
        ++start;
        --end;
    }
}

void displaySequence(const vector<int>& nums) {
    for (const int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers;
    int n, value;

    // User input
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter the sequence of numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

    cout << "\nOriginal Sequence: ";
    displaySequence(numbers);

    // Using reverse()
    reverseWithSTL(numbers);
    cout << "Reversed using reverse(): ";
    displaySequence(numbers);

    // Restore original order and reverse using iterators
    reverseWithSTL(numbers); // Undo previous reversal
    reverseWithIterators(numbers);
    cout << "Reversed using iterators: ";
    displaySequence(numbers);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}