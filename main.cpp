#include <iostream>
#include "lib/Dictionary.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Dictionary dict;
    dict.loadWord("apple");
    dict.loadWord("banana");
    dict.loadWord("carrot");
    dict.loadWord("donut");
    dict.loadWord("guava");
    dict.loadWord("mango");
    dict.print();

    // searches
    char* search1 = "donut";
    char* search2 = "manga";
    std::cout << search1 << ' ' <<  dict.searchWord(search1) << std::endl;
    std::cout << search2 << ' ' <<  dict.searchWord(search2) << std::endl;
    return 0;
}
