//
// Created by KhubaibAfzal on 02/05/2020.
//

#include <iostream>
#include "DictNote.h"

DictNode::DictNode() : width(26) {

    this->wordEnds = false;
    this->_char = 0;
    this->initBranches();
}

void DictNode::initBranches() {
    // O(1) operation.
    // Always initializes constant [this->width] array.

    this->branches = new DictNode*[this->width];
    for (int i=0; i < this->width; ++i) {
        this->branches[i] = nullptr;
    }
}

bool DictNode::isValidNode() {
    return this->_char != 0;
}

void DictNode::loadWordAlpha(const char* word) {
    if (!word || *word == 0) return;

    this->_char = *word;
    // find suitable index
    int index = this->calculateBranchIndex(*(word + 1));
    DictNode* node = this->getBranchNode(index);
    if (node) node->loadWordAlpha(word + 1); else this->wordEnds = true;
}

int DictNode::calculateBranchIndex(const char _char) {
    // O(1) operation.
    // Calculates an index where _char should be stored.
    // Index should be in range (0, this->width) for a valid word character.

    int ascii, normalized_ascii = (int) _char;
    if (ascii >= 65 && ascii <= 90) normalized_ascii += 32;
    return normalized_ascii - 97;
}

DictNode *DictNode::getBranchNode(const int index) {
    // If a branch node exists already then returns it.
    // Otherwise creates new branch node and returns it.

    if (!this->isValidBranchIndex(index)) return nullptr;
    if (!this->branches[index]) this->branches[index] = new DictNode;
    return this->branches[index];
}

bool DictNode::isValidBranchIndex(const int index) {
    return index >= 0 && index < this->width;
}

int DictNode::getWidth() {
    return this->width;
}

bool DictNode::searchBranch(const char* word) {
    // If searching null/empty word.
    char _char = *word;
    char next_char = *(word + 1);
    if (!word || _char == 0) return false;
    // If first character matches and search string ends.
    int index = this->calculateBranchIndex(next_char);
    bool hasNextBranch = this->isValidBranchIndex(index) && this->branches[index];
    if (this->_char == _char && next_char == 0 && this->wordEnds) return true;
    // If none of above, then repeat above steps with next word character.
    return (hasNextBranch && this->branches[index]->searchBranch(word + 1));
}

void DictNode::printBranch() {
    // Does not work properly. Figure out a way to print
    // all branch words e.g, test, tested, testing, etc.
    bool hasBranch = false;
    std::cout << this->_char;
    for (int i=0; i < this->width; ++i) {
        if (this->branches[i]) {
            hasBranch = true;
            this->branches[i]->printBranch();
        }
    }
    if (!hasBranch) std::cout << ", ";
}

DictNode::~DictNode() {
    this->_char = 0;
    if (!this->branches) return;

    for (int i=0; i < this->width; ++i) {
        delete this->branches[i];
    }

    delete [] this->branches;
}
