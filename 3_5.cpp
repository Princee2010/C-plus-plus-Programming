#include<iostream>
#include<string>
using namespace std;

//Recursive function to calculate super digit
int SuperDigit(long long n)
{
    if(n < 10)
    {
        return n; 
    }
    long long sum = 0;
    while( n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }

    return SuperDigit(sum);
}

int calculateSuperDigit( string n , int k)
{
    long long initialSum = 0;
    for(char ch : n)
    {
        initialSum += ch - '0';
    }

    return SuperDigit(initialSum * k);
}


int main()
{
    string n;
    int k;

    n = "4523"; // 3 + 2 + 1 = 6
    k = 2; // 1 time repeat

    /*
    n = "4523"; // 4+5+2+3+4+5+2+3 = 28 = 2+8 = 10 = 1+0 = 1
    k = 2;
    */

    int result = calculateSuperDigit( n , k);
    cout<<"Super Digit : "<<result <<endl;
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}