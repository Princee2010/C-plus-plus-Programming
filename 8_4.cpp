#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int score;
};

// Custom comparison function for sorting students in descending order
bool compareStudents(const Student& a, const Student& b) {
    return a.score > b.score; // Higher scores come first
}

void displayRankedStudents(const vector<Student>& students) {
    cout << left << setw(5) << "Rank" 
              << setw(20) << "Name" 
              << setw(10) << "Score" << "\n";
    cout << "--------------------------------------\n";

    int rank = 1;
    for (const auto& student : students) {
        cout << left <<setw(5) << rank++
                  << setw(20) << student.name
                  << setw(10) << student.score << "\n";
    }
}

int main() {
    vector<Student> students;
    int n;
    
    cout << "Enter the number of students: ";
    cin >> n;

    // Input student data
    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "Enter name and score for student " << i + 1 << ": ";
        cin >> s.name >> s.score;
        students.push_back(s);
    }

    // Sorting students based on scores (descending order)
    sort(students.begin(), students.end(), compareStudents);

    cout << "\nRanked List of Students:\n";
    displayRankedStudents(students);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}