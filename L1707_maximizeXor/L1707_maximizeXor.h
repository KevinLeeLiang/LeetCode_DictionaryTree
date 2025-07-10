//
// Created by garen_lee on 2025/7/10.
/**
  ******************************************************************************
  * @file           : L1707_maximizeXor.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/10
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1707_MAXIMIZEXOR_H
#define DICTIONARYTREE_L1707_MAXIMIZEXOR_H

#include "util.h"
class L1707_maximizeXor : public LeetcodeDictionaryTree {
private:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries);
public:
    L1707_maximizeXor() {}
    void test();
};


#endif //DICTIONARYTREE_L1707_MAXIMIZEXOR_H
