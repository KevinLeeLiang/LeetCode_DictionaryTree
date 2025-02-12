//
// Created by garen_lee on 2025/2/12.
/**
  ******************************************************************************
  * @file           : L140_wordBreak.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/12
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L140_WORDBREAK_H
#define DICTIONARYTREE_L140_WORDBREAK_H

#include "util.h"
class L140_wordBreak : public LeetcodeDictionaryTree{
private:
    vector<string> wordBreak(string s, vector<string>& wordDict);
    void backTrack(const string& s, int index);
    unordered_map<int, vector<string>> ans_;
    unordered_set<string> wordSet_;

public:
    L140_wordBreak(){}
    void test();

};


#endif //DICTIONARYTREE_L140_WORDBREAK_H
