#include <string>
#include <iostream>
#include "lib/Dictionary.h"

using namespace std;

int main() {
    Dictionary dict;
    // dict.loadWord("alpha");
    // dict.loadWord("apple");
    // dict.loadWord("banana");
    // dict.loadWord("carrot");
    // dict.loadWord("donut");
    // dict.loadWord("guava");
    // dict.loadWord("mango");
    // dict.loadWord("tested");
    // dict.loadWord("testing");
    dict.loadFromFile("./res/words_alpha.txt");
    // dict.print();

    const char* search1 = "donut";
    const char* search2 = "manga";
    const char* search3 = "mango";
    const char* search4 = "dictionary";
    const char* search5 = "ngaudifnkjlvdkvl";

    cout << search1 << ' ' <<  dict.searchWord(search1) << endl;
    cout << search2 << ' ' <<  dict.searchWord(search2) << endl;
    cout << search3 << ' ' <<  dict.searchWord(search3) << endl;
    cout << search4 << ' ' <<  dict.searchWord(search4) << endl;
    cout << search5 << ' ' <<  dict.searchWord(search5) << endl;

    return 0;
}
