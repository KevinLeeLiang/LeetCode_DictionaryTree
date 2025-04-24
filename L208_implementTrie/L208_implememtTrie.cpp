//
// Created by garen_lee on 2025/2/12.
/**
  ******************************************************************************
  * @file           : L208_implememtTrie.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/12
  ******************************************************************************
  */
//

#include "L208_implememtTrie.h"

using namespace implememtTrie;

Trie::Trie() : children(26) , isEnd(false) {}

void Trie::insert(string word) {
    Trie* node = this;
    for (char ch : word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            node->children[ch] = new Trie();
        }
        node = node->children[ch];
    }
    node->isEnd = true;
}

bool Trie::search(string word) {
    Trie* node = this->searchPrefix(word);
    return node != nullptr && node->isEnd;
}

Trie* Trie::searchPrefix(string prefix) {
    Trie* node = this;
    for (char ch : prefix) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            return nullptr;
        }
        node = node->children[ch];
    }
    return node;
}

bool Trie::startsWith(string prefix) {
    return this->searchPrefix(prefix) != nullptr;
}

void L208_implememtTrie::test() {
    implememtTrie::Trie trie;
    trie.insert("apple");
    cout <<trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
}