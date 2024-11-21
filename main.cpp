// Alisha Khan
// Cosc 2030
// Programming Assignment #3

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "HashTable.h"
#include "timer.h"

using namespace std;

string cleanWord(string word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch) || ch == '\'') {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    ifstream dictFile, bookFile;
    ofstream misspelledOutFile;
    Timer myTime;

    HashTable<string> hashDictionary, hashMisspelled;

    unsigned long misspelled = 0, correct_s = 0, correct_compares = 0, misspelled_compares = 0, skipp = 0;

    // Load dictionary
    dictFile.open("dict.txt");
    if (!dictFile) {
        cout << "Dictionary file could not be opened." << endl;
        return 1;
    }

    string dictWord;
    while (dictFile >> dictWord) {
        string cleanDictWord = cleanWord(dictWord);
        if (!cleanDictWord.empty()) {
            hashDictionary.insert(cleanDictWord);
        }
    }
    dictFile.close();

    // Open book file
    bookFile.open("book.txt");
    if (!bookFile) {
        cout << "Book file could not be opened." << endl;
        return 1;
    }

    string bookWord;
    myTime.Start();
    while (bookFile >> bookWord) {
        string cleanBookWord = cleanWord(bookWord);

        if (!cleanBookWord.empty()) {
            if (isalpha(cleanBookWord[0])) {
                if (hashDictionary.find(cleanBookWord)) {
                    correct_s++;
                    correct_compares += hashDictionary.getCompareCount();
                } else {
                    misspelled++;
                    misspelled_compares += hashDictionary.getCompareCount();
                    hashMisspelled.insert(cleanBookWord);
                }
            } else {
                skipp++;
            }
        }
    }
    bookFile.close();
    myTime.Stop();

    // Calculate averages
    unsigned long long cc_avg = correct_s > 0 ? correct_compares / correct_s : 0;
    unsigned long long m_avg = misspelled > 0 ? misspelled_compares / misspelled : 0;

   // Write misspelled words to a file
    misspelledOutFile.open("misspelled.txt");
    for (const auto& word : hashMisspelled.getAllKeys()) {
        misspelledOutFile << word << std::endl;
    }
    misspelledOutFile.close();
    
    // Output results
    cout << "Dictionary size: " << hashDictionary.getSize() << endl;
    cout << "Finished in time: " << myTime.Time() << " seconds" << endl;
    cout << "There are " << correct_s << " words found in the dictionary." << endl;
    cout << "   " << correct_compares << " compares. Average: " << cc_avg << endl;
    cout << "There are " << misspelled << " words NOT found in the dictionary." << endl;
    cout << "   " << misspelled_compares << " compares. Average: " << m_avg << endl;
    cout << "There are " << skipp << " words not checked." << endl;

    return 0;
}
