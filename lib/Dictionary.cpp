#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary() : uniqueAlphabets(26) {
    this->wordCount = 0;
    this->words = new DictNode[this->uniqueAlphabets];
}

void Dictionary::print() {
    const string title = " DICTIONARY ";
    const string divider = " ========== ";
    
    cout << divider << title << this->wordCount << divider << endl;

    for (int i=0; i < this->uniqueAlphabets; ++i) {
        this->words[i].printBranch();
    }

    cout << divider << title << this->wordCount << divider << endl;
}

/**
 * Load a word character by character.
 * Takes as long as the length of the word.
 */
void Dictionary::loadWord(const char* word) {
    if (!word || *word == 0) return;
    if (this->searchWord(word)) return;

    int index = this->calculateWordIndex(*word);

    if (this->isValidWordIndex(index)) {
        if (this->words[index].loadWordAlpha(word)) {
            ++this->wordCount;
        }
        
    }
}

/**
 * Use first character to determine where to start the search from.
 * Then traverse the branch at that index and keep searching character by character.
 */
bool Dictionary::searchWord(const char* word) {
    int index = this->calculateWordIndex(*word);
    
    if (this->isValidWordIndex(index)) {
        return this->words[index].searchBranch(word);
    }
    
    return false;
}

int Dictionary::getWordCount() {
    return this->wordCount;
}

bool Dictionary::loadFromFile(const string filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Failed to open the file at: " << filePath << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        // Strip and turn to lower case.
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        transform(line.begin(), line.end(), line.begin(), ::tolower);

        this->loadWord(line.c_str());
    }

    file.close();
    return true;
}

/**
 * Calculates an index where _char should be stored.
 * Index should be in range (0, this->uniqueAlphabets) for a valid word character.
 */
int Dictionary::calculateWordIndex(const char _char) {
    int ascii = (int) tolower(_char);
    return ascii - 97;
}

bool Dictionary::isValidWordIndex(const int index) {
    return index >= 0 && index < this->uniqueAlphabets;
}

Dictionary::~Dictionary() {
    delete [] this->words;
}
