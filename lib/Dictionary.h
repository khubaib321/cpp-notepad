#ifndef CPP_NOTEPAD_DICTIONARY_H
#define CPP_NOTEPAD_DICTIONARY_H

#include "DictNode.h"
#include <string>

using namespace std;

class Dictionary {
    DictNode* words;
    
    int wordCount;
    const int uniqueAlphabets;

    bool isValidWordIndex(const int);
    int calculateWordIndex(const char);

public:
    Dictionary();
    void print();
    void loadWord(const char*);
    bool searchWord(const char*);
    bool loadFromFile(const string);
    ~Dictionary();
};

#endif //CPP_NOTEPAD_DICTIONARY_H
