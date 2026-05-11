#include <iostream>
using namespace std;

// Define a class named Student
class Student
{
private:
    int rollNumber;
    string nameOfStudent;
    double marks[10] = {0};

public:
    // Default constructer initializing rollnumber and name
    Student()
    {
        rollNumber = 0;
        nameOfStudent = "N/A";
    }
    // Parameterizedd constructer to initialize all data members
    Student(int rollNum, string name, int numOfstudent, double marksOfstudent[])
    {
        rollNumber = rollNum;
        nameOfStudent = name;
        for (int i = 0; i < numOfstudent; i++)
        {
            marks[i] = marksOfstudent[i]; // Copy marks to class array
        }
    }
    // Function to display student detials including marks and avarage
    void displayDetials(int noOFsub)
    {
        cout << "Name :" << nameOfStudent
             << endl;
        cout << "Roll Number :" << rollNumber
             << endl;
        for (int i = 0; i < noOFsub; i++)
        {
            cout << "Marks of Subject " << i + 1 << ":" << marks[i] << endl;
        }
        cout << "Avrage marks is : " << calculateAverage(noOFsub) << endl;
    }
    // Function tp calculate and return the average marks
    double calculateAverage(int numOfsub)
    {
        double avg = 0, sum = 0;
        for (int i = 0; i < numOfsub; i++)
        {
            sum = sum + marks[i]; // Sum of marks
        }
        avg = sum / numOfsub; // Calculate average
        return avg;
    }
};
int main()
{
    Student s1; // Create student object s1 using default constructor
    cout << endl;

    int rollNumber, numOfSub;
    string name;

    // Take user input for student detials
    cout << "Enter Name Student :";
    cin >> name;
    cout << "Enter Roll Number :";
    cin >> rollNumber;
    cout << "Enter Number of Subject :";
    cin >> numOfSub;

    double marks[numOfSub]; // Array to hold marks

    // Input marks for each sub
    for (int i = 0; i < numOfSub; i++)
    {
        cout << "Enter marks of subject " << i + 1 << ":";
        cin >> marks[i];
    }

    // Display default object detials (default values)
    s1.displayDetials(numOfSub);
    cout<<endl
        <<endl;
    
    //Create student object s2 using parameterized constructor

    Student s2(rollNumber, name, numOfSub, marks);
    
    //Display actual student detials with provided data
    s2.displayDetials(numOfSub);
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

}
