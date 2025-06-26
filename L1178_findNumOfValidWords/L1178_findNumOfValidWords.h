//
// Created by garen_lee on 2025/6/26.
/**
  ******************************************************************************
  * @file           : L1178_findNumOfValidWords.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/6/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1178_FINDNUMOFVALIDWORDS_H
#define DICTIONARYTREE_L1178_FINDNUMOFVALIDWORDS_H

#include "util.h"
class L1178_findNumOfValidWords : public LeetcodeDictionaryTree {
private:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles);
public:
    L1178_findNumOfValidWords() {}
    void test();
};


#endif //DICTIONARYTREE_L1178_FINDNUMOFVALIDWORDS_H
