#include <iostream>
using namespace std;


class DynamicArray
{
private:
    int *data;       // Pointer to dynamically allocated array
    size_t size;     // Current number of elements
    size_t capacity; // Total allocated memory

    void resize()
    {
        capacity *= 2; // Double the capacity
        int *newData = new int[capacity];

        // Copy existing elements
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data; // Free old memory
        data = newData;
    }

public:
    DynamicArray(size_t cap = 2) : size(0), capacity(cap)
    {
        data = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] data; // Clean up memory
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = value;
    }

    void remove(size_t index)
    {
        if (index >= size)
        {
            cerr << "Invalid index!\n";
            return;
        }

        for (size_t i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    void print()
    {
        if (size == 0)
        {
            cout << "Array is empty.\n";
            return;
        }

        for (size_t i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    DynamicArray arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.print(); // Output: 10 20 30 40

    arr.remove(2);
    arr.print(); // Output: 10 20 40

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}