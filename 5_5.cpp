#include <iostream>
#include <vector>

using namespace std;
// Base class
class Shape {
public:
    virtual double Area() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override {
        return length * width;
    }
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {

    // Dynamically managed collection
    vector<Shape*> shapes; 
    int r,a,b;
    cout<<"Enter Radius: ";
    cin>>r;
    cout<<"Enter Rectangle length and width: ";
    cin>>a>>b;

    shapes.push_back(new Circle(r));
    shapes.push_back(new Rectangle(a, b));

    for (const auto& shape : shapes) {
        cout << "Area : " << shape->Area() << endl;
    }

    // Cleanup memory
    for (auto shape : shapes) {
        delete shape;
    }

    cout << endl
         << endl
         << "24DIT006_PRINCEE BHINGRADIYA" << endl
         << endl;

    return 0;
}