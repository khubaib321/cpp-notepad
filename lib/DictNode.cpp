#include <iostream>
#include "DictNode.h"
#include <string>

using namespace std;

DictNode::DictNode() : width(26) {
    this->_char = 0;
    this->initBranches();
    this->wordEnds = false;
}

/**
 * Always initializes constant [this->width] array.
 */
void DictNode::initBranches() {
    this->branches = new DictNode*[this->width];
    for (int i=0; i < this->width; ++i) {
        this->branches[i] = nullptr;
    }
}

/**
 * Recursively loads a word character by character (alphabets only).
 * Each character is stored at a specific node calculated by hash method.
 * If that node is already created then it moves forward to store the next
 * character. The last character in word is stored, marks the ending of a word.
 */
bool DictNode::loadWordAlpha(const char* word) {
    this->_char = *word;
    
    // Get index of the next character in word
    int index = this->calculateBranchIndex(*(word + 1));
    DictNode* node = this->getBranchNode(index);
    
    // Continue to load the next character
    if (node) {
        return node->loadWordAlpha(word + 1);
     } else {
        this->wordEnds = true;
        return true;
     }
}

/**
 * Calculates an index where _char should be stored. 
 * Index should be in range (0, this->width) for a valid word character.
 */
int DictNode::calculateBranchIndex(const char _char) {
    int ascii = (int) tolower(_char);
    return ascii - 97;
}

/**
 * If a branch node exists already then returns it.
 * Otherwise creates new branch node and returns it.
 */
DictNode *DictNode::getBranchNode(const int index) {
    if (!this->isValidBranchIndex(index)) return nullptr;
    
    if (!this->branches[index]) {
        this->branches[index] = new DictNode;
    }
    
    return this->branches[index];
}

bool DictNode::isValidBranchIndex(const int index) {
    return index >= 0 && index < this->width;
}

/**
 * Recursive search character by character.
 * Takes as long as the longest word in the branch (worst case).
 */
bool DictNode::searchBranch(const char* word) {
    char _char = *word;
    char next_char = *(word + 1);
    if (!word || _char == 0) return false;
    if (next_char == 0 && this->wordEnds) return true;

    // If none of above, then repeat above steps with next word character.
    int index = this->calculateBranchIndex(next_char);
    bool hasNextBranch = this->isValidBranchIndex(index) && this->branches[index];

    return (hasNextBranch && this->branches[index]->searchBranch(word + 1));
}

/**
 * Traverse a branch memorizing visited nodes.
 * Prints all visited nodes when it reaches a dead end.
 */
void DictNode::printBranch(const string visited) {
    if (!this->_char) return;

    bool hasNextBranch = false;

    for (int i=0; i < this->width; ++i) {
        if (this->branches[i]) {
            hasNextBranch = true;
            this->branches[i]->printBranch(visited + this->_char);
        }
    }

    if (!hasNextBranch) cout << visited + this->_char << endl;
}

DictNode::~DictNode() {
    this->_char = 0;
    if (!this->branches) return;

    for (int i=0; i < this->width; ++i) {
        delete this->branches[i];
    }

    delete [] this->branches;
}
