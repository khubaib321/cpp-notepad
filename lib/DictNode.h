//
// Created by KhubaibAfzal on 02/05/2020.
//

#ifndef CPP_NOTEPAD_DICTNODE_H
#define CPP_NOTEPAD_DICTNODE_H

class DictNode {

    char _char;
    bool wordEnds;
    const int width;
    DictNode** branches;

    void initBranches();
    bool isValidBranchIndex(const int);
    DictNode* getBranchNode(const int);
    int calculateBranchIndex(const char);

public:
    DictNode();
    void loadWordAlpha(const char*);
    bool searchBranch(const char*);
    void printBranch();
    ~DictNode();
};

#endif //CPP_NOTEPAD_DICTNODE_H
