//
// Created by garen_lee on 2025/3/26.
/**
  ******************************************************************************
  * @file           : L692_topKFrequent.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L692_TOPKFREQUENT_H
#define DICTIONARYTREE_L692_TOPKFREQUENT_H

#include "util.h"
class L692_topKFrequent : public LeetcodeDictionaryTree {
private:
    vector<string> topKFrequent(vector<string> &words, int k) ;
public:
    L692_topKFrequent() {}
    void test();
};


#endif //DICTIONARYTREE_L692_TOPKFREQUENT_H
