#include <iostream>
#include <queue>

using namespace std;
class Fahrenheit; // Forward declaration

class Celsius {
    double value;

public:
     Celsius(double v) : value(v) {}

    operator Fahrenheit(); // Conversion operator

    bool operator==(const Celsius& p) const {
        return value == p.value;
    }

    double getValue() const { return value; }
};

class Fahrenheit {
    double value;

public:
     Fahrenheit(double v) : value(v) {}

    operator Celsius(); // Conversion operator

    bool operator==(const Fahrenheit& p) const {
        return value == p.value;
    }

    double getValue() const { return value; }
};

// Definition for conversion from Celsius to Fahrenheit
Celsius::operator Fahrenheit() {
    return Fahrenheit((value * 9.0 / 5.0) + 32);
}

// Definition for conversion from Fahrenheit to Celsius
Fahrenheit::operator Celsius() {
    return Celsius((value - 32) * 5.0 / 9.0);
}

int main() {
    // Example objects
    Celsius c1(30.0);          // 25 degrees Celsius
    Fahrenheit f1(86.0);       // 77 degrees Fahrenheit

    // Demonstrating conversions
    Fahrenheit f2 = c1;        // Celsius to Fahrenheit
    Celsius c2 = f1;           // Fahrenheit to Celsius

    cout << "Celsius: " << c1.getValue() << " -> Fahrenheit: " << f2.getValue() << '\n';
    cout << "Fahrenheit: " << f1.getValue() << " -> Celsius: " << c2.getValue() << '\n';

    // Overloading == operator
    if (c1 == c2) {
        cout << "Celsius and Fahrenheit objects are equal after conversion.\n";
    } else {
        cout << "Celsius and Fahrenheit objects are not equal after conversion.\n";
    }

    queue<Fahrenheit> fahrenQueue;
    queue<Celsius> celsiusQueue;

    fahrenQueue.push(f2);
    celsiusQueue.push(c2);

    cout << " Celsius :" << celsiusQueue.front().getValue() << '\n';
    cout << " Fahrenheit :" << fahrenQueue.front().getValue() << '\n';

    cout << endl
         << endl
         << "24DIT006_PRINCEE BHINGRADIYA" << endl
         << endl;

    return 0;
}