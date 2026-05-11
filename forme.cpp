
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename t>
void disp(const vector<t> v1)
{
    for(auto& i:v1)
    {
        cout<<i<<" ";
    }
}
template<typename t>
t max(const vector<t> v1)
{
    return *max_element(v1.begin(),v1.end());
}
template<typename t>
void rev(vector<t> &v1)
{
    reverse(v1.begin(),v1.end());
}

int main()
{
    int n;
    cout<<"Number of element:"; cin>>n;

    vector<int,char> v;
    for(int i=0;i<n;i++)
    {
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    disp(v);
    cout <<endl<<"Maximum element:"<< max(v);
    rev(v);
    cout<<"\nReverse of vector:";
    disp(v);
    return 0 ;

}

// practical 3.2

#include <iostream>
#include <vector>

// Recursive function to calculate sum of array elements
int recursiveSum(const std::vector<int>& arr, int index) {
    if (index < 0) return 0;
    return arr[index] + recursiveSum(arr, index - 1);
}

// Non-recursive (iterative) function to calculate sum
int iterativeSum(const std::vector<int>& arr) {
    int sum = 0;
    for (int val : arr) {
        sum += val;
    }
    return sum;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int sumRec = recursiveSum(arr, size - 1);
    int sumIter = iterativeSum(arr);

    std::cout << "\nSum using recursion: " << sumRec;
    std::cout << "\nSum using iteration: " << sumIter << std::endl;

    return 0;
}


// practical 5.1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Calculator
{
private:
    vector<string> results; // Store results as strings for display

public:
    // Overloaded add functions
    int add(int a, int b)
    {
        int result = a + b;
        storeResult(a, b, result);
        return result;
    }

    float add(float a, float b)
    {
        float result = a + b;
        storeResult(a, b, result);
        return result;
    }

    double add(double a, int b)
    {
        double result = a + b;
        storeResult(a, b, result);
        return result;
    }

    double add(int a, double b)
    {
        double result = a + b;
        storeResult(a, b, result);
        return result;
    }

    // Function to store results as strings
    template <typename T1, typename T2, typename T3>
    void storeResult(T1 a, T2 b, T3 result)
    {
        results.push_back("Add(" + to_string(a) + ", " + to_string(b) + ") = " + to_string(result));
    }

    // Display all results
    void displayResults()
    {
        cout << "\nStored Calculation Results:\n";
        for (const auto &r : results)
        {
            cout << r << endl;
        }
    }
};

int main()
{
    Calculator calc;

    // Test various overloaded add functions
    calc.add(5, 10);      // int + int
    calc.add(2.5f, 4.3f); // float + float
    calc.add(3.14, 2);    // double + int
    calc.add(7, 3.5);     // int + double

    // Display stored results
    calc.displayResults();

    return 0;
}


//Practical 3.3
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    static int nextAccountNumber;
    static int totalAccounts;

    int accountNumber;
    string holderName;
    double balance;

public:
    Account(string name, double initialBalance) {
        accountNumber = ++nextAccountNumber;
        holderName = name;
        balance = initialBalance;
        totalAccounts++;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return holderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    bool transferTo(Account &other, double amount) {
        if (withdraw(amount)) {
            other.deposit(amount);
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Account Number: " << accountNumber
             << ", Name: " << holderName
             << ", Balance: $" << balance << endl;
    }
};

// Initialize static variables
int Account::nextAccountNumber = 1000;
int Account::totalAccounts = 0;

int main() {
    vector<Account> accounts;

    // Creating accounts
    accounts.emplace_back("Alice Johnson", 1000.0);
    accounts.emplace_back("Bob Smith", 500.0);

    // Display account info
    for (const auto& acc : accounts) {
        acc.display();
    }

    // Transfer money
    cout << "\nTransferring $200 from Alice to Bob...\n";
    if (accounts[0].transferTo(accounts[1], 200)) {
        cout << "Transfer successful.\n";
    } else {
        cout << "Transfer failed due to insufficient funds.\n";
    }

    // Display updated account info
    for (const auto& acc : accounts) {
        acc.display();
    }

    // Show total number of accounts
    cout << "\nTotal accounts created: " << Account::getTotalAccounts() << endl;

    return 0;
}


// practical 3.4

#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

// Template function to find the maximum value in a collection
template <typename T>
T findMax(const vector<T>& collection) {
    T maxVal = collection[0];
    for (const T& item : collection) {
        if (item > maxVal) {
            maxVal = item;
        }
    }
    return maxVal;
}

// Template function to reverse the collection
template <typename T>
void reverseCollection(vector<T>& collection) {
    reverse(collection.begin(), collection.end());
}

// Template function to display the collection
template <typename T>
void displayCollection(const vector<T>& collection) {
    for (const T& item : collection) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    // Integer collection
    vector<int> intCollection = {4, 2, 9, 1, 7};
    cout << "Integer Collection: ";
    displayCollection(intCollection);
    cout << "Max: " << findMax(intCollection) << endl;
    reverseCollection(intCollection);
    cout << "Reversed: ";
    displayCollection(intCollection);

    // Float collection
    vector<float> floatCollection = {3.1f, 2.4f, 5.7f, 1.0f};
    cout << "\nFloat Collection: ";
    displayCollection(floatCollection);
    cout << "Max: " << findMax(floatCollection) << endl;
    reverseCollection(floatCollection);
    cout << "Reversed: ";
    displayCollection(floatCollection);

    // Char collection
    vector<char> charCollection = {'d', 'a', 'z', 'b'};
    cout << "\nChar Collection: ";
    displayCollection(charCollection);
    cout << "Max: " << findMax(charCollection) << endl;
    reverseCollection(charCollection);
    cout << "Reversed: ";
    displayCollection(charCollection);

    return 0;
}


// practical 3.5

#include <iostream>
#include <string>

using namespace std;

// Recursive function to calculate super digit
int superDigit(long long n) {
    if (n < 10)
        return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

// Helper to calculate initial sum of digits in the string and multiply by k
int calculateSuperDigit(string n, int k) {
    long long initialSum = 0;
    for (char ch : n) {
        initialSum += ch - '0';
    }

    return superDigit(initialSum * k);
}

int main() {
    string n;
    int k;

    // Example input
    n = "9875";
    k = 4;

    int result = calculateSuperDigit(n, k);
    cout << "Super digit: " << result << endl;

    return 0;
}

//4.1

#include <iostream>
#include <vector> // To handle multiple circles dynamically

using namespace std;

// Base class representing a generic shape
class Shape {
protected:
    double radius; // Store the radius of the shape

public:
    // Constructor to initialize radius
    Shape(double r) : radius(r) {}

    // Getter method to access radius
    double getRadius() const {
        return radius;
    }

    // Virtual function for calculating area (to be overridden in derived class)
    virtual double calculateArea() const {
        return 0.0;
    }
};

// Derived class representing a circle
class Circle : public Shape {
public:
    // Constructor to initialize radius using base class constructor
    Circle(double r) : Shape(r) {}

    // Overriding the calculateArea function to compute the area of a circle
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

// Function to display the areas of multiple circles
void displayAreas(const vector<Circle>& circles) {
    for (size_t i = 0; i < circles.size(); ++i) {
        cout << "Circle " << i + 1 << " (Radius: " << circles[i].getRadius()
             << ") -> Area: " << circles[i].calculateArea() << endl;
    }
}

int main() {
    // Creating a collection (vector) of circles dynamically
    vector<Circle> circles;

    // Adding circles with different radii to the collection
    circles.push_back(Circle(3.0));
    circles.push_back(Circle(5.5));
    circles.push_back(Circle(7.2));

    // Displaying the areas of the circles
    displayAreas(circles);

    return 0;
}

//practical : 4.3

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Base class for fuel type
class Fuel {
protected:
    string fuelType;
public:
    Fuel(string type) {
        fuelType = type;
    }
    void displayFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Base class for brand
class Brand {
protected:
    string brandName;
public:
    Brand(string name) {
        brandName = name;
    }
    void displayBrand() {
        cout << "Brand: " << brandName << endl;
    }
};

// Derived class combining fuel and brand
class Car : public Fuel, public Brand {
public:
    Car(string type, string name) : Fuel(type), Brand(name) {}

    void displayInfo() {
        displayBrand();
        displayFuel();
    }
};

int main() {
    // Create a queue to simulate service line
    queue<Car> serviceQueue;

    // Create car objects and add them to the queue
    Car car1("Petrol", "Toyota");
    Car car2("Diesel", "Ford");
    Car car3("Electric", "Tesla");

    serviceQueue.push(car1);
    serviceQueue.push(car2);
    serviceQueue.push(car3);

    // Process each car in the queue
    int carNumber = 1;
    while (!serviceQueue.empty()) {
        cout << "\nCar #" << carNumber << " Details:\n";
        serviceQueue.front().displayInfo();
        serviceQueue.pop();
        carNumber++;
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Base class for fuel type
class Fuel
{
protected:
    string FuelType;

public:
    Fuel(string type) : FuelType(type) {}
    void DisplayFuel()
    {
        cout << "Fuel Type : " << FuelType << endl;
    }
};

// Base class for Brand
class Brand
{
protected:
    string BrandName;

public:
    Brand(string brand) : BrandName(brand) {}
    void DisplayBrand()
    {
        cout << "Brand : " << BrandName << endl;
    }
};

// Derived class combining fuel and brand
class Car : public Fuel, public Brand
{
public:
    Car(string type, string brand) : Fuel(type), Brand(brand) {}

    void DisplayInfo()
    {
        DisplayFuel();
        DisplayBrand();
    }
};

int main()
{
    // Create a queue to simulate service line
    queue<Car> C;

    // Create car objects and add them to the queue
    Car car1("Petrol", "Toyota");
    Car car2("Diesel", "Ford");
    Car car3("Electric", "Tesla");

    C.push(car1);
    C.push(car2);
    C.push(car3);

    // Process each car in the queue
    int Number = 1;
    while (!C.empty())
    {
        cout << "Car : " << Number << " Details : ";
        C.front().DisplayInfo();
        C.pop();
        Number++;
    }
    return 0;
}

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Base class for fuel type
class Fuel
{
protected:
    string FuelType;

public:
    Fuel(string type) : FuelType(type) {}
    void DisplayFuel()
    {
        cout << "Fuel Type : " << FuelType << endl;
    }
};

// Base class for Brand
class Brand
{
protected:
    string BrandName;

public:
    Brand(string brand) : BrandName(brand) {}
    void DisplayBrand()
    {
        cout << "Brand : " << BrandName << endl;
    }
};

// Derived class combining fuel and brand
class Car : public Fuel, public Brand
{
public:
    Car(string type, string brand) : Fuel(type), Brand(brand) {}

    void DisplayInfo()
    {
        DisplayFuel();
        DisplayBrand();
    }
};

int main()
{
    // Create a queue to simulate service line
    queue<Car> C;

    // Create car objects and add them to the queue
    Car car1("Petrol", "Toyota");
    Car car2("Diesel", "Ford");
    Car car3("Electric", "Tesla");

    C.push(car1);
    C.push(car2);
    C.push(car3);

    // Process each car in the queue
    int Number = 1;
    while (!C.empty())
    {
        cout << "Car : " << Number << " Details : ";
        C.front().DisplayInfo();
        C.pop();
        Number++;
    }
    return 0;
}

//3.3
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Account class
class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Static variable to track total accounts
    static int totalAccounts;

    // Constructor
    Account(int number, string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {
        totalAccounts++;
    }

    // Destructor
    ~Account() {
        totalAccounts--;
    }

    // Get account details
    void displayDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Transfer money to another account
    bool transfer(Account &toAccount, double amount) {
        if (balance >= amount && amount > 0) {
            balance -= amount;
            toAccount.balance += amount;
            return true;
        }
        return false;
    }

    // Get balance
    double getBalance() const {
        return balance;
    }

    // Static function to get total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Initialize static variable
int Account::totalAccounts = 0;

int main() {
    // Vector to dynamically store accounts
    vector<Account> accounts;

    // Create accounts
    accounts.push_back(Account(1001, "Alice", 5000.00));
    accounts.push_back(Account(1002, "Bob", 3000.00));
    accounts.push_back(Account(1003, "Charlie", 7000.00));

    // Display account details
    cout << "Account Details:\n";
    for (const auto &account : accounts) {
        account.displayDetails();
        cout << "--------------------\n";
    }

    // Perform a money transfer
    cout << "\nTransferring money...\n";
    if (accounts[0].transfer(accounts[1], 2000.00)) {
        cout << "Transfer successful.\n";
    } else {
        cout << "Transfer failed due to insufficient balance.\n";
    }

    // Display updated balances
    cout << "\nUpdated Account Balances:\n";
    for (const auto &account : accounts) {
        account.displayDetails();
        cout << "--------------------\n";
    }

    // Total accounts
    cout << "\nTotal Accounts: " << Account::getTotalAccounts() << endl;

    return 0;
}



#include <iostream>
using namespace std;

void mergeSortedArrays(int *arr1, int n, int *arr2, int m, int *mergedArr)
{
    int i = 0, j = 0, k = 0;

    // Merge while both arrays have elements
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k++] = arr1[i++];
        }
        else
        {
            mergedArr[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while (i < n)
    {
        mergedArr[k++] = arr1[i++];
    }
    while (j < m)
    {
        mergedArr[k++] = arr2[j++];
    }
}

int main()
{
    int n, m;
    cout << "Enter sizes of two arrays: ";
    cin >> n >> m;

    // Dynamic allocation
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    int *mergedArr = new int[n + m];

    cout << "Enter " << n << " sorted elements for first array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter " << m << " sorted elements for second array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // Merge arrays
    mergeSortedArrays(arr1, n, arr2, m, mergedArr);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < n + m; i++)
    {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;

    return 0;
}


#include<iostream>

using namespace std;

class boss
{
    protected:

    int p;
    float r;
    string name;


    public:

    boss (int b , float v , string n){
        p = b;
        r = v;
    }

    void func();
    void func1();

    friend boss

};




#include<iostream>

class outer
{
    int x;

    private:
    class inner
    {

        private:

        int y;

        public:
        void get()
        {
            cout<<"Enter Y:";
            cin>>y;

            void put()
            {
                cout<<" y = "<<y<<endl;
            }
        }

    }i;
    public:
        void geto()
        {

            cout<<"Enter X:";
            cin>>x;

            void puto()
            {
                cout<<" X = "<<x<<endl;
            }
        }

}

int main()
{



    return 0;
}

*/

/*

//practical::1

#include<iostream>
#include<string>


using namespace std;

class BankAccount
{
    private:

    string Account_Holder_name;
    int Account_Number;
    int Balance;

    public:

        void SetData()
        {

            cout<<"Enter Your Bank Details:::::::::::::"<<endl;
            cout<<"Enter The Account Holder Name::";
            cin>>Account_Holder_name;
            cout<<"Enter The Account Number::";
            cin>>Account_Number;
            cout<<"Enter The Account Balance::";
            cin>>Balance;

        }

        void Deposite(int Money)
        {
            Balance = Balance + Money;
        }
        void Withdraw(int Amount)
        {
            if (Amount > Balance)
            {
                cout<<"Error ! there is no sufficient money!!";
            }
            else
            {
                Balance = Balance - Amount;
            }
        }

    void Display_Balance()
    {
        cout<<"Current Balance :"<<Balance<<endl;
    }
};

int main()
{
    BankAccount A1;
    int Money,Amount;

    A1.SetData();
    cout<<"Enter the Amount Which is to be Deposited :";
    cin>>Money;

    A1.Deposite(Money);
    A1.Display_Balance();

    cout<<"Enter the Amount you want to Withdraw :";
    cin>>Amount;

    A1.Withdraw(Amount);
    A1.Display_Balance();
}


#include <iostream>
using namespace std;

class Product
{
public:
    string ID;
    string Name;
    int Quantity;
    double price;

    void updateQuantity()
    {
        Quantity += 1;
    }

    double totalPriceOfProduct()
    {
        return (Quantity * price);
    }

    void getinfo()
    {
        cout << "Product Name:" << Name
             << endl
             << "Product id:" << ID
             << endl
             << "Quantity:" << Quantity
             << endl
             << "Price:" << price
             << endl;
    }
};

int main()
{
    string tempID;
    int i, choice, numOfproduct = 0;
    Product product[30];

    cout << "Enter Number of product:";
    cin >> numOfproduct;
    cout << endl
         << "Enter Product Details::"
         << endl;

    for (int i = 0; i < numOfproduct; i++)
    {
        cout << endl
             << "For Product no."
             << i + 1
             << endl
             << "Enter the Detials:"
             << endl;

        cout << "ID:";
        cin >> product[i].ID;
        cout << "Name:";
        cin >> product[i].Name;
        cout << "Quantity :";
        cin >> product[i].Quantity;
        cout << "Price : ";
        cin >> product[i].price;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"
             << endl;
    }
    for (i = 0; i < numOfproduct; i++)
    {
        product[i].getinfo();
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    }
again:
    cout << "press 1 : If you want add product" << endl;
    cout << "press 2 : If you want edit quantity of any product" << endl;
    cout << "press 0 : for select neither of them" << endl;
    cin >> choice;

    if (choice == 1) // if choice=1 then it will execute
    {
        cout << "For Product no. " << i + 1 << " Enter the details :" << endl;
        cout << "ID : ";
        cin >> product[i].ID;
        cout << "Name : ";
        cin >> product[i].Name;
        cout << "Quantity :";
        cin >> product[i].Quantity;
        cout << "price : ";
        cin >> product[i].price;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        product[i].getinfo();
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        i++;
        numOfproduct++;

        goto again;
    }
    else if (choice == 2) // if choice=2 then it will execute
    {
        int edit = 0; // For edit the quantity
        cout << "Enter ID of Product : ";
        cin >> tempID;
        for (i = 0; i < numOfproduct; i++)
        {
            if (product[i].ID == tempID)
            {
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                cout << "Enter no of Quantity:";
                cin >> edit;
                product[i].Quantity += edit;
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                product[i].getinfo();
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                break;
            }
        }
        if (edit == 0)
        {
            cout << "*****There is no such product with ID***** " << tempID << endl;

            goto again;
        }

        else if (choice == 0) // if choice=0 then it will execute
        {
            goto continueTheflow;
        }
    }

continueTheflow:

 double totalPriceOfAllPrroducts = 0;

    for (i = 0; i < numOfproduct; i++)
    {
        totalPriceOfAllPrroducts += product[i].totalPriceOfProduct();
    }
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Total Price of all products is " << totalPriceOfAllPrroducts
<< endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    return 0;
}


#include <iostream>
using namespace std;

class Student
{
private:
    int rollNumber;
    string nameOfStudent;
    double marks[10] = {0};

public:
    Student()
    {
        rollNumber = 0;
        nameOfStudent = "N/A";
    }

    Student(int rollNum, string name, int numOfstudent, double marksOfstudent[])
    {
        rollNumber = rollNum;
        nameOfStudent = name;
        for (int i = 0; i < numOfstudent; i++)
        {
            marks[i] = marksOfstudent[i]; // Copy marks to class array
        }
    }
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

     s1.displayDetials(numOfSub); 
    cout<<endl 
        <<endl; 
     
    //Create student object s2 using parameterized constructor 
 
    Student s2(rollNumber, name, numOfSub, marks); 
     
    //Display actual student detials with provided data 
    s2.displayDetials(numOfSub); 
        return 0;
    }

    */

    #include<iostream>

    #include<cstring>

    #include<cctype>

    using namespace std;

    #define MAX_WORDS 100

    void toLowerCase(char *str)
    {
        for (int i = 0;str[i];i++)
        {
            str[i] = tolower(str[i]);
        }
    }

    void countWords[MAX_WORDS];
    {
          char *word[MAX_WORDS];
          int wordCount[MAX_WORDS] = {0};
          int totalWorlds = 0;

          char *token = strtok(paragraph, " ");
          while (token != nullptr)
          {
            toLowerCaase(token);

            bool found = false;
            for(int i = 0; i < totalWords;i++)
            {
               if(strcmp(words[i],token) == 0)
               {
                wordCount[i]++;
                found = true;
                break;
               } 
            }
          }
    }