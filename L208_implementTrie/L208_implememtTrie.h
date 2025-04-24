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

        Trie* searchPrefix(string prefix);

    public:
        Trie();
        void insert(string word);

        bool search(string word);

        bool startsWith(string prefix) ;
    };
};

class L208_implememtTrie : public LeetcodeDictionaryTree{
private:

public:
    L208_implememtTrie(){}
    void test();
};


#endif //DICTIONARYTREE_L208_IMPLEMEMTTRIE_H
