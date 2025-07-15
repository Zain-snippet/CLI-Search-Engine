#include <iostream>
#include <string>
#include "tokenizer.h"
using namespace std;


int main() {
    string folder;
    cout << "📂 Enter folder path with .txt files: ";
    getline(cin, folder);

    indexFolder(folder);

    int choice;
    string query;

    do {
        cout << "\n====== SEARCH ENGINE MENU ======\n";
        cout << "1. Search for a word\n";
        cout << "2. View indexed words (optional)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clean input buffer

        switch (choice) {
            case 1:
                cout << "\n🔍 Enter word to search: ";
                getline(cin, query);
                query = cleanToken(query);

                if (invertedIndex.count(query)) {
                    cout << "\n✅ Found in:\n";
                    for (auto& [file, count] : invertedIndex[query]) {
                        cout << "📄 " << file << " (" << count << " times)\n";
                    }
                } else {
                    cout << "\n❌ Word not found in any file.\n";
                }
                break;

            case 2:
                cout << "\n📚 Indexed words:\n";
                for (auto& [word, fileMap] : invertedIndex) {
                    cout << "📝 " << word << " → ";
                    for (auto& [file, count] : fileMap) {
                        cout << file << " (" << count << " times) ";
                    }
                    cout << endl;
                }
                break;

            case 3:
                cout << "👋 Exiting. Thank you!\n";
                break;

            default:
                cout << "⚠️ Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}


        