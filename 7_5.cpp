#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

struct Student
{
    string name;
    int marks;
    double tuitionFee;
};

ostream &currency(ostream &os)
{
    return os << "₹"; // You can replace "₹" with "$" or any currency symbol as needed.
}

void readStudentData(const string &filename, vector<Student> &students)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file!\n";
        return;
    }
    string name;
    int marks;
    double tuitionFee;

    while (file >> name >> marks >> tuitionFee)
    {
        students.push_back({name, marks, tuitionFee});
    }
}

void displayStudentData(const vector<Student> &students)
{
    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << "\n";
    cout << setfill('-') << setw(45) << "" << setfill(' ') << "\n";

    for (const auto &student : students)
    {
        cout << left << setw(20) << student.name
             << setw(10) << student.marks
             << currency << fixed << setprecision(2) << setw(15) << student.tuitionFee << "\n";
    }
}

int main()
{
    vector<Student> students;
    readStudentData("sample.txt", students);
    displayStudentData(students);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}