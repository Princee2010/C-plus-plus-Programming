#include <iostream>
using namespace std;

// Define a class named Rectangle
class Rectangle
{
private:
    // Private data member to store length and width of Rectangle
    int L;
    int W;

public:
    // Public member function to input dimension of the rectangle
    void setDimensions()
    {
        cout << "Enter Rectangle L:";
        cin >> L; // Take input for length

        cout << "Enter Rectangle W:";
        cin >> W; // Take input for width
    }
    // Public member function to calculate area of the rectangle
    int Area()
    {
        int A = L * W;
        return A;
    }
    // Public member function to calculate perimeter of the rectangle
    int Perimeter()
    {
        int p = 2 * (L + W);
        return p;
    }
};
int main()
{
    Rectangle h, v;    // create an object h, v of class Rectangle
    h.setDimensions(); // Call function to input length and width

    int AA = h.Area(); // Output of area
    cout << "Area :" << AA << endl;

    int PP = h.Perimeter(); // Output of perimeter
    cout << "Perimeter :" << PP << endl;

    v.setDimensions(); // Call function to input length and width

    int BB = v.Area(); // Output of area
    cout << "Area :" << BB << endl;

    int CC = v.Perimeter(); // Output of perimeter
    cout << "Perimeter :" << CC << endl;

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}