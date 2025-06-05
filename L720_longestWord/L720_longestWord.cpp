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

namespace L720 {
class Trie {
public:
    Trie(){
        this->children = vector<Trie*>(26, nullptr);
        is_end = false;
    }
    bool insert(const string &word) {;
        Trie* node = this;
        for (auto ch : word) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->is_end = true;
        return true;
    }
    bool search(const string & word) {
        Trie* node = this;
        for (auto ch : word) {
            if (node->children[ch - 'a'] == nullptr|| !node->children[ch - 'a']->is_end) {
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return node->is_end && node != nullptr;
    }
private:
    vector<Trie*>children;
    int is_end;
};
}
using namespace L720;
string L720_longestWord::longestWord(vector<string> words) {
    Trie trie;
    for (auto word : words) {
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