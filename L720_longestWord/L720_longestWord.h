//
// Created by garen_lee on 2025/3/26.
/**
  ******************************************************************************
  * @file           : L720_longestWord.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L720_LONGESTWORD_H
#define DICTIONARYTREE_L720_LONGESTWORD_H

#include "util.h"

class L720_longestWord : public LeetcodeDictionaryTree {
private:
    string longestWord(vector<string> words);
public:
    L720_longestWord() {};
    void test();
};


#endif //DICTIONARYTREE_L720_LONGESTWORD_H
