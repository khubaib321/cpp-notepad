//
// Created by KhubaibAfzal on 02/05/2020.
//

#ifndef CPP_NOTEPAD_DICTNOTE_H
#define CPP_NOTEPAD_DICTNOTE_H

class DictNode {

    char _char;
    const int width;
    bool wordEnds;
    DictNode** branches;

    void initBranches();
    bool isValidNode();
    bool isValidBranchIndex(const int);
    DictNode* getBranchNode(const int);
    int calculateBranchIndex(const char);

public:
    DictNode();
    void loadWordAlpha(const char*);
    bool searchBranch(const char*);
    void printBranch();
    int getWidth();
    ~DictNode();
};

#endif //CPP_NOTEPAD_DICTNOTE_H
