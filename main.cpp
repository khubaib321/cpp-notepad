#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include "lib/Dictionary.h"

using namespace std;

int main() {
    Dictionary dict;
    dict.loadFromFile("./res/words_unix.txt");
    dict.loadFromFile("./res/words_alpha.txt");

    cout << "Loaded " << dict.getWordCount() << " words." << endl;

    const char* searchWords[] = {
        "gess",
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

    cout << endl << "Welcome to the world's \"fastest\" notepad. Type away! (press esc+enter to escape)" << endl << endl;

    string word = "";
    vector<string> words;

    while (true) {
        const char ch = cin.get();

        if (ch == 27) {
            break;
        }

        if (isalnum(ch)) word += ch;
        else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    
    cout << endl << "Your english:" << endl;
    for (const auto& w : words) {
        cout << w << ' ';
        if (dict.searchWord(w.c_str())) cout << "...ok" << endl;
        else cout << "...lol" << endl;
    }

    return 0;
}
