#ifndef CPP_NOTEPAD_DICTNODE_H
#define CPP_NOTEPAD_DICTNODE_H
#include <string>
using namespace std;

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
    bool loadWordAlpha(const char*);
    bool searchBranch(const char*);
    void printBranch(const string = "");
    ~DictNode();
};

#endif //CPP_NOTEPAD_DICTNODE_H
