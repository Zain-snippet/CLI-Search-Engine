// tokenizer.h
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <map>
using namespace std;

extern map<string, map<string, int>> invertedIndex;

string cleanToken(const string& word);
void indexFile(const string& filename);
void indexFolder(const string& folderPath);

#endif