#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class DirectoryManager
{
private:
    map<string, vector<string>> directory; // Folder mapping

public:
    // Function to create a new folder
    void createFolder(const string &folderName)
    {
        if (directory.find(folderName) == directory.end())
        {
            directory[folderName] = {}; // Initialize empty file list
            cout << "Folder '" << folderName << "' created successfully.\n";
        }
        else
        {
            cout << "Folder '" << folderName << "' already exists.\n";
        }
    }

    // Function to add a file to a specified folder
    void addFile(const string &folderName, const string &fileName)
    {
        if (directory.find(folderName) != directory.end())
        {
            directory[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        }
        else
        {
            cout << "Error: Folder '" << folderName << "' does not exist.\n";
        }
    }

    // Function to display the directory structure
    void displayDirectory() const
    {
        cout << "\nDirectory Structure:\n";
        for (const auto &entry : directory)
        {
            cout << "[" << entry.first << "]\n";
            for (const auto &file : entry.second)
            {
                cout << "  - " << file << "\n";
            }
        }
    }
};

int main()
{
    DirectoryManager dm;
    int choice;
    string folderName, fileName;

    while (true)
    {
        cout << "Directory Management System\n";
        cout << "1. Create Folder\n";
        cout << "2. Add File\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter folder name: ";
            cin >> folderName;
            dm.createFolder(folderName);
            break;
        case 2:
            cout << "Enter folder name: ";
            cin >> folderName;
            cout << "Enter file name: ";
            cin >> fileName;
            dm.addFile(folderName, fileName);
            break;
        case 3:
            dm.displayDirectory();
            break;
        case 4:
            cout << "Exiting program.";
            cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<< endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again.";
        }
    }
}
