#include <iostream>
#include <vector>

using namespace std;

class Employee
{
private:
    string employee_name;
    int basic_salary;
    int bonus;

public:
    Employee(string name, int bsalary, int bonus = 500)
    {
        employee_name = name;
        basic_salary = bsalary;
        this->bonus = bonus; // Fixing scope issue
    }

    inline float salary()
    {
        return basic_salary + bonus; // Simplified logic
    }

    void display()
    {
        cout << "Employee name: " << employee_name << endl;
        cout << "Basic salary: " << basic_salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total salary: " << salary() << endl;
    }
};

int main()
{
    vector<Employee> a;
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore(); // Prevent empty getline input

    for (int i = 0; i < n; i++)
    {
        string employee_name;
        cout << "Enter the Employee name: ";
        getline(cin, employee_name); // Corrected input handling

        int basic_salary;
        cout << "Enter the Basic salary: ";
        cin >> basic_salary;

        int bonus;
        cout << "Enter the Bonus: ";
        cin >> bonus;
        cin.ignore(); // Prevent input issues for next iteration

        a.push_back(Employee(employee_name, basic_salary, bonus));
    }

    // Display all employees AFTER input collection is complete
    cout << "\nEmployee Details:\n";
    for (int i = 0; i < a.size(); i++)
    {
        a[i].display();
    }
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}