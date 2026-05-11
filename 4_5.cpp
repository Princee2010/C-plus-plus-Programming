#include <iostream>
#include <vector>
using namespace std;

// Abstract base class
class Student
{
protected:
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    // Pure virtual function
    virtual string computeGrade() = 0;

    // Virtual function to display
    virtual void display()
    {
        cout << "Name: " << name << "\nMarks: " << marks << "\nGrade: " << computeGrade() << "\n";
        cout << "---------------------------\n";
    }

    virtual ~Student() {}
};
class Undergraduate : public Student
{
public:
    Undergraduate(string n, int m) : Student(n, m) {}

    string computeGrade() override
    {
        if (marks >= 70)
            return "A";
        else if (marks >= 60)
            return "B";
        else if (marks >= 50)
            return "C";
        else
            return "F";
    }
};

class Postgraduate : public Student
{
public:
    Postgraduate(string n, int m) : Student(n, m) {}

    string computeGrade() override
    {
        if (marks >= 80)
            return "A";
        else if (marks >= 70)
            return "B";
        else if (marks >= 60)
            return "C";
        else
            return "F";
    }
};

int main()
{
    vector<Student *> students;

    // Input data
    students.push_back(new Undergraduate("Radhe", 75));
    students.push_back(new Undergraduate("Yash", 48));
    students.push_back(new Postgraduate("Krishna", 72));
    students.push_back(new Postgraduate("Princee", 61));

    // Display all student records
    cout << "\n--- Student Records ---\n";
    for (Student *s : students)
    {
        s->display();
    }
    for (Student *s : students)
    {
        delete s;
    }
    cout << endl
         << endl
         << "24DIT006_PRINCEE BHINGRADIYA" << endl
         << endl;
    return 0;
}
