// tokenizer.cpp
#include "tokenizer.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cctype>
#include <iostream>
using namespace std;
namespace fs = filesystem;

map<string, map<string, int>> invertedIndex;

string cleanToken(const string& word) {
    string clean;
    for (char ch : word) {
        if (isalnum(ch)) clean += tolower(ch);
    }
    return clean;
}

void indexFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    string word;
    while (file >> word) {
        string token = cleanToken(word);
        if (!token.empty()) {
            invertedIndex[token][filename]++;
        }
    }

    file.close();
}

void indexFolder(const string& folderPath) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".txt") {
            indexFile(entry.path().string());
        }
    }
    cout << "Indexing complete.\n";
}