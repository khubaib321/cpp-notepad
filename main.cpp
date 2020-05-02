#include <iostream>
#include "lib/Dictionary.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Dictionary dict;
    dict.loadWord("apple");
    dict.loadWord("banana");
    dict.loadWord("carrot");
    dict.loadWord("dimple");
    dict.loadWord("guava");
    dict.loadWord("mango");
    dict.print();

    // searches
    char* search = "guava";
    std::cout << search << ' ' <<  dict.searchWord(search) << std::endl;
    return 0;
}
