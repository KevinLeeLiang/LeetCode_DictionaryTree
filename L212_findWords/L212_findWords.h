//
// Created by garen_lee on 2025/2/20.
/**
  ******************************************************************************
  * @file           : L212_findWords.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/20
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L212_FINDWORDS_H
#define DICTIONARYTREE_L212_FINDWORDS_H

#include "util.h"
class L212_findWords : public LeetcodeDictionaryTree {
private:
    struct TrieNode {
        string word;
        unordered_map<char, TrieNode *> children;
        TrieNode() {
            this->word = "";
        }
    };
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void insertTrie(TrieNode * root, const string & word);
    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * node, set<string> & res);
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
public:
    L212_findWords(){}
    void test();
};


#endif //DICTIONARYTREE_L212_FINDWORDS_H
