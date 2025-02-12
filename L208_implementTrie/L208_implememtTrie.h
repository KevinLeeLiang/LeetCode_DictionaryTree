//
// Created by garen_lee on 2025/2/12.
/**
  ******************************************************************************
  * @file           : L208_implememtTrie.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/12
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L208_IMPLEMEMTTRIE_H
#define DICTIONARYTREE_L208_IMPLEMEMTTRIE_H

#include "util.h"
namespace implememtTrie{
    class Trie {
    private:
        vector<Trie*> children;
        bool isEnd;

        Trie* searchPrefix(string prefix) {
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


    public:
        Trie() : children(26), isEnd(false) {}

        void insert(string word) {
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

        bool search(string word) {
            Trie* node = this->searchPrefix(word);
            return node != nullptr && node->isEnd;
        }

        bool startsWith(string prefix) {
            return this->searchPrefix(prefix) != nullptr;
        }
    };
};

class L208_implememtTrie : public LeetcodeDictionaryTree{
private:

public:
    L208_implememtTrie(){}
    void test();
};


#endif //DICTIONARYTREE_L208_IMPLEMEMTTRIE_H
