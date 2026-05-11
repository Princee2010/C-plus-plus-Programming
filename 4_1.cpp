#include <iostream>
#include <vector>
using namespace std;

// Base class representing a generic shape
class Shape
{
protected:
    double radius;

public:
    // Constructor to initialize radius
    Shape(double r) : radius(r){}

    // Access radius
    double getRadius() const
    {
        return radius;
    }

    // Virtual function for calculating area
    virtual double calculateArea() const
    {
        return 0.0;
    }
};

// Derived class representing a circle
class Circle : public Shape
{
public:
    // Constructor to initialize radius using base class constructo
    Circle(double r) : Shape(r){}

    // Overloading the calculateArea function to compute the area of a circle
    double calculateArea() const
    {
        return 3.14159 * radius * radius;
    }
};

// Function to display the areas of multiple circles
void displayAreas(const vector<Circle> &circle)
{
    for (int i = 0; i < circle.size(); i++)
    {
        cout << "Circle " << i + 1 << " Radius : " << circle[i].getRadius()<< " Area ::" << circle[i].calculateArea() << endl;
    }
}

int main()
{
    // Creating a collection vector of circle dynamically
    vector<Circle> circle;

    // Adding circle with different radius ro the collection
    circle.push_back(Circle(3.5));
    circle.push_back(Circle(5.5));

    // Displaying the areas of the circles
    displayAreas(circle);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;
    return 0;
}