#include<iostream>
using namespace std;

//template<T>
class Calculator
{
    public:
    // make add function for multiple time
    //show Function overloding
    int add(int a, int b)
    {
        int result = a + b ;
        cout<<"Addition of "<<a<<" + "<<b<<" is ::: "<<result<<endl;
    }
    double add(double a, double b)
    {
        double result = a + b ;
        cout<<"Addition of "<<a<<" + "<<b<<" is ::: "<<result<<endl;
    }
    double add(int a, double b)
    {
        double result = a + b ;
        cout<<"Addition of "<<a<<" + "<<b<<" is ::: "<<result<<endl;
    }
    double add(double a, int b)
    {
        double result = a + b ;
        cout<<"Addition of "<<a<<" + "<<b<<" is ::: "<<result<<endl;
    }
};

int main()
{
    Calculator calc;
    //T a,b;
    /*cout<<Enter value of a :;
    cin>>a;
    cout<<Enter value of b :;
    cin>>b;
    */
    calc.add(5, 10);      // int + int
    calc.add(2.5, 4.3); // double + double
    calc.add(3.14, 2);    // double + int
    calc.add(7, 3.5);     // int + double
    cout << endl
    << endl
    << "24DIT006_PRINCEE BHINGRADIYA" << endl
    << endl;
    return 0;
}