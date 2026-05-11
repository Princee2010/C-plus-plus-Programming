#include <iostream>
#include <vector>

using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator for addition
    Complex operator+(const Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload - operator for subtraction
    Complex operator-(const Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

};

// STL Approach using std::vector
void complex()
{
    vector<Complex> complexNumbers;
    Complex c1(2, 3);
    Complex c2(4, -1);
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    complexNumbers.push_back(c1);
    complexNumbers.push_back(c2);
    complexNumbers.push_back(sum);
    complexNumbers.push_back(diff);

   
    for (const auto &c : complexNumbers)
    {
        cout << c << endl;
    }
}


int main()
{
    complex();
   
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}