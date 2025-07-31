//
// Created by garen_lee on 2025/7/31.
/**
  ******************************************************************************
  * @file           : L1938_maxGeneticDifference.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/31
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1938_MAXGENETICDIFFERENCE_H
#define DICTIONARYTREE_L1938_MAXGENETICDIFFERENCE_H

#include "util.h"
class L1938_maxGeneticDifference : public LeetcodeDictionaryTree {
private:
    static constexpr int MAXD = 17;
    vector<int>  maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries);
public:
    L1938_maxGeneticDifference() {}
    void test();
};


#endif //DICTIONARYTREE_L1938_MAXGENETICDIFFERENCE_H
