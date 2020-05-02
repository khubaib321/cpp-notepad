//
// Created by KhubaibAfzal on 02/05/2020.
//

#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() : alphabets(26) {
    this->words = new DictNode[alphabets];
}

void Dictionary::print() {
    std::cout << "ALL LOADED WORDS =>" << std::endl;

    for (int i=0; i < this->alphabets; ++i) {
        this->words[i].printBranch();
        std::cout << std::endl;
    }
}

void Dictionary::loadWord(const char* word) {
    if (!word || *word == 0) return;
    int index = this->calculateWordIndex(*word);
    if (this->isValidWordIndex(index)) this->words[index].loadWordAlpha(word);
}

bool Dictionary::searchWord(const char* word) {
    int index = this->calculateWordIndex(*word);
    if (this->isValidWordIndex(index)) return this->words[index].searchBranch(word);
    std::cout << "Not a valid English word." << std::endl;
    return false;
}

void Dictionary::loadFromFile(const char* filePath) {

}

int Dictionary::calculateWordIndex(const char _char) {
    // O(1) operation.
    // Calculates an index where _char should be stored.
    // Index should be in range (0, this->width) for a valid word character.

    int ascii, normalized_ascii = (int) _char;
    if (ascii >= 65 && ascii <= 90) normalized_ascii += 32;
    return normalized_ascii - 97;
}

bool Dictionary::isValidWordIndex(const int index) {
    return index >= 0 && index < this->words->getWidth();
}

Dictionary::~Dictionary() {
    delete [] this->words;
}

