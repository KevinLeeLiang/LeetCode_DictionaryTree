//
// Created by garen_lee on 2025/4/3.
/**
  ******************************************************************************
  * @file           : L745_WordFilter.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/4/3
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L745_WORDFILTER_H
#define DICTIONARYTREE_L745_WORDFILTER_H

#include "util.h"
namespace L745 {
    struct Trie {
        unordered_map<string, Trie*>children;
        int weight;
    };
    class WordFilter {
    private:
        Trie *trie;
    public:
        WordFilter(vector<string>& words);

        int f(string prefix, string suffix);
    };
};
class L745_WordFilter : public LeetcodeDictionaryTree {
public:
    L745_WordFilter() {}
    void test();
};


#endif //DICTIONARYTREE_L745_WORDFILTER_H
