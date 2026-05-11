#include <iostream>

using namespace std;

// Base Class
class person
{
protected:
    string name;
    int age;

public:
    // Constructor for print name and age
    person(string n, int a)
    {
        name = n;
        age = a;
    }

    void DisplayPerson()
    {
        cout << "Employee Name is :" << name << endl;
        cout << "Employee age is :" << age << endl;
    }
};

// Intermediate Class
class Employee : public person
{
protected:
    string ID;
public:
    Employee(string n, int a, string id) : person(n, a)
    {
        ID = id;
    }
    void DisplayID()
    {
        DisplayPerson();
        cout << "Employee ID : " << ID << endl;
    }
};

// Derived class
class Manager : public Employee
{
protected:
    string Department;

public:
    Manager(string n, int a, string id, string d) : Employee(n, a, id)
    {
        Department = d;
    }

    void DisplayDepartment()
    {
        DisplayID();
        cout << "Employee Department :" << Department << endl;
    }
};

int main()
{
    Manager m1("princee_bhingradiya", 18, "24DIT006", "INFORMATION TECHNOLOGY");
    m1.DisplayDepartment();

    cout << endl
         << endl
         << "24DIT006_PRINCEE BHINGRADIYA" << endl
         << endl;

    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Intermediate Class
class Employee : public Person {
protected:
    string employeeID;

public:
    Employee(string n, int a, string id) : Person(n, a) {
        employeeID = id;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Derived Class
class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, string id, string dept)
        : Employee(n, a, id) {
        department = dept;
    }

    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

// Main function
int main() {
    Manager m1("princee_bhingradiya", 18, "24DIT006", "INFORMATION TECHNOLOGY");
    m1.displayManager();

    return 0;
}
*/