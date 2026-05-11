// #include <iostream>
// #include <queue>
// #include <string>
// using namespace std;

// // Base class for fuel type
// class Fuel
// {
// protected:
//     string FuelType;

// public:
//     Fuel(string type) : FuelType(type) {}
//     void DisplayFuel()
//     {
//         cout << "Fuel Type : " << FuelType << endl;
//     }
// };

// // Base class for Brand
// class Brand
// {
// protected:
//     string BrandName;

// public:
//     Brand(string brand) : BrandName(brand) {}
//     void DisplayBrand()
//     {
//         cout << "Brand : " << BrandName << endl;
//     }
// };

// // Derived class combining fuel and brand
// class Car : public Fuel, public Brand
// {
// public:
//     Car(string type, string Brand) : Fuel(type), Brand(name) {}

//     void DisplayInfo()
//     {
//         DisplayFuel();
//         DisplayBrand();
//     }
// };

// int main()
// {
//     // Create a queue to simulate service line
//     queue<Car> C;

//     // Create car object and add them to the queue
//     Car car1("Petrol", "Toyota");
//     Car car2("Diesel", "Ford");
//     Car car3("Electric", "Tesla");

//     C.push(car1);
//     C.push(car2);
//     C.push(car3);

//     // Process each car in the queue

//     int Number = 1;
//     while (!C.empty())
//     {
//         cout << "Car : " << Number << "Details : ";
//         C.front().DisplayInfo();
//         C.pop();
//         Number++;
//     }
//     return 0;
// }
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Base class for fuel type
class Fuel {
protected:
    string FuelType;

public:
    Fuel(string type) : FuelType(type) {}
    void DisplayFuel() {
        cout << "Fuel Type: " << FuelType << endl;
    }
};

// Base class for Brand
class Brand {
protected:
    string BrandName;

public:
    Brand(string name) : BrandName(name) {}
    void DisplayBrand() {
        cout << "Brand: " << BrandName << endl;
    }
};

// Derived class combining fuel and brand
class Car : public Fuel, public Brand {
public:
    Car(string type, string name) : Fuel(type), Brand(name) {}

    void DisplayInfo() {
        DisplayFuel();
        DisplayBrand();
    }
};

int main() {
    // Create a queue to simulate service line
    queue<Car> C;

    // Create car objects and add them to the queue
    Car car1("Petrol", "Toyota");
    Car car2("Diesel", "KIA");
    Car car3("Electric", "Tesla");

    C.push(car1);
    C.push(car2);
    C.push(car3);

    // Process each car in the queue
    int Number = 1;
    while (!C.empty()) {
        cout << "Car " << Number << " Details::::::\n";
        C.front().DisplayInfo();
        C.pop();
        Number++;
    }
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;
    return 0;
}