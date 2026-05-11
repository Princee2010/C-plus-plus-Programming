/*#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void countWordsSTL(const string& paragraph)
{
    unordered_map<string, int> wordFreq;
    stringstream ss(paragraph);
    string word;

    while (ss >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Convert to lowercase
        wordFreq[word]++;
    }

    for (const auto& pair : wordFreq)
    {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main()
{
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph); // Read entire input as a single string

    countWordsSTL(paragraph);
    return 0;
}
*/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#define MAX_WORDS 100

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void countWords(char *paragraph)
{
    char *words[MAX_WORDS];
    int wordCount[MAX_WORDS] = {0};
    int totalWords = 0;

    char *token = strtok(paragraph, " ");
    while (token != nullptr)
    {
        toLowerCase(token);

        bool found = false;
        for (int i = 0; i < totalWords; i++)
        {
            if (strcmp(words[i], token) == 0)
            {
                wordCount[i]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            words[totalWords] = token;
            wordCount[totalWords] = 1;
            totalWords++;
        }

        token = strtok(nullptr, " ");
    }

    for (int i = 0; i < totalWords; i++)
    {
        cout << words[i] << ": " << wordCount[i] << "\n";
    }
}

int main()
{
    char paragraph[500];
    cout << "Enter a paragraph: ";
    cin.getline(paragraph, 500); // Read entire input as a single string

    countWords(paragraph);

    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}