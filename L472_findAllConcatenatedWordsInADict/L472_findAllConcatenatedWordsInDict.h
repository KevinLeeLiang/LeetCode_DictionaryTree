//
// Created by garen_lee on 2025/3/12.
/**
  ******************************************************************************
  * @file           : L472_findAllConcatenatedWordsInDict.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/12
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L472_FINDALLCONCATENATEDWORDSINDICT_H
#define DICTIONARYTREE_L472_FINDALLCONCATENATEDWORDSINDICT_H

#include "util.h"
class L472_findAllConcatenatedWordsInDict : public LeetcodeDictionaryTree {

private:
    struct Trie {
        bool is_end;
        vector<Trie*>children;
        Trie(){
            this->children = vector<Trie*>(26, nullptr);
            this->is_end = false;
        }
    };
    Trie* trie = new Trie();
    bool dfs(const string &word, int start, vector<int>& visited);
    void insert(const string& word);
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words);
public:
    L472_findAllConcatenatedWordsInDict() {}
    void test();
};


#endif //DICTIONARYTREE_L472_FINDALLCONCATENATEDWORDSINDICT_H
