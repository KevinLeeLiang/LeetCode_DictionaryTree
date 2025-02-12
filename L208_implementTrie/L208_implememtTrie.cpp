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

void L208_implememtTrie::test() {
    implememtTrie::Trie trie;
    trie.insert("apple");
    cout <<trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
}