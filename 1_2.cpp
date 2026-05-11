// Practical:1.2

// A Program for an inventory managment system using object oriented approaches.

#include <iostream>
using namespace std;

// creating class named product

class Product
{
public:
    // Declaring attributes for product in public

    string ID;
    string Name;
    int Quantity;
    double price;

    // Declaring and defining methods

    // Method for update quantity

    void updateQuantity()
    {
        Quantity += 1;
    }

    // Method that calculates total price

    double totalPriceOfProduct()
    {
        return (Quantity * price);
    }

    // Method for printing information of product

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
    string tempID; // For finding the product for edit quantity
    int i, choice, numOfproduct = 0;
    Product product[30]; // Creating array of object

    cout << "Enter Number of product:";
    cin >> numOfproduct;
    cout << endl
         << "Enter Product Details::"
         << endl;

    // Taking user input for product information
    for (int i = 0; i < numOfproduct; i++)
    {
        cout <<endl
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
             <<endl;
    }

    // Displaying product detials

    for (i = 0; i < numOfproduct; i++)
    {
        product[i].getinfo();
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    }

again:

    // Displaying press keys for differnt tasks

    cout << "press 1 : If you want add product" << endl;
    cout << "press 2 : If you want edit quantity of any product" << endl;
    cout << "press 0 : for select neither of them" << endl;
    cin >> choice; // Taking user's choice

    if (choice == 1) // if choice=1 then it will execute
    {
        cout << "For Product no. " << i + 1 << " Enter the details :" << endl;
        cout << "ID : ";
        cin >> product[i].ID;
        cout << "Name : ";
        cin >> product[i].Name;
        cout << "Quantity :";
        cin >> product[i].Quantity;
        cout << "Price : ";
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
        }
        goto again;
    }

    else if (choice == 0) // if choice=0 then it will execute
    {
        goto continueTheflow;
    }

continueTheflow:

    double totalPriceOfAllPrroducts = 0;

    for (i = 0; i < numOfproduct; i++)
    {
        totalPriceOfAllPrroducts += product[i].totalPriceOfProduct();
    }
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Total Price of all products is " << totalPriceOfAllPrroducts << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

    cout << endl
         << endl
         << "24DIT006 PRINCEE_BHINGRADIYA" << endl;
    return 0;
}
