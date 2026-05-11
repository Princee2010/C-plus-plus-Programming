#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Item
{
    string name;
    int quantity;
    double price;
};

void addItemToFile(const Item &item, const string &filename)
{
    ofstream file(filename, ios::app);
    if (!file)
    {
        cerr << "Error: Unable to open file.\n";
        return;
    }
    file << item.name << " " << item.quantity << " " << item.price << "\n";
    file.close();
}

vector<Item> loadInventory(const string &filename)
{
    vector<Item> inventory;
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Unable to open file.\n";
        return inventory;
    }

    Item item;
    while (file >> item.name >> item.quantity >> item.price)
    {
        inventory.push_back(item);
    }
    file.close();
    return inventory;
}

void searchItem(const vector<Item> &inventory, const string &itemName)
{
    for (const auto &item : inventory)
    {
        if (item.name == itemName)
        {
            cout << "Item Found: " << item.name<<endl<< "Quantity: " << item.quantity <<endl<< "Price: $" << item.price << "\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

int main()
{
    string filename = "inventory.txt";

    // Example: Adding items
    addItemToFile({"Orange", 20, 2.0}, filename);
    addItemToFile({"Grapes", 50, 3.5}, filename);
    addItemToFile({"Apple", 25, 2.5}, filename);

    // Loading inventory into memory
    vector<Item> inventory = loadInventory(filename);

    // Searching for an item
    searchItem(inventory, "Apple");
    
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}
