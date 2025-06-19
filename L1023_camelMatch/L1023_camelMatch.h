//
// Created by garen_lee on 2025/6/19.
/**
  ******************************************************************************
  * @file           : L1023_camelMatch.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/6/19
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1023_CAMELMATCH_H
#define DICTIONARYTREE_L1023_CAMELMATCH_H

#include "util.h"
class L1023_camelMatch : public LeetcodeDictionaryTree {
private:
    vector<bool> camelMatch(vector<string>& queries, string pattern);
public:
    L1023_camelMatch() {}
    void test();
};


#endif //DICTIONARYTREE_L1023_CAMELMATCH_H
