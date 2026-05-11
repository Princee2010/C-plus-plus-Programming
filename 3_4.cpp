#include <iostream>
using namespace std;

// Function template to find the maximum value in an array
template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function template to reverse the array
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}

// Function template to display the array elements
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example with integers
    int intArr[] = {3, 1, 4, 1, 5};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Integer array: ";
    displayArray(intArr, intSize);
    cout << "Max integer: " << findMax(intArr, intSize) << endl;
    reverseArray(intArr, intSize);
    cout << "Reversed integer array: ";
    displayArray(intArr, intSize);

    // Example with floating-point numbers
    double floatArr[] = {2.5, 3.1, 0.7, 4.8};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "\nFloating-point array: ";
    displayArray(floatArr, floatSize);
    cout << "Max float: " << findMax(floatArr, floatSize) << endl;
    reverseArray(floatArr, floatSize);
    cout << "Reversed floating-point array: ";
    displayArray(floatArr, floatSize);

    // Example with characters
    char charArr[] = {'a', 'z', 'e', 'r'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "\nCharacter array: ";
    displayArray(charArr, charSize);
    cout << "Max character: " << findMax(charArr, charSize) << endl;
    reverseArray(charArr, charSize);
    cout << "Reversed character array: ";
    displayArray(charArr, charSize);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;
    return 0;
}