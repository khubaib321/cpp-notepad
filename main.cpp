#include <string>
#include <iostream>
#include "lib/Dictionary.h"

using namespace std;

int main() {
    Dictionary dict;
    dict.loadFromFile("./res/words_unix.txt");
    dict.loadFromFile("./res/words_alpha.txt");
    // dict.loadWord("alpha");
    // dict.loadWord("apple");
    // dict.loadWord("banana");
    // dict.loadWord("carrot");
    // dict.loadWord("donut");
    // dict.loadWord("guava");
    // dict.loadWord("mango");
    // dict.loadWord("tested");
    // dict.loadWord("testing");
    // dict.print();

    cout << "Loaded " << dict.getWordCount() << " words." << endl;

    const char* searchWords[] = {
        "donut",
        "manga",
        "mango",
        "nerdy",
        "dictionary",
        "zwitterionic",
        "ngaudifnkjlvdkvl"
    };

    for (const char* word : searchWords) {
        cout << word << ' ' <<  dict.searchWord(word) << endl;
    }

    return 0;
}
