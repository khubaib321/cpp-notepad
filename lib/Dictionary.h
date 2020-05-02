//
// Created by KhubaibAfzal on 02/05/2020.
//

#ifndef CPP_NOTEPAD_DICTIONARY_H
#define CPP_NOTEPAD_DICTIONARY_H

#include "DictNode.h"

class Dictionary {
    DictNode* words;
    const int uniqueAlphabets;

    bool isValidWordIndex(const int);
    int calculateWordIndex(const char);

public:
    Dictionary();
    void print();
    void loadWord(const char*);
    bool searchWord(const char*);
    void loadFromFile(const char*);
    ~Dictionary();
};

#endif //CPP_NOTEPAD_DICTIONARY_H
