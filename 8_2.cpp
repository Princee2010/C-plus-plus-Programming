#include <iostream>
#include <map>
#include <sstream>
#include <iterator>

using namespace std;

void analyzeWordFrequency(const string& text) {
    map<string, int> wordCount;
    istringstream stream(text);
    string word;

    // Extract words and update frequencies
    while (stream >> word) {
        ++wordCount[word];
    }

    // Display results
    cout << "\nWord Frequency Distribution:\n";
    for (const auto& entry : wordCount) {
        cout << entry.first << " : " << entry.second << "\n";
    }
}

int main() {
    string inputText;
    
    cout << "Enter text for analysis:\n";
    getline(cin, inputText);
    
    analyzeWordFrequency(inputText);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}