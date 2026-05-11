#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;


struct Student {
    string name;
    int marks;
    char grade;
};

ostream& tableFormat(ostream& os) {
    os << left << setw(20);
    return os;
}

void readFileWithSTL(const string& filename, vector<Student>& students) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!\n";
        return;
    }
    string name;
    int marks;
    char grade;
    while (file >> name >> marks >> grade) {
        students.push_back({name, marks, grade});
    }
}

void displayStudents(const vector<Student>& students) {
    cout << tableFormat << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << "\n";
    cout << "------------------------------------------\n";
    for (const auto& student : students) {
        cout << tableFormat << student.name << setw(10) << student.marks << setw(10) << student.grade << "\n";
    }
}

int main() {
    vector<Student> students;
    readFileWithSTL("sample.txt", students);
    displayStudents(students);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}