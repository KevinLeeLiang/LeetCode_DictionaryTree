//
// Created by garen_lee on 2025/7/3.
/**
  ******************************************************************************
  * @file           : L1268_suggestedProducts.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/3
  ******************************************************************************
  */
//

#include "L1268_suggestedProducts.h"

void L1268_suggestedProducts::addWord(Trie *root, const string &word) {
    Trie* cur = root;
    for (char c : word) {
        if (!cur->child.count(c)) {
            cur->child[c] = new Trie();
        }
        cur = cur->child[c];
        cur->words.push(word);
        if (cur->words.size() > 3) {
            cur->words.pop();
        }
    }
}

vector<vector<string>> L1268_suggestedProducts::suggestedProducts(vector<string>& products, string searchWord) {
    Trie* root = new Trie();
    for (string word : products) {
        addWord(root, word);
    }
    vector<vector<string>> ans;
    Trie* cur = root;
    bool flag = false;
    for (char c : searchWord) {
        if (flag || !cur->child.count(c)) {
            ans.push_back({});
            flag = true;
        } else {
            cur = cur->child[c];
            vector<string> selects;
            while (!cur->words.empty()) {
                selects.push_back(cur->words.top());
                cur->words.pop();
            }
            reverse(selects.begin(), selects.end());
            ans.push_back(selects);
        }
    }
    return ans;
}

void L1268_suggestedProducts::test() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> res = suggestedProducts(products, searchWord);
    print_vector_vector(res);
    products = {"havana"};
    searchWord = "havana";
    res = suggestedProducts(products, searchWord);
    print_vector_vector(res);
    products = {"bags","baggage","banner","box","cloths"};
    searchWord = "bags";
    res = suggestedProducts(products, searchWord);
    print_vector_vector(res);
}