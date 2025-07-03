//
// Created by garen_lee on 2025/7/3.
/**
  ******************************************************************************
  * @file           : L1268_suggestedProducts.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/3
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1268_SUGGESTEDPRODUCTS_H
#define DICTIONARYTREE_L1268_SUGGESTEDPRODUCTS_H

#include "util.h"
class L1268_suggestedProducts : public LeetcodeDictionaryTree {
    struct Trie {
        unordered_map<char, Trie*> child;
        priority_queue<string> words;
    };
private:
    void addWord(Trie* root, const string& word);

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) ;
public:
    L1268_suggestedProducts() {}
    void test();
};


#endif //DICTIONARYTREE_L1268_SUGGESTEDPRODUCTS_H
