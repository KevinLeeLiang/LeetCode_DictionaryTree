//
// Created by garen_lee on 2025/2/20.
/**
  ******************************************************************************
  * @file           : L211_WordDictionary.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/20
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L211_WORDDICTIONARY_H
#define DICTIONARYTREE_L211_WORDDICTIONARY_H

#include "util.h"

namespace L211 {
    struct TrieNode {
        vector<TrieNode *> child;
        bool isEnd;
        TrieNode() {
            this->child = vector<TrieNode *>(26,nullptr);
            this->isEnd = false;
        }
    };


    class WordDictionary {
    private:
        TrieNode * trie_;
        void insert(TrieNode * root, const string & word) {
            TrieNode * node = root;
            for (auto c : word) {
                if (node->child[c - 'a'] == nullptr) {
                    node->child[c - 'a'] = new TrieNode();
                }
                node = node->child[c - 'a'];
            }
            node->isEnd = true;
        }
    public:
        WordDictionary() {
            this->trie_ = new L211::TrieNode();
        }
        void addWord(string word) {
            insert(this->trie_, word);
        }
        bool search(string word) {
            return dfs(word, 0, trie_);
        }
        bool dfs(const string & word,int index,TrieNode * node) {
            if (index == word.size()) {
                return node->isEnd;
            }
            char ch = word[index];
            if (ch >= 'a' && ch <= 'z') {
                TrieNode * child = node->child[ch - 'a'];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            } else if (ch == '.') {
                for (int i = 0; i < 26; i++) {
                    TrieNode * child = node->child[i];
                    if (child != nullptr && dfs(word, index + 1, child)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };
}


class L211_WordDictionary : public LeetcodeDictionaryTree{
private:
    L211::WordDictionary *wd_;
public:
    L211_WordDictionary() {
        this->wd_ = new L211::WordDictionary();
    }
    void test();
};


#endif //DICTIONARYTREE_L211_WORDDICTIONARY_H
