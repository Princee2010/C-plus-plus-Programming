#include <iostream>
#include <vector>

using namespace std;

// Recursive function to calculate the sum of the array
int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0) {
        return 0; // Base case: empty array
    }
    return arr[n - 1] + recursiveSum(arr, n - 1); // Recursive case
}

// Non-recursive function to calculate the sum of the array
int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Calculate the sum using recursive approach
    int sumRecursive = recursiveSum(arr, size);

    // Calculate the sum using non-recursive approach
    int sumIterative = iterativeSum(arr);

    // Display results
    cout << "Sum using recursive approach: " << sumRecursive << endl;
    cout << "Sum using non-recursive approach: " << sumIterative << endl;

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}