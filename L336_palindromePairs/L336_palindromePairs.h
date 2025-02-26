//
// Created by garen_lee on 2025/2/26.
/**
  ******************************************************************************
  * @file           : L336_palindromePairs.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L336_PALINDROMEPAIRS_H
#define DICTIONARYTREE_L336_PALINDROMEPAIRS_H

#include "util.h"
class L336_palindromePairs : public LeetcodeDictionaryTree {
private:
    vector<vector<int>> palindromePairs(vector<string>& words);
    bool f(string s, int left, int right);
public:
    L336_palindromePairs() {}
    void test();

};


#endif //DICTIONARYTREE_L336_PALINDROMEPAIRS_H
