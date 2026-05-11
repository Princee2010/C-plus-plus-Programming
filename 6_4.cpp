#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base() { cout << "Base Destructor Called\n"; } // Virtual destructor
};

class Derived : public Base
{
private:
    int *data;

public:
    Derived() { data = new int(10); }
    ~Derived()
    {
        delete data;
        cout << "Derived Destructor Called\n";
    }
};

int main()
{
    Base *obj = new Derived(); // Upcasting
    delete obj;                // Both Base & Derived destructors are called, preventing memory leak!

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}