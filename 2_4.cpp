#include <iostream>
using namespace std;

// Class to represent an inventory item
class InventoryItem
{
public:
    string itemID;
    string itemName;
    double price;
    int Quantity;

    // Default constructor initializing price and quantity
    InventoryItem()
    {
        price = 0;
        Quantity = 0;
    }

    // Parameterized constructor initializing all item detials
    InventoryItem(string ID, string Name, double priceOfItem, int quantityOfItem)
    {
        itemID = ID;
        itemName = Name;
        price = priceOfItem;
        Quantity = quantityOfItem;
    }
    // Function to add stock
    void addStock(int qty)
    {
        Quantity += qty;
        cout << "The Quantity is updated !!" << endl;
    }

    // Function to sell item (decrease stock)

    void sellItem(int qty)
    {
        if (qty > Quantity)
        {
            cout << "There is no sufficient stock !!" << endl;
            return;
        }
        Quantity -= qty;
        cout << "The Quantity is updated !!" << endl;
    }

    // Function to display item detials
    void displayItem()
    {
        cout << "-------------------------------"
             << endl;
        cout << "Item ID :" << itemID << endl;
        cout << "Item Name :" << itemName << endl;
        cout << "Price :" << price << endl;
        cout << "Quantity :" << Quantity << endl;
        cout << "-------------------------------"
             << endl;
    }
};

int main()
{
    int num, qty;
    string id, name;
    double price;

    // Input for total number of item
    cout << "Enter number of item :";
    cin >> num;
    cout << endl;

    InventoryItem item[num]; // Array of object to store multiple items

    // Input detials for each item
    for (int i = 0; i < num; i++)
    {
        cout << "Enter Detials of item " << i + 1 << "!" << endl;
        cout << "Enter Item's ID : ";
        cin >> id;
        cout << "Enter Item's Name :";
        cin >> name;
        cout << "Enter Item's Price :";
        cin >> price;
        cout << "Enter Item's Quantity :";
        cin >> qty;

        item[i] = InventoryItem(id, name, price, qty); // Use Parameterized constructor
        cout << "---------------------------------"<<endl;
    }

    // Display Details of all items
    for (int i = 0; i < num; i++)
    {
        item[i].displayItem();
    }

    int choice, editqty, flag = 0;
    string tempID;

// Menu deriven system for inventory managment
again:
    cout << "Enter Below number for ti=o do corresponding work !!" << endl;
    cout << "     1     To Add Quantity of Any Item" << endl;
    cout << "     2     To Sell Any Item" << endl;
    cout << "     3     To see Detials of any item" << endl;
    cout << "     0     For Exit" << endl;

    cout << "Enter Choice :";
    cin >> choice;
    // if we choose 1 this code excute
    if (choice == 1)
    {
        cout << "Enter ID :";
        cin >> tempID;
        for (int i = 0; i < num; i++)
        {
            if (item[i].itemID == tempID)
            {
                cout << "Enter num of Quantity , that you want to  add :";
                cin >> editqty;
                item[i].addStock(editqty);
                flag = 1;
                goto again;
            }
        }
        if (flag == 0)
        {
            cout << "There is no such item id !!" << endl;
            goto again;
        }
    }
    // if we choose 2 this code excute
    else if (choice == 2)
    {
        cout << "Enter ID :";
        cin >> tempID;
        for (int i = 0; i < num; i++)
        {
            if (item[i].itemID == tempID)
            {
                cout << "Enter num of Quantity , that you want yo sell :";
                cin >> editqty;
                item[i].sellItem(editqty);
                flag = 1;
                goto again;
            }
            if (flag == 0)
            {
                cout << "There is no such item id !!" << endl;
                goto again;
            }
        }
    }
    // if we choose 3 this code excute
    else if (choice == 3)
    {
        cout << "Enter ID :";
        cin >> tempID;
        for (int i = 0; i < num; i++)
        {
            if (item[i].itemID == tempID)
            {
                item[i].displayItem();
                flag = 1;
                goto again;
            }
        }
        if (flag == 0)
        {
            cout << "There is no such item id !!";
            goto again;
        }
    }
    // if we want exit so we choose option 3
    else if (choice == 0)
    {
        cout << "-----------THANK YOU------------------";
        cout << endl
             << " 24DIT006 PRINCEE_BHINGRADIYA" << endl;
    }
    return 0;
}
