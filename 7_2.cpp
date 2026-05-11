#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void processFileDynamic(const string &filename)
{

    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    vector<string> lines;
    int lineCount = 0, wordCount = 0, charCount = 0;
    string line;

    while (getline(file, line))
    {
        lines.push_back(line);
        charCount += line.length();

        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            wordCount++;
        }

        lineCount++;
    }

    file.close();

    cout << "Lines: " << lineCount << "\n";
    cout << "Words: " << wordCount << "\n";
    cout << "Characters: " << charCount << "\n";
}

int main()
{
    string filename = "sample.txt";
    processFileDynamic(filename);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}