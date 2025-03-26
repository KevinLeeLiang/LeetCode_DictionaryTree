//
// Created by garen_lee on 2025/3/26.
/**
  ******************************************************************************
  * @file           : L720_longestWord.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/26
  ******************************************************************************
  */
//

#include "L720_longestWord.h"
using namespace L720;
string L720_longestWord::longestWord(vector<string> words) {
    Trie trie;
    for (const auto & word : words) {
        trie.insert(word);
    }
    string longest = "";
    for (const auto & word : words) {
        if (trie.search(word)) {
            if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                longest = word;
            }
        }
    }
    return longest;
}
void L720_longestWord::test() {
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    cout << longestWord(words) << endl;

    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestWord(words) << endl;
}