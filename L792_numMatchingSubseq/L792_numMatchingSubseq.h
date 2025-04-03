//
// Created by garen_lee on 2025/4/3.
/**
  ******************************************************************************
  * @file           : L792_numMatchingSubseq.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/4/3
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L792_NUMMATCHINGSUBSEQ_H
#define DICTIONARYTREE_L792_NUMMATCHINGSUBSEQ_H

#include "util.h"
class L792_numMatchingSubseq : public LeetcodeDictionaryTree {
private:
    int numMatchingSubseq(string s, vector<string>& words);
public:
    L792_numMatchingSubseq() {}
    void test();
};


#endif //DICTIONARYTREE_L792_NUMMATCHINGSUBSEQ_H
