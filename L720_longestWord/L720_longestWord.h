//
// Created by garen_lee on 2025/3/26.
/**
  ******************************************************************************
  * @file           : L720_longestWord.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L720_LONGESTWORD_H
#define DICTIONARYTREE_L720_LONGESTWORD_H

#include "util.h"

namespace L720 {
    class Trie {
    public:
        Trie(){
            this->children = vector<Trie*>(26, nullptr);
            is_end = false;
        }
        bool insert(const string &word) {
            Trie * node = this;
            for (const auto& ch : word) {
                int index = ch - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new Trie();
                }
                node = node->children[index];
            }
            node->is_end = true;
            return true;
        }
        bool search(const string & word) {
            Trie * node = this;
            for (const auto& ch : word) {
                int index = ch - 'a';
                if (node->children[index] == nullptr || !node->children[index]->is_end) {
                    return false;
                }
                node = node->children[index];
            }
            return node != nullptr && node->is_end;
        }
    private:
        vector<Trie*>children;
        int is_end;
    };
}

class L720_longestWord : public LeetcodeDictionaryTree {
private:
    string longestWord(vector<string> words);
public:
    L720_longestWord() {};
    void test();
};


#endif //DICTIONARYTREE_L720_LONGESTWORD_H
