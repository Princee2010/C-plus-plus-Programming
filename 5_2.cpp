#include <iostream>
using namespace std;
class Complex {
public:
    double real, imag;

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex add(Complex other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex subtract(Complex other) {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);

    Complex sum = c1.add(c2);
    Complex diff = c1.subtract(c2);

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();
    cout << endl
    << endl
    << "24DIT006_PRINCEE BHINGRADIYA" << endl
    << endl;

    return 0;
}