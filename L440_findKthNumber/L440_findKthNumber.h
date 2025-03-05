//
// Created by garen_lee on 2025/3/5.
/**
  ******************************************************************************
  * @file           : L440_findKthNumber.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/5
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L440_FINDKTHNUMBER_H
#define DICTIONARYTREE_L440_FINDKTHNUMBER_H

#include "util.h"
class L440_findKthNumber : public LeetcodeDictionaryTree {
private:
    int calculateSteps(int n, long long curr, long long next);
    int findKthNumber(int n, int k);
public:
    L440_findKthNumber() {}
    void test();
};


#endif //DICTIONARYTREE_L440_FINDKTHNUMBER_H
